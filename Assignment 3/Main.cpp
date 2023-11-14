#include <iostream>
#include <string>
#include <queue>

#include "infixToPostfix.h"

using namespace std;

int main()
{
    string infixExp;
    cout << "Enter infix expression: ";
    getline(cin, infixExp);

    queue<string> postfixExp = infixToPostfix(infixExp);

    if (postfixExp.empty())
    {
        cout << "Invalid Expression" << endl;
    }
    else
    {
        cout << "Postfix expression: ";

        // Use a temporary queue for printing
        queue<string> tempQueue = postfixExp;

        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;

        int numberOfElements = postfixExp.size(); // Calculate the size of the original queue
        cout << "Total number of elements in the postfix expression queue: " << numberOfElements << endl;
    }

    return 0;
}

