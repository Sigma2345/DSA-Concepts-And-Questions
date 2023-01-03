// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;
int main()
{
// n -> no of tickets
// m -> no of customers 
    int n, m;
    cin >> n >> m; 
    // since repeated values can exist
    multiset<int> tickets;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tickets.insert(-x); 
    }

    for (int i = 0; i < m; i++){
        int y;
        cin >> y;
        auto x = tickets.lower_bound(-y); 
        // lower boudn not found 
        if(x==tickets.end()){
            cout << -1 << endl;
        }
        // lower bound found 
        else{
            // print price 
            cout << -1*(*x) << endl;
            // remove that ticket 
            tickets.erase(x); 
        }
    }

        return 0;
}

/**
 * @brief the concept is to find maximum price less than (or equal to) 
 * the price quoted by the customer
 * for that we use set 
 * we do not use vector because we need to delete elements 
 * deletion in vector is O(n) operation
 * negative is uploaded to adjust for lower bound 
 */
