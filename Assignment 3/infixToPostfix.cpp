#include <iostream>
#include <queue>
#include <string>
#include <stack>

#include "Operand.h"

using namespace std;

queue<string> infixToPostfix(string exp)
{
    stack<char> st;
    queue<string> q;
    string operand;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        // Debug output
        cout << "Processing character: " << ch << endl;

        if (isOperand(ch))
        {
            operand += ch;
            if (i == exp.length() - 1 || !isOperand(exp[i + 1]))
            {
                q.push(operand);
                operand = "";
            }
        }
        else if (isOperator(ch))
        {
            while (!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch))
            {
                q.push(string(1, st.top()));
                st.pop();
            }
            st.push(ch);
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                q.push(string(1, st.top()));
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                // Unbalanced parentheses
                cout << "Unbalanced parentheses" << endl;
                // You can choose to handle the error as appropriate, e.g., return an error code
            }
        }
        else
        {
            // Invalid character in the expression
            cout << "Invalid character: " << ch << endl;
            // You can choose to handle the error as appropriate, e.g., return an error code
        }

        // Debug output
       cout << "Stack contents:";
        stack<char> tempStack = st;
        while (!tempStack.empty())
        {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }

    while (!st.empty())
    {
        if (st.top() == '(')
        {
            // Unbalanced parentheses
            cout << "Unbalanced parentheses" << endl;
            // You can choose to handle the error as appropriate, e.g., return an error code
        }
        q.push(string(1, st.top()));
        st.pop();
    }

    return q;
}