;masm code to convert binary to decimal and vice versa
.model small
.stack 100h

.data
menuPrompt DB "Menu:",13,10,"1.Decimal to binary",13,10,"2.Binary to decimal",13,10,"Enter choice: $"

.code
mov ax,@data
mov ds,ax
call main
mov ah,4ch
int 21h


main proc

    ;displaying menu
    lea dx,menuPrompt
    mov ah,9
    int 21h

    call getChar
    cmp al,49 ;compare with 1
    je dec2binary
    cmp al,50 ;compare with 2
    je binary2dec
    jmp done
    dec2binary:
    ;call d2b
    jmp done
    binary2dec:
    ;call b2d
    jmp done
    done:


    ret
main endp

getChar proc
    mov ah,1
    int 21h
    ret
getChar endp

end