/**
 *
 * ASP Rahmenprogramm
 *
 * 1. Setup
 *   - Projekt umbenennen (Rechtsklick im Project Explorer -> Rename)
 *   - Projekt kompilieren (Rechtsklick im Project Explorer -> Build Project)
 *
 * 2. Dateiname anpassen
 *   - default.c z.B. in main.c umbenennen
 *       Im Makefile: TARGET = main
 *   - nop.S z.B. in gauss.S umbennen
 *       Im Makefile: ASM_TARGET = gauss
 *
 * 3. Debug-Konfiguration erstellen
 *   - Run -> Debug Configurations
 *   - Neue "DS-5 Debugger" Konfiguration erstellen (Doppelklick auf "DS-5 Debugger")
 *   - Namen fuer die Konfiguration eingeben
 *   - Im Connection Tab:
 *       Select Target: beagleboard.org -> xM -> Linux Application Debug -> Download and Debug Application
 *       Connections: Connection auswaehlen
 *   - Im Files Tab:
 *       Target Configuration:
 *         Application on host to download: Workspace anklicken -> Projekt auswaehlen -> kompilierte Binary (Standard: "default")
 *         Load Symbols aktiviert lassen!
 *       Target download directory:
 *         Ein auf dem Zielboard verfuegbares Verzeichnis eingeben (je nach Board /writeable or /home/<username>)
 *       Target working directory:
 *         Selbes Verzeichnis wie download directory eingeben
 *
 * 4. Rahmenprogramm implementieren
 *   - Siehe Blatt 4, H1
 *
 * 5. Projekt implementieren
 *   - Implementieren Sie als Platzhalter fuer die Projektimplementierung den Gauss-Schleifen-Algorithmus
 *     oder einen anderen der behandelten Summationalgorithmen mit Uebergabe der Parameter auf der Kommandozeile
 *       1. Implementieren Sie den Algorithmus in C in dieser Datei in einer Funktion "int gauss_c(int n)"
 *       2. Implementieren Sie den Algorithmus in Assembler in Ihrer Assembler-Datei in einer Funktion "_gauss_asm"
 *     Kommandozeilenparameter koennen Sie beim debuggen ueber DS-5 direkt in der Debugger-Konfiguration im Arguments Tab
 *     eingeben!
 *   - Kommentieren Sie Ihre Implementation, insbesondere den Assembler-Teil!
 *   - Testen Sie Ihre Implementation. Vergleichen Sie dabei die Ergebnisse der Algorithmus in C, in Assembler, und
 *     vorberechnete Referenzwerte!
 *   - Benchmarken Sie die C-Version gegen die Assembler-Version indem Sie den "time" oder "perf stat -e cycles" Befehl,
 *     oder das DS-5 Streamline Tool benutzen.
 *   - Die "Usage"-Ausgabe die in der main-Funktion implementiert ist soll Ihnen als Anregung fuer die Implementierung der
 *     verschiedenen Ausfuehrungsmodi fuer Test und Benchmarking in einem Programm dienen.
 *
**/

#include <stdio.h>

// TODO: C-Funktion implementieren
// TODO: ASM-Funktion importieren

// TODO: Benchmark-Loop-Funktion implementieren

// TODO: Test-Funktion implementieren


int main(int argc, char **argv) {
	printf("\nDefault hello\n\n");

	//TODO: Commandline-Parameter parsen
	if (argc > 1) {

	} else {
		printf("Usage: %s MODE [args...]\n", argv[0]);
		printf("\t %s eval N              Auswertung des Algorithmus mit Parameter N\n", argv[0]);
		printf("\t %s test                Testlauf zur Ueberpruefung der Korrektheit\n", argv[0]);
		printf("\t %s loop_a N RUNS       ASM-Implementation mit Parameter N und RUNS Durchlaeufen ausfuehren\n", argv[0]);
		printf("\t %s loop_c N RUNS       C-Implementation mit Parameter N und RUNS Durchlaeufen ausfuehren\n", argv[0]);
		printf("\t %s loop_e N RUNS       Ausfuehrung von RUNS leeren Schleifendurchlaeufen (N wird ignoriert)\n", argv[0]);
	}

	printf("\n");

	return 0;
}
