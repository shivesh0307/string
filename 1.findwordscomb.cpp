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

struct Trie {
    Trie* next[26];
    bool end;
    
    Trie() {
        for (int i = 0; i < 26; i++) next[i] = nullptr;
        end = false;
    }
};

void insert(Trie* root, const string& word, int i) {
    if (i == word.size()) {
        root->end = true;
        return;
    }
    if (root->next[word[i] - 'a'] == nullptr) {
        root->next[word[i] - 'a'] = new Trie();
    }
    root = root->next[word[i] - 'a'];
    insert(root, word, i + 1);
}

void solve() {
    int n, k;
    string str;
    cin >> str >> k;
    n = str.size();
    if (n == 0 || k == 0) {
        cout << 0 << endl;
        return;
    }
    vector<string> word(k);
    Trie* root = new Trie();
    for (int i = 0; i < k; i++) {
        cin >> word[i];
        insert(root, word[i], 0);
    }
    vector<ll> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        Trie* start = root;
        for (int j = i; j < n; j++) {
            if (start->next[str[j] - 'a'] != nullptr) {
                start = start->next[str[j] - 'a'];
                if (start->end) {
                    dp[i] += dp[j + 1];
                    dp[i] %= mod;
                }
            } else {
                break;
            }
        }
    }
    cout << dp[0] << endl;

    
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
