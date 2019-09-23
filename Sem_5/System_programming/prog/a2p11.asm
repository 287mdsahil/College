.model small
.stack 100
.data
linefeed    db 13, 10, "$"
prompt1     db "Enter Len: $"
prompt2     db "Enter Num: $"
msg1        db "Array is: $"
msg2        db "Selection Sort:$"
msg3        db "Insertion Sort:$"
len         db ?
nums        db 10 DUP(?), "$"
dec_out     db 2 DUP(?), "$"

.code 	                    ; code segment
call main
mov  ax, 4c00h              ; terminate properly
int  21h  

main proc
    mov ax, @data
    mov ds, ax
    
    mov dx, offset prompt1
    call show_msg
    call get_arr_inp
    call ins_linefeed
    
    call selection_sort
    
    mov dx, offset msg2
    call show_msg
    call ins_linefeed
    call disp_arr_output
    call ins_linefeed
    call ins_linefeed
    
    mov dx, offset prompt1
    call show_msg
    call get_arr_inp
    call ins_linefeed
    
    call insertion_sort
    mov dx, offset msg3
    call show_msg
    call ins_linefeed
    call disp_arr_output
    call ins_linefeed
    
    ret
main endp

; insertion sort 
insertion_sort proc
    push ax
    push bx
    push cx
    push dx
    
    mov cl, 1
    mov bx, offset nums
    
ins_outer:
    mov ch, 0
    mov di, cx
    mov dl, nums[di]
    mov si, di
    dec si

ins_inner:    
    cmp si, 0
    jl ins_outer_update
    
    cmp nums[si], dl
    jbe ins_outer_update

    mov ch, nums[si]
    mov nums[di], ch
    dec di
    dec si
    jmp ins_inner

    
ins_outer_update:
    mov nums[si+1], dl
    inc cl
    cmp cl, len
    jl ins_outer
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
insertion_sort endp

; selection sort 
selection_sort proc
    push ax
    push bx
    push cx
    push dx
    
    mov cl, len
    mov bx, offset nums
sel_outer:
    ; call disp_arr_output
    ; call ins_linefeed
    
    mov ch, 0
    inc ch
    mov dh, cl
    mov dl, [bx]
sel_inner:
    push cx
    xchg cl, ch
    mov ch, 0
    add bx, cx
    mov al, [bx]
    cmp dl, al
    jbe sel_inner_upd
    mov dl, al
    mov dh, cl
    
sel_inner_upd:
    sub bx, cx
    pop cx
    inc ch
    cmp ch, cl
    jl sel_inner

sel_done_inner:
    mov ah, [bx]
    push bx
    add bl, dh
    adc bh, 0
    mov [bx], ah
    pop bx
    
    mov [bx], dl

    inc bx
    dec cl
    cmp cl, 1
    jg sel_outer
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
selection_sort endp

; get array as input
get_arr_inp proc
    push ax
    push bx
    push cx
    push dx
    
    
    call get_dec_val
    mov len, al
    
    call ins_linefeed
    
    mov cx, 0
get_arr_elems_loop:
    mov bx, offset nums
    add bx, cx
    
    mov dx, offset prompt2
    call show_msg
    call get_dec_val
    mov [bx], al
    
    inc cl
    cmp cl, len
    jl get_arr_elems_loop
    
done_get_arr_elems:
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
get_arr_inp endp

disp_arr_output proc
    push ax
    push bx
    push cx
    push dx
    
    mov cl, 0
    mov bx, offset nums
disp_arr_output_loop:
    mov al, [bx]
    mov ah, 0
    
    call disp_dec_val
    mov al, 32
    call show_char
    
    inc bx
    inc cl
    cmp cl, len
    jl disp_arr_output_loop

    pop dx
    pop cx
    pop bx
    pop ax
    ret
disp_arr_output endp

; get decimal value, store in ax
get_dec_val proc
    push bx
    push cx
    push dx
    
    mov dx, 0
get_characters:
    call get_char
    cmp al, 13 ; cmp w/ [enter]
    je done
    
    sub al, 48
    
    mov bx, dx
    mov cl, 3
    shl bx, cl
    shl dx, 1
    add dx, bx
    add dl, al
    jnc get_characters
    add dh, 1
    jmp get_characters
    
done:
    mov ax, dx
    
    pop dx
    pop cx
    pop bx
    ret
get_dec_val endp

; display ax value in decimal
disp_dec_val proc
    push ax
    push bx
    push cx
    push dx

    mov cl, 2
disp_dec_val_loop:
    dec cl
    cmp cl, 0
    jl disp_dec_val_loop_done
    mov bx, offset dec_out
    push cx
    mov ch, 0
    add bx, cx
    pop cx
    
    mov ch, 10
    div ch
    push ax
    add ah, 48
    mov [bx], ah
    pop ax
    
    mov ah, 0
    jmp disp_dec_val_loop

disp_dec_val_loop_done:
    mov dx, offset dec_out
    call show_msg

    pop dx
    pop cx
    pop bx
    pop ax
    ret
disp_dec_val endp

; show character, ascii value in al
show_char proc
    push ax
    push dx
    
    mov dl, al
    mov ah, 2
    int 21h
    
    pop dx
    pop ax
    ret
show_char endp

; show message, location in dx
show_msg proc
    push ax
    mov ah, 9
    int 21h
    pop ax
    ret
show_msg endp

; get a single character, modify ah, store in al
get_char proc
    mov ah, 1
    int 21h
    ret
get_char endp

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
