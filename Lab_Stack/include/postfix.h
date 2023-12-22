#include <iostream>
#include <string>
#include "TStack.h"
using namespace std; 

template <class T>
class PostCalc
{
private:
    string inf;
    string postf;
    TStack<char> opstack;
    TStack<double> dstack;
public:
    PostCalc(string ex) {
        postf = "";
        inf = ex;
        opstack = TStack<char>(ex.length());
        dstack = TStack<double>(ex.length());
    }

    int Priority(char s) {
        switch (s)
        {
        case '(':
        case ')':
            return 1;

        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        }
    }

    string GetPost() {
        return postf;
    }
    void ToPost() {
        char el = '!';
        postf = "";
        string s = "(" + inf + ")";
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] <= '9' && s[i] >= '0') postf += s[i];
            if (s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-') {
                postf += " ";
                el = opstack.Pop();
                while (Priority(s[i]) <= Priority(el)) {
                    postf += el;
                    postf += " ";
                    el = opstack.Pop();
                }
                opstack.Push(el);
                opstack.Push(s[i]);
            }
            if (s[i] == '(') opstack.Push(s[i]);
            if (s[i] == ')') {
                el = opstack.Pop();

                while (el != '(') {
                    postf += el;
                    el = opstack.Pop();
                }
            }
        }
    }
    
    double CalcPost()
    {
        for (size_t i = 0; i < postf.size(); i++)
        {
            if (postf[i] == '+' || postf[i] == '-' || postf[i] == '*' || postf[i] == '/') {
                double a, b;
                switch (postf[i]) {
                case '+':
                    a = dstack.Pop();
                    b = dstack.Pop();
                    dstack.Push(a + b);
                    break;
                case '-':
                    a = dstack.Pop();
                    b = dstack.Pop();
                    dstack.Push(a - b);
                    break;
                case '*':
                    a = dstack.Pop();
                    b = dstack.Pop();
                    dstack.Push(a * b);
                    break;
                case '/':
                    a = dstack.Pop();
                    b = dstack.Pop();
                    dstack.Push(b / a);
                    break;
                }
            }
            if (postf[i] <= '9' && postf[i] >= '0') {
                size_t count;
                double t = std::stod(&postf[i], &count);
                dstack.Push(t);
                i += count - 1;
            }
        }
        return dstack.Top();
    }
};