#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<string> s(n);
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'X') {
                cnt[(i + j) % 3]++;
            }
        }
    }
    int T = min ({cnt[0], cnt[1], cnt[2]});
    int pos;
    if (T == cnt[0]) {
        pos = 0;
    } else if (T == cnt[1]) {
        pos = 1;
    } else {
        pos = 2;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pos == ((i + j) % 3) && s[i][j] == 'X') {
                cout << 'O';
            } else {
                cout << s[i][j];
            }
        }
        cout << '\n';
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