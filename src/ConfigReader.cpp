#include "ConfigReader.h"

void ConfigReader::SetFloat(const char* name, float data)
{
	string content;
	ifstream cfgFile;
	cfgFile.open("westmac.ini", ios::in);

	if (cfgFile.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(cfgFile)),
			(std::istreambuf_iterator<char>()));
	}
	else { throw std::exception("westmac.ini not found"); }
}

void ConfigReader::SetInt(const char* name, int data)
{
	string content;
	ifstream cfgFile;
	cfgFile.open("westmac.ini", ios::in);

	if (cfgFile.is_open())
	{
		std::string content((std::istreambuf_iterator<char>(cfgFile)),
			(std::istreambuf_iterator<char>()));
	}
	else { throw std::exception("westmac.ini not found"); }
}