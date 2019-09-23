.model small
.stack 10
.data
	Subs db 50 dup(0)
	str db 50 dup(0)
	FinalString db 50 dup(0)
	msg1 db "Enter String:",32,"$"
	msg2 db "Enter substring to remove:",32,"$"
	msg3 db "Substring Not Found!",10,13,"$"
	msg4 db "String After Deletion:",32,"$"
	lenStr dw 0
	lenSubs dw 0
.code

main proc
	mov ax,@data
	mov ds,ax
	
	lea dx,msg1
	mov ah,9
	int 21h

	mov si,offset str
	call input
	mov ch,0
	mov lenStr,cx
	

	lea dx,msg2
	mov ah,9
	int 21h

	mov si,offset Subs
	call input
	mov ch,0
	mov lenSubs,cx
	
	call deleteSubs

	mov ah,4ch
	int 21h
ret
main endp

deleteSubs proc
	mov ax,lenStr
	cmp ax,lenSubs
	jge lab

	jmp exitProc

lab:	cmp lenStr,0
	je exitProc1
	lea si,str
	lea di,Subs
	mov bx,si
	;mov cx,0
	
checkStr:
	;mov dx,0
	mov al,[di]
	cmp al,[si]
	je equalChar
	inc si
	mov bx,si
	;inc cx
	cmp word ptr [si],'$'
	jne checkStr
	jmp exitProc

	equalChar:
		inc di
		inc si
		;inc cx
		;inc dx
		cmp word ptr [di],'$'
		je exitProc1
		cmp word ptr [si],'$'
		je exitProc	
		mov al,[di]
		cmp al,[si]
		je equalChar
		inc bx
		mov si,bx
		;mov cx,bx;cx=(bx-offset)
		;sub cx,offset str
		lea di,Subs
		jmp checkStr
exitProc1:
	lea dx,msg4
	mov ah,9
	int 21h
	
	mov ah,2
	lea si,str
	lea di,Subs
store:	cmp si,bx
	jne store2
no_char: inc si
	inc di
	cmp word ptr [di],'$'
	jne no_char
store2:	cmp word ptr [si],'$'
	je exitLab
	mov dl,[si]
	int 21h
	inc si
	jmp store
	jmp exitLab
exitProc:
	lea dx,msg3
	mov ah,9
	int 21h
exitLab:
	mov ah,2
	mov dl,10
	int 21h
ret
deleteSubs endp

input proc

mov ah,1
int 21h
mov cl,0

inputStr:
	cmp al,13
	je exit
	mov [si],al
	inc cl
	inc si
	int 21h
	jmp inputStr
exit:
	mov word ptr [si],'$'
	mov ah,2
	mov dl,10
	int 21h
ret
input endp
end main
