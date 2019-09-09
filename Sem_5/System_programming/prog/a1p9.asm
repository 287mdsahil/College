.model small
.stack 100h

.data
inputPrompt DB 10,'Continue?(y):$'

.code
mov ax,@data
mov ds,ax
call main
mov ah, 4ch
int 21h

main proc
    continue:
    lea dx,inputPrompt
    mov ah,9
    int 21h
    mov ah,1
    int 21h
    cmp al,121
    je continue
    ret
main endp

end