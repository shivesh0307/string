#include <bits/stdc++.h>
using namespace std;

#define PRIME1 1000000007
#define PRIME2 1000000009
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

ll n, k, q, queries; 
string s, rs;
ll p1 = 31, p2 = 37; 
ll m1 = PRIME1, m2 = PRIME2;
map<ll, vector<pair<pair<ll, ll>, ll>>> queries_map;   // length with all hashes
vil power1(MAX, 1), power2(MAX, 1);
vil mpower1(MAX, 1), mpower2(MAX, 1); // store the mutliplicative inverses
vil hash1(MAX, 0), hash2(MAX, 0);

// Function to solve the problem
pair<ll, ll> getHash(string &st)
{
    ll hash1_val = 0, hash2_val = 0;
    for(size_t i = 0; i < st.size(); i++)
    {
        hash1_val = (hash1_val + (st[i] - 'a' + 1) * power1[i]) % m1;
        hash2_val = (hash2_val + (st[i] - 'a' + 1) * power2[i]) % m2;
    }
    return {hash1_val, hash2_val};
}

ll modInverse(ll a, ll mod) {
    ll m0 = mod, t, q;
    ll x0 = 0, x1 = 1;

    if (mod == 1) return 0;

    while (a > 1) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

ll solve() {
    ll i, j, x;
    cin >> s >> queries; 
    n = s.size();
    vector<string> vs(queries);
    vil ans(queries, 0);

    // Precompute powers and modular inverses for both hash functions
    for(i = 1; i < MAX; i++) {
        power1[i] = (power1[i-1] * p1) % m1;
        power2[i] = (power2[i-1] * p2) % m2;
        mpower1[i] = modInverse(power1[i], m1);
        mpower2[i] = modInverse(power2[i], m2);
    }

    // Compute hash for each query and store them in map
    for(i = 0; i < queries; i++) {
        cin >> vs[i];
        auto hash_pair = getHash(vs[i]);
        queries_map[vs[i].size()].pb({hash_pair, i});
    }

    // Compute prefix hashes for the string `s` for both hash functions
    for(i = 1; i <= n; i++) {
        hash1[i] = (hash1[i-1] + (s[i-1] - 'a' + 1) * power1[i-1]) % m1;
        hash2[i] = (hash2[i-1] + (s[i-1] - 'a' + 1) * power2[i-1]) % m2;
    }

    auto computeHash = [&](int l, int r) -> pair<ll, ll> {
        ll hr1 = hash1[r+1], hl1 = hash1[l];
        ll hr2 = hash2[r+1], hl2 = hash2[l];
        ll res1 = (((hr1 - hl1 + m1) % m1) * mpower1[l]) % m1;
        ll res2 = (((hr2 - hl2 + m2) % m2) * mpower2[l]) % m2;
        return {res1, res2};
    };

    // Check for each length
    for(auto &len_pair : queries_map) {
        ll len = len_pair.first;
        vector<pair<pair<ll, ll>, ll>> &hashes = len_pair.second;
        sort(hashes.begin(), hashes.end());

        for(i = 0; i <= n - len; i++) {
            auto h1 = computeHash(i, i + len - 1);
            auto startInd = lower_bound(hashes.begin(), hashes.end(), mp(h1, LLONG_MIN));
            auto endInd = upper_bound(hashes.begin(), hashes.end(), mp(h1, LLONG_MAX));
            for(auto it = startInd; it != endInd; ++it) {
                if(ans[it->second] == 1) break;
                if(it->first == h1) {
                    ans[it->second] = 1;
                }
                else break;
                
                
            }
        }
    }

    for(ll a : ans) {
        if(a == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
