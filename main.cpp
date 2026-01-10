#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#include "Models.h";
#include "QueueSystem.h"

int main(){
	std::srand(std::time(nullptr));
	int clientId = 0;
	listOperators();

	// Generate Clients
	while (true) {
		
		generateRandomClient(clientId);
		manageClient();
		processOperator();
		
		clientId++;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}