

// Leetcode = 22  include  '(' then include ')'

#include <iostream>
#include <vector>

using namespace std;

void paranthesis(int leftB, int rightB, vector<string> &ans, string &op)
{
    // base case-
    if (leftB == 0 && rightB == 0)
    {
        ans.push_back(op);
    }

    // first include all (
    if (leftB > 0)
    {
        // include (
        op.push_back('(');

        // recursion
        paranthesis(leftB - 1, rightB, ans, op);

        // backtrack
        op.pop_back();
    }

    // then include all )
    if (rightB > leftB) // jab tak right bracket ka count bda hae mtlb right bracket aa sakta kyunki us right bracket kae liye ek left bracket already hae tabhi toh rightB ka count jyada hae varna equal hota
    {
        // include )
        op.push_back(')');

        // recursion (kyunki abhi orr bache hae)
        paranthesis(leftB, rightB - 1, ans, op);

        // backtrack
        op.pop_back();
    }
}

int main()
{
    int n = 3;

    vector<string> ans;
    string op;
    /*
     steps-
      implement '(' till count of '(' > 0, then do same for ')' till count of ')' is < count of "("
    */
    int leftB = n;
    int rightB = n;

    paranthesis(leftB, rightB, ans, op);

    cout << "Ans- " << endl;

    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}