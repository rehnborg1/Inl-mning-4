#ifndef CAR_H_
#define CAR_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/********************************************************************************
* car_transmission: Enumeration f�r val av transmission (manuell/automat)
********************************************************************************/
enum car_transmission
{
	CAR_TRANSMISSION_MANUAL,
	CAR_TRANSMISSION_AUTOMATIC
};

/********************************************************************************
* car: Strukt f�r lagring av bilrelaterad data. 
********************************************************************************/
struct car
{
	char* brand;
	char* model;
	char* colour;
	unsigned int year_of_launch;
	enum car_transmission transmission;

};

/********************************************************************************
* car_init: Initieringsrutin/konstruktor f�r givet car-objekt, d�r ovanst�nde
*			parametrar passeras tillsammans med en pekare till car-objektet.
*			Denna funktion skall utg�ra ett alternativ till direkt initiering
*			n�r ett objekt skapas.
********************************************************************************/
void car_init(struct car* self, 
			  char* brand, 
			  char* model, char* colour, 
			  unsigned int year_of_launch, 
			  enum car_transmission transmission);

/********************************************************************************
* car_clear: Nollst�ller givet car-objekt. Samtliga parametrar s�tts till 0,
*			 nullpekare eller liknande).
********************************************************************************/
void car_clear(struct car* self);

/********************************************************************************
* car_new: Returnerar en pekare till ett heapallokerat car-objekt, som initieras
*		   via funktionen car_init.
********************************************************************************/
struct car* car_new(char* brand, 
					char* model, 
					char* colour, 
					unsigned int year_of_launch, 
					enum car_transmission transmission);

/********************************************************************************
* car_delete:	 Raderar angivet car-objekt genom att frig�ra dynamiskt
*                allokerat minne f�r denna och s�tter motsvarande pekare till
*                null. F�r att m�jligg�ra detta passeras adressen till den pekare
*                som pekar p� det dynamiskt allokerade minnet.
*
*                - self: Adressen till den pekare som pekar p� objektet som
*                        som ska raderas.
********************************************************************************/
void car_delete(struct car** self);

/********************************************************************************
* car_print:	Skriver ut lagrad bildata via angiven utstr�m, d�r
*               standardutenheten stdout anv�nds som default f�r utskrift
*               i terminalen.
*
*               - self   : Pekare till objektet som lagrar bildatan.
*               - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void car_print(struct car* self, FILE* ostream);

/********************************************************************************
* car_change_colour: Byter f�rg p� bilen via pekare.
********************************************************************************/
void car_change_colour(struct car* self, char* colour);

/********************************************************************************
* car_change_transmission: Byter bilens transmission (manuell/automat)
********************************************************************************/
void car_change_transmission(struct car* self, bool transmission);

/********************************************************************************
* file_read: L�ser inneh�llet fr�n angiven fils�kv�g rad f�r rad och skriver
*            ut i terminalen.
*
*            - filepath: Pekare till fils�kv�gen d�r l�sning skall ske.
********************************************************************************/
void file_read(const char* filepath);


#endif CAR_H_