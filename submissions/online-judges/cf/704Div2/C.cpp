#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

int n, m;
string s, t;

void solve() {
    cin >> n >> m;
    cin >> s >> t;
    int pos = 0;
    vector<int> left(m), right(m);
    for (int i = 0; i < m; i++) {
        while (s[pos] != t[i]) pos++;
        left[i] = pos;
        pos++;
    }
    pos = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (s[pos] != t[i]) pos--;
        right[i] = pos;
        pos--;
    }
    int ans = -INF;
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, right[i + 1] - left[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}