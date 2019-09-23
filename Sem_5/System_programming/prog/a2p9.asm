.model small
.stack 100
.data

    arr db 5 dup(0)
    msg db "Enter values:",13,10,"$"
    msg2 db "Key found at pos:",32,"$"
    msg3 db "Enter key to be searched:",10,"$" 
    msg4 db "Not Found!",13,10,"$"
    msg5 db "Enter Search Method",10,13,"1.Linear Search",10,13,"2.Binary Search",10,13,"$"
    msg6 db "Not Sorted!!",13,10,"$"
    key db ?
    true db 0
.code
    
    main proc
        mov ax, @data
        mov ds,ax
        xor bx,bx
        xor cx,cx

        lea dx,msg
        mov ah,9
        int 21h
        mov cl,5h

        mov si,offset arr
        @input2:
            call input    
            mov [si],dl
            inc si
            loop @input2
       
	lea dx,msg3
        mov ah,9
        int 21h
	call input
	mov key,bl
	
	lea dx,msg5
	mov ah,9
	int 21h
	
	mov ah,1
	int 21h
	
	cmp al,'1'
	jne bs
	call linearSearch
	jmp exitMain
bs:	call binarySearch
	jmp exitMain
exitMain:
	mov ah,4ch
        int 21h
ret
main endp

binarySearch proc
	
search:	mov bx,00
	mov dx,5
	mov cl,key
again: cmp bx,dx
       ja fail
       mov ax,bx
       add ax,dx
       shr ax,1
       mov si,ax
       ;add si,si
       cmp cl,arr[si]
       jae big
       dec ax
       mov dx,ax
       jmp again
big:   je success
       inc ax
       mov bx,ax
       jmp again
success: 
	add al,01
       	mov bl,al
	mov bh,0
        lea dx,msg2
        mov ah,9
	int 21h	
	call output
	jmp exitFunc
fail: 	lea dx,msg4
	mov ah,9
	int 21h
	
exitFunc:
	ret
binarySearch endp

linearSearch proc
	mov si,offset arr
	mov cl,5h
	mov dl,key
	d_loop:
	    cmp dl,[si]
	    je found
	    inc si
	    dec cl
	    cmp cl,0
	    jg d_loop
	    jmp not_found

found:  mov bx,si
	mov si,offset arr
	sub bx,si
	inc bx  
	lea dx,msg2
        mov ah,9
        int 21h
	call output
	jmp exitProc

not_found:       
	lea dx,msg4
        mov ah,9
        int 21h
exitProc:
ret
linearSearch endp
output proc                  ;data in bl
    xor dx,dx
    push cx
    mov ah,2
    mov dl,bl
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

    mov dl,bl
    and dl,0fh
    cmp dl,9
    jle @print_letter1
    add dl,7h

    @print_letter1:
    add dl,30h
    int 21h  
    mov dl,10
    int 21h
    pop cx    
    ret
output endp

input proc                     ; final data in bx and dx
    push cx
    xor bx,bx
    xor cx,cx
    xor dx,dx
    mov cl,4

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
        shl bl,cl
        add bl,al
        int 21h
        jmp @input1

    line:
        mov dx,bx
        pop cx
    ret
input endp
end main
