.model small
.stack 10h
.data
	var1 dw 0
	var2 dw 0
	var3 dw 0
	res dw 0
	msg db "GCD:",32,"$"
	msg2 db "LCM:",32,"$"
	prompt db "Enter 3 numbers(HEX):",10,13,"$"
.code
main proc
	mov ax,@data
	mov ds,ax
	
	lea dx,prompt
	mov ah,9
	int 21h
	call input
	mov var1,bx

	call input
	mov var2,bx

	call input
	mov var3,bx

	mov dx,0000h
	mov ax,var1
	mov bx,var2
	cmp ax,bx
	jnc gcdLab
	xchg ax,bx

gcdLab:	call gcd
	xor ax,ax
	xor bx,bx
	xor dx,dx
	mov ax,cx
	mov bx,var3
	cmp ax,bx
	jnc gcdLab2
	xchg ax,bx
gcdLab2:	call gcd
	mov bx,cx
	
	lea dx,msg
	mov ah,9
	int 21h

	call output
	
	call lcm

	lea dx,msg2
	mov ah,9
	int 21h

	mov bx,res
	call output
	mov ah,4ch
	int 21h
	
ret
main endp


lcm proc
	mov dx,var1
	mov bx,var2
	mov cx,var3
	cmp dx,bx
	jnc bigger
	xchg dx,bx
bigger: cmp bx,cx
	jnc biggest
	xchg bx,cx
biggest: mov var1,dx
	mov var2,bx
	mov var3,cx
	
lcmFind:
	mov ax,cx
	mov dx,0000h	
	div var1
	cmp dx,0000h	
	jne again
	mov ax,cx
	mov dx,0000h
	div var2
	cmp dx,0000h
	jne again
	mov ax,cx
	mov dx,0000h
	div var3
	cmp dx,0000h
	jne again
	mov res,cx
	jmp exit3
again:	add cx,1
	jmp lcmFind
exit3:
mov res,cx
ret
lcm endp


gcd proc
loop1:	mov dx,0000h
	div bx
	cmp dx,0000h
	je found
	mov ax,bx
	mov bx,dx
	jmp loop1
found:	mov cx,bx
ret
gcd endp

input proc
    push cx
    xor bx,bx
    xor cx,cx
    xor dx,dx
    mov cl,1

    mov ah,1
    int 21h

    @input1:
        cmp al,0dh
        je line

        cmp al,39h
        jg @letter

        and al,0fh
        jmp @shift

    @letter:
        sub al,37h

    @shift:
        shl bh,1
        shl bh,1
        shl bh,1
        shl bh,1
        add bh,al
        int 21h

        inc cl
        cmp cl,2
        jle @input1
    mov cl,1
    @input2:
        cmp al,0dh
        je line

        cmp al,39h
        jg @letter2

        and al,0fh
        jmp @shift2

    @letter2:
        sub al,37h

    @shift2:
        shl bl,1
        shl bl,1
        shl bl,1
        shl bl,1
        add bl,al
        int 21h
        inc cl
        cmp cl,2
        jle @input2

    line:
        cmp bl,00
        jne exit
        mov bl,bh
        mov bh,0
    exit:  mov dx,bx
        pop cx
    ret
input endp

output proc                  ;data in bl
    xor dx,dx
    push cx
    mov ah,2
    mov dl,bh
    shr dl,1
    shr dl,1
    shr dl,1
    shr dl,1
    cmp dl,9
    jle @print_num
    add dl,7h

    @print_num:
    add dl,30h
    int 21h

    mov dl,bh
    and dl,0fh
    cmp dl,9
    jle @print_letter1
    add dl,7h

    @print_letter1:
    add dl,30h
    int 21h

    mov dl,bl
    shr dl,1
    shr dl,1
    shr dl,1
    shr dl,1
    cmp dl,9
    jle @print_num2
    add dl,7h

    @print_num2:
    add dl,30h
    int 21h

    mov dl,bl
    and dl,0fh
    cmp dl,9
    jle @print_letter2
    add dl,7h

    @print_letter2:
    add dl,30h
    int 21h

    mov dl,10
    int 21h
    pop cx    
    ret
output endp
end main
	
