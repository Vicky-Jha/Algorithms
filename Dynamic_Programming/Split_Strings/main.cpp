# include <iostream>
#include <vector>
#include <set>
using namespace std;
// __int128

vector<string> split_string(string);

void miniMaxSum(set<int> arr) {
    
    int min=0,max=0,count=1,flag=0;
    
    for(auto x : arr)
    {
        if(count <= 4)
            min += x;
        
        if(flag == 1)
            max += x;
        
        count++;
        flag=1;
    }
    cout<<min<<" "<<max<<endl;
    
}


int main()
{
    string temp_enter_string;
    getline(cin, temp_enter_string);
    vector<string> str = split_string(temp_enter_string);
    
    set<int> v;
    int store;
    for(int i =0 ; i<5 ; i++)
    {
        store = stoi(str[i]);
        v.insert(store);
    }
    miniMaxSum(v);
    
    return 0;
}
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    
    input_string.erase(new_end, input_string.end());
    
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    
    vector<string> splits;
    char delimiter = ' ';
    
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}
