#include "car.h"

/********************************************************************************
* main: Lagrar uppgifter om tre bilar och skriver ut i terminalen
*       och till filen "cars.txt".
********************************************************************************/


int main(void)
{
	struct car car1, car2, car3;
	struct car* cars[] = { &car1, &car2, &car3 };

	FILE* ostream = fopen("cars.txt", "a");

	car_init(&car1, "Volvo", "V70", "Black", 1985, CAR_TRANSMISSION_MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, CAR_TRANSMISSION_AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, CAR_TRANSMISSION_MANUAL);

	for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
	{
		car_print(cars[i], ostream);
	}
	
	car_change_colour(&car3, "Green");
	car_change_transmission(&car3, CAR_TRANSMISSION_AUTOMATIC);
	car_print(&car3, ostream);		
	fclose(ostream);

	file_read("cars.txt");

	return 0;
}