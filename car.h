#ifndef CAR_H_
#define CAR_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/********************************************************************************
* car_transmission: Enumeration för val av transmission (manuell/automat)
********************************************************************************/
enum car_transmission
{
	CAR_TRANSMISSION_MANUAL,
	CAR_TRANSMISSION_AUTOMATIC
};

/********************************************************************************
* car: Strukt för lagring av bilrelaterad data. 
********************************************************************************/
struct car
{
	char* brand;
	char* model;
	char* colour;
	unsigned int year_of_launch;
	enum car_transmission transmission;

	/********************************************************************************
	* print:	Skriver ut lagrad bildata via angiven utström, där
	*               standardutenheten stdout används som default för utskrift
	*               i terminalen.
	*
	*               - self   : Pekare till objektet som lagrar bildatan.
	*               - ostream: Pekare till angiven utström (default = stdout).
	********************************************************************************/
	void (*print)(struct car* self,
				  FILE* ostream);

	/********************************************************************************
	* change_colour: Byter färg på bilen via pekare.
	********************************************************************************/
	void (*change_colour)(struct car* self, 
						  char* colour);

	/********************************************************************************
	* change_transmission: Byter bilens transmission (manuell/automat)
	********************************************************************************/
	void (*change_transmission)(struct car* self, bool transmission);
};

/********************************************************************************
* car_init: Initieringsrutin/konstruktor för givet car-objekt, där ovanstënde
*			parametrar passeras tillsammans med en pekare till car-objektet.
*			Denna funktion skall utgöra ett alternativ till direkt initiering
*			när ett objekt skapas.
********************************************************************************/
void car_init(struct car* self, 
			  char* brand, 
			  char* model, char* colour, 
			  unsigned int year_of_launch, 
			  enum car_transmission transmission);

/********************************************************************************
* car_clear: Nollställer givet car-objekt. Samtliga parametrar sätts till 0,
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
* car_delete:	 Raderar angivet car-objekt genom att frigöra dynamiskt
*                allokerat minne för denna och sätter motsvarande pekare till
*                null. För att möjliggöra detta passeras adressen till den pekare
*                som pekar på det dynamiskt allokerade minnet.
*
*                - self: Adressen till den pekare som pekar på objektet som
*                        som ska raderas.
********************************************************************************/
void car_delete(struct car** self);

/********************************************************************************
* car_print:	Skriver ut lagrad bildata via angiven utström, där
*               standardutenheten stdout används som default för utskrift
*               i terminalen.
*
*               - self   : Pekare till objektet som lagrar bildatan.
*               - ostream: Pekare till angiven utström (default = stdout).
********************************************************************************/
void car_print(struct car* self, FILE* ostream);

/********************************************************************************
* car_change_colour: Byter färg på bilen via pekare.
********************************************************************************/
void car_change_colour(struct car* self, char* colour);

/********************************************************************************
* car_change_transmission: Byter bilens transmission (manuell/automat)
********************************************************************************/
void car_change_transmission(struct car* self, bool transmission);

/********************************************************************************
* file_read: Läser innehållet från angiven filsökväg rad för rad och skriver
*            ut i terminalen.
*
*            - filepath: Pekare till filsökvägen där läsning skall ske.
********************************************************************************/
void file_read(const char* filepath);


#endif CAR_H_
