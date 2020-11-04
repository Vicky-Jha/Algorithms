#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define MOD 1000000007
#define d 256
using namespace std;

long long powerFunc(int a , int n)
{

    int res = 1;
    while( n )
    {
        if( !( n & 1 ) )
        {
            n = n / 2;
            a = ( ( a%MOD )*( a%MOD ) ) % MOD;
        }
        else
        {
            n--;
            res = ( ( res%MOD ) *( a % MOD) )%MOD;
        }

    }
    return res%mod;

}

bool cmp(int pos, string const& p, string const& t)
{
	for ( int i = pos,k = 0; i < pos + p.size(); ++i, ++k )
		if(p[k] != t[i])
		return false;
	return true;
}

vector<int> rabin_karp(string const& p, string const& t)
{
	int m = p.size(); // pattern size
	int n = t.size(); // text size
	long long p_hash  = 0;
	vector<unsigned long long> tn(n-m+1);
	vector<int> occurrences;
	
	for ( int i = 0; i < m; i++ ){
		p_hash = ( ( p_hash % mod )*( d % mod ) % mod )+ ( p[i] - 'a' ) + 1;
		tn[0] = ( ( tn[0] % mod )*( d % mod ) % mod ) + (t[i] - 'a') + 1;
	}
	cout<<p_hash<<"\n";
	
	if(tn[0] == p_hash)
		if(cmp(0,p,t))
			occurrences.push_back(0);
	long long power = powerFunc( d,m-1 );
		
	for ( long long i = 1; i <= n - m; ++i ){
		tn[i] = d * ( tn[i-1] - (t[i-1] - 'a' + 1 )*power ) + t[i + m - 1] - 'a' + 1;
		if ( tn[i] == p_hash ) 
			if( cmp( i,p,t ) ) 
				occurrences.push_back(i);
		cout<<i<<" "<<tn[i]<<"\n";
		
	}
	return occurrences;
	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	string pat = "abc";
    string text = "abcabcabcabc";
    
    vector<int>occurrences = rabin_karp(pat, text);
    
    for ( int x : occurrences )
		cout<<x<<" ";
		cout<<"\n";

    return 0;
}
