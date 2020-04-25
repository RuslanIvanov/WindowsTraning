#pragma once

using namespace std;

string& mytolowerString(std::string& st);
string& mytoupperString(std::string& st);
void writeToFile(const char* filename, const string& str);
void readFromFile(const char* filename, string& str);
void readWriteAndChangeFromFile(const string& filename);
void MyBeep(unsigned int F, unsigned int MC);
