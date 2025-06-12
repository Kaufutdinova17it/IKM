#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std; 

class Calculator
{
public:
    int Evaluate(const string& expression);

private:
    int EvaluateExpression(const string& expression);
    void ValidateExpression(const string& expression);
};




