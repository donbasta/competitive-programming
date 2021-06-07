#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n >> s;
    vector<bool> ada(26);
    vector<vector<bool>> ada2(26, vector<bool>(26));
    vector<vector<vector<bool>>> ada3(26, vector<vector<bool>>(26, vector<bool>(26)));
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        ada[c] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int c = s[i] - 'a';
        int d = s[i + 1] - 'a';
        ada2[c][d] = 1;
    }
    for (int i = 0; i < n - 2; i++) {
        int c = s[i] - 'a';
        int d = s[i + 1] - 'a';
        int e = s[i + 2] - 'a';
        ada3[c][d][e] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (!ada[i]) {
            cout << (char) (i + 'a') << '\n';
            return;
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (!ada2[i][j]) {
                cout << (char) (i + 'a') << (char) (j + 'a') << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (!ada3[i][j][k]) {
                    cout << (char) (i + 'a') << (char) (j + 'a') << (char) (k + 'a') << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}