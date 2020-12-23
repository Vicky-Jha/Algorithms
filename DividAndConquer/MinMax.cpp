#include <iostream>
#include <vector>
using namespace std;
class piar
{
public:
    int min;
    int max;
};

piar getMinMax(vector<int> arr, int low, unsigned long high)
{
    piar minmax, L, R;
    int mid;
    
    
    if (low == high)
    {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    
    
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.min = arr[high];
            minmax.max = arr[low];
            return minmax;
            
        }
        else
        {
            minmax.min = arr[low];
            minmax.max = arr[high];
            return minmax;
        }
    }
    
    
    mid = int(low + high)/2;
    L = getMinMax(arr, low, mid);
    R = getMinMax(arr, mid+1, high);
    
    
    if (L.min < R.min)
        minmax.min = L.min;
        else
            minmax.min = R.min;
            
        
            if (L.max > R.max)
                minmax.max = L.max;
                else
                    minmax.max = R.max;
                    
                    return minmax;
}


int main()
{
    vector<int> arr = {1000, 11, 445, 1, 330, 3000};
    unsigned long arr_size = arr.size();
    piar minmax = getMinMax(arr, 0, arr_size-1);
    cout<<"Minimum is "<<minmax.min<<endl;
    cout<<"Maximum is "<<minmax.max<<endl;
}

