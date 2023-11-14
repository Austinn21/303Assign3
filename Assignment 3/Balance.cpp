#include <stack>
#include <string>

using namespace std;

/* a function that takes a string argument 'exp' and returns a boolean value
indicating whether the '()', {}, '[]' in the expression are balanced */
bool isBalanced(string exp) 
{   // Declares an empty stack to hold opening brackets
    stack<char> st;
    for (int i = 0; i < exp.length(); i++) 
    {
        char ch = exp[i];
        //// If the character is an opening bracket, push it onto the stack
        if (ch == '{' || ch == '[' || ch == '(') 
        {
            st.push(ch);
        }
        // If the character is a closing bracket, check if it matches the top of the stack
        else if (ch == '}' || ch == ']' || ch == ')') 
        {
            // If the stack is empty, the brackets are not balanced
            if (st.empty()) {
                return false;
            }
            // If the closing bracket matches the top of the stack, pop the top element
            if ((ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[') || (ch == ')' && st.top() == '(')) 
            {
                st.pop();
            }
            // If the closing bracket does not match the top of the stack, the brackets are not balanced
            else 
            { 
                return false;
            }
        }
    }
    
    return st.empty();
}