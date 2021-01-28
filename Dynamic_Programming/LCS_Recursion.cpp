#include <iostream>
using namespace std;
int LCS(string str1 , string str2 , int i , int j)
{
    if(str1[i] == '\0' || str2[j] == '\0')
        return 0;
    else if (str1[i] == str2[j])
        return 1+ LCS(str1, str2, i+1, j+1);
    else
        return max(LCS(str1, str2, i, j+1) , LCS(str1, str2, i+1, j));
}
int main()
{
    string str1,str2;
    getline(cin, str1);
    getline(cin, str2);
    cout<<LCS(str1 , str2 , 0 ,0)<<endl;
    return 0;
}
// Worst Case Complexity is m.O(2^n) or n.O(2^m)
