/*
This is the MST structure print out 
*/

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define pb push_back

class Graphs
{

public:
    unordered_map<char, list<pair<int, char > > >  h;

    void AddEdge(char a, char b, int w, bool bidir = true)
    {
        h[a].pb(make_pair(w, b));

        if (bidir)
        {
            h[b].pb(make_pair(w, a));
        }
    }

    void PrintGraph()
    {
        for (auto node : h)
        {
            cout << node.first << " : ";
            for (auto child : node.second)
            {
                cout << "(" << child.first << "," << child.second << ")"
                     << "-->";
            }
            cout << endl;
        }
    }

    void PrimAlgo()
    {
        unordered_map<char, char> parent;

        set<pair<int, char> > ms;
        map<char, int> mshelp;

        for (auto node : h)
        {
            char a = node.first;
            ms.insert(make_pair(INT_MAX, a));
            mshelp[a] = INT_MAX;
        }

        auto front = *ms.begin();
        ms.erase(ms.begin());
        ms.insert(make_pair(0, front.second));
        mshelp[front.second] = 0;
        parent[front.second] = front.second;

        while (!ms.empty())
        {

            // extract minimum element
            auto minEl = *ms.begin();
            ms.erase(ms.begin());

            char minElChar = minEl.second;

            for (auto node : h[minElChar])
            {
                int nodeWeight = node.first;
                char nodeChar = node.second;

                auto m = ms.find(make_pair(mshelp[nodeChar], nodeChar));
                if (m != ms.end() && nodeWeight < mshelp[nodeChar])
                {

                    parent[nodeChar] = minElChar;

                    ms.erase(m);

                    ms.insert(make_pair(nodeWeight, nodeChar));
                    mshelp[nodeChar] = nodeWeight;
                }
            }
        }

        for (auto node : parent)
        {
            cout << node.first << "-->" << node.second << endl;
        }
    }
};

int main()
{

    Graphs g;

    g.AddEdge('a', 'b', 4);
    g.AddEdge('b', 'c', 8);
    g.AddEdge('b', 'h', 1);
    g.AddEdge('a', 'h', 8);

    g.PrimAlgo();

    return 0;
}
