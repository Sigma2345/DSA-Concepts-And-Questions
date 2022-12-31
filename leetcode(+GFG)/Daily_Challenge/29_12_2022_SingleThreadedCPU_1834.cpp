// https://leetcode.com/problems/single-threaded-cpu/description/

class Solution
{
public:
    // pair < pair<int, int>, int >
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<int> ans;
        int n = tasks.size();
        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.rbegin(), tasks.rend());
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

        auto y = tasks.back();
        tasks.pop_back();
        long long int initialTime = y[0];
        pq.push({{y[1], y[2]}, y[0]});

        // we have sorted the tasks on the basis of which occurs first
        // pq is ready queue indicating which tasks can be done now 
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            cout << initialTime << endl;
            initialTime += x.first.first;
            ans.push_back(x.first.second);
            // top task

            while (tasks.size())
            {
                auto z = tasks.back();
                if (z[0] <= initialTime)
                {
                    pq.push({{z[1], z[2]}, z[0]});
                    tasks.pop_back();
                }
                else
                {
                    break;
                }
            }

            if (pq.empty() && tasks.size())
            {
                auto m = tasks.back();
                tasks.pop_back();
                pq.push({{m[1], m[2]}, m[0]});
                initialTime = m[0];
            }
        }

        return ans;
    }
};
