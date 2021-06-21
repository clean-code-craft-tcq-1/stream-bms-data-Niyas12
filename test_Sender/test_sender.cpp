#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "../BMS_Sender/BMS_Sender.h"

bool validate_range(int value, int min, int max)
{
	return value >= min && value <= max;
}

TEST_CASE("validate json output") 
{	
	Data_generator generator;
	std::stringstream data = generator.prepare_data();

	std::string parameters[5];
	for (int i = 0;i < 5;i++)
		data >> parameters[i];

	int temperature = atoi(parameters[1].c_str());
	int soc = atoi(parameters[3].c_str());

	REQUIRE(validate_range(temperature, MIN_TEMP, MAX_TEMP));
	REQUIRE(validate_range(soc, MIN_SOC, MAX_SOC));
	REQUIRE(parameters[0] == "{\"Temperature\":");
	REQUIRE(parameters[2] == ",\"SOC\":");
}
