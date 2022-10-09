void test(){
	register int i asm("r0");
	register int *a asm("r8");
	register int *b asm("r9");

	for(i = 0; i <= 10; i++){
		if(i < 5)
			a++;
		else
			b++;
	}
}