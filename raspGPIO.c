#include "raspGPIO.h"

// Generische Funktion für das "behandeln" von Fehlern
void handleError(const char* msg){
	perror(msg);
	exit(EXIT_FAILURE);
}

// Generische Funktion zum beschreiben von Dateien
void writeToFile(const char* path, const char* value){
	int file = open(path, O_WRONLY);
	if(-1 == file) handleError(path);
	if(-1 == write(file, value, strlen(value))){
		close(file);
		handleError("Schreibfehler");
	}
	close(file);
}

// Aktivieren von GPIO-Pins
// type = 0 => Input Pin
// type = 1 => Output Pin
void pinMode(const uint8_t pin, const GPIO_TYPE type){
	// Pin als String speichern
	char pin_string[PIN_LENGTH];
	snprintf(pin_string, sizeof(pin_string), "%d",pin);
	// Exportdatei öffnen und Pin hineinschreiben
	writeToFile(GPIO_EXPORT, pin_string);
	// Pin als Input oder Output definieren
	// Pfad der Konfigurationsdatei ermitteln
	char direction_path[PATH_LENGTH];
	snprintf(direction_path, sizeof(direction_path), "%s%s/direction", GPIO_PIN_PATH, pin_string);
	// Pin Typ in Konfigurationsdatei definieren
	if(OUTPUT == type) writeToFile(direction_path, "out");
	else writeToFile(direction_path, "in");
	return;
}

// Löscht Einstellungen eines bestimmten GPIO-Pins
void clearPin(const uint8_t pin){
	// Pin als String speichern
	char pin_string[PIN_LENGTH];
	snprintf(pin_string, sizeof(pin_string), "%d",pin);
	// Pin in die Unexportdatei schreiben
	writeToFile(GPIO_UNEXPORT, pin_string);
	return;
}

// Setzt einen Pin auf einen bestimmten Wert
void setPin(const uint8_t pin, const GPIO_LEVEL level){
	// Pfad der Value-Datei in String speichern
	char value_path[PATH_LENGTH];
	snprintf(value_path, sizeof(value_path), "%s%d/value", GPIO_PIN_PATH, pin);
	// Wert als String speichern
	char value_string[TYPE_LENGTH];
	snprintf(value_string, sizeof(value_string), "%d", level);
	// Wert des Pins in die passende Value-Datei schreiben
	writeToFile(value_path, value_string);
	return;
}
