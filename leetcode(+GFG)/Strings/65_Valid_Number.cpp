// https://leetcode.com/problems/valid-number/description/

#include<bits/stdc++.h>
using namespace std; 
class Solution
{
public:
    bool isNumber(string s)
    {
        // divide string into 2 parts -> prev e and post e
        int n = s.length();
        string pre, post;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                index = i;
                break;
            }
        }

        if (s == "+." || s == "-.")
            return false;

        if (index != -1)
        {
            pre = s.substr(0, index);
            post = s.substr(index + 1, s.length() - index);
            if (pre.length() == 0 || post.length() == 0)
            {
                return false;
            }

            // check pre
            int numDecimals = 0;
            for (int i = 0; i < pre.length(); i++)
            {
                if ((pre[i] == '-' || pre[i] == '+') && i != 0)
                    return false;
                else if ((pre[i] == '-' || pre[i] == '+') && pre.length() == 1)
                    return false;
                else if (pre[i] == '.')
                {
                    numDecimals++;
                    if (numDecimals > 1)
                        return false;
                    if (pre.length() == 1)
                        return false;
                }
                else if (pre[i] != '-' && pre[i] != '+' && ((pre[i] - '0') > 9 || (pre[i] - '0') < 0))
                    return false;
            }

            numDecimals = 0;
            for (int i = 0; i < post.length(); i++)
            {
                if ((post[i] == '-' || post[i] == '+') && i != 0)
                    return false;
                else if ((post[i] == '-' || post[i] == '+') && post.length() == 1)
                    return false;
                else if (post[i] == '.')
                {
                    numDecimals++;
                    if (numDecimals > 0)
                        return false;
                    if (post.length() == 1)
                        return false;
                }
                else if (post[i] != '-' && post[i] != '+' && ((post[i] - '0') > 9 || (post[i] - '0') < 0))
                    return false;
            }

            return true;
        }

        // in both parts
        // only initial char can be + -
        int numDecimals = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == '-' || s[i] == '+') && i != 0)
                return false;
            else if ((s[i] == '-' || s[i] == '+') && s.length() == 1)
                return false;
            else if (s[i] == '.')
            {
                numDecimals++;
                if (numDecimals > 1)
                    return false;
                if (s.length() == 1)
                    return false;
            }
            else if (s[i] != '-' && s[i] != '+' && ((s[i] - '0') > 9 || (s[i] - '0') < 0))
            {
                // cout<<"nskjvnk"<<endl;
                return false;
            }
        }
        return true;
    }
};
