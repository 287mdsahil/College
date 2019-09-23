.model small
.stack 10
.data
	file db 25 dup(?)
	newFile db 25 dup(?)
	msg1 db "Enter FileName:",32,"$"
	msg2 db "Enter New FileName:",32,"$"
	errorMsg db "File doesn't exist!!",10,13,"$"
	DoneMsg db "Renamed Succesfully!!",10,13,"$"
.code
main proc
	mov ax,@data
	mov ds,ax

	lea dx,msg1
	mov ah,9
	int 21h

	lea si, file
	call input

	lea dx,msg2
	mov ah,9
	int 21h

	mov si,offset newFile
	call input

	mov ax,seg file
	mov ds,ax
	mov es,ax
	mov ah,56h
	lea dx,file
	lea di,newFile
	int 21h
	jnc done

	lea dx,errorMsg
	mov ah,9
	int 21h
	jmp exit

done:	lea dx,DoneMsg
	mov ah,9
	int 21h

exit:	mov ah,4ch
	int 21h

ret
main endp

input proc

mov ah,1
int 21h
mov cl,0

inputStr:
	cmp al,13
	je exitX
	mov [si],al
	inc cl
	inc si
	int 21h
	jmp inputStr
exitX:
	mov word ptr [si],'$'
	mov ah,2
	mov dl,10
	int 21h
ret
input endp

end main
