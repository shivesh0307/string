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

ll n, k, q;
string s, rs;
ll p = 31; 
ll m = PRIME;

// Function to get sum from BITree up to the given index
ll getSum(vector<ll> &BITree, ll index) {
    if(index < 0) return 0;
    ll sum = 0;
    index = index + 1;
  
    while (index > 0) {
        sum += BITree[index];
        sum %= m;
        index -= index & (-index);
    }
    return sum;
}

// Function to update BITree at given index with given value
void updateBIT(vector<ll> &BITree, ll n, ll index, ll val) {
    index = index + 1;
  
    while (index <= n) {
        BITree[index] += val;
        BITree[index] %= m;
        index += index & (-index);
    }
}

// Function to construct BITree from given array
vector<ll> constructBITree(vector<ll> &arr, ll n) {
    vector<ll> BITree(n + 1, 0);
    for (int i = 0; i < n; i++) 
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}

// Function to solve the problem
ll solve() {
    ll i, j, x; ll num_queries;
    cin >> n >> num_queries >> s;
    vil arr(n, 0);
    vil rarr(n, 0);
    rs = s; 
    reverse(rs.begin(), rs.end());
    vil power(n + 1, 1);

    for (i = 1; i <= n; i++) {
        power[i] = (power[i - 1] * p) % m;
    }
    for (i = 0; i < n; i++) {
        arr[i] = ((s[i] - 'a') * power[n - i - 1]) % m;
        rarr[i] = ((rs[i] - 'a') * power[n - i - 1]) % m;
    }
    vector<ll> BITree = constructBITree(arr, n);
    vector<ll> rBITree = constructBITree(rarr, n);

    while (num_queries--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll pos; 
            char ch; 
            cin >> pos >> ch;
            pos--;
            ll oldVal = ((s[pos] - 'a') * power[n - pos - 1]) % m;
            ll newVal = ((ch - 'a') * power[n - pos - 1]) % m;
            ll oldValForReverse = ((rs[n-pos-1] - 'a') * power[n-(n - pos - 1)-1]) % m;
            ll newValForReverse =((ch - 'a') * power[n-(n - pos - 1)-1]) % m;
            s[pos] = ch;   rs[n-pos-1]=ch;
            updateBIT(BITree, n, pos, (newVal - oldVal + m) % m);
            updateBIT(rBITree, n, n - pos - 1, (newValForReverse - oldValForReverse + m) % m);
        } else {
            ll l, r;
            cin >> l >> r;
            l--; r--;
            ll hash1 = (getSum(BITree, r) - getSum(BITree, l - 1) + m) % m;
            ll hash2 = (getSum(rBITree, n - l - 1) - getSum(rBITree, n - r - 2) + m) % m;
            
            if (l > n - r - 1) {
                hash1 = (hash1 * power[l - (n - r - 1)]) % m;
            } else if (n - r - 1 > l) {
                hash2 = (hash2 * power[(n - r - 1) - l]) % m;
            }

            if (hash1 == hash2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            //cout<<hash1<<" "<<hash2<<endl;
        }
    }

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
