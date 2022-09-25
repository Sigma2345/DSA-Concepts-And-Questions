#include<bits/stdc++.h>
using namespace std;

map<int, int> nodeToParent; 

// individual so return single node which is its own parent 
void makeSet(int v){
    nodeToParent[v] = v;
}

// recursively find parent , if arriev at root return root 
int findSet(int v){
    if(v==nodeToParent[v]) return v;
    return findSet(nodeToParent[v]); 
}
// if same parent then do nothing , else make root of tree
// in which second element is present as root of as child of root of element of first tree 
void unionSet(int a, int b)
{
    if(findSet(a) == findSet(b))
        return;

    nodeToParent[findSet(b)] = findSet(a);
}

int main(){

    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);

    cout << findSet(2) << endl;
    unionSet(1, 2);
    cout << findSet(2) << endl;

    unionSet(4,3);
    cout << findSet(3) << endl;
    unionSet(2, 3);
    cout << findSet(3) << endl;

    return 0; 
}
// find set can take O(n) time 
