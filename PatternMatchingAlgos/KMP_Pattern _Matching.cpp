
#include <iostream>
using namespace std;
void prefix_table(int F[] , string S , int m)
{
    int i=1,j=0;
    F[0]=0;
    while(i<m)
    {
        if(S[i] == S[j])
        {
            F[i] = j+1;
            i++;
            j++;
        }
        else if(j > 0)
            j = F[j-1];
        else
        {
            F[i] = 0;
            i++;
        }
    }
}

void kmp(string T , string S , int n ,int m, int F[])
{
    prefix_table(F,S,m);
    int i=0,j=0;
    while(i<n)
    {
        if(T[i] == S[j])
        {
            if(j == m-1) {
                cout<<i-j<<endl;
                j = F[j-1];
            }
            else
            {
                i++;j++;
            }
        }
        else if(j > 0)
            j = F[j-1];
        else i++;
    }
}
int main()
{
    
    string S,T;
    cout<<"Enter Text"<<endl;
    getline(cin , T);
    cout<<"Enter Pattern to be searched in text"<<endl;
    getline(cin , S);
    
    int F[S.size()];
    
    kmp(T,S,T.size(),S.size(),F);
    return 0;
}

//Input 
// txt : ababeabcabababdababd
// pat : ababd

// abcdabeabf pattern
// 0 0 0 0 1 2 0 1 2 0  prefix table



