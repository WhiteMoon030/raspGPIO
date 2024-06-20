#ifndef RASPGPIO_H
#define RASPGPIO_H

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INPUT 0
#define OUTPUT 1
#define LOW 0
#define HIGH 1

// Generische Funktion für das "behandeln" von Fehlern
void handleError(const char* msg);

// Generische Funktion zum beschreiben von Dateien
void writeToFile(const char* path, const char* value);

// Aktivieren von GPIO-Pins
// type = 0 => Input Pin
// type = 1 => Output Pin
void pinMode(uint8_t pin, uint8_t type);

// Löscht Einstellungen eines bestimmten GPIO-Pins
void clearPin(uint8_t pin);

// Setzt einen Pin auf einen bestimmten Wert
void setPin(uint8_t pin, uint8_t value);

#endif
