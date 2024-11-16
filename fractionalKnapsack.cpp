#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;

class item{
    public: 
    float price;
    float weight;
    float ratio;

    public:
    item(float p, float w){
        this->price = p;
        this->weight = w;
        this->ratio = p/w;
    }

};

bool comparator(item a, item b){
    return (a.ratio > b.ratio) ; 
}

class Knapsack{
    public:
    int capacity;
    vector<item> items;

    public:
    Knapsack(int c){
        this->capacity = c;
    }

    void addItems(float p, float w){
        items.push_back(item(p, w));
    }

    float maximizedPrice(){

        sort(items.begin(), items.end(), comparator);

        float totalPrice = 0.0;
        float currWeight = 0.0;

        for( auto &item : items){
            if(currWeight + item.weight <= capacity){
                currWeight = currWeight + item.weight;
                totalPrice = totalPrice + item.price;
            }
            else{
                double remWeight = capacity - currWeight;
                totalPrice = totalPrice + remWeight * item.ratio ;
            }
        }
        return totalPrice;
    }
};

int main(){

    Knapsack k1(20);
    k1.addItems(160000, 7);
    k1.addItems(25000, 5);
    k1.addItems(5000, 10);
    float p = k1.maximizedPrice();
    cout <<"Maximized price : "<<p<<endl;
    return 0;
}