#include <stdio.h>


int sumSimple(int x){
	int result;
	asm(
//schiebe input in register 3(Laufindex)
		"mov r3, %[out];"
//schreibe 0 in register 4(Ergebnis)
		"mov r4, #0;"
//label loop_anfang
		"loop_anfang:"
/*register 5 = asl 2 um so viele stellen wie in register 3 als wert 
steht*/
		"mov r5, #1;"
		"lsl r5, r5, r3;"
//register 4 = register 4 + register5
		"add r4, r4, r5;"
//dekrementiere laufindex
		"sub r3, r3, #1;"
//compare register 3 und 0
		"cmp r3, #0;"
//branch wenn ge zu loop_anfang
		"bge loop_anfang;"
//schiebe register 4 auf output
		"mov %[out], r4;"
	: [out] "=r" (result)
	: [in] "r" (x)
	: "r3", "r4", "r5"
	);
	return result;
}

/*
Idee: 
f(x) = 1 + f(x-1);
*/
int sumIntelligent(int x){
	int result;
	asm(
//schiebe input in register3(vergleichswert)
		"mov r3, %[in];"
//schreibe 1 in register 4(laufindex)
		"mov r4, #1;"
//schreibe 1 in register 5(Ergebnis)
		"mov r5, #1;"
//comp register(input) 3 mit 0
		"cmp r3, #0;"
//wenn <= dann ueberspringe Schleife
		"ble nach_loop;"
//label loop_anfang
		"loop_anfangI:"
//register 5 = 2*register 5
		"lsl r5, r5, #1;"
//register 5 + 1
		"add r5, r5, #1;"
//register 4 + 1
		"add r4, r4, #1;"
//comp register 3 register 4
		"cmp r4, r3;"
//wenn le dann zu loop_anfang
		"ble loop_anfangI;"
//label nach loop
		"nach_loop:"
//schiebe ergebnis in [out]
		"mov %[out], r5;"
		: [out] "=r" (result)
		: [in] "r" (x)
		: "r3", "r4", "r5"
	);
	return result;
}


/*
sum 2 hoch i = 2 hoch (n+1) -1
*/
int sumMoreAdvanced(int x){
	int result;
	asm(
//input in speicher laden(register3)
		"mov r3, %[in];"
//input inkrementieren
		"add r3, r3, #1;"
//1 in speicher laden (register4)
		"mov r4, #1;"
//register 4 um register3 stellen shiften
		"lsl r4, r4, r3;"
//register 4 dekrementieren
		"sub r4, r4, #1;"
//register 4 in ergebnis laden
		"mov %[out], r4;"
		: [out] "=r" (result)
		: [in] "r" (x)
		: "r3", "r4"
	);
	return result;
}

int main(int argc, char** argv){
	int result = sumSimple(30);
	printf("Summe von 2^i von i = 0..10 ist %i\n", result);
	result = sumIntelligent(30);
	printf("Summe von 2^i von i = 0..10 ist %i\n", result);
	result = sumMoreAdvanced(30);
	printf("Summe von 2^i von i = 0..10 ist %i\n", result);
	return 0;
}
