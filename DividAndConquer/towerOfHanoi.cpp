// C++ recursive function to
// solve tower of hanoi puzzle
#include <iostream>
using namespace std;
void towerOfHanoi(int n , char S, char Aux , char D)
{

    if(n>0)
    {
        towerOfHanoi(n-1, S, D, Aux);//towerOfHanoi(n-1, A, C, B);
        cout<<"Move disk "<<n<<" from "<<S<<" to "<<D<<endl; // A // C
        towerOfHanoi(n-1, Aux, S, D);//towerOfHanoi(n-1, B, A, Aux);
    }
}
int main()
{
    int n;
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    return 0;
}

