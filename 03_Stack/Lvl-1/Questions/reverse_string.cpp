#include <iostream>
#include <stack>

using namespace std;

void reverseUsingStack(string &s)
{
    stack<char> st;
    // store in stack
    for (char c : s)
    {
        st.push(c);
    }
    int i = 0;
    while (!st.empty())
    {
        s[i] = st.top();
        st.pop();
        i++;
    }
}

int main()
{
    string s = "papa";

    reverseUsingStack(s);

    cout << s << endl;

    return 0;
}