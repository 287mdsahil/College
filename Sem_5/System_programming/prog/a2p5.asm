;masm program for division of 16 bit number by 8 bit number
.model small
.stack 100h

.data
inputDividend DB 13,"Enter the dividend (16bit): $"
inputDivisor DB 13,"Enter the divisor (8bit): $"
outputQuotient DB 13,"Quotiend is: $"
ouputReminder DB 10,"Reminder is: $"
dividend DW ?
divisor DB ?
quotient DW ?
reminder Dw ?
num16 DW ?
num8 DB ?

.code 
mov ax,@data
mov ds,ax
call main
mov ah,4ch
int 21h


main proc

    ;taking input for dividend
    lea dx,inputDividend
    mov ah,9
    int 21h
    call getNum16
    mov dividend,ax

    ;taking input for divisor
    lea dx,inputDivisor
    mov ah,9
    int 21h
    call getNum8
    mov divisor,al

    ;performing division
    mov ax,dividend
    mov dx,00
    mov bl,divisor
    mov bh,0
    div bx
    mov quotient,ax
    mov reminder,dx

    ;output quotient
    lea dx, outputQuotient
    mov ah,9
    int 21h
    mov ax,quotient
    mov num16,ax
    call outputNum16

    ;output reminder
    lea dx, ouputReminder
    mov ah,9
    int 21h
    mov ax,reminder
    mov num16,ax
    call outputNum16

    ret
main endp


;fucntion to take in character
getChar proc
    mov ah,1
    int 21h
    ret
getChar endp

;function to take 16 bit number input
getNum16 proc
    push cx
    push dx

    mov dx, 0000
    mov ax, 0000
    mov cl, 4
    
    getNumber16:

    call getChar
    cmp al, 13
    je inputDone16
    cmp al, 10
    je inputDone16

    shl dx,cl
    sub al, 48
    cmp al, 9
    jle isNumber
    sub al, 7

    isNumber:
    or dl, al

    jmp getNumber16

    inputDone16:
    mov ax, dx

    pop dx
    pop cx
    ret
getNum16 endp

; program to output a 16 bit number stored in num16
outputNum16 proc
    push cx
    push dx


    mov cl, 4
    mov dx, num16
    mov dl,dh
    shr dl,cl
    and dl, 0fh
    cmp dl,0ah
    jl isNumber16n4
    add dl,7
    isNumber16n4:
    add dl,48
    mov ah, 2
    int 21h

    mov dx, num16
    mov dl,dh
    and dl, 0fh
    cmp dl, 0ah
    jl isNumber16n3
    add dl, 07h
    isNumber16n3:
    add dl,48
    mov ah, 2
    int 21h


    mov cl, 4
    mov dx, num16
    shr dl,cl
    and dl, 0fh
    cmp dl,0ah
    jl isNumber16n2
    add dl,7
    isNumber16n2:
    add dl,48
    mov ah, 2
    int 21h

    mov dx, num16
    and dl, 0fh
    cmp dl, 0ah
    jl isNumber16n1
    add dl, 07h
    isNumber16n1:
    add dl,48
    mov ah, 2
    int 21h

    pop dx
    pop cx
    ret
outputNum16 endp

;function to take number input 8bit
getNum8 proc
    push cx
    push dx

    mov dl, 00
    mov cl, 04
    
    getNumber8:

    call getChar
    cmp al, 13
    je inputDone8
    cmp al, 10
    je inputDone8

    shl dl,cl
    sub al, 48
    cmp al, 9
    jle isNumber8
    sub al, 7

    isNumber8:
    or dl, al
    
    jmp getNumber8

    inputDone8:
    mov al, dl
    pop dx
    pop cx
    ret
getNum8 endp

; program to output a number stored in num8
outputNum8 proc
    push cx
    push dx

    mov cl, 4
    mov dl, num8
    shr dl,cl
    and dl, 0fh
    cmp dl,0ah
    jl isNumber8n2
    add dl,7
    isNumber8n2:
    add dl,48
    mov ah, 2
    int 21h

    mov dl, num8
    and dl, 0fh
    cmp dl, 0ah
    jl isNumber8n1
    add dl, 07h
    isNumber8n1:
    add dl,48
    mov ah, 2
    int 21h

    pop dx
    pop cx
    ret
outputNum8 endp

end
