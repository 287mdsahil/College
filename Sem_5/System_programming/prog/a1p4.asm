.model small
.stack 100h

.data
arr DB 1, 2, 3, 4, 5
arrsize DW 5
smallest DB ?
smallest2 DB ?
greatest DB ?
greatest2 DB ?
num DB ?
smallest2Prompt DB 13,10,"2nd smallest number: $"
greatest2Prompt DB 13,10,"2nd greatest number: $"


.code
mov ax, @data
mov ds, ax
call main
mov ah, 4ch
int 21h

;main function
main proc

    ;taking input
    mov bx, 00
    inputLoop:
    call getNum
    mov arr[bx],al
    inc bx
    cmp bx, arrsize
    jne inputLoop

    ;finding smallest element
    mov bx,00        ;bx is counter
    mov dl,arr[0]   ;initializing dl with a[0]
    ;looping through the array to find the smallest element
    loop1:
    inc bx          ;increment counter
    cmp dl,arr[bx]
    jl greater
    mov dl,arr[bx]
    greater:
    cmp bx,arrsize
    jl loop1
    mov smallest,dl

    ;finding largest element
    mov bx,00       ;bx is counter
    mov dl,arr[0]   ;initializing dl with a[0]
    ;looping through the array to find the largest element
    loop2:
    inc bx          ;increment counter
    cmp dl,arr[bx]
    jg lesser
    mov dl,arr[bx]
    lesser:
    cmp bx,arrsize
    jl loop2
    mov greatest,dl

    ;finding 2nd smallest element
    mov bx,00       ;bx is counter
    mov dl,greatest   ;initializing dl with a[0]
    mov dh,smallest    ;storing the value of the smallest 
    ;looping through the array to find the largest element
    loop3:
    inc bx          ;increment counter
    cmp dh, arr[bx]
    je lesser2
    cmp dl,arr[bx]
    jl lesser2
    mov dl,arr[bx]
    lesser2:
    cmp bx,arrsize
    jl loop3
    mov smallest2,dl

    ;finding 2nd largest element
    mov bx,00       ;bx is counter
    mov dl,smallest   ;initializing dl with a[0]
    mov dh,greatest    ;storing the value of the smallest 
    ;looping through the array to find the largest element
    loop4:
    inc bx          ;increment counter
    cmp dh, arr[bx]
    je greater2
    cmp dl,arr[bx]
    jg greater2
    mov dl,arr[bx]
    greater2:
    cmp bx,arrsize
    jl loop4
    mov greatest2,dl

    ;displaying the results

    lea dx,smallest2Prompt
    mov ah,9
    int 21h

    mov dl,smallest2
    mov num,dl
    call outputNum

    lea dx,greatest2Prompt
    mov ah,9
    int 21h

    mov dl,greatest2
    mov num,dl
    call outputNum



    ret
main endp

; program to output a number stored in num
outputNum proc
    push cx
    push dx

    mov cl, 4
    mov dl, num
    shr dl,cl
    and dl, 15
    add dl,48
    cmp dl,58
    jl isNumber2
    add dl,7
    isNumber2:
    mov ah, 2
    int 21h

    mov dl, num
    and dl, 15
    add dl, 48
    cmp dl, 58
    jl isNumber1
    add dl, 7
    isNumber1:
    mov ah, 2
    int 21h

    pop dx
    pop cx
    ret
outputNum endp

;function to take number input
getNum proc
    push cx
    push dx

    mov dl, 00
    mov cl, 04
    shl dl, cl

    getNumber:
    call getChar
    cmp al, 13
    je inputDone
    cmp al, 10
    je inputDone

    sub al, 48;
    cmp al, 9
    jle isNumber
    sub al, 7

    isNumber:
    add dl, al
    jmp getNumber

    inputDone:
    mov al, dl
    pop dx
    pop cx
    ret
getNum endp


;fucntion to take in character
getChar proc
    mov ah,1
    int 21h
    ret
getChar endp

end
