
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

/*
	To use the config reader.
*/

template<typename T>
class ConfigKey
{
public:
	const char* name;
	T data;
};

static class ConfigReader
{
public:
	static void SetFloat(const char* name, float data);
	static void SetString(const char* name, float data);
	static void SetInt(const char* name, int data);

private:
};