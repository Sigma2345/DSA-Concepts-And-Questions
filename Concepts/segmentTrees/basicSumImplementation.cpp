#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int t[4*MAXN] ; 

void build(int a[], int v,  int tl, int tr){
    if(tl==tr){
        t[v] = a[tl]; 
        return ; 
    }

    int mid = tl + (tr - tl)/2 ; 
    build(a, v*2, tl, mid); 
    build(a, v*2 + 1, mid+1, tr); 
    t[v] = t[2*v] + t[2*v+1] ; 
}

/**
 * @param a
 * @param v: vertex
 * @param tl: left boundary of node
 * @param tr: right boundary of node
 * @param l: left side
 * @param r: right side
 * @return int -> sum
 * min(r, mid) -> in case entire array in left node we take end till r
 * max(l, mid+1) -> in case entire array in right node we take start from l
 */
int sum(int v, int tl, int tr, int l, int r){
    if (l>r) return 0 ; 

    if(l==tl && r==tr) return t[v] ;

    int mid = tl + (tr - tl) / 2;


    return sum(v * 2, tl, mid, l, min(r, mid)) 
                + sum(v*2 + 1, mid+1, tr, max(l, mid+1), r); 
}

void update(int v, int tl, int tr, int pos, int new_val){

    if(tl==tr){
        t[v] = new_val;
        return; 
    }

    //recursive case
    int mid = tl + (tr-tl)/2 ; 
    if(pos <= mid) update(2*v, tl, mid, pos, new_val);
    else update(2*v+1, mid+1, tr, pos, new_val);
    t[v] = t[2*v] + t[2*v+1]; 
}


int main()
{
    int a[] = {10, 20, 3, 43, 80, 17}; 
    int n = sizeof(a)/sizeof(int);
    // memset(t, 0, sizeof(t));

    build(a, 1, 0, n - 1);
    for (int i = 0; i<4*n ; i++){
        cout << t[i] << ' ';
    }
    cout << endl;

    update(1, 0, n - 1, 1, 10);
    for (int i = 0; i < 4 * n; i++)
    {
        cout << t[i] << ' ';
    }
    cout << endl;

    return 0;
}
