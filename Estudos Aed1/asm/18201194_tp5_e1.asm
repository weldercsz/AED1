
.data

	.half 30	# a -> 0x10010000
	.half 5		# b -> 0x10010002
	.space 4	# y -> 0x10010004
	
.text
	# BEGIN

	lui $t0, 0x1001
	lh $t1, 0($t0)
	lh $t2, 2($t0)
	
	beq $t1, $t2, multiply
	j divide
	
	multiply:
	
		mult $t1, $t2
		mflo $t1
		j exit
		
	divide:
		div $t1, $t2
		mflo $t1
		j exit

	exit:
	
		sw $t1, 4($t0)
	
	#END

# answer: 0x10010004