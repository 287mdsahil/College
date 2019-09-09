.model small
.stack 100h

.data
num1 DB ?
num2 DB ?
num DB ?
inputPrompt DB 13,10,"Enter number: $"
greaterPrompt DB " is greater than $"
lesserPrompt DB " is lesser than $"
equalPrompt DB " is equal to $"

.code
mov ax,@data
mov ds,ax
call main
mov ah,4ch
int 21h


;main function
main proc

    lea dx, inputPrompt
    mov ah,9
    int 21h

    call getNum
    mov num1,al

    lea dx, inputPrompt
    mov ah,9
    int 21h

    call getNum
    mov num2,al

    mov ch,num1
    mov cl,num2
    cmp ch,cl
    jg greater
    ;je equal
    ;jl lesser

    greater:
    mov num,cl
    call outputNum
    lea dx,greaterPrompt
    mov ah, 9
    int 21h
    mov num,ch
    call outputNum



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

; program to output a number stored in num
outputNum proc
    push cx
    push dx

    mov cl, 4
    mov dl, num
    shr dl,cl
    and dl, 15
    add dl,48
    cmp dl,58
    jl isNumber2
    add dl,7
    isNumber2:
    mov ah, 2
    int 21h

    mov dl, num
    and dl, 15
    add dl, 48
    cmp dl, 58
    jl isNumber1
    add dl, 7
    isNumber1:
    mov ah, 2
    int 21h

    pop dx
    pop cx
    ret
outputNum endp

end