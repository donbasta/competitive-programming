#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    int n;
    string s;
    cin >> n >> s;
    string cs = s;
    sort(cs.begin(), cs.end());
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] != cs[i]) {
            ans.emplace_back(i + 1);
        }
    }
    if (ans.empty()) {
        cout << 0 << '\n';
        return;
    }
    cout << 1 << '\n';
    cout << ans.size() << ' ';
    for (auto e : ans) {
        cout << e << ' '; 
    }
    cout << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}