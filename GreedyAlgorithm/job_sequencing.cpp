#include<iostream>
#include<algorithm>
using namespace std;


class Job
{
public:
    string id;
    int dead;
    int profit;
};


bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}


void printJobScheduling(Job arr[], int n)
{
    
    sort(arr, arr+n, comparison);
    
    string result[n];
    bool slot[n];
    
    memset(slot, false, sizeof(slot));
    
    int count=0;
    int max_profit=0;
    
    for (int i=0; i<n; i++)
    {
        int check = arr[i].dead;
        if(check <= n)
        {
        for (int j=check-1; j>=0; j--)
        {
            
            if (slot[j]==false)
            {
                result[j] = arr[i].id;
                max_profit += arr[i].profit;
                slot[j] = true;
                count++;
                break;
            }
        }
        }
    }
    
    
    for (int i=0; i<count; i++)
        cout<<result[i]<<" ";
    cout<<endl;
    
    cout<<"Max profit is "<<max_profit<<endl;
        
}


int main()
{
//    int n;
//    cin>>n;
//    Job arr[n];
//    char id;
//    int dead , profit;
//    for(int i=0 ; i<n ; i++)
//    {
//        cin>>id;
//        arr[i].id = id;
//        cin>>dead;
//        arr[i].dead = dead;
//        cin>>profit;
//        arr[i].profit = profit;
//
//    }
    Job arr[] = { {"j1", 2, 100}, {"j2", 1, 19}, {"j3", 2, 27},
        {"j4", 1, 25}, {"j5", 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "<<endl;
    printJobScheduling(arr, n);
    return 0;
}

