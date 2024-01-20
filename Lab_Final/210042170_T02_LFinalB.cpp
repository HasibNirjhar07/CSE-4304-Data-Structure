// Checking parenthesis in Mathematical Expressions
//  Write a program that will take a mathematical expression as input and check
//  whether it is properly parenthesized or not.
//  The first line of input will take an integer N signifying the number of test
//  cases. The next lines will be N mathematical expressions. Each input
//  expression may contain any single-digit number (0~9), operators (+- x /) and
//  any parenthesis ( )/[ ]/{ }.
// The output will be Yes/No representing whether it is properly parenthesized.
//  Sample Input Sample Output
//  8
//  [ 5 + (2 x 5)-(7 / 2) ]
//  [ 1 + { 3 x (2 / 3 ) ] }
//  [ ( 1 + 1 ) ]
//  [ ( 1 + 1 ] )
//  [ ( ) ] { } { [ ( ) ( ) ] ( ) }
//  ( ( (
//  [ 5 + (2 x 5)-(7 / 2)
//  5 + (2 x 5)-(7 / 2) ]
//  ( ) ) )
//  ( ( ( ) )
//  Yes
//  No
//  Yes
//  No
//  Yes
//  No
//  No
//  No
//  No
//  N0














#include <iostream>

#include <stack>

using namespace std;

bool checkParenthesis(string input)
{
    stack<char> s;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            i++;
        }
        
        else if (input[i] == '(' || input[i] == '[' || input[i] == '{')
        
            s.push(input[i]);
        
        else if (input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
        
            if (s.empty())
        
                return false;
        
            else if (input[i] == ')' && s.top() != '(')
        
                return false;
        
            else if (input[i] == ']' && s.top() != '[')
        
                return false;
        
            else if (input[i] == '}' && s.top() != '{')
        
                return false;
        
            else
                s.pop();
        }
    }
   
    if (s.empty())
   
        return true;
   
    else
   
        return false;
}

int main()
{
    int x;
    
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        string input;
        
        cin >> input;
        
        if (checkParenthesis(input))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}