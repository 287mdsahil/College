;masm program to add and substract two 16 bit numbers
.model small
.stack 100h

.data
inputPrompt DB 13,"Enter a 16 bit number: $"
num1 DW ?
num2 DW ?
num DW ?
sum DW ?
sumCarry DW 00h
sumPrompt DB 10,"The sum is: $"

.code
mov ax,@data
mov ds,ax
call main
mov ah,4ch
int 21h

main proc

    ;taking input for first number
    lea dx, inputPrompt
    mov ah,9
    int 21h
    call getNum
    mov num1,ax

    ;taking input for second number
    lea dx, inputPrompt
    mov ah,9
    int 21h
    call getNum
    mov num2,ax

    ;performing addition
    mov ax,num1
    add ax,num2
    jnc noCarry
    inc sumCarry
    noCarry:
    mov sum,ax

    ;output for sum
    lea dx,sumPrompt
    mov ah,9
    int 21h
    mov ax,sumCarry
    mov num,ax
    call outputNum
    mov ax,sum
    mov num,ax
    call outputNum

    ret
main endp

;function to take 16 bit number input
getNum proc
    push cx
    push dx

    mov dx, 0000
    mov ax, 0000
    mov cl, 4
    
    getNumber:

    call getChar
    cmp al, 13
    je inputDone
    cmp al, 10
    je inputDone

    shl dx,cl
    sub al, 48
    cmp al, 9
    jle isNumber
    sub al, 7

    isNumber:
    or dl, al

    jmp getNumber

    inputDone:
    mov ax, dx

    pop dx
    pop cx
    ret
getNum endp


;fucntion to take in character
getChar proc
    mov ah,1
    int 21h
    ret
getChar endp


; program to output a 16 bit number stored in num
outputNum proc
    push cx
    push dx


    mov cl, 4
    mov dx, num
    mov dl,dh
    shr dl,cl
    and dl, 0fh
    cmp dl,0ah
    jl isNumber4
    add dl,7
    isNumber4:
    add dl,48
    mov ah, 2
    int 21h

    mov dx, num
    mov dl,dh
    and dl, 0fh
    cmp dl, 0ah
    jl isNumber3
    add dl, 07h
    isNumber3:
    add dl,48
    mov ah, 2
    int 21h


    mov cl, 4
    mov dx, num
    shr dl,cl
    and dl, 0fh
    cmp dl,0ah
    jl isNumber2
    add dl,7
    isNumber2:
    add dl,48
    mov ah, 2
    int 21h

    mov dx, num
    and dl, 0fh
    cmp dl, 0ah
    jl isNumber1
    add dl, 07h
    isNumber1:
    add dl,48
    mov ah, 2
    int 21h

    pop dx
    pop cx
    ret
outputNum endp

end