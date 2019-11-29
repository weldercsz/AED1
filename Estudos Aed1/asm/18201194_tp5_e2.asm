
.data
	.space 4	# y -> 10010000
	
.text
	lui $t0, 0x1001
	lui $t1, 0
	while:
		slti $t7, $t1, 333
		beq $t7, $zero, end
		
		addi $t1, $t1, 1
		j while
		
	end:
		sw $t1, 0($t0)