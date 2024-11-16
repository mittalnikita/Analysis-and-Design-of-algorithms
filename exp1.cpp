#include<iostream>
using namespace std;

float exp(float a, int n){
    if(n==1){
        return a;
    }
    float ans = 1;
    ans = exp(a, n/2);
    float result = (ans * ans);
    if(n%2 == 0){
        return result;    
    }
    else{
        return result*a;

    }
}

float inflationCalculator(float present, float inflation, float years){
    float future = present * exp(1 + inflation, years);
    return future;
}

int main(){
    float p = 15;
    float inf = 0.05;
    float y = 2;
    float ans = inflationCalculator(p, inf, y);
    cout<<ans;
    return 0;
}