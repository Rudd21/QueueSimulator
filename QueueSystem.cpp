#include <iostream>
#include <vector>

#include "Models.h"
#include "QueueSystem.h"

std::string arrayOfNames[] = { "Taras", "James", "Adrian", "Yulian", "Vadim", "Yaroslav", "Enzo", "Fernando" };
std::string arrayOfTypes[] = { "Regular", "First-time", "VIP" };
int arrayOfComplexity[] = { 1, 2, 3 };
int arrayOfPatience[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

std::vector<Client> clients;
std::vector<Client> vipClients;

std::vector<Operator> operators;
bool isOperator = false;

void createOperator(const int& operatorId,const std::string& name, const int& qualification, const int& experience, const int& withoutBreak) {
	Operator o{operatorId ,name, qualification, experience, withoutBreak };

	operators.push_back(o);
	std::cout << "Added new operator: " << o.name << std::endl;
	isOperator = true;
};

void listOperators() {
	createOperator(1, "Denis", 2, 5, 2);
	createOperator(2, "Yurii", 4, 7, 3);
	createOperator(3, "Vitalii", 3, 3, 0);
}

void printQueue(const std::vector<Client>& queue, const std::string& title) {
	std::cout << title << " list:" << std::endl;

	for (const Client& c : queue) {
		std::cout
			<< "Name: " << c.name
			<< ", Type: " << c.type
			<< ", Complexity: " << c.complexity
			<< ", Patience: " << c.patienceTime << std::endl;
	};
};

void generateRandomClient(int& clientId) {
	int randomName = std::rand() % 8;
	int randomType = std::rand() % 3;
	int randomComplexity = std::rand() % 3;
	int randomPatience = std::rand() % 10;

	createClient(clientId, 
				arrayOfNames[randomName],
				arrayOfTypes[randomType],
				arrayOfComplexity[randomComplexity],
				arrayOfPatience[randomPatience],
				0);
}

void createClient(const int& clientId,const std::string& name, const std::string& type, const int& complexity, const int& patienceTime, const int& operatingBy) {
	Client c{ clientId, name, type, complexity, patienceTime, operatingBy };

	if (c.type == "VIP") {
		vipClients.push_back(c);
		printQueue(vipClients, "VIP clients");
	}
	else {
		clients.push_back(c);
		printQueue(clients, "Regular clients");
	}

};

void assignClientToOperator(Operator& op, const Client& c) {
	op.currentClient = c;
	op.remainingTime = calculateServiceTime(c, op);
	op.isBusy = true;
};

void releaseOperator(Operator& op) {
	std::cout << "--------------------------" << std::endl
		<< "Client name/id: " << op.currentClient.name << "/" << op.currentClient.clientId << ", Operated by: " << op.name << std::endl
		<< "--------------------------" << std::endl;

	op.remainingTime = 0;
	op.isBusy = false;
};

void manageClient() {
	for (Operator& op : operators) {

		if (op.isBusy) continue;

		if (!vipClients.empty()) {

			assignClientToOperator(op, vipClients.front());
			vipClients.erase(vipClients.begin());

		}
		else if (!clients.empty()) {

			assignClientToOperator(op, clients.front());
			clients.erase(clients.begin());

		};
	};
};

void processOperator() {
	for (Operator& op : operators) {

		if (!op.isBusy) continue;

		op.remainingTime--;
		op.withoutBreak++;

		if (op.remainingTime <= 0) {
			releaseOperator(op);
		};

	};
};

int calculateServiceTime(const Client& c, const Operator& op) {
	int baseTime = c.complexity * 3;
	int operatorSkill = op.qualification + op.experience;
	int debaufBreak = op.withoutBreak;

	int time = baseTime - operatorSkill + debaufBreak;

	if (time < 1) time = 1;

	return time;
};
