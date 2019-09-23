.model small
.stack 100h
.data
linefeed    db 13, 10, "$"
num1        db 64 DUP(0), "$"
num2        db 64 DUP(0), "$"
result      db 64 DUP(0), "$"
len         db 32
prompt1     db "Enter multiplicand: $"
prompt2     db "Enter multiplier: $"
prompt3     db "Enter length: $"
prompt4     db "Enter binary num: $"
msg1        db "Product: $"
bin_out     dw ?

.code
call main
mov ax, 4c00h
int 21h

main proc
    mov ax, @data
    mov ds, ax
    mov es, ax

    mov ax, offset num1
    mov bin_out, ax
    call inp_binary_num
    call ins_linefeed
    
    mov ax, offset num2
    mov bin_out, ax
    call inp_binary_num
    call ins_linefeed
    
    call ins_linefeed
    
    call multiply_nums
    
    mov dx, offset msg1
    call show_msg
    call disp_binary_result
main endp

; multiply num1 and num2, store in result
multiply_nums proc
    push ax
    push bx
    push cx
    push dx

    mov cl, len
    
mul_loop_outer:
    dec cl
    cmp cl, 0
    jl done
    
    mov ah, 0
    mov al, len
    add al, cl
    adc ah, 0
    mov di, offset num1
    add di, ax
    cmp byte ptr [di], 1
    jne mul_loop_outer
    
    mov di, offset result
    add di, ax
    mov ah, 0
    mov al, len
    shl ax, 1
    dec ax
    mov si, offset num2
    add si, ax
    
    mov ch, len
    mov dl, 0

mul_loop_inner:
    dec ch
    cmp ch, 0
    jl done_inner
    
    mov al, [si]
    add al, [di]
    add al, dl
    mov dl, al
    and al, 1
    shr dl, 1
    mov [di], al
    dec si
    dec di
    jmp mul_loop_inner
    
done_inner:
    cmp dl, 0
    jle mul_loop_outer
    mov [di], dl
    jmp mul_loop_outer
    
done:
    pop dx
    pop cx
    pop bx
    pop ax
    ret
multiply_nums endp

; accept binary number as input, output loc in bin_out
inp_binary_num proc
    push ax
    push bx
    push cx
    push dx
    
    mov dx, offset prompt3
    call show_msg
    
    mov bx, 0
inp_len_loop:
    call get_char
    cmp al, 13
    je get_binary_num
    
    sub al, 48
    mov ch, al
    mov ax, bx
    mov cl, 10
    mul cl
    add al, ch
    mov bx, ax
    
    jmp inp_len_loop
    
get_binary_num:
    
    mov dx, offset prompt4
    call show_msg
    
    mov dl, bl
    
    mov ch, 0
    mov cl, len
    mov bx, bin_out
    shl cx, 1
    add bx, cx
    ; dec bx
    mov dh, 0
    sub bx, dx
inp_bin_loop:
    call get_char
    sub al, 48
    mov [bx], al
    
    inc bx
    dec dl
    jnz inp_bin_loop
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
inp_binary_num endp

; display value of result
disp_binary_result proc
    push ax
    push bx
    push cx
    push dx

    mov ch, 00
    mov cl, len
    shl cx, 1
    mov di, 0
    
disp_res_loop:
    mov dl, result[di]
    add dl, 48
    mov ah, 2
    int 21h
    
    inc di
    cmp di, cx
    jl disp_res_loop
    
done_disp:
    pop dx
    pop cx
    pop bx
    pop ax
    ret
disp_binary_result endp

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

; insert new-line
ins_linefeed proc
    push ax
    push dx
    lea dx,linefeed
    mov ah,9
    int 21h
    pop dx
    pop ax
    ret
ins_linefeed endp
   
end