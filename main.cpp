#include <iostream>
#include <vector>

#include "Models.h";
#include "QueueSystem.h"

int main(){
	createClient("Taras", "Regular", 1, 0);

	printClient(getClient(0));

	return 0;
}