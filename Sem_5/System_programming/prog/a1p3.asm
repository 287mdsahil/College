.model small
.stack 100h

.data
linefeed    db 13, 10, "$"
prompt1     db "Number 1: $"
prompt2     db "Number 2: $"
resultMsg   db "Result: $"
num1        db 00h, "$"
num2        db 00h, "$"

.code
call main
mov ax, 4c00h
int 21h

main proc
    mov ax, @data
    mov ds, ax

    ;displaying first prompt
    lea dx, prompt1
    mov ah, 9
    int 21h
    call getNum
    mov num1, al

    ;displaying second prompt
    lea dx, prompt2
    mov ah,9
    int 21h
    call getNum
    mov num2,al

    ;addition
    mov dl,num1
    add dl,num2
    mov dh, 0
    jnc nocarry
    inc dh
    nocarry:
    
    mov bx,dx

    ;showing result message
    mov dx, offset resultMsg
    mov ah,9
    int 21h

    mov dx, bx
    mov ah, 9
    int 21h


    ret
main endp


;function to take number input
getNum proc
    push cx
    push dx

    mov dl, 00
    mov cl, 04
    shl dl, cl

    getNumber:
    call getChar
    cmp al, 72
    je inputDone

    sub al, 48;
    jle isNumber
    sub al, 7

    isNumber:
    add dl, al
    jmp getNumber

    inputDone:
    mov al, dl
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

end


