

// Leetcode = 17

#include <iostream>
#include <vector>

using namespace std;

void getAllstrings(string digits, vector<string> &mapping, int i, vector<string> &ans, string &op)
{
    // base case
    if (i >= digits.length())
    {
        ans.push_back(op);
        return;
    }

    // traverse string of that digit and include all
    // so first need to get the number from the digits string
    int number = digits[i] - '0'; // gives the number from string in int form

    string stringOnthatNumber = mapping[number];

    // then traverse string and made combinations till string over
    for (int j = 0; j < stringOnthatNumber.length(); j++)
    {
        // include that char
        op.push_back(stringOnthatNumber[j]);

        // recursion
        getAllstrings(digits, mapping, i + 1, ans, op);

        // backtrack
        op.pop_back();
    }
}

int main()
{

    string digits = "23";

    // then first need to map all the present digits manually in a array of string
    vector<string> mapping(9);

    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    int i = 0;

    vector<string> ans;
    string op;

    getAllstrings(digits, mapping, i, ans, op);

    cout << "Printing ans- ";

    for (string a : ans)
    {
        cout << a << endl;
    }

    return 0;
}