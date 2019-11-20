.model small
.stack 100
.data
    res db 3 dup(0)
    msg db "Primes(1-100):",13,10,"$"
.code
main proc
mov ax,@data
mov ds,ax

lea dx,msg
mov ah,9
int 21H

mov dl,1
mov cx,25
l1:
       mov bl, 02
       add dl, 01h

       cmp dl, 02h
       je print
       cmp dl, 03h
       je print
       cmp dl, 04h
       jge Logic

    logic:
          mov ah, 00
          mov al, dl
          div bl
          cmp ah, 00
      je L1
          add bl, 01h
          cmp bl, al  
          jle Logic
      jmp print

    print:
       mov al, dl
       mov ah,00
       call output
       loop l1

    exit:
       mov ah, 4ch
       int 21h
    ret
main endp
        
output proc                  ;data in ax
    push ax
    push bx
    push cx
    push dx
    MOV CX,0
    MOV BX,10
    MOV SI,OFFSET RES
LOOP1: MOV DX,0
       DIV BX
       ADD DL,30H
       PUSH DX
       INC CX
       CMP AX,9
       JG LOOP1
     
       ADD AL,30H
       MOV [SI],AL
     
LOOP2: POP AX
       INC SI
       MOV [SI],AL
       LOOP LOOP2    

    MOV DL,res[0]
    MOV AH,2
    INT 21h

    MOV DL,res[1]
    INT 21h

    MOV DL,32
    INT 21H

    pop dx 
    pop cx
    pop bx
    pop ax
    ret
output endp
end main
