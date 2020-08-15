#include <iostream>
using namespace std;
int board[20];
void print(int n)
{
    int j,i;
    for(j=1 ; j<=n ; j++)
    {
        for(i=1 ; i<=n; i++)
        {
            if(board[j] == i)
                cout<<" Q ";
            else cout<<" - ";
        }
        cout<<endl;
    }
}


bool place(int row , int column)
{
    int j;
    for(j=1 ; j<=row-1 ; j++)
    {
        if(board[j] == column || abs(j-row) == abs(board[j] - column))
            return false;
    }
    return true;
}
void Queens(int i,int size)
{
    int j;
    for(j=1 ; j<=size ; j++)
    {
        if(place(i,j))
        {
            board[i] = j;
            if(i ==size)
                print(size);
            else
                Queens(i+1,size);
        }
    }
}


    int main()
    {
        int n;
        cout<<"Enter number of Queens"<<endl;
        cin>>n;
        Queens(1,n);
        
        return 0;
    }
