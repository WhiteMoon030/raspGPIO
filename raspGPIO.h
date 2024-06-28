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
#define GPIO_EXPORT_PATH "/sys/class/gpio/export"
#define GPIO_UNEXPORT_PATH "/sys/class/gpio/unexport"
#define GPIO_PIN_PATH "/sys/class/gpio/gpio"
#define PATH_LENGTH 35
#define PIN_LENGTH 3
#define TYPE_LENGTH 2

// ---- Enums ----
typedef enum GPIO_PIN{
    GPIO_PIN_1 = 1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15,
    GPIO_PIN_16,
    GPIO_PIN_17,
    GPIO_PIN_18,
    GPIO_PIN_19,
    GPIO_PIN_20,
    GPIO_PIN_21,
    GPIO_PIN_22,
    GPIO_PIN_23,
    GPIO_PIN_24,
    GPIO_PIN_25,
    GPIO_PIN_26,
}GPIO_PIN;

typedef enum GPIO_TYPE{
    INPUT,
    OUTPUT
}GPIO_TYPE;

typedef enum GPIO_LEVEL{
    LOW,
    HIGH
}GPIO_LEVEL;

// ---- Funktionen ----
// Generische Funktion für das "behandeln" von Fehlern
void handleError(const char* msg);

// Generische Funktion zum beschreiben von Dateien
void writeToFile(const char* path, const char* value);

// Aktivieren von GPIO-Pins
void pinMode(const GPIO_PIN pin, const GPIO_TYPE type);

// Löscht Einstellungen eines bestimmten GPIO-Pins
void clearPin(const GPIO_PIN pin);

// Setzt einen Pin auf einen bestimmten Wert
void setPin(const GPIO_PIN pin, const GPIO_LEVEL level);

#endif
