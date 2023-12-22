#include <iostream>
#include <string>
#include "postfix.h"


void main() 
{
    string str;
    cin >> str;
    PostCalc<double> t(str); 
    t.ToPost(); 
    double res = t.CalcPost();
    cout << str << "=" << res;

}