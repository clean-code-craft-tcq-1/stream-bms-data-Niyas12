#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "BMS_Sender.h"
#include <chrono>
#include <thread>

using namespace std;

class BMS_parameters
{
	int SOC;
	int temeperature;

public:
	int generate_random_value(int min_value, int max_value)
	{
		return (rand() % (min_value - max_value + 1)) + min_value;
	};

	int get_temperature()
	{
		return generate_random_value(MIN_TEMP,MAX_TEMP);
	}

	int get_soc()
	{
		return generate_random_value(MIN_SOC, MAX_SOC);
	}

};

class Data_generator
{
	BMS_parameters parameters;

public:

	stringstream prepare_data()
	{		
		stringstream data;
		data << "{\"Temperature\": " << parameters.get_temperature() << " ,\"SOC\": " << parameters.get_soc() << " }\n";
		return data;
	}

};

int main()
{
	Data_generator streamer;

	for (int index = 0;index < 10; index++)
	{
		cout << streamer.prepare_data().str();
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	return 0;
}