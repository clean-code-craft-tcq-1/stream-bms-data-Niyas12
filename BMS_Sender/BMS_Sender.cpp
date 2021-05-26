#include <cstdio>
#include <cstdlib>

class BMS_parameters
{
	int SOC;
	int temeperature;

public:
	void generate_parameters()
	{
		SOC = rand() % 100 + 1;
		temeperature = rand() % 100 + 1;
	};

	int get_temperature()
	{
		return temeperature;
	}

	int get_soc()
	{
		return SOC;
	}

};

class Data_streamer
{
	BMS_parameters parameters;

public:

	void stream_console()
	{
		parameters.generate_parameters();
		printf("soc: %d, temperature: %d \n", parameters.get_soc(), parameters.get_temperature());
	}

};

int main()
{
	Data_streamer streamer;

	streamer.stream_console();


	return 0;
}