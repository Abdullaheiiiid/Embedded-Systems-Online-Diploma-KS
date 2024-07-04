.global reset 
reset:
	ldr sp, = stack_pointer
	bl  main
stop: b stop