#pragma once
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>

#define MAX_TEMP 100
#define MIN_TEMP 50

#define MAX_SOC 80
#define MIN_SOC 40


class BMS_parameters
{
public:
	int generate_random_value(int min_value, int max_value);
	int get_temperature();
	int get_soc();
};

class Data_generator
{
	BMS_parameters parameters;

public:

	std::stringstream prepare_data();

};