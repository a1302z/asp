;# TODO: Sinnvoller Funktionsname
.globl _asm_do_nothing

.code 32

;# TODO: Funktionsparameter und Rueckgabewert dokumentieren
_asm_do_nothing:
  ;# TODO: Stackframe erstellen
  NOP

  ;# TODO: Stack wiederherstellen

  BX lr

;#.globl _asm_xor_cipher

;#.code 32

;# _asm_xor_cipher(char *str, int key);
;#_asm_xor_cipher:

;#frame pointer wird gepusht
;#push {fp}
;#frame pointer wird auf den wert des stack pointers gesetzt
;#add fp, sp, #0
;#der stackpointer wird um 5 Plaetze verschoben
;#sub sp, sp, #20
;#der erste uebergabeparameter wird in den 4. platz auf dem stack 
;#geschrieben
;#str r0, [fp, #-16]
;#der zweite uebergabeparameter wird in den 5.platz auf dem stack 
;#geschrieben
;#str r1, [fp, #-20]
;#r3 wird auf 0 gesetzt(Laufindex)
;#mov r3, #0
;# 0 wird in den 2. platz auf dem stack gelegt (Laufindex)
;#str r3, [fp, #-8]
;#man springt zum Schleifenkopf mit Vergleich und moeglichem Abbruch der 
;#Schleife
;#b loop_end
;#wenn die Schleifenbedingung noch erfuellt ist wird hier her gesprungen
;#loop_begin:
;#in r3 wird der Laufindex geladen
;#ldr r3, [fp, #-8]
;#in r2 wird das erste argument geladen (char* str)(Adresse von string beginn)
;#ldr r2, [fp, #-16]
;#in r2 wird die adresse des aktuellen characters geladen (ursprungsadresse + laufindex)
;#add r2, r2, r3
;#in r1 wird key gespeichert
;#ldr r1, [fp, #-20]
;#in r3 wird der character geschrieben
;#ldr r3, [r2, #0]
;# in r1 wird key xor r3(key xor char) gespeichert
;#eor r1, r1, r3
;#r1 wird in adresse die in r2 gespeichert ist geschrieben
;#str r1, r2
;#Laufindex erhoehen
;#ldrb r3, [fp, #-8]
;#add r3, r3, #1
;#str r3, [fp, #-8]
;#loop_end:
;#in r3 wird der lauf index geladen
;#ldr r3, [fp, #-8]
;#in r2 wird der erste uebergabeparameter geladen
;#ldr r2, [fp, #-16]
;#r3 = i + r2(Adressermittlung bei Arrayzugriff => array[i])
;#add r3, r2, r3
;# in r3 wird der dereferenzierte wert geschrieben
;#ldrb r3, [r3]
;#wenn dieser = 0 ist ist der string zu ende
;#cmp r3, #0
;#wenn der string nicht zuende ist wird nochmal an den anfang der 
;#schleife gesprungen
;#bne loop_begin
;#der stack pointer wird wieder auf den frame pointer gesetzt
;#sub sp, fp, #0
;#der frame pointer wird wieder vom stack genommen
;#pop {fp}
;#es wird zurueck gesprungen
;#bx lr


.globl _asm_test_program

.code 32


;#test programm, das eine bestimmte zahl an speicherplaetzen auf dem stack reserviert, deren werte als ints interpretiert, addiert und die summe als rueckgabe ausgibt
;#int _asm_test_program(int anzRegister);
_asm_test_program:
;#frame pointer pushen
push {fp}
;#frame pointer auf wert des stack pointers setzen
mov fp, sp
;#r1, r2 auf dem Stack zwischenspeichern(werden spaeter benutzt)
;#r3 zwischenspeichern (im folgenden ist r3 eine temporaere Variable)
push {r1, r2, r3}
;#Anzahl der Speicherplaetze berechnen (eingabe*4byte)
mov r3, #4
mul r0, r0, r3
;#speicherplatz reservieren(abhaengig von der Eingabe)(hier: r0 = Adresse des letzten Wertes)
sub sp, sp, r0
;# Im folgenden soll r0 := bisherige Summe, r1 := aktuelle Stackadresse, r2 := letztes register sein
add r2, sp, #0
add r1, fp, #0
;#muss noch um 3 speicherplaetze erhoeht werden (zwischengespeicherte register)
sub r1, r1, #12
mov r0, #0
;# bis hierher funktionierts
;#Springe zur Schleifenbedingung
b for_loop_condition
;#Schleifenanfang: for(int i = fp+3*4byte, i > sp, i-= 4byte)
for_loop_over_stack_registers:
;#r0+= [r1]
ldr r3, [r1, #0]
;#Wert in geladenem Speicherplatz auf Gesamtsumme addieren
add r0, r0, r3
;#Laufindex erhoehen
sub r1, r1, #4
;#Schleifenbedingung
for_loop_condition:
cmp r1, r2
;# i < sp
bgt for_loop_over_stack_registers
end:
;#r1, r2, fp wieder mit urspruenglichen Werten befuellen
pop {r1, r2, r3}
;#stackpointer und framepointer zurueck setzen
mov sp, fp
pop {fp}
;#zurueck springen
bx lr



.globl _asm_test_loops

.code 32

_asm_test_loops:
push {fp}
add fp, sp, #0
push {r1, r2}
mov r1, #0
mov r2, #0
b loop_cond
loop_beg:
add r2, r2, #1
loop_cond:
cmp r1, r0
add r1, r1, #1
blt loop_beg
mov r0, r2
pop {r1, r2}
pop {fp}
bx lr


