#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n >> s;
    vector<vector<char>> ans(n, vector<char>(n, '='));
    vector<int> haha;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            haha.emplace_back(i);
        }
    }
    int sz = (int) haha.size();
    if ((sz == 1) || (sz == 2)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < sz; i++) {
        int A = haha[i];
        int B = haha[(i + 1) % sz];
        ans[A][B] = '+';
        ans[B][A] = '-';
    }
    for (int i = 0; i < n; i++) {
        ans[i][i] = 'X';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return;
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