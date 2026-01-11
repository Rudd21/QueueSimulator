#pragma once

void listOperators();

void createOperator(const int& operatorId, const std::string& name, const int& qualification, const int& experience, const int& withoutBreak);

void generateRandomClient(int& clientId);

void createClient(const int& clientId, const std::string& name, const std::string& type, const int& complexity, const int& patienceTime,const int& operatingBy);

void manageClient();

void processOperator();

int calculateServiceTime(const Client& c, const Operator& op);

void clientPatienceTime();