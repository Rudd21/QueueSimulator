#pragma once

void createClient(const std::string& name, const std::string& type, const int& complexity, const int& patienceTime);

void printClient(const Client& c);

const Client& getClient(int index);

void printClient();

void reqClient();

void inClient();

void addApplication();

void outClient();
