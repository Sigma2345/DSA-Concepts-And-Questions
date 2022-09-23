#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF 100000000

class Graphs
{
public:
    unordered_map<char, list<pair<char, int> > > h;

    void AddEdge(char a, char b, int wt, bool bidir = false)
    {
        h[a].pb(mp(b, wt));
        if (bidir)
            h[b].pb(mp(a, wt));
    }

    void PrintGraph()
    {
        for (auto node : h)
        {
            cout << node.first << ':';
            for (auto child : node.second)
                cout << '(' << child.first << ',' << child.second << ')' << ' ';
            cout << endl;
        }
    }

    void BellManFord(char src)
    {
        unordered_map<char, int> distFromSrc;
        unordered_map<char, char> parentOf;
        int numVertices = 0;
        // initialize single source
        for (auto node : h)
        {
            distFromSrc[node.first] = INF;
            numVertices++;
        }
        parentOf[src] = src;
        distFromSrc[src] = 0;
        // cout << numVertices << "wef" << endl;
        for (int i = 1; i < numVertices; i++)
        {

            for (auto node : h)
            {
                char parent = node.first;
                // cout << parent << endl;
                for (auto children : h[parent])
                {
                    //cout << children.first << endl;
                    char child = children.first;
                    int wt = children.second;
                    if (distFromSrc[child] > distFromSrc[parent] + wt)
                    {
                        distFromSrc[child] = distFromSrc[parent] + wt;
                        // cout << distFromSrc[child] << "end" << endl;
                        parentOf[child] = parent;
                    }
                }
            }
        }

        for (auto node : h)
        {
            char parent = node.first;
            for (auto children : h[parent])
            {
                char child = children.first;
                int wt = children.second;
                if (distFromSrc[child] > distFromSrc[parent] + wt)
                {
                    cout << "Negative edge cycle detected" << endl;
                    return;
                }
            }
        }
        cout << "No negative cycle detected" << endl;
        for (auto node : h)
        {
            cout << node.first << ' ' << parentOf[node.first] << endl;
        }
    }
};
int main()
{
    Graphs g;
    g.AddEdge('s', 'u', 10);
    g.AddEdge('s', 'x', 5);
    g.AddEdge('u', 'v', 1);
    g.AddEdge('u', 'x', 2);
    g.AddEdge('v', 'y', 4);
    g.AddEdge('x', 'u', 3);
    g.AddEdge('x', 'y', 2);
    g.AddEdge('x', 'v', 9);
    g.AddEdge('y', 'v', 6);
    g.AddEdge('y', 's', 7);

    g.PrintGraph();
    g.BellManFord('s');

    return 0;
}
