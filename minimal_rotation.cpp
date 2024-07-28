#include <bits/stdc++.h>
using namespace std;

// Function to find the lexicographically minimal rotation of a string using Booth's Algorithm
int booth(string s) {
    s = s + s;
    int n = s.size();
    vector<int> f(n, -1);
    int k = 0; // least rotation of string found so far

    for (int j = 1; j < n; j++) {
        char sj = s[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != s[k + i + 1]) {
            if (sj < s[k + i + 1]) k = j - i - 1;
            i = f[i];
        }
        if (sj != s[k + i + 1]) { // mismatch after i matches.
            if (sj < s[k]) k = j; // found a smaller rotation, start over.
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}

int main() {
    // input string
    string s; cin>>s;

    // Find the lexicographically minimal rotation
    int minRotationIdx = booth(s);

    // Print the lexicographically minimal rotation
    cout << s.substr(minRotationIdx) + s.substr(0, minRotationIdx) << endl;

    return 0;
}
