.data
var1: .word 9 
nl: .asciiz "\n"

.text
main:
	lw $t0, var1 # $t0 = var1 "load word"
	li $t1, 7 # $t1 = 7 "load immediate"
	add $t1, $t1, $t0 # t1 = t1 + t0
	sw $t1, var1 # var1 = $t1 "store word"
	
	#imprimir
	li $v0, 1 #print_int
	move $a0, $t1 #copia o numero a ser impresso para $a0. argumento de entrada para printar int
	syscall #chamada de sistema
	
	#imprimi pular linha
	li $v0, 4 #print_str
	la $a0, nl #"load adress"
	syscall
	
	addi $t1, $t1, 5 # "add imeddiate"
	sw $t1, 4($t2) # armazena no t2 + 4 bytes (32 bits prox endereço - word)
	lw $t3, 4($t2) #recupera o valor de t2 + 4 bytes e load em t3
	
exit:
	
	li $v0, 10 #"exit"
	syscall
	
	
	
	
	
	