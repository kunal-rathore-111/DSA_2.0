
/*
// https://leetcode.com/problems/valid-parentheses/description/ */

class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.length();
        if (size == 1)
            return false;

        stack<char> k;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                k.push(c);
            }
            else
            {
                if (!k.empty())
                {
                    bool case1 = (k.top() == '(') && c == ')';
                    bool case2 = (k.top() == '{') && c == '}';
                    bool case3 = (k.top() == '[') && c == ']';

                    if (case1 | case2 | case3)
                    {
                        k.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (!k.empty())
            return false;
        return true;
    }
};