void test(){
	register int i asm("r0");
	register int *a asm("r8");
	register int *b asm("r9");
	register int *c asm("r10");

	for(i = 0; i <= 10; i++){
		a[i] = b[i] + c[i];
	}
}