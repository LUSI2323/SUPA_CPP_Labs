//Assignment 1 created by Lucia Barbieri on 21/11/23
#ifndef CUSTOMFUNCTIONS_H
#define CUSTOMFUNCTIONS_H

#include <vector>
#include <string>

std::pair<std::vector<float>, std::vector<float> > storeData(std::string); //store data in vectors X and Y

int printData(std::vector<float>, std::vector<float>); //print the data on terminal

std::vector<float> calculateMagnitude(std::vector<float>, std::vector<float>); //cslculate magnitude of data

int leastSquaresFitting(std::vector<float>, std::vector<float>); //perform least suare fitting on data

#endif

