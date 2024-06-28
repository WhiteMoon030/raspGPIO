#ifndef RASPGPIO_H
#define RASPGPIO_H

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ---- Konstanten ----
#define GPIO_EXPORT "/sys/class/gpio/export"
#define GPIO_UNEXPORT "/sys/class/gpio/unexport"
#define GPIO_PIN_PATH "/sys/class/gpio/gpio"
#define PATH_LENGTH 35
#define PIN_LENGTH 3
#define TYPE_LENGTH 2

// ---- Enums ----
typedef enum GPIO_TYPE{
    INPUT,
    OUTPUT
}GPIO_TYPE;

typedef enum GPIO_LEVEL{
    LOW,
    HIGH
}GPIO_LEVEL;

// Generische Funktion für das "behandeln" von Fehlern
void handleError(const char* msg);

// Generische Funktion zum beschreiben von Dateien
void writeToFile(const char* path, const char* value);

// Aktivieren von GPIO-Pins
void pinMode(const uint8_t pin, const GPIO_TYPE type);

// Löscht Einstellungen eines bestimmten GPIO-Pins
void clearPin(const uint8_t pin);

// Setzt einen Pin auf einen bestimmten Wert
void setPin(const uint8_t pin, const GPIO_LEVEL level);

#endif