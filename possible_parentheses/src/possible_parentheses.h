#include <list>
#define MAX_SIZE 100
// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n
void _possibleParenthesis(int pos, int n, int open, int close, std::list<std::string> & result)
{
    static char str[MAX_SIZE];
    if(open==n && close == n) {
        result.emplace_back(str);//replaced printf to output into vector
        return;
    }else {

        if (open > close) {
            str[pos] = '}';
            _possibleParenthesis(pos+1, n, open, close + 1, result);
        }

        if (open < n) {
            str[pos] = '{';
            _possibleParenthesis(pos+1, n, open + 1, close, result);
        }
    }
}

void possibleParenthesis(int n, std::list<std::string> & result)
{
    // homework
    if(n>0){
        _possibleParenthesis(0,n,0,0,result);
    }


}
