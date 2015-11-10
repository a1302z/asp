#include <stdio.h>

int cubeSumLoop(int x){
	int result;
	asm(
//0 in register 1 laden
		"mov r4, #0;"
//x in register 2 laden
		"mov r5, %[in];"
//label: loop anfang
		"loop_anfang:"
//register 2 mit 3 potenzieren und in register 3 speichern
		"mul r6, r5, r5;"
		"mul r6, r6, r5;"
//register 3 zu register 1 addieren
		"add r4, r4, r6;"
//register 2 dekrementieren
		"sub r5, r5, #1;"
//vergleich register 2 > 0
		"cmp r5, #0;"
//wenn vergleich ge ergibt zu label loop anfang springen
		"bgt loop_anfang;"
//register 1 als output definieren
		"mov %[out], r4;"
		//+ -> lesend, = -> schreibend
	: [out] "=r" (result)	//out oder in
//				 -> Assembler namen in eckigen Klammern
	: [in] "r" (x) 		//r-> Referenz
	: "r5", "r5", "r6"	//in runden Klammern c Name
	);
	return result;
}

int cubeSum(int x){
	int result;
	asm(
//x wird in r4 geladen
		"mov r4, %[in];"
//auf den Wert in r4 wird 1 addiert und in r5 gespeichert
		"add r5, r4, #1;"
//r4 und r5 werden multipliziert und in r4 gespeichert
		"mul r4, r4, r5;"
//der Wert in r4 wird (durch asr) durch 2 geteilt
		"asr r4, r4, #1;"
//der wert in r4 wird mit 2 potenziert
		"mul r4, r4, r4;"
//der wert in r4 wird auf die out Variable geschoben
		"mov %[out], r4;"
		: [out] "=r" (result)
		: [in] "r" (x)
		: "r4", "r5"
	);
	return result;
}

int main(int argc, char** argv){
	int result = cubeSum(10);
	printf("sum(i^3) i=0..10 = %i\n", result);	
	result = cubeSumLoop(10);
	printf("sum(i^3) i=0..10 = %i\n", result);
	return 0;
}
