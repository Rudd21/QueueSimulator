#include <iostream>
#include <vector>

#include "Models.h"
#include "QueueSystem.h"

std::vector<Client> clients;

void createClient(const std::string& name, const std::string& type, const int& complexity, const int& patienceTime) {
	Client c{name, type, complexity, patienceTime };

	clients.push_back(c);
};

void printClient(const Client& c) {
	std::cout << "Name: " << c.name
		<< ", Type: " << c.type
		<< ", Complexity: " << c.complexity
		<< ", Patience: " << c.patienceTime << std::endl;
};

const Client& getClient(int index) {
	return clients[index];
}
