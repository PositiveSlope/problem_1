#include "gtest/gtest.h"
#include "possible_parentheses.h"
void showResult(std::list<std::string> & result) {
    for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        printf("%s\n", (*i).c_str());
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
    std::list<std::string> expectedResult={"{}"};

    int left, right=0;
    possibleParenthesis(1, result);

    // homework: add verification
    showResult(result);//{}

    ASSERT_TRUE(result.size()==1);//{}
    ASSERT_TRUE(result==expectedResult);
}

TEST(test_recursive, 2) {
    std::list<std::string> result;
    std::list<std::string> expectedResult={"{}{}","{{}}"};//sequences
    std::list<std::string> expectedResult1={"{{}}","{}{}"};
    possibleParenthesis(2, result);

    // homework: add verification
    showResult(result);
    std::cout<<result.size();
    ASSERT_TRUE(result.size()==2);//{{}} and {}{}, 2 possibilities
    ASSERT_TRUE((result==expectedResult || result == expectedResult1));
}

TEST(test_recursive, 3) {
    std::list<std::string> result;
    std::list<std::string> expectedResult={"{}{}{}","{}{{}}","{{}}{}","{{}{}}","{{{}}}"};
    possibleParenthesis(3, result);

    // homework: add verification
    showResult(result);
    std::cout<<result.size();
    ASSERT_TRUE(result.size()==5);//{}{}{}, {}{{}}, {{}}{}, {{}{}}, {{{}}}
    ASSERT_TRUE(result==expectedResult);
}

// and more, n=0
