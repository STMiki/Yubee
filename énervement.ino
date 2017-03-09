#define button_pin 6

int enervement = 0;
unsigned long test_millis = 0;
int state = 0;

unsigned int croissance_enervement = 100;
unsigned int interval_decroissance_enervement = 1000;
unsigned int decroissance_enervement = 10;

void setup() {
	pinMode(button_pin, OUTPUT);
	digitalWrite(button_pin, true);
}

void loop() {
 int state = !digitalRead(button_pin);
 
 if (state == 1)
	{	 
		enervement += croissance_enervement;
		test_millis = millis() + interval_decroissance_enervement;
	}

	else
	{
		if (enervement > 0 && test_millis <= millis())
		{
			test_millis <= millis() + interval_decroissance_enervement;
			enervement -= croissance_enervement;
		}
	}

	if (enervement > 0)
	{
		digitalWrite(13, false);
		//writeLed(test); // writeLed(tableau)
	}

	else
	{
		digitalWrite(13, true);
	}
}
