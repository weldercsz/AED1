
.data
	.word 7		# x -> 0x10010000
	.space 4	# y -> 0x10010004
	
	
.text
	lui $t0, 0x1001	# begin of .data
	lw $t5, 0($t0)	# x
	lui $t1, 3	# i
	lui $t2, 1	# aux
	lui $t4, 1	# y
	
	fibonacci:
	
		sub $t7, $t1, $t5
		beq $t7, $zero, ok
		slt $t7, $t1, $t5  # 1
		beq $t7, $zero, end
		
		ok:
		
			add $t3, $t2, $t4	# aux2 = aux + y
			add $t2, $t4, $zero	# aux = y
			add $t4, $t3, $zero	# y = aux2
			
			addi $t1, $t1, 1
			j fibonacci
		
	end:
		
		sw $t4, 4($t0)
		