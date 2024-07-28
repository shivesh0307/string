#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PRIME 1000000009
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned int
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(c) c.size()
#define r(i, a, b) for(i = a; i < b; i++)
#define ra(i, a, b) for(i = a; i <= b; i++)
#define vi vector<int>
#define vil vector<ll>


void solve() {
    int n, k;
    string t,p; cin>>t>>p;
    string str=p+"#" +t;  n=str.size(); int l = p.size();
    vector<int> pi(n,0); 
    for(int i=1,j=0;i<n;i++)
    {
        while (j > 0 && str[j] != str[i]) { j = pi[j - 1]; }
		if (str[i] == str[j]) { j++; }
		pi[i] = j;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(pi[i]==l)
        cnt++;
    }
    cout<<cnt;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
