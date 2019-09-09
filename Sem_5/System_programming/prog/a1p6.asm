.model small
.stack 100h

.data
inputPrompt DB 'Enter a character :$'
ouputPrompt DB 13,10,'The character entered is :$'

.code
mov ax,@data
mov ds,ax
call main
mov ah, 4ch
int 21h

main proc
    lea dx,inputPrompt
    mov ah,9
    int 21h

    mov ah,1
    int 21h

    lea dx,ouputPrompt
    mov ah,9
    int 21h

    mov dl,al
    mov ah,2
    int 21h

    ret
main endp

end