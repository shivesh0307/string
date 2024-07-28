#include <bits/stdc++.h>
using namespace std;

#define PRIME 1000000007
#define MOD 1000000009
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(c) c.size()
#define r(i, a, b) for(i = a; i < b; i++)
#define ra(i, a, b) for(i = a; i <= b; i++)
#define vi vector<int>
#define vil vector<ll>
#define MAX 200000+1 

ll n, m, k, q;
string s; 
ll dp[1001][101];
vector<int> pi(101);

// Function to calculate the KMP prefix function
void prefix_function(string s1) {
    int n1 = (int)s1.length();
    for (int i = 1; i < n1; i++) {
        int j = pi[i-1];
        while (j > 0 && s1[i] != s1[j])
            j = pi[j-1];
        if (s1[i] == s1[j])
            j++;
        pi[i] = j;
    }
}

// Recursive function to solve the problem using dynamic programming
ll calc(ll i , ll j) {
    if(dp[i][j] != -1) return dp[i][j]; //done then return
    dp[i][j] = 0; //done
    if(i == n) {
        if(j == m) return (dp[i][j] = 1);
        return (dp[i][j] = 0);
    }
    if(j == m) {
        return dp[i][j] = (26 * calc(i + 1, j))%PRIME; // we can have any alphabet at i in our string
    }
    ll t;
    for(ll k = 0; k < 26; k++) {
        // let's try to place k at i. k = 0 means 'a'
         t= j;
        while(true) {
            if(k == s[t] - 'A') {
                dp[i][j] += calc(i + 1, t + 1);
                dp[i][j]%=PRIME;
                break;
            } else if(t) {
                // where t is our progress, i.e., the largest prefix in substring from where we can start over
                t = pi[t - 1];
            }
            else
            {
                 dp[i][j] += calc(i + 1, t);
        dp[i][j]%=PRIME;
            break;
            }
        }
       //cout<<i <<" "<<j << " "<<dp[i][j]<<endl;
    }
    return dp[i][j];
}

// Function to solve the problem
ll solve() {
    ll i, j, x;
    cin >> n >> s;
    m = s.size();
    //cout<<"m " <<m<<endl;
    memset(dp, -1, sizeof(dp));
    prefix_function(s);
    //  for(i=0;i<s.size();i++) cout<<pi[i]<<" ";
    //  cout<<"\n";
    cout << calc(0, 0)<<"\n";
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<s.size();j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    return 0;
}

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
