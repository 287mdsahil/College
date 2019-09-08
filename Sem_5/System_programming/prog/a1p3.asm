.model small
.stack 100h

.data
linefeed    db 13, 10, "$"
prompt1     db "Number 1: $"
prompt2     db "Number 2: $"
resultMsg   db "Result: $"
num1        db 00h, "$"
num2        db 00h, "$"
result      dw ?, "$"

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
    call hexAddition16Bit

    ;showing result prompt
    lea dx, resultMsg
    mov ah,9
    int 21h
    
    ;showing result
    call showResult

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
    cmp al, 13
    je inputDone
    cmp al, 10
    je inputDone

    sub al, 48;
    cmp al, 9
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

;function to display result
showResult proc
    push cx
    push dx

    mov cx, result

    add cl,48
    cmp cl, 58
    jl isNumber1
    add cl, 7
    isNumber1:

    add ch,48
    cmp ch, 58
    jl isNumber2
    add ch, 7
    isNumber2:

    mov dl,ch
    mov ah, 2
    int 21h

    mov dl,cl
    mov ah, 2
    int 21h

    pop cx
    pop dx
    ret
showResult endp

;function to perform 8 bit hexadecimal addition
hexAddition16Bit proc
    push cx
    push dx

    mov cl,num1
    add cl,num2
    mov ch,00

    cmp cl,16
    jl noCarry
    sub cl,16
    mov ch,1
    noCarry:

    mov result, cx

    pop dx
    pop cx
    ret
hexAddition16Bit endp

end


