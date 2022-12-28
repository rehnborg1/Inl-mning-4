#include "car.h"

/********************************************************************************
* car_init:	   Lagrar angivna bil-attribut i ett car-objekt.
*
*         - self		     : Pekare till objektet som ska lagra uppgifterna.
*         - brand		     : Bilens m�rke.
*         - model		     : Bilens modell.
*         - colour		     : Bilens f�rg.
*         - year_of_launch   : �ret bilen kom.
*         - car_transmission : Bilens transmissionstyp (manuell/automat) 
*							   som en enumerator av enumerationen car_transmission.
********************************************************************************/

void car_init(struct car* self,
	char* brand,
	char* model,
	char* colour,
	unsigned int year_of_launch,
	enum car_transmission transmission)
{
	self->brand = brand;
	self->model = model;
	self->colour = colour;
	self->year_of_launch = year_of_launch;
	self->transmission = transmission;

	return;
}

/********************************************************************************
* car_clear: Nollst�ller bildata lagrat av angivet car-objekt.
*
*               - self: Pekare till objektet som ska nollst�llas.
********************************************************************************/

void car_clear(struct car* self)
{
	self->brand = 0;
	self->model = 0;
	self->colour = 0;
	self->year_of_launch = 0;
	self->transmission = 0;

	return;
}

/********************************************************************************
* car_new: Allokerar minne och lagrar angiven persondata i ett car-objekt.
*             En pekare till det dynamiskt allokerade objektet returneras.
*             Om minnesallokeringen misslyckas s� returneras null.
*
*         - brand		     : Bilens m�rke.
*         - model		     : Bilens modell.
*         - colour		     : Bilens f�rg.
*         - year_of_launch   : �ret bilen kom.
*         - car_transmission : Bilens transmissionstyp (manuell/automat)
*							   som en enumerator av enumerationen car_transmission.
********************************************************************************/

struct car* car_new(char* brand,
	char* model,
	char* colour,
	unsigned int year_of_launch,
	enum car_transmission transmission)
{
	struct car* self = (struct car*)malloc(sizeof(struct car));
	if (!self) return 0;
	car_init(self, brand, model, colour, year_of_launch, transmission);
	return self;
}

/********************************************************************************
* car_delete:	 Raderar angivet car-objekt genom att frig�ra dynamiskt
*                allokerat minne f�r denna och s�tter motsvarande pekare till
*                null. F�r att m�jligg�ra detta passeras adressen till den pekare
*                som pekar p� det dynamiskt allokerade minnet.
*
*                - self: Adressen till den pekare som pekar p� objektet som
*                        som ska raderas.
********************************************************************************/

void car_delete(struct car** self)
{
	free(*self);
	*self = 0;
	return;
}

/********************************************************************************
* car_print:	Skriver ut lagrad bildata via angiven utstr�m, d�r
*               standardutenheten stdout anv�nds som default f�r utskrift
*               i terminalen.
*
*               - self   : Pekare till objektet som lagrar bildatan.
*               - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/

void car_print(struct car* self, FILE* ostream)
{
	if (!ostream) ostream = stdout;

	fprintf(ostream, "--------------------------------------------------------------------------------\n");
	fprintf(ostream, "Brand:\t\t %s \n", self->brand);
	fprintf(ostream, "Model:\t\t %s \n", self->model);
	fprintf(ostream, "Colour:\t\t %s \n", self->colour);
	fprintf(ostream, "Year of launch:\t %d \n", self->year_of_launch);
	if (self->transmission == CAR_TRANSMISSION_MANUAL)
	{
		fprintf(ostream, "Transmission: \t Manual\n");
	}
	else if (self->transmission == CAR_TRANSMISSION_AUTOMATIC)
	{
		fprintf(ostream, "Transmission: \t Automatic\n");
	}
	fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
	return;
}

/********************************************************************************
* car_change_colour: Byter f�rg p� bilen via pekare.
********************************************************************************/

void car_change_colour(struct car* self, char* colour)
{
	self->colour = colour;
	return;
}

/********************************************************************************
* car_change_transmission: Byter bilens transmission fr�n manuell-automat, 
*						   automat-manuell.
********************************************************************************/

void car_change_transmission(struct car* self, bool transmission)
{
	if (self->transmission == 1)
	{
		self->transmission = 0;
	}
	else if (self->transmission == 0)
	{
		self->transmission = 1;
	}
	return;
}

/********************************************************************************
* file_read: Funktion som �ppnar dokumentet cars.txt och skriver ut inneh�llet
*			 som str�ngar i terminalen. Funktionen slutar skriva ut n�r den
*			 kommit till en tom rad.
********************************************************************************/

void file_read(const char* filepath)
{
	FILE* istream = fopen(filepath, "r");

	if (!istream) return;

	char s[100] = { '\0' };

	while (fgets(s, sizeof(s), istream))
	{
		printf("%s", s);
	}

	fclose(istream);
	return;
}