#include <iostream>
using namespace std;
int main()
{
    string Txt , Pat;
    cout<<"Enter Text"<<endl;
    getline(cin , Txt);
    cout<<"Enter Pattern"<<endl;
    getline(cin , Pat);
    
    for(int i=0 ; i<Txt.size() - Pat.size() + 1 ; i++)
    {
        int j=0;
        while(Txt[i+j] == Pat[j])
            j++;
        if(j == Pat.size())
            cout<<i<<endl;
    }
    return 0;
}
