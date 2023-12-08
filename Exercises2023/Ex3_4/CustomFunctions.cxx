#include "CustomFunctions.h"
#include <cmath>
#include <iostream>


///Normal distribution
NormalFunction::NormalFunction(double range_min, double range_max, double mu, double sigma, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile) {
    m_mu = mu;
    m_sigma = sigma;
} //overload (we add two arguments)


double NormalFunction::normdistr(double mu, double sigma, double x) { return exp(-0.5 * pow((x - mu) / sigma, 2)) / (sqrt(2 * M_PI) * sigma);}; //evaluation 

double NormalFunction::callFunction(double x) {
    return this->normdistr(m_mu, m_sigma, x); //override: it call normdistr
};

void NormalFunction::printInfo() {
    FiniteFunction::printInfo();
    std::cout << "mu: " << m_mu << std::endl; //ovverride, it also prints mu and sigma
    std::cout << "sigma: " << m_sigma << std::endl;
}

///Cauchy Lorentz distribution
CauchyLorentzFunction::CauchyLorentzFunction(double range_min, double range_max, double x0, double gamma, double sigma, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile) {
    m_x0 = x0;
    m_gamma = gamma;
    m_sigma = sigma;
} //overload (we add three arguments)

double CauchyLorentzFunction::cldistr(double x0, double gamma, double sigma, double x) 
{ 
    return 1.0 / ((M_PI * gamma) * ( 1.0 + (((x - x0) * (x - x0))/ (gamma * gamma))));
} //evaluation 

double CauchyLorentzFunction::callFunction(double x) {
    return this->cldistr(m_x0, m_gamma, m_sigma, x); //override: it call cldistr
};

void CauchyLorentzFunction::printInfo() {
    FiniteFunction::printInfo();
    std::cout << "x0: " << m_x0 << std::endl; //ovverride, it also prints x0, gamma, sigma
    std::cout << "gamma: " << m_gamma << std::endl;
    std::cout << "sigma: " << m_sigma << std::endl;
}

///negative Crystal Ball distribution
NegativeCrystalBallFunction::NegativeCrystalBallFunction(double range_min, double range_max, double xbar, double sigma, double n, double alpha, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile) {
    m_xbar = xbar;
    m_sigma = sigma;
    m_n = n;
    m_alpha = alpha;
} //overload (we add four arguments)

double NegativeCrystalBallFunction::ncbdistr(double xbar, double sigma, double n, double alpha, double x) 
{ 
    double A = pow(n / fabs(alpha), n) * exp(-alpha * alpha / 2.0);
    double B = n / fabs(alpha) - fabs(alpha);
    double C = (n / fabs(alpha)) * (1.0 / (n - 1)) * exp(-alpha * alpha / 2.0);
    double D = sqrt(M_PI / 2.0) * (1.0 + erf(fabs(alpha) / sqrt(2.0)));
    double N = 1.0/(sigma*(C+D));

     if ((x - xbar) / sigma > -alpha) {
        return N* (exp(-0.5 * pow((x - xbar) / sigma, 2)));
    } 
    else {
        return N*A*pow(B-((x-xbar)/sigma),-n);
    }
} //evaluation 

double NegativeCrystalBallFunction::callFunction(double x) {
    return this->ncbdistr(m_xbar, m_sigma, m_n, m_alpha, x); //override: it call ncbdistr
};

void NegativeCrystalBallFunction::printInfo() {
    FiniteFunction::printInfo();
    std::cout << "xbar: " << m_xbar << std::endl; //ovverride, it also prints xbar, sigma, n, alpha
    std::cout << "sigma: " << m_sigma << std::endl;
    std::cout << "n: " << m_n << std::endl;
    std::cout << "alpha: " << m_alpha << std::endl;
}
