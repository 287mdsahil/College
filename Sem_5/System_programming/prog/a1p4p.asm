.model small
.stack 100
.data

    arr db 10 dup(0)
    msg db "Enter values:",13,10,"$"
    msg2 db "Entered values are:",13,10,"$"
    msg3 db "Second Maximum value is:",10,"$" 
    msg4 db "Second Minimum is:",13,10,"$"
    smin db 255
    smax db 0
.code
    
    main proc
        mov ax, @data
        mov ds,ax
        xor bx,bx
        xor cx,cx

        lea dx,msg
        mov ah,9
        int 21h
        mov cl,0ah

        mov si,offset arr
        @input2:
            call input    
            mov [si],dl
            inc si
            loop @input2
       
        call findMinMax

        lea dx,msg3
        mov ah,9
        int 21h

        mov bl,smax
        call output

        lea dx,msg4
        mov ah,9
        int 21h

        mov bl,smin
        call output

        mov ah,4ch
        int 21h
    ret
    main endp

findMinMax proc
    xor cx,cx
    mov cl,0ah
    mov bl,arr[0]
    mov bh,arr[0]
    mov smin,bl
    mov smax,bh
    mov si,offset arr
    loop1:
        cmp bl,[si]
        jle lab
        mov smin,bl
        mov bl,[si]
        jmp sminl
    lab:
        mov al,smin
        cmp al,bl
        je tab2
        cmp al,[si]
        jle sminl
       tab2: mov al,[si]
        mov smin,al
    sminl:
        cmp bh,[si]
        jge lab2
        mov smax,bh
        mov bh,[si]
        jmp smaxl
    lab2:
        mov al,smax
        cmp al,bh
        je tab3
        cmp al,[si]
        jge smaxl
        tab3: mov al,[si]
        mov smax,al
    smaxl:
        inc si
        loop loop1
    cmp smax,bh
    jl tab
    mov smax,bh
    tab:
        cmp smin,bl
        jg exit
        mov smin,bl
    exit:
    ret
findMinMax endp

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