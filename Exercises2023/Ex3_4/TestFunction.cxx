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
    myFunction.plotFunction(); //plot the function f(x)
    myFunction.plotData(dataPoints, 50, true); //plot data points from MysteryData03122
    myFunction.printInfo();

    //////////////Testing NormalDistribution
    std::cout<<"******Test 2******"<<std::endl;
    double mu = 1.0;
    double sigma = 1.5;
    NormalFunction myNormalFunction(-5.0, 7.0, mu, sigma, "NormalDistribution");

    myNormalFunction.plotFunction(); // plot the function f(x) for NormalDistribution
    myNormalFunction.plotData(dataPoints, 70, true); // plot data points for NormalDistribution
    myNormalFunction.printInfo();

    //////////////Testing Cauchy lorentz Distribution
    std::cout<<"******Test 3******"<<std::endl;
    double x0 = 1.0;
    double gamma = 1.0;
    double sigma2 = 1.6;
    CauchyLorentzFunction myCauchyLorentzFunction(-5.0, 7.0, x0, gamma, sigma2, "CauchyLorentzDistribution");

    myCauchyLorentzFunction.plotFunction(); // plot the function f(x) for NormalDistribution
    myCauchyLorentzFunction.plotData(dataPoints, 50, true); // plot data points for NormalDistribution
    myCauchyLorentzFunction.printInfo();

    //////////////Testing NegativeCrystalBallDistribution
    std::cout<<"******Test 4******"<<std::endl;
    double xbar = 1.0;
    double sigma3 = 1.5;
    double n =5.0; //n>1
    double alpha = 10.0; //>0
    NegativeCrystalBallFunction myNegativeCrystalBallFunction(-10.0, 12.0, xbar, sigma3, n, alpha, "NegativeCrystalBallDistribution");

    myNegativeCrystalBallFunction.plotFunction(); // plot the function f(x) for NormalDistribution
    myNegativeCrystalBallFunction.plotData(dataPoints, 100, true); // plot data points for NormalDistribution
    myNegativeCrystalBallFunction.printInfo();

    return 0;
}

