#include<bits/stdc++.h>
using namespace std ;
#define DIVS 10
#define PI 3.14159265

// write function here 
float fn(double val){
    // calculates values of function
    return exp(val) ; 
}

int main(){


 // using integral as sum of trapezoids property to calculate integral
    float lb = 0 , ub = (360*PI)/180.0 ; 
    float divLength = (ub-lb)/DIVS ; 
    float ans = 0 ; 
    for(int i = 0 ; i<DIVS ; i++){
        float x = lb + (divLength)*i ; 
        float x1 = lb + (divLength)*(i+1) ; 
        x = fn(x), x1 = fn(x1) ; 
        float ans1 = ((x+x1)*divLength)/2 ; 
        ans = ans + ans1 ;  
    }
    cout<<ans<<endl ; 

    return 0; 
}
