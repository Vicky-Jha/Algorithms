//
//  main.cpp
//  searchNumberOfOccurence
//
//  Created by Vicky_Jha on 04/05/20.
//  Copyright © 2020 test. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int searchNumOccurrence(vector<int> &V, int k, int start, int end) {
    if (start > end) return 0;
    int mid = (start + end) / 2;
    if (V[mid] < k) return searchNumOccurrence(V, k, mid + 1, end);
    if (V[mid] > k) return searchNumOccurrence(V, k, start, mid - 1);
    return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);
}
int main(int argc, const char * argv[]) {
    vector<int> v = {1,2,3,4,5,6,7,7,7,7,7,7,7,9};
    int end = v.size()-1;
    cout<<searchNumOccurrence(v, 7, 0, end)<<endl;
    return 0;
}
