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
    string str; cin>>str;  n=str.size(); 
    ll p=69420; ll m =PRIME;
    vector<ll> hash(n+1,0);
    for(int i=1;i<n+1;i++)
    {
        hash[i]=((hash[i-1]*p )%m+ (str[i-1]-'a'+1))%m;
    }
    vector<ll> pw(n+1,1);
    for(int i=1;i<n+1;i++)
    {
        pw[i]=(pw[i-1]*p)%m;
    }
    auto get = [&](int l, int r) -> ll {
        ll hr=hash[r+1];
        ll hl=(hash[l]*pw[r-l+1])%m;
        return (hr-hl+m)%m;
    };
    for(int len=1;len<=n;len++)
    {
        int currind=0;
        while(currind<n)
        {
            int l=currind; int r=min(currind+len-1,n-1);
            ll h1=get(l,r);
            ll h2=hash[r-l+1];
            //cout<<"len currind h1 h2 " <<len<<" "<<currind<<" "<<h1<<" "<<h2<<endl;
            if(h1!=h2) break;
            currind=currind+len;
        }
        //cout<<"Currind " << currind<<endl;
        if(currind>=n) cout<<len<<" ";
    }
    
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
