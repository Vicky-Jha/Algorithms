#include<iostream>
#include<list>
#define COINS 3
using namespace std;
//see leetcode problem322 for perfect ans
float coins[COINS] = {1, 2, 5};

void findMinCoin(int cost) {
    list<int> coinList;
    
    for(int i = COINS-1; i>=0; i--) {
        while(cost >= coins[i]) {
            cost -= coins[i];
            coinList.push_back(coins[i]); //add coin in the list
            
        }
    }
    
    list<int>::iterator it;
    
    for(it = coinList.begin(); it != coinList.end(); it++) {
        cout << *it << ", ";
    }
}

int main() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    cout << "Coins are: ";
    findMinCoin(val);
    cout << endl;
}
