#include <iostream>
#include <chrono>
#include <thread>
#include "BMS_Sender.h"


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