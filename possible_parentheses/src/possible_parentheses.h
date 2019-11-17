#include <list>

// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n
void _possibleParenthesis(int n, int open, int close, std::list<std::string> & result)
{
    if(open==n && close == n) {
        return;
    }else {

        if (open > close) {

            _possibleParenthesis(n, open, close + 1, result);
            result.emplace_back("{");
            return;//w/o return, I would get size 7 for n=2, and size 21 for n=3
        }

        if (open < n) {//adding else if gave me the best result

            _possibleParenthesis(n, open + 1, close, result);
            result.emplace_back("}");//when debugging, it looked like my code left its recursion function, it went to the line before
            return;
        }//so i moved emplaceback after the call and switched { and }
    }
}//i drew out the state flows and when they drew things, but i couldnt figure out why it branched the way it did

void possibleParenthesis(int n, std::list<std::string> & result)
{
    // homework
    if(n>0){
        _possibleParenthesis(n,0,0,result);
    }


}
