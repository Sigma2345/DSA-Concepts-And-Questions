// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int n = tasks.size();
        if (n == 1)
            return -1;
        // get same nums together
        sort(tasks.begin(), tasks.end());
        int ans = 0;
        for (int i = 0; i < n;)
        {
            // cnt the number of occurences of each number 
            int cnt = 0;
            int j = i;
            for (; j < n && tasks[i] == tasks[j]; j++)
            {
                cnt++;
            }
            // if cnt == 1 cannot be delivered so return -1
            if (cnt == 1)
                return -1;
            else
            {
                // express number as sum of 2 and 3
                // first cnt/3
                // finding m1 and m2 
                // s.t 3*m1 + 2*m2 = cnt 
                int m1 = cnt / 3;
                int m2 = 0;
                while (1)
                {
                    if ((cnt - m1 * 3) % 2 == 0)
                    {
                        m2 = (cnt - m1 * 3) / 2;
                        break;
                    }
                    m1--;
                }
                ans = ans + (m1 + m2);
            }
            i = j;
        }
        return ans;
    }
};
