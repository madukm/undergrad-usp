.data
	str1: .asciiz "\n\tDigite um valor: "
.text
.globl main
main:
	li $v0, 4 #pede ao utilizador o valor de n
	la $a0, str1
	syscall
	li $v0, 5 #ler o inteiro fornecido
	syscall
	addi $a0, $v0, 0 #valor lido fica em a0
	jal fact
	addi $a0, $v0, 0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
	
 fact:
 	sub $sp, $sp, 8 #ajusta a stack para 2 items
 	sw $ra, 4($sp) #guarda o endereco de retorno
 	sw $a0, 0($sp) #guarda arg n
 	slti $t0, $a0, 1 #testa se n < 1
 	beq $t0, $zero, L1 #se n >= 1, vai chamar L1
 	li $v0, 1 #se n devolve 1 #caso base
 	add $sp, $sp, 8 #libera espaco
 	jr $ra #retorna
 	
 L1:
 	sub $a0, $a0, 1 #nova chamada, novo arg (n-1)
 	jal fact #call fact com (n-1)
 	#ponto de retorno da chamada revursica
 	lw $a0, 0($sp) #recupera o argumento passado
 	lw $ra, 4($sp) #recupera o endereco de retorno
 	add $sp, $sp, 8 #libera espaco da stack
 	mul $v0, $a0, $v0 #calcula n*fact (n-1)
 	jr $ra
