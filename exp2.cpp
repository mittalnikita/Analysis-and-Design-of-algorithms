// Bottom-Up approach

#include<stdlib.h>
#include<iostream>
using namespace std;

int main(){
    float a;
    int n;
    cout<<"Enter the base : " ;
    cin>>a;
    cout<<"Enter the exponent : ";;
    cin>>n;

    float result = 1;

    while(n>0){
        if(n%2 != 0){
            result = result * a;
        }

        n = n/2;
        a = a*a;
    }

    cout<<"Answer is "<<result<<endl;

    return 0;
}