/*************************************************************************
	> File Name: test_stack_cpp.cpp
	> Author: Hui Wang
	> Mail: ncepuwanghui@gmail.com 
	> Created Time: Sun 07 Dec 2014 10:26:18 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>

int main(int argc, char* argv[])
{
    std::stack<int> st;
    int i = 0;

    for (i = 0; i < 3; i++) {
        st.push(i + 1);
    }
    while (!st.empty()) {
        std::cout << st.top() << std::endl;
        st.pop();
    }

    return 0;
}
