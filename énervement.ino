#include <time.h>

#define button_pin 6

unsigned int enervement = 0;
unsigned long test_millis = 0;
int state = 0;

unsigned int croissance_enervement = 100;
unsigned int frequence_decroissance_enervement = 1000;
unsigned int decroissance_enervement = 10;

int random(int min = -1, int max = -1) {
	srand(time(NULL));

	if (min != -1 or max != -1)
	{
		
		return (rand() % (max - min + 1)) + min;
	}
	else
	{
		return rand();
	}
}

void action(int section_interval) {



}

int set_interval(int enervement) {

	if (enervement >= /*x_min*/ && enervement <= /*x_max*/)  // si enervement € [x_min ; x_max] alors :
	{
		return /*x*/; // x le numero de l'interval. (premier interval : x = 1. deuxiemme interval : x = 2. etc...)
	}


}

void setup() {
	pinMode(button_pin, OUTPUT);
	digitalWrite(button_pin, true);
}

void loop() {
 int state = !digitalRead(button_pin);
 
 if (state == 1)
	{	 
		enervement += croissance_enervement;
		test_millis = millis() + frequence_decroissance_enervement;
	}

	else
	{
		if (enervement > 0 && test_millis <= millis())
		{
			test_millis <= millis() + frequence_decroissance_enervement;
			enervement -= croissance_enervement;
		}
	}

	if (enervement > 0)
	{
		digitalWrite(13, false);
		action(set_interval(enervement));
	}

	else
	{
		digitalWrite(13, true);
	}
}
