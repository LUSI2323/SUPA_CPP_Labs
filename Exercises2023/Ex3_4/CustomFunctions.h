#pragma once

#include "FiniteFunctions.h" //parent

//normal distribution
class NormalFunction : public FiniteFunction{
    public:
    //overload constructor
        NormalFunction(double range_min, double range_max, double mu, double sigma, std::string outfile);
    //override functions
        double callFunction(double x) override;
        void printInfo() override;
    //variables
        double mu;
        double sigma;
    private:
        double normdistr(double sigma, double mu, double x);
        double m_mu;
        double m_sigma;
};

///Cauchy-Lorentz
class CauchyLorentzFunction : public FiniteFunction {
      public:
    //overload constructor
        CauchyLorentzFunction(double range_min, double range_max, double x0, double gamma, double sigma, std::string outfile);
    //override functions
        double callFunction(double x) override;
        void printInfo() override;
    //variables
        double x0;
        double gamma;
        double sigma;
    private:
        double cldistr(double x0, double gamma, double sigma, double x);
        double m_x0;
        double m_gamma; //>0
        double m_sigma;
};

///negative Crystal Ball
class NegativeCrystalBallFunction : public FiniteFunction {
      public:
    //overload constructor
        NegativeCrystalBallFunction(double range_min, double range_max, double xbar, double sigma, double n, double alpha, std::string outfile);
    //override functions
        double callFunction(double x) override;
        void printInfo() override;
    //variables
        double xbar;
        double sigma;
        double n;
        double alpha;


    private:
        double ncbdistr(double xbar, double sigma, double n, double alpha, double x);
        double m_xbar;
        double m_sigma;
        double m_n;
        double m_alpha;
};
