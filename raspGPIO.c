#include "raspGPIO.h"

// Generische Funktion für das "behandeln" von Fehlern
void handleError(const char* msg){
	perror(msg);
	exit(EXIT_FAILURE);
}

// Generische Funktion zum beschreiben von Dateien
void writeToFile(const char* path, const char* value){
	int file = open(path, O_WRONLY);
	if(file == -1) handleError(path);
	if(write(file, value, strlen(value))== -1){
		close(file);
		handleError("Schreibfehler");
	}
	close(file);
}

// Aktivieren von GPIO-Pins
// type = 0 => Input Pin
// type = 1 => Output Pin
void pinMode(uint8_t pin, uint8_t type){
	// Pin als String speichern
	char pin_string[3];
	snprintf(pin_string, sizeof(pin_string), "%d",pin);
	// Exportdatei öffnen und Pin hineinschreiben
	writeToFile("/sys/class/gpio/export",pin_string);
	// Pin als Input oder Output definieren
	// Pfad der Konfigurationsdatei ermitteln
	char direction_path[35];
	snprintf(direction_path, sizeof(direction_path), "/sys/class/gpio/gpio%s/direction", pin_string);
	// Pin Typ in Konfigurationsdatei definieren
	if(type == OUTPUT) writeToFile(direction_path, "out");
	else writeToFile(direction_path, "in");
	return;
}

// Löscht Einstellungen eines bestimmten GPIO-Pins
void clearPin(uint8_t pin){
	// Pin als String speichern
	char pin_string[3];
	snprintf(pin_string, sizeof(pin_string), "%d",pin);
	// Pin in die Unexportdatei schreiben
	writeToFile("/sys/class/gpio/unexport", pin_string);
	return;
}

// Setzt einen Pin auf einen bestimmten Wert
void setPin(uint8_t pin, uint8_t value){
	// Pfad der Value-Datei in String speichern
	char value_path[35];
	snprintf(value_path, sizeof(value_path), "/sys/class/gpio/gpio%d/value", pin);
	// Wert als String speichern
	char value_string[2];
	snprintf(value_string, sizeof(value_string), "%d", value);
	// Wert des Pins in die passende Value-Datei schreiben
	writeToFile(value_path, value_string);
	return;
}
