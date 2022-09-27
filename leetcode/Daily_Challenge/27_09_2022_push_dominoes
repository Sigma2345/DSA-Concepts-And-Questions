// https://leetcode.com/problems/push-dominoes/

/*
    we store all indexes that have been assigned R and L initially in a set
    set.lower_bound(i) returns pointer to lowest element greater than or equal to the number passed (i)
*/

// .L.R...LR..L..
// 1 3 7 8 11 
// LL.R
class Solution {
public:
    
    // 0 2 4
    string pushDominoes(string dominoes) {
        int n = dominoes.length(); 
        if(n==1) return dominoes ;
        string ans = "" ; 
        set<int> s; 
        for(int i = 0 ; i<n ; i++){
            if(dominoes[i]!='.') s.insert(i); 
        }
        if(s.size()==0) return dominoes; 
        for(int i = 0 ; i<n ; i++){
            if(dominoes[i] == '.'){
               auto it = s.lower_bound(i) ; 
               if(it==s.end()){
                   // here we get to the last index, in this case only two possiblities are there
                   // L . -> nothing will happen as L domino can only affect left domino
                   // R . -> will make i th domino fall right
                   it-- ; 
                   if(dominoes[*it] == 'R') ans += dominoes[*it] ;
                   else ans += '.' ; 
               }
               else if(it==s.begin()){
                    // the first falling domino lies on left of the current domino 
                   // . L -> will turn domino left
                   // . R -> no effect
                   if(dominoes[*it] == 'L') ans += dominoes[*it] ;
                   else ans += '.' ; 
               }
               else {
                   it-- ; 
                   auto it2 = it ;
                   it++ ;
                   if(dominoes[*it2]==dominoes[*it]) ans += dominoes[*it] ; // if equal domino then same as both 
                   else{
                        // in this case effect can be seen depending on which side is closer to the domino
                        if(dominoes[*it2] == 'R' && dominoes[*it]=='L'){
                            int dist1 = i - *it2 , dist2 = *it - i ;
                            if(dist1 < dist2) ans += 'R' ; // r closer than l
                            else if(dist1 > dist2) ans += 'L' ; // l closer than r
                            else ans += '.' ;  
                        }
                        else{
                            ans += '.' ; 
                        }
                   }
               }
            }
            else{
                ans += dominoes[i] ; 
            }
        }
        return ans ;
    }
};
