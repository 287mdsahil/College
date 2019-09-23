.model small
.stack 10
.data
	Date db "Date:",32,"$"
	Time db "Time:",32,"$"
.code
main proc
	mov ax,@data
	mov ds,ax
	
	lea dx,Date
	mov ah,9
	int 21h
	
	call get_date
	
	mov al,dl
	aam
	mov bx,ax
	call display
	mov dl,'-'
	int 21h

	
	call get_date
	
	mov al,dh
	aam
	mov bx,ax
	call display
	mov dl,'-'
	int 21h

	call get_date
	
	add cx,0F830H
	mov ax,cx
	aam
	mov bx,ax
	call display

	mov dl,10
	int 21h

	lea dx,Time
	mov ah,9
	int 21h

	call get_time
	
	mov al,ch
	aam
	mov bx,ax
	call display
	mov dl,':'
	int 21h

	
	call get_time
	
	mov al,cl
	aam
	mov bx,ax
	call display
	mov dl,':'
	int 21h

	call get_time
	
	mov al,dh
	aam
	mov bx,ax
	call display

	mov ah,4ch
	int 21h
	
ret
main endp

display proc
	mov ah,2
	mov dl,bh
	add dl,30h
	int 21h

	mov dl,bl
	add dl,30h
	int 21h
ret
display endp
get_date proc
	mov ah,2ah
	int 21h
ret
get_date endp

get_time proc
	mov ah,2ch
	int 21h
ret
get_time endp
end main
