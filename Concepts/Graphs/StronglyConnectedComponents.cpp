#include <iostream>
#include<vector>
#include <unordered_map>
#include <list>
#define pb push_back
using namespace std;

class GraphNode
{
public:
    int d;
    int f;
    char val;

    GraphNode(char _val)
    {
        d = 0;
        f = 0;
        val = _val;
    }
};

class Graph
{

    void DFS_final(unordered_map<char, bool> &visited1, char v, unordered_map<char,list<char> >h_transpose)
    {
        cout << v << ' ';
        visited1[v] = true;
        for (auto node : h_transpose[v])
        {
            if (!visited1[node])
            {
                DFS_final(visited1, node, h_transpose);
            }
            else{
                return;
            }
        }
        cout << endl;
    }

    void DFS_visit(int &time, unordered_map<char, bool> &visited, char v)
    {
        time = time + 1;
        visited[v] = true;
        vertices[indexOfVertices[v]]->d = time;
        for (auto node : h[v])
        {
            if (!visited[node])
            {
                DFS_visit(time, visited, node);
            }
        }
        time = time + 1;
        vertices[indexOfVertices[v]]->f = time;
    }

public:
    vector<GraphNode *> vertices;
    unordered_map<char, list<char> > h;
    unordered_map<char, int> indexOfVertices;
    unordered_map<char ,  bool> exists; 

    void AddEdge(char _val1, char _val2, bool bidir, unordered_map<char, list<char>  > &m)
    {
        GraphNode *M1 = new GraphNode(_val1);
        GraphNode *M2 = new GraphNode(_val2);

        if (m == h)
        {
            if (exists[_val1] == false)
            {
                vertices.push_back(M1);
                indexOfVertices[_val1] = vertices.size() - 1;
                exists[_val1] = true; 
            }
            if (exists[_val2] == false)
            {
                vertices.push_back(M2);
                indexOfVertices[_val2] = vertices.size() - 1;
                exists[_val2] = true; 
            }
        }

        m[_val1].push_back(_val2);
        if (bidir)
            m[_val2].push_back(_val1);
    }

    // dfs and update start and end time
    void Print()
    {
        for (auto node : h)
        {
            cout << node.first << " : ";
            for (auto child : h[node.first])
            {
                cout << child << "-->";
            }
            cout << endl;
        }
    }

    // by dfs assign each vector time f
    void SCC()
    {
        int time = 0;
        unordered_map<char, bool> visited;

        // for (int i = 0; i < vertices.size(); i++)
        // {
        //     cout << vertices[i]->val << " " << vertices[i]->f << endl;
        // }
        // cout << endl;

        DFS_visit(time, visited, vertices[0]->val);
        cout << "time"
             << " : " << time<<endl;
        for (auto node : h)
        {
            if (visited[node.first] == false) 
            {
                DFS_visit(time, visited, node.first);
                cout << "time"
                     << " : " << time << endl;
            }
        }

        // now sort vector on basis of final time
        for (int i = 0; i < vertices.size(); i++)
        {
            for (int j = i + 1; j < vertices.size(); j++)
            {
                if (vertices[i]->f < vertices[j]->f)
                {
                    swap(vertices[i], vertices[j]);
                }
            }
        }

        // for (int i = 0; i < vertices.size(); i++)
        // {
        //     cout << vertices[i]->val << " " << vertices[i]->f << endl;
        // }

        // another map gtranspose

        unordered_map<char, list<char>  > h_transpose;
        for (auto node : h)
        {
            char x = node.first;
            for (auto child : h[x])
            {
                AddEdge(child, x, false, h_transpose);
            }
        }

        unordered_map<char, bool> visited1(false);
        DFS_final(visited1, vertices[0]->val, h_transpose);
        for (int i = 0; i < vertices.size(); i++)
        {
            if (visited1[vertices[i]->val])
                DFS_final(visited1, vertices[i]->val, h_transpose);
        }
        cout<<endl ; 
    }
};

int main()
{

    Graph g;
    g.AddEdge('a', 'b', false, g.h);
    g.AddEdge('e', 'a', false, g.h);
    g.AddEdge('b', 'e', false, g.h);
    g.AddEdge('b', 'f', false, g.h);
    g.AddEdge('f', 'e', false, g.h);
    g.AddEdge('f', 'g', false, g.h);
    g.AddEdge('g', 'f', false, g.h);
    g.AddEdge('b', 'c', false, g.h);
    g.AddEdge('c', 'g', false, g.h);
    g.AddEdge('g', 'h', false, g.h);
    g.AddEdge('c', 'd', false, g.h);
    g.AddEdge('d', 'c', false, g.h);
    g.AddEdge('d', 'h', false, g.h);
    g.AddEdge('h', 'h', false, g.h);

    // g.Print();
    g.SCC();
    return 0;
}
