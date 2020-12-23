#include <iostream>
using namespace std;

class Item
{
public:
    int value , weight;
};

int knapSack(int W, Item arr[] ,  int n)
{
    int i, j;
    int V[n+1][W+1];
    
    
    
    for(i=0 ; i<=n ; i++)
        V[i][0] = 0;
    for(i=0 ; i<=W ; i++)
        V[0][i] = 0;
    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= W; j++)
        {
            if (arr[i-1].weight <= j)
                V[i][j] = max(arr[i-1].value + V[i-1][j-arr[i-1].weight],  V[i-1][j]);
            else
                V[i][j] = V[i-1][j];
        }
    }
    
    int res = V[n][W];
    j = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res != V[i - 1][j])
        {
            printf("%d ", arr[i - 1].weight);
            
            res = res - arr[i - 1].value;
            j = j - arr[i - 1].weight;
        }
    }
    
    
    
    return V[n][W];
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
