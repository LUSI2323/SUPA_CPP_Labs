//Assignment 1 created by Lucia Barbieri on 21/11/23
#pragma once

std::pair<std::vector<float>, std::vector<float> > storeData(std::string); //store data in vectors X and Y

void selectLines(int&, int); //select number of lines to be printed

int printData(std::vector<float>, std::vector<float>,int); //print the data on terminal-case 2 vectors + int for file length
int printData(std::vector<float>, int); //print the data on terminal-case 1 vector + int for file length
int printData(float, float, float); //print the data on terminal-case 3 float

//save data overloads
int saveData(std::string,float, float, float); //fitting function and chi squared
int saveData(std::string, std::string, std::vector<float> ); //magnitudes or x^y

std::vector<float> calculateMagnitude(std::vector<float>, std::vector<float>); //calculate magnitude of data

int leastSquaresFitting(std::vector<float>, std::vector<float>, std::vector<float>); //perform least squares fitting on data

float xPowerY(float x, int y); //calculate x^y (recursive)

