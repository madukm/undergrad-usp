.data
	str1: .asciiz "\n\tQual fibonacci? "
.text
.globl main
main:
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 5
	syscall
	
	move $a0, $v0
	jal fib
	
	move $a0, $v0
	li, $v0, 1
	syscall
	li $v0, 10
	syscall

fib:
	sub $sp, $sp, 12
	sw $ra, 4($sp) 
	sw $a0, 0($sp) #guarda n
	slti $t0, $a0, 3 #testa se n < 2, coloca 1 em t0 se a0 < 2
 	beq $t0, $zero, fib_rec #se n >= 2, vai chamar fib_rec
	li $v0, 1 #se n < 2 devolve 1 #caso base
	#move $a0, $v0
	add $sp, $sp, 12
	jr $ra

fib_rec:
	sw $ra, 4($sp) #save $ra
	sw $a0, 0($sp) #save n because we'll need it for fib(n-2)
	sub $a0, $a0, 1	#n-1
	jal fib
	lw $a0, 0($sp) #restore n
	lw $ra, 4($sp) #restore $ra
	sw $v0, 8($sp) #save return fib(n-1)
	sub $a0, $a0, 2 #n-2	
	jal fib
	lw $t0, 8($sp) #restorne return fib(n-1)
	add $v0, $t0, $v0 #return value
	lw $ra, 4($sp) #restore $ra
	add $sp, $sp, 12 #tear down stack
	jr $ra
	
		
