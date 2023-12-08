#include <cmath>
#include <string>
#include <iostream>
#include <time.h>
#include <random>

int main(int argc, char *argv[]){
    if (argc < 3) {
          std::cout << "Usage: " << argv[0] << " <radius> <n_random>  \n";
          return 1;
      }

    double radius = std::stod(argv[1]);
    int nRandom = std::stoi(argv[2]);

    auto seed = time(NULL); //seed
    std::mt19937 mtEngines(static_cast<unsigned int>(seed));
    std::uniform_real_distribution<> pointsPDF(-radius,radius); //initialize random generator
    //box dimension is twice the radius of the circle inside

    //initialize storage of points
    int circlePoints = 0;
    int boxPoints = 0;

    for (int i;i<nRandom;i++) {
        double x = pointsPDF(mtEngines);
        double y = pointsPDF(mtEngines);
        //double u = x*x+y*y;
        //std::cout<<u<<std::endl;
        if ((x*x+y*y)<=(radius*radius)){   
            circlePoints++;
            //std::cout<<circlePoints<<std::endl; 
        }
        boxPoints++;
        }     

    //box area= 4r^2 (2r*2r)
    //circle area = pi*r^2
    //so circle/box=pi/4--->pi=4*circle/box 
    double estimatePi = 4.0*(static_cast<double>(circlePoints)/static_cast<double>(boxPoints));
    //I need the 4 because 
    std::printf("My estimate of pi is %.10f\n", estimatePi);

    return 0;
}

