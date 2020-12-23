#include <iostream>

using namespace std;
void findOrderMRT(int L[], int n)
{
    
    sort(L, L + n);
    cout << "Optimal order in which programs are to be stored is: "<<endl;
    for (int i = 0; i < n; i++)
        cout << L[i] << " ";
    cout << endl;
    
    
    double MRT = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++)
            sum += L[j];
        MRT += sum;
    }
    MRT /= n;
    cout << "Minimum Retrieval Time of this order is " << MRT<<endl;
}


int main()
{
    int L[] = { 2, 5, 4 };
    int n = sizeof(L) / sizeof(L[0]);
    findOrderMRT(L, n);
    return 0;
}

