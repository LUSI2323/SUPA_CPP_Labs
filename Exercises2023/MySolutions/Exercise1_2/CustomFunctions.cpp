//Assignment 1 created by Lucia Barbieri on 21/11/23
//libraries import
#include <iostream>
#include <fstream>
#include <sstream> //to parse my lines
#include <vector>
#include <string>
#include <cmath>


//function to store the two columns of my txt file into two vectors, print the values, and return the two vectors
//NOTE: I used std::pair to return two vectors, X and Y, from my function

std::pair<std::vector<float>, std::vector<float> > storeData(std::string fileName){
    std::ifstream inputFile(fileName); // initialize the input file
    
    if (!inputFile) { //Prompt error message if file cannot be opened
        std::cerr << "Error: cannot open your txt file.\n"; //\n alternative way to go to new line
        }
    
    std::string line; //declare the variable that will associate each row in the file to a string
    std::string token; //token are the 'pieces' in a line separated by a delimiter, in my case the comma
    std::vector<float> X, Y; //declare X and Y vectors
    std::vector<float> values; //to store tokens, then distributed in the two x and Y vectors
    int tokenCounter=0; //counter to skip first two tokens
    
    while (std::getline(inputFile,line)){ // parsing through the line
        
        std::stringstream ss(line); //initialize the stream continaing the string line
        std::vector<float> values; //to store tokens, then distriuted in the two x and Y vectors
        
        while (std::getline(ss, token, ',')) { //parsing the line
            tokenCounter++;
        if (tokenCounter > 2) { // Check if tokenCounter is beyond the first two tokens
            values.push_back(std::stof(token));
                }
            if (values.size() >= 2) {
                    X.push_back(values[0]); //store x value
                    Y.push_back(values[1]); //store y value
                    }
                }
       
            }
    inputFile.close();
    return std::make_pair(X, Y); //I can then refer to X as Data.first and to Y as Data.second
    
}

//function to select the number of lines to be printed: it takes N by reference and change it to the selected value
void selectLines(int& N, int len){
    //select the number of lines to be printed (n) and check is less than the length of the file
    int n;
    std::cout<<"How many lines do you want to print?"<<std::endl;
    std::cin>>n; //ask for number of lines and take the user value
    std::cout<<"You have chosen to print "<<n<<" lines"<<std::endl;
    if (n>len){
        N=5;
        std::cout<<"Sorry, the file has less than "<<n<<" lines: printing the first "<<N<<" instead!"<<std::endl;
    }
    else {
        N=n;
    }
}


//function to print (argument:2 vectors)
int printData(std::vector<float> X, std::vector<float> Y, int len){
    //call the function to select the number of lines to be printed
    int N=0; //initialize to 0
    selectLines(N,len);
    //actually print
    for (int i=0;i<N;i++){
            std::cout<<"Line number "<<i<<": x= "<<X[i]<<" and y= "<<Y[i]<<std::endl;
        }
    return 0;
}


//function to print (argument:1 vector)-overload
int printData(std::vector<float> mv, int len){
    //call the function to select the number of lines to be printed
    int N=0; //initialize to 0
    selectLines(N,len);
    for (int i=0;i<N;i++){
        std::cout<<"Magnitude of vector in row "<<i<<" is "<<mv[i]<<std::endl;
    }
    return 0;
}


//function to print (argument:2 floats)-overload
int printData(float m, float c, float chi){
    std::cout<<"The function obtained from least square fitting is\n";
    std::cout<<"y= "<<m<<"x + "<<c<<std::endl;
    std::cout<<"The chi squared is "<<chi<<std::endl;
    return 0;
}

//functions to save data to a file
//write magnitudes to a file- overload, case 1 string (file name), 1 string(quantity that is saved- magnitude or x^y),  1 vector (Vector will be either the magnitude vector or the x^y vector!
int saveData(std::string outputName,std::string title, std::vector<float> Vector){
    std::ofstream outFile(outputName); //ofstream to write to a file
    if (outFile.is_open()) {
        outFile << title<<std::endl;
        for (int i=0;i<Vector.size();i++){
            outFile<<Vector[i]<< std::endl;
        }
       std::cout << "Results written to " << outputName<< std::endl;
    }
    else {
        std::cerr << "Error: I could not open the file for writing!" << std::endl;
        return 1;
    }
    outFile.close();
    return 0;
}
//write fit results to a file- overload, case 1 string,3  floats
int saveData(std::string outputName,float m, float c,float chiSquared){
    std::ofstream outFile(outputName); //ofstream to write to a file
    if (outFile.is_open()) {
        outFile << "The function obtained from least squares fitting is\n";
        outFile << "y= " << m << "x + " << c << std::endl;
        outFile << "with reduced Chi squared: " << chiSquared << std::endl;
        std::cout << "Results written to " << outputName<< std::endl;
    }
    else {
        std::cerr << "Error: I could not open the file for writing!" << std::endl;
        return 1;
    }
    outFile.close();
    return 0;
}

//function to calculate magnitude of the vector with x and y as components
std::vector<float> calculateMagnitude(std::vector<float> X, std::vector<float> Y){  //define the function
    // check X and Y have same dimensions
    if (X.size()!=Y.size()){
        std::cerr<<"Error: x and y data mismatch!"<<std::endl;
        exit(1);
        }
    std::vector<float> magVector;
    for (int i=0;i<X.size();i++){
        float x=X[i];
        float y=Y[i];
        double mag= pow((x*x+y*y),0.5);
        magVector.push_back(mag);
        }
    std::string outputName="Magnitudes.txt";
    std::string title="Magnitude:";
    saveData(outputName,title,magVector);
    return magVector;
}


//function for least squares linear fitting
//function: y=mx+c
int leastSquaresFitting(std::vector<float> X, std::vector<float> Y, std::vector<float> errY){
    int N=X.size();
    //initialize individual pieces
    double xsum=0;
    double ysum=0;
    double xy=0;
    double xx=0;
    for (int i=0;i<N;i++){
        xsum+=X[i];
        ysum+=Y[i];
        xy+=X[i]*Y[i];
        xx+=X[i]*X[i];
    }
    double m=(N*xy-(xsum*ysum))/(N*xx-(xsum*xsum));
    double c= (xx*ysum-(xy*xsum))/(N*xx-(xsum*xsum));
    //calculate Chi Squared
    float chiSquared;
    for (int i=0;i<N;i++){
        chiSquared+=pow((Y[i]-(m*X[i]+c)),2)/(errY[i]*errY[i]);
    }
    //print to terminal
    int parNum=2; //parameters for linear fitting
    chiSquared/=(N-parNum);
    printData(m,c,chiSquared);
    std::string outputName="LeastSquaresFittingResults.txt";
    saveData(outputName,m,c,chiSquared);
    return 0;
}

//function to calculate x^y
float xPowerY(float x, int y) {
    if (y == 0) {
        return 1;
    } 
    else {
        return x * xPowerY(x, y - 1);
    }
}
