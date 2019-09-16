;masm code to convert binary to decimal and vice versa
.model small
.stack 100h

.data
menuPrompt DB 10,10,13,"Menu:",13,10,"1.Decimal to binary",13,10,"2.Binary to decimal",13,10,"Enter choice: $"
prompt_2 DB 10,13,'Enter the Binary Number : $'
prompt_3 DB 10,13,'Enter the Decimal Number : $'
prompt_4 DB 13,'The converted Binary Number is : $'
prompt_5 DB 13,'The converted Decimal Number is : $'

display macro msg
    mov ah,9
    lea dx,msg
    int 21h
endm

ch_input macro 
    mov ah,1
    int 21h
endm

.code
mov ax,@data
mov ds,ax
call main
mov ah,4ch
int 21h


main proc

    @start:

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




    binary2dec:
    display prompt_2
    call bin_input
    display prompt_5
    call dec_output
    jmp @start

    dec2binary:
    display prompt_3
    call dec_input
    display prompt_4
    call bin_output
    jmp @start

    done:


    ret
main endp

getChar proc
    mov ah,1
    int 21h
    ret
getChar endp


    ;binary input
	bin_input proc
		xor bx,bx
		xor cx,cx

		@binput:
		mov ah,1
		int 21h

		cmp al,13
		je @bend

		sub ax,30h
		shl bx,1
		or bl,al
		jmp @binput

		@bend:
		ret
	bin_input endp

    ;binary output
	bin_output proc
		mov ax, bx                     	; set ax=bx
		xor cx, cx                     	; clear cx
		mov bx, 2                     	; set bx=2

	   	@brepeat:                       	; loop label
		xor dx, dx                   	; clear dx
		div bx                       	; divide ax by bx
		push dx                      	; push dx onto the stack
		inc cx                       	; increment cx
		or ax, ax                    	; take or of ax with ax
	   	jne @brepeat                    	; jump to label @repeat if zf=0

	   	mov ah, 2                      	; set output function

	   	@bdisplay:                      	; loop label
		pop dx                       	; pop a value from stack to dx
		or dl, 30h                   	; convert decimal to ascii code
		int 21h                      	; print a character
	   	loop @bdisplay                  	; jump to label @display if cx!=0

	   	ret      
	bin_output endp

    ;decimal input
    dec_input proc

		@dread:                         	; jump label
		xor bx, bx                     	; clear bx
		xor cx, cx                     	; clear cx

		mov ah,1
		int 21h                        	; read a character
		cmp al, 0dh                    	; compare al with cr
		je @dend                        	; jump to label @end if al=cr

	   	@dinput:                        	; jump label
		and ax, 000fh                	; convert ascii to decimal code

		push ax                      	; push ax onto the stack

		mov ax, 10                   	; set ax=10
		mul bx                       	; set ax=ax*bx
		mov bx, ax                   	; set bx=ax

		pop ax                       	; pop a value from stack into ax

		add bx, ax                   	; set bx=ax+bx

		mov ah, 1                    	; set input function
		int 21h                      	; read a character

		cmp al, 0dh                  	; compare al with cr
		jne @dinput                   	; jump to label if al!=cr
	                                   

		@dend:                         ; jump label
		ret                            ; return control to the calling procedure
	dec_input endp

    ;decimal output
	dec_output proc
		mov ax, bx                     	; set ax=bx
		xor cx, cx                     	; clear cx
		mov bx, 10                     	; set bx=10

	   	@drepeat:                       	; loop label
		xor dx, dx                   	; clear dx
		div bx                       	; divide ax by bx
		push dx                      	; push dx onto the stack
		inc cx                       	; increment cx
		or ax, ax                    	; take or of ax with ax
	   	jne @drepeat                    	; jump to label @repeat if zf=0

	   	mov ah, 2                      	; set output function

	   	@ddisplay:                      	; loop label
		pop dx                       	; pop a value from stack to dx
		or dl, 30h                   	; convert decimal to ascii code
		int 21h                      	; print a character
	   	loop @ddisplay                  	; jump to label @display if cx!=0

	   	ret      
	dec_output endp

end