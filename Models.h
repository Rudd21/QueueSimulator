#pragma once
#include <string>

struct Client
{
	std::string name;
	std::string type;
	int complexity;
	int patienceTime;
};

struct Operator
{
	std::string name;
	int qualification;
	int experience;
	int withoutBreak;
};