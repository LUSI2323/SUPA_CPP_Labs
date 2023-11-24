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
std::string fileName_err="error2D_float.txt"; //name of the file to be imported (errrors)
int len;

 
//////MAIN///////////////////////
int main(){
   //store data in the X and Y vector
    std::pair< std::vector<float>, std::vector<float> > Data = storeData(fileName);
    len=Data.first.size();
    //store x and y errors in vectors
    std::pair< std::vector<float>, std::vector<float> > errData = storeData(fileName_err);
    //print n (user input) data
    printData(Data.first,Data.second,len);
    //switch to decide which function to execute
    bool go=true;
    int s;
    while(go){
        std::cout<<"Do you want to exit (0), calculate magnitude (1), perform a least squares fitting (2) or calculate x^y (3)" <<std::endl;
        std::cout<<"Please choose between 0, 1, 2 or 3\n";
        std::cin>>s;
        
        switch(s){
            case 0: {
                std::cout<<"Exiting loop..."<<std::endl;
                go=false; //finish loop
                break;
            }
            case 1:{
                std::cout<<"Calculating magnitude..."<<std::endl;
                std::vector<float> magVector; //vector to store the magnitudes
                magVector=calculateMagnitude(Data.first,Data.second);
                printData(magVector,len);
                break; //go back to orginal question
            }
            case 2: {
                std::cout<<"Performing least squares fitting..."<<std::endl;
                leastSquaresFitting(Data.first,Data.second,errData.second);
                break; //go back to orginal question
            }
            case 3:{
                std::cout<<"Calculating x^y..."<<std::endl;
                std::vector<float> xToY;
                for (int i=0;i<len;i++){
                    //Converting y to closer integer
                    int y=static_cast<int>(Data.second[i]);
                    float x=Data.first[i];
                    float xP=xPowerY(x,y); //recursive
                    //now x should be changed into x^y, I put it in the vector
                    xToY.push_back(xP);
                    }
                //now let's save to a file the values
                std::string outputName="XPowerY.txt";
                std::string title="X^y:";
                saveData(outputName,title,xToY);
                break; //go back to orginal question
            }
            default:{
                std::cout<<"You did not choose a valid integer, try again..."<<std::endl;
                break;
            }
        }
    }
    return 0;
}

