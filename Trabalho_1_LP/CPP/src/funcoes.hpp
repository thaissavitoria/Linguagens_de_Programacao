#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std;

void leArquivo(vector<vector<double>> matrixCalc,vector<vector<double>> identidade); //Le o arquivo e gera a matriz com todos os dados
int matrizInversa(vector<vector<double>> matrixCalc,vector<vector<double>> identidade); //
void print(vector<vector<double>>matrix);

#endif