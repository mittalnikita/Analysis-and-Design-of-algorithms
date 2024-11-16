// Top - Down approach

#include<stdlib.h>
#include<iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> memo;

float exponent(float a, int n){
    if(n==0){
        return 1;
    }

    if(memo.find(n) != memo.end()) return memo[n];

    float halfPower = exponent(a, n/2);

    if(n%2 == 0){
        memo[n] = halfPower* halfPower;
    }

    else{
        memo[n] = a * halfPower*halfPower;
    }

    return memo[n];

}

int main(){

    float ans = exponent(4, 3);
    cout<<ans;
    return 0;
}