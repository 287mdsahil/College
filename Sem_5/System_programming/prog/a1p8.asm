.model small
.stack 100h

.data
arr DB 1, 2, 3, 4, 5
arrsize DW 5
smallest DB ?
greatest DB ?
num DB ?
smallestPrompt DB 13,10,"Smallest number: $"
greatestPrompt DB 13,10,"Greatest number: $"


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


    ;displaying the results

    lea dx,smallestPrompt
    mov ah,9
    int 21h

    mov dl,smallest
    mov num,dl
    call outputNum

    lea dx,greatestPrompt
    mov ah,9
    int 21h

    mov dl,greatest
    mov num,dl
    call outputNum


    ret
main endp


;function to take number input
getNum proc
    push cx
    push dx

    mov dl, 00
    mov cl, 04
    
    getNumber:

    call getChar
    cmp al, 13
    je inputDone
    cmp al, 10
    je inputDone

    shl dl,cl
    sub al, 48
    cmp al, 9
    jle isNumber
    sub al, 7

    isNumber:
    or dl, al
    
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

; program to output a number stored in num
outputNum proc
    push cx
    push dx

    mov cl, 4
    mov dl, num
    shr dl,cl
    and dl, 0fh
    cmp dl,0ah
    jl isNumber2
    add dl,7
    isNumber2:
    add dl,48
    mov ah, 2
    int 21h

    mov dl, num
    and dl, 0fh
    cmp dl, 0ah
    jl isNumber1
    add dl, 07h
    isNumber1:
    add dl,48
    mov ah, 2
    int 21h

    pop dx
    pop cx
    ret
outputNum endp

end