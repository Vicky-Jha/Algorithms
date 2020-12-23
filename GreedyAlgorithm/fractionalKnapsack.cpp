// C/C++ program to solve fractional Knapsack Problem
#include <iostream>
#include <vector>
using namespace std;

// Structure for an item which stores weight and corresponding
// value of Item
class Item
{
public:
    int value, weight;
    
    // Constructor
    Item(int value, int weight) : value(value), weight(weight)
    {}
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, vector<Item> arr, unsigned long n)
{
    // sorting Item on basis of ratio
    sort(arr.begin() , arr.end() , cmp);
    
//     Uncomment to see new order of Items with their ratio
    
     for (int i = 0; i < n; i++)
     {
     cout << arr[i].value << " " << arr[i].weight << " : "
     << ((double)arr[i].value / arr[i].weight) << endl;
     }
     
    
    int curWeight = 0; // Current weight in knapsack
    double finalvalue = 0; // Result (value in Knapsack)
    
    // Looping through all Items
    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it completely
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        
        // If we can't add current Item, add fractional part of it
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }
    
    // Returning final value
    return finalvalue;
}
// driver program to test above function
int main()
{
    int W = 50; // Weight of knapsack
    vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};
    
    unsigned long n = arr.size();
    
    cout << "Maximum value we can obtain = "
    << fractionalKnapsack(W, arr, n);
    cout<<endl;
    
    return 0;
}

