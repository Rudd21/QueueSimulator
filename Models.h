#pragma once
#include <string>

struct Client
{
	int clientId;
	std::string name;
	std::string type;
	int complexity;
	int patienceTime;
	int operatingBy;
};

struct Operator
{
	int operatorId;
	std::string name;
	int qualification;
	int experience;
	int withoutBreak;

	Client currentClient;
	bool isBusy = false;
	int remainingTime = 0;
	int currentClientId = -1;
};