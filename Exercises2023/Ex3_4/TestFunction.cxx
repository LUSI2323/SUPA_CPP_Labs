//created by Lucia Barbieri on 8/12/23
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

//my functions
#include "FiniteFunctions.h"
#include "CustomFunctions.h"

int main(){
    //read data from MysteryData03122.txt
    std::ifstream mysteryDataFile("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex3_4/Outputs/data/MysteryData03122.txt");
    if (!mysteryDataFile.is_open()) {
        std::cerr << "Cannot open MysteryData file." << std::endl;
        return 1;
    }
    std::vector<double> dataPoints; //fill the vector with the data from MysteryData
    double point; //to temporarely store each read value
    while (mysteryDataFile >> point) { //the operator >> read in the file each value(point)
        dataPoints.push_back(point);
    }
    mysteryDataFile.close();

     //////////////Testing DefaultDistribution
    std::cout<<"******Test 1******"<<std::endl;
    //create an instance of FiniteFunction named myFunction
    FiniteFunction myFunction; //empty constructor so it will use (-5,5,DefaultFunction)

    myFunction.printInfo();

    //////////////Testing NormalDistribution
    std::cout<<"******Test 2******"<<std::endl;
    double mu = 1.0;
    double sigma = 1.5;
    NormalFunction myNormalFunction(-10.0, 10.0, mu, sigma, "NormalDistribution");

    
    myNormalFunction.printInfo();

    //////////////Testing Cauchy lorentz Distribution
    std::cout<<"******Test 3******"<<std::endl;
    double x0 = 1.0;
    double gamma = 1.0;
    double sigma2 = 1.6;
    CauchyLorentzFunction myCauchyLorentzFunction(-10.0, 10.0, x0, gamma, sigma2, "CauchyLorentzDistribution");

    myCauchyLorentzFunction.printInfo();

    //////////////Testing NegativeCrystalBallDistribution
    std::cout<<"******Test 4******"<<std::endl;
    double xbar = 1.0;
    double sigma3 = 1.5;
    double n =5.0; //n>1
    double alpha = 10.0; //>0
    NegativeCrystalBallFunction myNegativeCrystalBallFunction(-10.0, 10.0, xbar, sigma3, n, alpha, "NegativeCrystalBallDistribution");

    myNegativeCrystalBallFunction.plotFunction();
    myNegativeCrystalBallFunction.plotData(dataPoints, 500, true); 
    myNegativeCrystalBallFunction.printInfo();

 std::cout<<"******Sampling******"<<std::endl;
 std::vector<double> sampledDefaultData;
 std::vector<double> sampledNormalData;
 std::vector<double> sampledCauchyData;
 std::vector<double> sampledNegativeCrystalBallData;

 //sampled data for each distribution
myFunction.sampleMetropolis(&sampledDefaultData);
myNormalFunction.sampleMetropolis(&sampledNormalData);
myCauchyLorentzFunction.sampleMetropolis(&sampledCauchyData);
myNegativeCrystalBallFunction.sampleMetropolis(&sampledNegativeCrystalBallData);

myFunction.plotFunction(); //plot the function f(x)
myFunction.plotData(dataPoints, 500, true); //plot data points from MysteryData03122
myFunction.plotData(sampledDefaultData, 200, false);

myNormalFunction.plotFunction(); // plot the function f(x) for NormalDistribution
myNormalFunction.plotData(dataPoints, 500, true); // plot data points for NormalDistribution
myNormalFunction.plotData(sampledNormalData, 200, false);
    
myCauchyLorentzFunction.plotFunction(); 
myCauchyLorentzFunction.plotData(dataPoints, 500, true); 
myCauchyLorentzFunction.plotData(sampledCauchyData, 200, false);

myNegativeCrystalBallFunction.plotFunction(); // plot the function f(x) for NormalDistribution
myNegativeCrystalBallFunction.plotData(dataPoints, 500, true); // plot data points for NormalDistribution
myNegativeCrystalBallFunction.plotData(sampledNegativeCrystalBallData, 200, false);

return 0;
}

