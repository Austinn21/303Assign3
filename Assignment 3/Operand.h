#pragma once


// header that limits the digits from 0-9
bool isOperand(char ch);
// header that runs the operators
bool isOperator(char ch);
// header that sets the precedence for the string
int precedence(char op);