.model small
.stack 100h


.code
mov ax,@data
mov ds,ax
call main
mov ah, 4ch
int 21h

main proc
    mov cl,64
    continue:
    inc cl

    mov dl,cl
    mov ah,2
    int 21h

    mov dl,32
    mov ah,2
    int 21h

    cmp cl,90
    jne continue
    ret
main endp

end