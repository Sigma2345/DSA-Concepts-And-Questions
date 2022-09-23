#include <bits/stdc++.h>
using namespace std;

template <typename T>

class WeightedGraph
{
public:
    unordered_map<T, list<pair<T, int>>> h;

    void AddEdge(T u, T v, int wt, bool bidir = true)
    {
        h[u].push_back({v, wt});
        if (bidir)
        {
            h[v].push_back({u, wt});
        }
    }

    void Dijkstra(T src)
    {
        unordered_map<T, int> distance;
        for (auto node : h)
        {
            distance[node.first] = INT_MAX;
        }
        distance[src] = 0;
        set<pair<int, T>> s;
        s.insert({0, src});
        while (!s.empty())
        {
            auto node = *(s.begin());
            s.erase(s.begin());

            int parentDist = node.first;
            T parent = node.second;

            for (auto children : h[parent])
            {

                int edgeDist = children.second;
                if (distance[children.first] > parentDist + edgeDist) // then change it
                {
                    // first find if the element is already present or not
                    auto f = s.find({distance[children.first], children.first});
                    if (f != s.end())
                    { // this means node is present
                        s.erase(f);
                    }
                    distance[children.first] = parentDist + edgeDist;
                    s.insert({distance[children.first], children.first});
                }
            }
        }
        for (auto node : h)
        {
            cout << "minimum distance of " << node.first << " from " << src << " is " << distance[node.first] << endl;
        }
    }

    // to get shortest path and distance
    int SSSP(T src, T des)
    {
        unordered_map<T, int> distance;
        unordered_map<T, T> parentPath;
        for (auto node : h)
        {
            distance[node.first] = INT_MAX;
        }
        distance[src] = 0;
        parentPath[src] = src;
        set<pair<int, T>> s;
        s.insert({0, src});
        while (!s.empty())
        {
            auto node = *(s.begin());
            s.erase(s.begin());

            int parentDist = node.first;
            T parent = node.second;

            for (auto children : h[parent])
            {

                int edgeDist = children.second;
                if (distance[children.first] > parentDist + edgeDist) // then change it
                {
                    // first find if the element is already present or not
                    auto f = s.find({distance[children.first], children.first});
                    if (f != s.end())
                    { // this means node is present
                        s.erase(f);
                    }
                    distance[children.first] = parentDist + edgeDist;
                    parentPath[children.first] = parent;
                    s.insert({distance[children.first], children.first});
                }
            }
        }
        T temp = des;
        while (parentPath[temp] != temp)
        {
            cout << temp << "<--";
            temp = parentPath[temp];
        }
        cout << temp << endl;
        return distance[des];
    }

    void Print()
    {
        for (auto node : h)
        {
            cout << node.first << " : ";
            for (auto children : node.second)
            {
                cout << " ( " << children.first << " , " << children.second << " ) ";
            }
            cout << endl;
        }
    }
};

int main()
{
    WeightedGraph<char> g;
    g.AddEdge('A', 'B', 4);
    g.AddEdge('A', 'C', 1);
    g.AddEdge('C', 'B', 2);
    g.AddEdge('B', 'D', 1);
    g.AddEdge('C', 'D', 5);
    g.AddEdge('D', 'E', 3);

    g.Dijkstra('A');
    // cout << "minimum distance between A and D is " << ans ;
    // cout << "minimum distance between A and D is " << ans ;
    return 0;
}