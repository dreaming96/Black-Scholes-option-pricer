/*
    This program prices European Call and Put options given the parameters:
    S: Underlying price
    K: Strike price
    r: Risk-free rate
    sigma: Underlying volatility
    t: Time-to-maturity
*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <stats.hpp>
using namespace std;

int main()
{
    double S, K, r, t, sigma, C, d1, d2, P;

    cout << "Input the stock price: ";
    cin >> S;

    cout << "Input the strike price: ";
    cin >> K;

    cout << "Input the risk-free rate: ";
    cin >> r;

    cout << "Input the volatility: ";
    cin >> sigma;

    cout << "Input the time to maturity: ";
    cin >> t;

    //Defining the d_n parameters
    d1 = (log(S / K) + (r + pow(sigma, 2) * t)) / (sigma * sqrt(t));
    d2 = d1 - (sigma * sqrt(t));

    //Black-Scholes formula for option pricing
    C = S * stats::pnorm(d1, 0, 1) - K * exp(-r * t) * stats::pnorm(d2, 0, 1);
    P = K * exp(-r * t) - S + (S * stats::pnorm(d1, 0, 1) - K * exp(-r * t) * stats::pnorm(d2, 0, 1));
    
    cout << "Call Price: " << C << " \n ";
    cout << "Put Price: " << P;

    return 0;
}