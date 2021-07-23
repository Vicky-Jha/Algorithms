#include <bits/stdc++.h>
using namespace std;
class Item
{
public:
    int value , weight;
};
int knapSack(int w, Item arr[], int n) {
    vector<int> dpTemp(w + 1), dp(w + 1, 0);
    
    for(int pos = 0; pos < n; ++pos) {
        dpTemp = dp;
        dp.resize(w + 1, 0);
        for(int i = 0; i <= w; ++i) {
            if(i >= arr[pos].weight) {
                dp[i] = max(dpTemp[i], arr[pos].value + dpTemp[i - arr[pos].weight]);
            } else {
                dp[i] = dpTemp[i];
            }
        }
//        for(int d : dp) {
//            cout << d << " ";
//        }
//        cout << endl;
    }
    return dp.back();
}

int main()
{
    int n;
    int W;
    printf("Enter number of items:");
    scanf("%d", &n);
    Item arr[n];
    printf("Enter value and weight of items:\n");
    for(int i = 0;i < n; ++i){
        cin>>arr[i].value;
        cin>>arr[i].weight;
    }
    
    printf("Enter size of knapsack:");
    scanf("%d", &W);
    
    printf("%d", knapSack(W, arr, n));
    return 0;
}
