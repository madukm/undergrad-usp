#Trabalho 1 - Calculadora
#Breno Cunha Queiroz - 11218991
#Maria Eduarda Kawakami Moreira - 11218751
#30/03/2020

.data
	menu_main: .asciiz "\n\n\t-----MENU----\n\tEscreva a letra da operação:\n\tM: Memória\n\tC: Cálculo\n\t"
	menu_calc: .asciiz "\n\n\t-----MENU CALCULO----\n\tEscreva o número da operação:\n\t1:  Adição\n\t2:  Subtração\n\t3:  Multiplicação\n\t4:  Divisão\n\t5:  Potenciação\n\t6:  Raiz quadrada\n\t7:  Tabela multiplicação\n\t8:  Fatorial\n\t9:  Fibonacci\n\t10: Sequência de Fibonacci\n\t"
	menu_mem: .asciiz "\n\n\t-----MENU MEMORIA----\n\tEscolha a memória que você quer consultar:\n\tM1: Memória 1\n\tM2: Memória 2\n\tM3: Memória 3\n\t"
	addition_header: .asciiz "\n\t-----ADIÇÃO----\n"
	subtraction_header: .asciiz "\n\t-----SUBTRAÇÃO----\n"
	multiplication_header: .asciiz "\n\t-----MULTIPLICAÇÃO----\n"
	division_header: .asciiz "\n\t-----DIVISÃO----\n"
	potentiation_header: .asciiz "\n\t-----POTENCIAÇÃO----\n"
	square_root_header: .asciiz "\n\t-----RAIZ QUADRADA----\n"
	mult_table_header: .asciiz "\n\t-----TABELA MULTIPLICAÇÃO----\n"
	factorial_header: .asciiz "\n\t-----FATORIAL----\n"
	fibonacci_header: .asciiz "\n\t-----FIBONACCI----\n"
	fibonacci_sequence_header: .asciiz "\n\t-----SEQUÊNCIA DE FIBONACCI----\n"
	num: .asciiz "\tNúmero: "
	first_num: .asciiz "\tPrimeiro número:"
	second_num: .asciiz "\tSegundo número:"
	base: .asciiz "\tBase:"
	expoent: .asciiz "\tExpoente:"
	not_exact: .asciiz "\tO resultado a seguir não é exato (raiz não natural).\n"
	first_num_fib: .asciiz "\tPrimeiro numero(menor):"
	second_num_fib: .asciiz "\tSegundo numero(maior):"
	number_negative: .asciiz "\tPor favor insira um valor não negativo."
	square_root_negative: .asciiz "\tNão existe raiz real de número negativo. Tente novamente."
	fib_seq_error_sequence: .asciiz "\tO primeiro número deve ser menor ou igual ao segundo. Tente novamente."
	fib_seq_error_negative: .asciiz "\tUm intervalo não pode conter números negativos. Tente novamente."
	division_error_input: .asciiz "\tO segundo número não pode ser zero. Tente novamente."
	nl: .asciiz "\n"
	nlt: .asciiz "\n\t"
	result: .asciiz "\tResultado:"
	m1_result: .asciiz "\n\tValor de M1:"
	m2_result: .asciiz "\n\tValor de M2:"
	m3_result: .asciiz "\n\tValor de M3:"
	empty_memory: .asciiz "Nenhum valor salvo"
	memory_selected: .space 3
.text

.globl main
init:
	jal init_empty_memory
	j main

main:
	li $v0, 4
	la $a0, menu_main
	syscall
	
	li $v0, 12
	syscall
	
	addi $a0, $v0, 0
	
	#choose M or C
	li $t0, 'C'
	beq $a0, $t0, calculate
	li $t0, 'M'
	beq $a0, $t0, memory
	
	# Exit program
	j exit
	
#################################################
################## SEC MENUS ####################
#################################################
calculate:
	# Show menu
	li $v0, 4
	la $a0, menu_calc
	syscall
	
	# Read option
	li $v0, 5
	syscall
	
	# Check each option
	beq $v0, 1, addition
	beq $v0, 2, subtraction
	beq $v0, 3, multiplication
	beq $v0, 4, division
	beq $v0, 5, potentiation_main
	beq $v0, 6, square_root_main
	beq $v0, 7, mult_table
	beq $v0, 8, fact_main
	beq $v0, 9, fib_main
	beq $v0, 10, fib_seq_main
	# Return to main
	j main

memory:
	# Show menu
	li $v0, 4
	la $a0, menu_mem
	syscall
	
	# Read option
	li $v0, 8
	la $a0, memory_selected
	li $a1, 3
	syscall
	
	# Load second char to t0
	la $a0, memory_selected
	lb $t0, 1($a0)
	# Load char 1,2,3 to compare
        li $t1, '1'
        li $t2, '2'
        li $t3, '3'
	
	# Compare input with each option
	beq $t0, $t1, show_m1
	beq $t0, $t2, show_m2
	beq $t0, $t3, show_m3
	# Return to main
	j main

#################################################
################## OPERATIONS ###################
#################################################

################### Addition ####################
addition:
	# Show header
	li $v0, 4
	la $a0, addition_header
	syscall
	
	# Read first num
	li $v0, 4
	la $a0, first_num
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	# Read second num
	li $v0, 4
	la $a0, second_num
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	# Calculate result
	add $t2, $t0, $t1
	
	# Show result
	li $v0, 4
	la $a0, result
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	# Save result memory
	jal shift_memory
	move $s5, $t2
	# Return to main
	j main
	
################# Subtraction ###################
subtraction:
	# Show header
	li $v0, 4
	la $a0, subtraction_header
	syscall
	
	# Read first num
	li $v0, 4
	la $a0, first_num
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	# Read second num
	li $v0, 4
	la $a0, second_num
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	# Calculate result
	sub $t2, $t0, $t1
	
	# Show result
	li $v0, 4
	la $a0, result
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	# Save result memory
	jal shift_memory
	move $s5, $t2
	# Return to main
	j main
################ Multiplication #################
multiplication:
	# Show header
	li $v0, 4
	la $a0, multiplication_header
	syscall
	
	# Read first num
	li $v0, 4
	la $a0, first_num
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	# Read second num
	li $v0, 4
	la $a0, second_num
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	# Calculate result
	mul $t2, $t0, $t1
	
	# Show result
	li $v0, 4
	la $a0, result
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	# Save result memory
	jal shift_memory
	move $s5, $t2
	# Return to main
	j main

################## Division #####################
division:
	# Show header
	li $v0, 4
	la $a0, division_header
	syscall
	
	# Read first num
	li $v0, 4
	la $a0, first_num
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	# Read second num
	li $v0, 4
	la $a0, second_num
	syscall
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	# Check division by 0
	bnez $t1 continue_div
		li $v0, 4
		la $a0, division_error_input
		syscall
		j division
	continue_div:
	
	# Calculate result
	div $t2, $t0, $t1
	
	# Show result
	li $v0, 4
	la $a0, result
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	# Save result memory
	jal shift_memory
	move $s5, $t2
	# Return to main
	j main
	
################ Potentiation ###################
potentiation_main:
	# Show header
        li $v0, 4
        la $a0, potentiation_header
        syscall

        # Ask for base
        li $v0, 4
        la $a0, base
        syscall

	#Read base
        li $v0, 5
        syscall
        move $t0, $v0

        #Ask for expoent
        li $v0, 4
        la $a0, expoent
        syscall

	#Read expoent
        li $v0, 5
        syscall
        move $t1, $v0
	
	# Deal with expoent equal 0 and negative expoent
	
	# If expoent==0, show 1 or -1
	bnez $t1, potentiation_check_negative
		# If base<0
		bgez $t0, potentiaion_equal_one
			addi $t2, $zero, -1
			j show_potentiation_result
		# Else
		potentiaion_equal_one:
			addi $t2, $zero, 1
			j show_potentiation_result
	potentiation_check_negative:
	# If expoent<0
	bgtz $t1, calculate_potentiation
		# If base<=1, result=base
		bgt $t0, 1, potentiation_result_zero
			add $t2, $t0, $zero
			j show_potentiation_result
		potentiation_result_zero:
		# Else result=0
			add $t2, $zero, $zero
			j show_potentiation_result
	# Else, calculate potentiation
	calculate_potentiation:
	jal potentiation
	show_potentiation_result:
	
	# Show result
	li $v0, 4
	la $a0, result
	syscall
	
	# Show number
	li $v0, 1
	la $a0, ($t2)
	syscall
	
	# Save result memory
	jal shift_memory
	move $s5, $a0
	# Return to main
	j main
	
potentiation:
	sub $sp, $sp, 8 
	sw $ra, 4($sp)
	
	sub $t1, $t1, 1 #expoent--
	beq $t1, 0, potentiation_return
	
	jal potentiation
	
	lw $t3, 0($sp)
	mul $t2, $t0, $t3 #(last call of potentiation) * base
	addi $sp, $sp, 8 
	sw $t2, 0($sp) #result is saved in $t2
	lw $ra, 4($sp) 
	jr $ra
	
potentiation_return:
	sw $t0, 0($sp)
	lw $ra, 4($sp) 
	jr $ra

################# Square Root ###################
square_root_main:
	# Show header
	li $v0, 4
	la $a0, square_root_header
	syscall
	
	# Ask for number
	li $v0, 4
        la $a0, num
        syscall
        
        # Get number
        li $v0, 5
        syscall
        
        # Check negative
        bltz $v0, square_root_error_negative
        
        # Calculate square root
        jal square_root
        move $t1, $v0
	
        # Show result not exact
        beq $t1, 0, square_root_display_exact
        bne $v1, 1, square_root_display_exact# If not exact
		# Display not exact
		li $v0, 4
		la $a0, not_exact
		syscall
	square_root_display_exact:
        
        # Show "result:"
	li $v0, 4
	la $a0, result
	syscall
        
        # Display number
	li $v0, 1
	move $a0, $t1
	syscall
		
	# Save result memory
	jal shift_memory
	move $s5, $a0
        
	# Return to main
	j main

square_root:
        # Init variables
        add $t0, $v0, $zero   # goal x*x
        
        addi $t1, $zero, 1    
        sll $t1, $t1, 15       # bit mask offset (0000 0000 0000 0000 1000 0000 0000 0000)
     
        add $t2, $zero, $zero # x
        add $t3, $zero, $zero # x*x
        
        square_root_while:
        	# Test mask
        	add $t2, $t2, $t1 # t2=x+mask
        	mul $t3, $t2, $t2 # t3=t2*t2
        	
        	ble $t3, $t0, square_root_continue # If x*x>goal (number bigger than goal)
        		sub $t2, $t2, $t1 # t2=x-mask (remove mask, try with lower number)
        	square_root_continue:
        	beq $t3, $t0, square_root_end # If x*x==goal (mask>>1)
		srl $t1, $t1, 1
		
		beqz $t1, square_root_end # If x*x==goal not found (not natural)
		
        	j square_root_while
        square_root_end:
        
        # $v1 is as flag to square root not exact
        addi, $v1, $zero, 0
	bnez $t1, square_root_natural 
		addi, $v1, $zero, 1
	square_root_natural:
     
     	move $v0, $t2
     	
        jr $ra
        
square_root_error_negative:
	li $v0, 4
	la $a0, square_root_negative
	syscall
	j square_root_main

############# Multiplication Table ##############

mult_table:
	#show header
        li $v0, 4
        la $a0, mult_table_header
        syscall

        #ask for number
        li $v0, 4
        la $a0, num
        syscall
	
	li $v0, 5
	syscall
	
	move $t0, $v0
	
	li $t1, 0 #counter
	
	mult_table_loop:
		beq $t1, 10, mult_table_return # stops when conteur = 10
		addi $t1, $t1, 1 #counter++
		mul $t2, $t1, $t0 #counter*n
		
		#print \n
		li $v0, 4
		la $a0, nl
		syscall
		
		#print result
		li $v0, 1
		la $a0, ($t2)
		syscall
		
		j mult_table_loop 

	mult_table_return:
		j main
		
################## Factorial ####################

fact_main:
	#show header
	li $v0, 4
	la $a0, factorial_header
	syscall
	
	#ask for number
	li $v0, 4
        la $a0, num
        syscall
        
        li $v0, 5
	syscall 
	move $a0, $v0
	
	# Check negative
        bltz $a0, fact_error_negative
        
	jal fact
	move $t1, $v0
	
	# Show result
	li $v0, 4
	la $a0, result
	syscall
	
	li $v0, 1
	la $a0, ($t1)
	syscall
	
	# Save result memory
	jal shift_memory
	move $s5, $a0
	# Return to main
	j main

fact:
	sub $sp, $sp, 8 
 	sw $ra, 4($sp) #store $ra
 	sw $a0, 0($sp) #store n
 	slti $t0, $a0, 1 #$t0 = 1 if n < 1
 	beq $t0, $zero, fact_rec #if n >= 1, call fact_rec
 	li $v0, 1 #if n < 1 return 1 - base case
 	add $sp, $sp, 8 # free stack
 	jr $ra
 	
fact_rec:
 	sub $a0, $a0, 1 #n-1
 	jal fact
 	lw $a0, 0($sp) #restore n
 	lw $ra, 4($sp) #restore $ra
 	add $sp, $sp, 8 #free stack
 	mul $v0, $a0, $v0 #return n * fact(n-1)
 	jr $ra
 	
fact_error_negative:
	li $v0, 4
	la $a0, number_negative
	syscall
	j fact_main
################## Fibonacci ####################
fib_main:
	#show header
        li $v0, 4
        la $a0, fibonacci_header
        syscall

        #ask for number
        li $v0, 4
        la $a0, num
        syscall
        
        li $v0, 5
        syscall
        
        move $a0, $v0
        
        # Check negative
        bltz $a0, fib_error_negative
        
        jal fib
	
	move $t1, $v0
	
	# Show result
	li $v0, 4
	la $a0, result
	syscall
	
	li $v0, 1
	la $a0, ($t1)	
	syscall
	
	# Save result memory
	jal shift_memory
	move $s5, $a0
	# Return to main
	j main

fib:

	sub $sp, $sp, 12
	sw $ra, 4($sp) 
	sw $a0, 0($sp) #save n
	slti $t0, $a0, 2 # $t0 = 1 if n < 2
 	beq $t0, $zero, fib_rec #if n >= 2, call fib_rec
	li $v0, 1 #if n < 2 return 1 #base case
	add $sp, $sp, 12
	jr $ra

fib_rec:
	sw $ra, 4($sp) #save $ra
	sw $a0, 0($sp) #save n for fib(n-2)
	sub $a0, $a0, 1	#n-1
	jal fib
	lw $a0, 0($sp) #restore n
	lw $ra, 4($sp) #restore $ra
	sw $v0, 8($sp) #save return fib(n-1)
	sub $a0, $a0, 2 #n-2	
	jal fib
	lw $t0, 8($sp) #restore return fib(n-1)
	add $v0, $t0, $v0 #return fib(n-1) + fib(n-2)
	lw $ra, 4($sp) #restore $ra
	add $sp, $sp, 12 #tear down stack
	jr $ra		
	
fib_error_negative:
	li $v0, 4
	la $a0, number_negative
	syscall
	j fib_main
############# Fibonacci Sequence ################
fib_seq_main:
	# Show header
	li $v0, 4
	la $a0, fibonacci_sequence_header
	syscall
	
	# Ask first num
	li $v0, 4
	la $a0, first_num_fib
	syscall
	
	# Get first num
	li $v0, 5
	syscall
	move $t6, $v0
	
	move $t0, $v0
	# Ask second num
	li $v0, 4
	la $a0, second_num_fib
	syscall
	
	# Get second num
	li $v0, 5
	syscall
	move $t7, $v0
	
	# Ask again if t6>t7
	ble $t6 $t7 continue_fib_seq
		li $v0, 4
		la $a0, fib_seq_error_sequence
		syscall
		j fib_seq_main
	continue_fib_seq:
	
	# Ask again if t6<0 or t7<0
	bltz $t6, error_negative_fib_seq
	bltz $t7, error_negative_fib_seq
	
	# While t6<=t7
	while_fib_seq:
		# Call fib
		move $a0, $t6
        	jal fib
		move $t2, $v0
		
		# Print \n\t
		li $v0, 4
		la $a0, nlt
		syscall
		
		# Print number
		li $v0, 1
		move $a0, $t2
		syscall
		
		# t6++
		addi $t6, $t6, 1
		# If t6<=t7, continue
		ble, $t6, $t7, while_fib_seq
	
	# Nothing to save to memory
	# Return to main
	j main
	
error_negative_fib_seq:
	li $v0, 4
	la $a0, fib_seq_error_negative
	syscall
	j fib_seq_main

#################################################
################# SHOW MEMORY ###################
#################################################
show_m1:
	# Show header
	li $v0, 4
	la $a0, m1_result
	syscall
	
	beq $s5, -32768, show_m1_empty #If not empty
		# Show value
		li $v0, 1
		move $a0, $s5
		syscall
		j show_m1_end
	show_m1_empty: #If empty
		# Show empty
		li $v0, 4
		la $a0, empty_memory
		syscall
	show_m1_end:
	
	j memory
	
show_m2:
	# Show header
	li $v0, 4
	la $a0, m2_result
	syscall
	beq $s6, -32768, show_m2_empty #If not empty
		# Show value
		li $v0, 1
		move $a0, $s6
		syscall
		j show_m2_end
	show_m2_empty: #If empty
		# Show empty
		li $v0, 4
		la $a0, empty_memory
		syscall
	show_m2_end:
	
	j memory
	
show_m3:
	# Show header
	li $v0, 4
	la $a0, m3_result
	syscall
	
	beq $s7, -32768, show_m3_empty #If not empty
		# Show value
		li $v0, 1
		move $a0, $s7
		syscall
		j show_m3_end
	show_m3_empty: #If empty
		# Show empty
		li $v0, 4
		la $a0, empty_memory
		syscall
	show_m3_end:
	
	j memory

#################################################
################# AUXILIARIES ###################
#################################################
init_empty_memory:
	addi $s5, $zero, -32768# M1 = empty
	addi $s6, $zero, -32768# M2 = empty
	addi $s7, $zero, -32768# M3 = empty
	
	jr $ra
	
shift_memory:
	# M2 -> M3
	# M1 -> M2
	# M1 = 0
	move $s7, $s6
	move $s6, $s5
	add $s5, $zero, $zero

	jr $ra
	
exit:
	li $v0, 10
	syscall
