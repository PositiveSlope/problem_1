#include "gtest/gtest.h"
#include "possible_parentheses.h"
void showResult(std::list<std::string> & result) {
    for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        printf("%s", (*i).c_str());
    }
};

TEST(test_recursive, 0) {
    std::list<std::string> result;
    possibleParenthesis(0, result);
    showResult(result);
    ASSERT_TRUE(result.size()==0);
}

TEST(test_recursive, 1) {
    std::list<std::string> result;
    int left, right=0;
    possibleParenthesis(1, result);

    // homework: add verification
    showResult(result);//{}
    /*for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        if((*i).c_str()=="{"){
            left++;
        }
        if((*i).c_str()=="}"){
            right++;
        }

    }
    std::cout<<left<<std::endl;
    std::cout<<right<<std::endl;*/
    ASSERT_TRUE(result.size()==2);//{}
}

TEST(test_recursive, 2) {//I traced debug to follow an FSM
    //where (n, int open, int close) is as follows
    //2,0,0->2,1,0->2,1,1->2,2,1->2,2,2->return/exit back to 2,2,1->return back to 2,1,1
    //return back to 2,1,0 where (open < n), so open+1 ->2,2,0 -> (open>close) ->2,2,1
    //again to 2,2,2
    std::list<std::string> result;
    possibleParenthesis(2, result);

    // homework: add verification
    showResult(result);
    std::cout<<result.size();
    ASSERT_TRUE(result.size()==4);//{{}} and {}{}
}

TEST(test_recursive, 3) {
    std::list<std::string> result;
    possibleParenthesis(3, result);

    // homework: add verification
    showResult(result);
    std::cout<<result.size();
    ASSERT_TRUE(result.size()==6);//{{{}}} of size 6
    // {}{}{}, {}{{}}, {{}}{}, {{}{}}, {{{}}}
}

// and more, n=0
