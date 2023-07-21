#pragma once
#include <cstring>
#include <string> 
#include <fstream> 
#include "Header.h"
#include "Gerenatedata.h"
#include "Copydata.h"

bool checkAlgorithm1(string name[], int number,  string inputname1);
bool checkAlgorithm2(string name[], int number,  string inputname1, string inputname2); 

int getAlgoId(const char* algo_name); 
int getinputorderId(char* order_name);

void Comparison_inputfile(const char* filename, string name_algo1, string name_algo2); 
void Comparison_inputsize_order(string name_algo1, string name_algo2, int inputsize, char* inputorder); 