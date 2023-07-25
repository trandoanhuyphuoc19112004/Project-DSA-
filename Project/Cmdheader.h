#pragma once
#include <cstring>
#include <string> 
#include <fstream> 
#include "Header.h"
#include "Gerenatedata.h"
#include "Copydata.h"

//Check if algorithm exist
bool checkAlgorithm1(string name[], int number,  string inputname1);
bool checkAlgorithm2(string name[], int number,  string inputname1, string inputname2); 

//Get ID for algorithm and input order
int getAlgoId(const char* algo_name); 
int getinputorderId(char* order_name);
int getoutputparamID(char* param);

//Function for print information
string printInputOrder1(int order_index);

//Command line
void Command_Line_1(const char* filename, string name_algo, char* output_param);
void Command_Line_2(string name_algo, int inputSize, char* inputOrder, char* output_param);
void Command_Line_3(string name_algo, int input_size, char* output_parameter);
void Command_Line_4(const char* filename, string name_algo1, string name_algo2);
void Command_Line_5(string name_algo1, string name_algo2, int inputsize, char* inputorder);