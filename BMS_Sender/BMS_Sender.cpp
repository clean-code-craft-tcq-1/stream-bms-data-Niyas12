#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "BMS_Sender.h"
#include <chrono>
#include <thread>

int BMS_parameters::generate_random_value(int min_value, int max_value)
{
	return (rand() % (min_value - max_value + 1)) + min_value;
}

int BMS_parameters::get_temperature()
{
	return generate_random_value(MIN_TEMP,MAX_TEMP);
}

int BMS_parameters::get_soc()
{
	return generate_random_value(MIN_SOC, MAX_SOC);
}

std::stringstream Data_generator::prepare_data()
{		
	std::stringstream data;
	data << "{\"Temperature\": " << parameters.get_temperature() << " ,\"SOC\": " << parameters.get_soc() << " }\n";
	return data;
}

int main()
{
	Data_generator streamer;

	for (int index = 0;index < 10; index++)
	{
		std::cout << streamer.prepare_data().str();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	return 0;
}