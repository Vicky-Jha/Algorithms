#include <bits/stdc++.h>
#include <assert.h>
// #define lli long long int
#define mod 1000000007
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

using namespace std;

unordered_map<char, int> charFreq;
unordered_map<char, string> charCode;

struct Nodes{
    
    Nodes *left, *right;
    char data;
    unsigned freq;
    
    Nodes(char data, unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
}*root= NULL;

void printHuffmanCodes(Nodes *root, string code){
    if(!root){
        return;
    }
    
    if(root->data != '$'){
        cout<<root->data<<" "<<code<<"\n";
        charCode[root->data] = code;
        return;
    }
    
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

void HuffmanCodes(char arr[], int freq[], int size){
    
    auto cmp = [](Nodes*& a, Nodes*& b){
        return a->freq > b->freq;
    };
    
    priority_queue<Nodes*, vector<Nodes*>, decltype(cmp)> minHeap(cmp);
    
    Nodes *left, *right, *parent;
    
    for(int i = 0; i < size; ++i){
        minHeap.push(new Nodes(arr[i], freq[i]));
    }
    
    while(minHeap.size() != 1){
        
        left = minHeap.top();
        minHeap.pop();
        
        right = minHeap.top();
        minHeap.pop();
        
        parent = new Nodes('$', left->freq + right->freq);
        
        parent->left = left;
        parent->right = right;
        
        minHeap.push(parent);
    }
    root = minHeap.top();
    
    printHuffmanCodes(minHeap.top(), "");
    
}

void calcFreq(string s, int size){
    for(int i = 0; i < size; ++i){
        charFreq[s[i]]++;
    }
}
string decode_file(struct Nodes* root, string s)
{
    string res = "";
    int pos = 0;
    Nodes* temp = root;
    while(pos < s.size()){
        if(s[pos] == '0'){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
        if(temp->data != '$'){
            res += temp->data;
            temp = root;
        }
        pos++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    string str;
    
    cout<<"Enter String for Huffman Coding\n";
    cin>>str;
    
    string encodedString, decodedString;
    
    calcFreq(str, str.length());

    int size = charFreq.size();
    
    char arr[size];
    int freq[size];
    
    int k = 0;
    for(auto x : charFreq){
        arr[k] = x.first;
        freq[k] = x.second;
        k++;
    }

    HuffmanCodes(arr, freq, size);
    
    for(int i = 0; i < str.size(); ++i){
        encodedString += charCode[str[i]];
    }
    
    cout<<"\nEncoded String = "<<encodedString<<endl;
    
    cout<<"\nDecoded String = "<<decode_file(root, encodedString)<<endl;
    
    return 0;
}
