#include<iostream>
#include<string>

using namespace std;

int longestCommonSubsequece(string str1, string str2, int len1, int len2)
{
    int i, j;
//    vector<vector<int> > dp(n+1,vector<int> (m+1,0));
    
    int LCS[len1+1][len2+1];
    
    for(i=0;i<=len1;i++)
        LCS[i][0]=0;
    
    for(j=0;j<=len2;j++)
        LCS[0][j]=0;
    
    
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            
            if(str1[i-1]==str2[j-1])
            {
                LCS[i][j]=1+LCS[i-1][j-1];
            }
            
            
            else
            {
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
     int index = LCS[len1][len2];
    char lcs[index+1];
    lcs[index] = '\0';
    
   
    
    i=len1;
    j=len2;
    
    while(1)
    {
    if(str1[i-1] == str2[j-1])
    {
        lcs[index-1] = str1[i-1];
        index--;
        i--;
        j--;
        if(index == 0)
            break;
        
    }
    else if(LCS[i][j-1] < LCS[i-1][j])
        i--;
    else
        j--;
    }
    
    
    cout<<"LCS is "<<lcs<<endl;
    
    
    cout<<"LENGTH ";
    return LCS[len1][len2];
    
}


int main()
{
    string str1,str2;
    
    cout<<"Enter first string   ";
    getline(cin, str1);
    
    cout<<"Enter second string   ";
    getline(cin, str2);
    
    int len1=str1.length();
    int len2=str2.length();
    
    cout<<longestCommonSubsequece(str1,str2,len1,len2);
    
    cout<<endl;
    return 0;
}
// Worst Case Complexity is O(m.n)
