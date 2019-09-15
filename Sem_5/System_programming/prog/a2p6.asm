;masm program to print the first 10 number of the fibonacci series

.model small
.stack 100h

.data
num DW ?
num1 DW 0
num2 DW 1

.code
mov ax,@data
mov ds,ax
call main
mov ah,4ch
int 21h


main proc

    ;priting the first two numbers of the series
    mov ax,num1
    mov num,ax
    call outputNum
    mov dl,32
    mov ah,2
    int 21h
    mov ax,num2
    mov num,ax
    call outputNum

    ;printing the rest 8 elements
    mov bl,2
    loop1:

    mov dx, num2
    mov ax, num1
    add ax, num2
    mov num2, ax
    mov num1, dx

    mov dl,32
    mov ah,2
    int 21h

    mov ax,num2
    mov num,ax
    call outputNum

    inc bl
    cmp bl,10
    jle loop1


    ret
main endp


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