#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "../BMS_Sender/BMS_Sender.h"


TEST_CASE("infers the breach according to limits") {
	
	Data_generator generator;
	std::stringstream data = generator.prepare_data();

	std::string parameters[5];
	for (int i = 0;i < 5;i++)
		data >> parameters[i];

	int temperature = atoi(parameters[1].c_str());
	int soc = atoi(parameters[3].c_str());

}
