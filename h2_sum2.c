#include <stdio.h>

int sumSimple(int x){
	int result;
	asm(
//Input in register 3 speichern(Laufindex)
		"mov r3, %[out];"
//0 in register 4 speichern(Summe)
		"mov r4, #0;"
//label loop_anfang
		"loop_anfang:"
//register 3 * register 3 in register 5 speichern(Zwischenvariable)
		"mul r5, r3, r3;"
//register 3 * register 5 in register 5
		"mul r5, r3, r5;"
//register 5 = register 5 + register 3
		"add r5, r5, r3;"
//register 4 = register 4 + register 5
		"add r4, r4, r5;"
//register 3 - 1
		"sub r3, r3, #1;"
//Vergleich
		"cmp r3, #0;"
//branch wen groesser gleich zu loop_anfang
		"bgt loop_anfang;"
//register 4 in out schieben
		"mov %[out], r4;"
	: [out] "=r" (result)
	: [in] "r" (x)
	: "r3", "r4", "r5"
	);
	return result;
}

/*
summe von 0 bis n ueber (k^3 + k) entspricht
f(x) = (1/4) n (n+1) (n^2 +n +2)

(von wolfram alpha)
*/
int sumAdvanced(int x){
	int result;
	asm(
//x in register 3 laden
		"mov r3, %[in];"
//r3 * r3 in register r4
		"mul r4, r3, r3;"
//r4 = r3 + r4
		"add r4, r4, r3;"
//r4 += 2
		"add r4, r4, #2;"
//r4 *= r3
		"mul r4, r4, r3;"
//r3 += 1
		"add r3, r3, #1;"
//r4 *= r3
		"mul r4, r4, r3;"
//r4 lsr #2
		"lsr r4, r4, #2;"
//r4 auf out schieben
		"mov %[out], r4;"
		: [out] "=r" (result)
		: [in] "r" (x)
		: "r3", "r4"
	);
	return result;
}

int main(int argc, char** argv){
	int result = sumSimple(10);
	printf("Die Summe von 0 bis 10 ergibt %i\n", result);	
	result = sumAdvanced(10);
	printf("Die Summe von 0 bis 10 ergibt %i\n", result);	
	return 0;
}
