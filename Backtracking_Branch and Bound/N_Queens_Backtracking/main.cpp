#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int board[20],count;//global variables are initialized automatically with value zero
void queen(int row,int n);


int main()
{
    int n;
    
    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens:");
    scanf("%d",&n);//max n value can be 19
    queen(1,n);
    return 0;
}

//function for printing the solution
void print(int n)
{
    int i,j;
    printf("\n\nSolution %d:\n\n",++count);
    
    for(i=1;i<=n;++i)
        printf("\t%d",i);
    
    for(i=1;i<=n;++i)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j) //for nxn board
        {
            if(board[i]==j)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
        }
    }
}

/*funtion to check conflicts
 If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;++i)
    {
        //checking column and digonal conflicts
        if(board[i]==column || abs(board[i]-column)==abs(i-row))
            return 0;
    }
    
    return 1; //no conflicts
}

//function to check for proper positioning of queen
void queen(int i,int n)
{
    int j;
    for(j=1;j<=n;++j)
    {
        if(place(i,j))
        {
            board[i]=j; //no conflicts so place queen
            if(i==n) //dead end
                print(n); //printing the board configuration
            else //try queen with next position
                queen(i+1,n);
        }
    }
}
