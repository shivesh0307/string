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

vector<int> manacher_odd(string s) {
    // cout<<s<<" "<<s.size()<<endl;
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
    auto res = manacher_odd(s);
    return res;
}
void solve() {
    int n, k;
    string s,t; cin>>s; 
    for(auto c: s) {
        t += string("#") + c;
    }
    t=t+string("#");
    //cout<<t<<endl;
   vector<int> len=manacher(t);
   int ind=1; int mx=len[ind];
   for(int i=2;i<len.size();i++)
   {
       if(len[i]>mx)
       {
           ind=i; 
           mx=len[ind];
       }
   }
   int left=ind-len[ind]+1;
   int right=ind+len[ind]-1;
   for(int i=left;i<=right;i++)
   {
    if(t[i]!='#')
   cout<<t[i];
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
