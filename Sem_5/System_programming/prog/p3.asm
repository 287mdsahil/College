.model tiny
.stack 100
.data
linefeed    db 13, 10, "$"
prompt1     db "Num 1: $"
prompt2     db "Num 2: $"
msg1        db "Sum: $"  
num1        db 00h, "$"
num2        db 00h, "$"
hex_out     db 0, 0, 0, "H$"

.code 	                    ; code segment
call main
mov  ax, 4c00h              ; terminate properly
int  21h  

main proc
    mov ax,@data
    mov ds,ax
    
    ; get first number
    lea dx, prompt1
    call show_msg
    call get_num
    mov num1, al
    call ins_linefeed
    
    ; get second number
    lea dx, prompt2
    call show_msg
    call get_num
    mov num2, al
    call ins_linefeed
    
    ; perform addition
    mov dl,num1
    add dl,num2
    mov dh,0
    jnc nocarry
    inc dh

nocarry:
    mov bx, dx
    mov dx, offset msg1
    call show_msg
    
    ; display in hex form
    mov dx, bx
    call print_hex
    
    ret   
main endp

; display decimal value of dx reg in hex form; does not modify any reg
print_hex proc
    push ax
    push bx
    push cx
    push dx
    
    mov cx,3
c_loop:
    dec cx
    mov ax, dx
    
    shr dx,1
    shr dx,1
    shr dx,1
    shr dx,1
    
    and ax,0fh
    
    mov bx, offset hex_out
    add bx,cx
    
    cmp ax,0ah
    jl set_digit
    add al,07h

set_digit:
    add al,30h
    mov [bx],al
    
    cmp cx,0
    jne c_loop
    
    lea dx,hex_out
    mov ah,9
    int 21h
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
print_hex endp

; get 8-bit hex number in decimal form, modify ax, store in al
get_num proc
    push cx
    push dx

    mov dl, 00
get_characters:
    call get_char
    cmp al, 72 ; cmp w/ H
    je done
    
    mov cl, 4
    shl dl, cl
    
    sub al, 48 ; 48 = ascii of '0'
    cmp al, 9
    jle is_number
    sub al, 7
    
is_number:
    add dl, al
    jmp get_characters
    
done:
    mov al, dl
    pop dx
    pop cx
    ret
get_num endp

; get a single character, modify ah, store in al
get_char proc
    mov ah, 1
    int 21h
    ret
get_char endp

; show message, location in dx
show_msg proc
    push ax
    mov ah, 9
    int 21h
    pop ax
    ret
show_msg endp

; insert new-line, modify ax
ins_linefeed proc
    push dx
    lea dx,linefeed
    mov ah,9
    int 21h
    pop dx
    ret
ins_linefeed endp

end