//Assignment 1 created by Lucia Barbieri on 21/11/23
//libraries import
#include <iostream>
#include <fstream>
#include <sstream> //to parse my lines
#include <vector>
#include <string>

//my prototypes' import
#include "/workspaces/SUPA_CPP_Labs/Exercises2023/MySolutions/Exercise1_2/CustomFunctions.h"

///INITIALIZATIONS OF GLOBAL VARIABLES
std::string fileName="input2D_float.txt"; //name of the file to be imported
std::vector<float> magVector; //vector to store the magnitudes

 
//////MAIN///////////////////////
int main(){
    std::pair< std::vector<float>, std::vector<float> > Data = storeData(fileName);
    std::string choice;
    std::cout<<"Do you want to print the values (p) or calculate the magnitude (m)?"<<std::endl;
    std::cin>>choice;
    if (choice=="p"){
        printData(Data.first,Data.second); //.first and .second referring to the component in the pair
    }
    else if (choice=="m"){
        magVector=calculateMagnitude(Data.first,Data.second);
    }
    else{
        std::cout<<"You should choose between p or m"<<std::endl;
    }
    
    std::cout<<"Calculating function for linear least squares fitting?"<<std::endl;
    leastSquaresFitting(Data.first,Data.second);
    
    
    
    return 0;
}

