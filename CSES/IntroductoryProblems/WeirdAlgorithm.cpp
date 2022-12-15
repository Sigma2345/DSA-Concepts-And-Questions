#include<bits/stdc++.h>
using namespace std ; 

int main(){
   // collatz conjecture
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   long long int n;
   cin>>n ; 

   while(n!=1){
      cout << n << ' ';
      if (n % 2)
         n = 3 * n + 1; 
      
      else
         n = n/2; 
   }

   cout << 1 ;

   return 0 ; 
}
