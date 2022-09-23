#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define pb push_back
#define pf push_front

template <typename T>

class Graph
{

    void TopSortHelper(T start, unordered_map<T, bool> &visited, list<T> &l)
    {

        visited[start] = true;
        for (auto child : h[start])
        {
            if (!visited[child])
            {
                TopSortHelper(child, visited, l);
            }
        }
        l.pf(start);
        return;
    }

public:
    unordered_map<T, list<T> > h;

    void AddEdge(T u, T v, bool bidir = false)
    {
        h[u].pb(v);
        if (bidir)
        {
            h[v].pb(u);
        }
    }

    void print()
    {
        for (auto node : h)
        {
            cout << node.first << " : ";
            for (auto child : node.second)
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }

    list<T> TopSort(T start)
    {
        // use list instead of vectors
        list<T> l;
        unordered_map<T, bool> visited;
        TopSortHelper(start, visited, l);
        for (auto node : h)
        {
            if (!visited[node.first])
            {
                TopSortHelper(node.first, visited, l);
            }
        }
        for (auto x : l)
        {
            cout << x << ' ';
        }
        cout << endl;
        return l;
    }
};

int main()
{
    Graph<char> g;
    g.AddEdge('A', 'B');
    g.AddEdge('A', 'C');
    g.AddEdge('A', 'D');
    g.AddEdge('B', 'J');
    g.AddEdge('C', 'F');
    g.AddEdge('C', 'I');
    g.AddEdge('D', 'G');
    g.AddEdge('D', 'E');
    g.AddEdge('E', 'K');
    g.AddEdge('E', 'H');


    list<char> l =  g.TopSort('D');
    return 0;
}
