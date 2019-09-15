;program to print pair of even numbers whose sum is 100
.model small
.stack 100h

.data
num DB ?

.code 
mov ax,@data
mov ds,ax
call main
mov ah,4ch
int 21h

main proc
    ;initialize al with 0
    mov bl,0
    mov bh,100
    
    loop1:

    ;output

    ;display opening braces
    mov dl,40
    mov ah,2
    int 21h

    ;display number 1
    mov num,bl
    call outputNum

    ;display coma
    mov dl,44
    mov ah,2
    int 21h

    ;display number 2
    mov num,bh
    call outputNum

    ;display closing braces
    mov dl,41
    mov ah,2
    int 21h

    ;display space
    mov dl,32
    mov ah,2
    int 21h

    ;increment al
    inc bl
    inc bl

    ;compare al with 51
    cmp bl,50
    jle loop1
    ret
main endp

; program to output a number stored in num
outputNum proc
    push cx
    push dx
    push ax

    mov cl, 4
    mov dl, num
    shr dl,cl
    and dl, 0fh
    cmp dl,0ah
    jl isNumber2
    add dl,7
    isNumber2:
    add dl,48
    mov ah, 2
    int 21h

    mov dl, num
    and dl, 0fh
    cmp dl, 0ah
    jl isNumber1
    add dl, 07h
    isNumber1:
    add dl,48
    mov ah, 2
    int 21h

    pop ax
    pop dx
    pop cx
    ret
outputNum endp

end