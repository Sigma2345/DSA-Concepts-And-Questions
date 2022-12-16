// https://leetcode.com/problems/maximal-rectangle/description/
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();

        if (r * c == 1)
            return matrix[0][0] - '0';

        vector<vector<int>> v(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if ((matrix[i][j] - '0') == 1)
                    v[i][j] = i > 0 ? v[i - 1][j] + 1 : 1;
            }
        }
        cout << "VR:" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }

        // now maximal rectangle in each row

        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            stack<int> s;
            vector<int> left(c, 0);
            vector<int> right(c, 0);
            s.push(0);
            left[0] = 0;
            right[c - 1] = c - 1;
            for (int j = 1; j < c; j++)
            {
                while (!s.empty() && v[i][s.top()] >= v[i][j])
                    s.pop();
                if (s.empty())
                    left[j] = 0;
                else
                    left[j] = s.top() + 1;
                s.push(j);
            }
            while (!s.empty())
                s.pop();
            s.push(c - 1);
            for (int j = c - 2; j >= 0; j--)
            {
                while (!s.empty() && v[i][s.top()] >= v[i][j])
                    s.pop();
                if (s.empty())
                    right[j] = c - 1;
                else
                    right[j] = s.top() - 1;
                s.push(j);
            }
            for (int k = 0; k < c; k++)
            {
                int ar = (right[k] - left[k] + 1) * v[i][k];
                ans = max(ans, ar);
            }
        }
        return ans;
    }
};

/*
    solution:

->find out the max height too which each cell has a rectangle in vertical direction
-> apply largest rectangle area in histogram to find the largest rectangle formed with 1s in each row 

*/
