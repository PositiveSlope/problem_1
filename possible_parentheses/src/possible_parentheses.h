#include <list>
#include "LinkedStack.h"

// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n
void possibleParenthesis(int n, std::list<std::string> & result)
{
    // homework
    LinkedStack<std::string> stack;
    int open, close =0;

    /*while(!stack.isEmpty()){
        stack.pop();
        if(open==n && close==n){ // if we've consumed all left braces and right braces
            result.push_back(stack.peek()); // it will be a valid result
        }else{
            if(open<n){ // if we can still use a left brace
                stack.push(stack.peek()+'(');
                open+=1;
            }
            if(close<open){ // if we can still use a right brace
                stack.push(stack.peek()+')');
                close+=1;
            }
        }
    }*/
     while(!stack.isEmpty()){

        stack.pop();
        if(open==n && close==n){ // if we've consumed all left braces and right braces
            result.push_back(stack.peek()); // it will be a valid result
        }else{
            if(open<n){ // if we can still use a left brace
                stack.push(stack.peek()+'(');
                open+=1;
            }
            if(close<open){ // if we can still use a right brace
                stack.push(stack.peek()+')');
                close+=1;
            }
        }
    }
    //printf(result);
}

