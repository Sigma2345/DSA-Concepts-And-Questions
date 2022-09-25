#include <bits/stdc++.h>
using namespace std;

map<int, int> nodeToParent;
map<int, int> sizeOfTree; //store size of tree it is part of
map<int, int> rankOfNode;// app2 rankOfNode

// individual so return single node which is its own parent
void makeSet(int v)
{
    nodeToParent[v] = v;
    sizeOfTree[v] = 1;
    rankOfNode[v] = 0; 
}

// recursively find parent , if arriev at root return root
// in this case whenever find operation applied then assign the representative directly as parent 
int findSet(int v)
{
    if (v == nodeToParent[v])
        return v;
    return nodeToParent[v] = findSet(nodeToParent[v]); 
}
// if same parent then do nothing , else make root of tree
// in which second element is present as root of as child of root of element of first tree


// Union by rankOfNode 
// change which tree gets attached to which one
// naive implementation can lead to skew trees


/*
    app1 => use depth of tree (upper bound of depth of tree as tree depth will get smaller as path compression applied)
    make larger tree as main and smaller tree as child
*/

/*
    app2 => set rankOfNode as size of tree
*/

void unionSetApp1(int a, int b)
{
    a = findSet(a), b = findSet(b); 
    if(a!=b){
        if (sizeOfTree[a] < sizeOfTree[b]){
            swap(a, b); 
        }
        nodeToParent[b] = a ;
        sizeOfTree[a] += sizeOfTree[b]; 
    }
}

void unionSetApp2(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (rankOfNode[a] < rankOfNode[b])
            swap(a, b);
        nodeToParent[b] = a;
        if (rankOfNode[a] == rankOfNode[b])
            rankOfNode[a]++;
    }
}

int main()
{

    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);

    cout << findSet(2) << endl;
    unionSetApp2(1, 2);
    cout << findSet(2) << endl;

    unionSetApp2(4, 3);
    cout << findSet(3) << endl;
    unionSetApp2(2, 3);
    cout << findSet(3) << endl;

    return 0;
}
// find set can take O(n) time

/*
time complexity -> worst case => O(log(N))
*/
