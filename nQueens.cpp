#include<stdlib.h>
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class PlaceNQueens{
    private:
    vector<int>tuples;
    public:
    int n;

    public:
    PlaceNQueens(int numberOfQueens){
        n = numberOfQueens;
        tuples.resize(n+1);
        
    }

    bool isSafe(int k, int i){
        for(int j=1; j<k; j++){
            if(tuples[j] == i || abs(tuples[j] - i) == abs(j-k)){
                return false;
            }
        }
        return true;
    }

    void placeQueens(int k){
        
        for(int i=1; i<=n; i++){
            if(isSafe(k, i)){
                tuples[k] = i;
                if(k==n){
                    cout<<"Answer is ( ";
                    for(int l=1; l<=n; l++){
                        cout<<tuples[l]<<' ';
                    }
                    cout<<")"<<endl;
                }
                else{
                    placeQueens(k+1);
                }
            }
        }
    }

};

int main(){
    int n = 4;
    PlaceNQueens m1(n);
    m1.placeQueens(1);

    return 0;
}