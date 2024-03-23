.data
array: .space 100       # Khai báo mảng có thể chứa tối đa 100 phần tử
n:     .word 0           # Số phần tử của mảng
spc: .asciiz " "
str: .asciiz "Input N: "
str1: .asciiz "a["
str2: .asciiz "]: "
output: .asciiz "Output: "
.text
main:
    # Nhập số phần tử của mảng từ bàn phím
    li $v0,4
    la $a0,str
    syscall
    
    li $v0, 5             # syscall 5: nhập số nguyên
    syscall               # Gọi hàm syscall
    move $t0, $v0         # Lưu số phần tử vào $t0
    sw $t0, n             # Lưu số phần tử vào bộ nhớ
    
    # Nhập các phần tử của mảng từ bàn phím
    la $t1, array         # $t1 = địa chỉ bắt đầu của mảng
    li $t2, 0             # $t2 = index của phần tử hiện tại trong mảng
    
    
    
input_loop:
    beq $t2, $t0, end_input   # Nếu đã nhập đủ số phần tử thì kết thúc
    
    li $v0,4
    la $a0,str1
    syscall
    
    li $v0,1
    la $a0,($t2)
    syscall
    
    li $v0,4
    la $a0,str2
    syscall
    
    li $v0, 5                 # syscall 5: nhập số nguyên
    syscall                   # Gọi hàm syscall
    sw $v0, ($t1)             # Lưu giá trị nhập vào mảng
    addi $t1, $t1, 4          # Đi tới phần tử tiếp theo của mảng
    addi $t2, $t2, 1          # Tăng index của phần tử hiện tại
    
    j input_loop               # Quay lại nhập phần tử tiếp theo

end_input:
    
    li $v0,4
    la $a0,output
    syscall
    
    # In mảng đã nhập
    la $t1, array           # $t1 = địa chỉ bắt đầu của mảng
    li $t2, 0               # $t2 = index của phần tử hiện tại trong mảng
    
print_loop:
    beq $t2, $t0, end_print    # Nếu đã in đủ số phần tử thì kết thúc
    
    
    lw $a0, ($t1)               # Load giá trị của phần tử vào $a0 để in
    li $v0, 1                   # syscall 1: in số nguyên
    syscall                     # Gọi hàm syscall
    
    li $v0, 4                   # syscall 4: in chuỗi
    la $a0, spc             # Load địa chỉ của newline để in xuống dòng
    syscall                     # Gọi hàm syscall
    
    addi $t1, $t1, 4            # Đi tới phần tử tiếp theo của mảng
    addi $t2, $t2, 1            # Tăng index của phần tử hiện tại
    
    j print_loop                # Quay lại in phần tử tiếp theo

end_print:

    # Kết thúc chương trình
    li $v0, 10                  # syscall 10: kết thúc chương trình
    syscall                     # Gọi hàm syscall

