#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string u, v;
    cin >> u >> v;
    int su = u.length(), sv = v.length();
    vector<int> cu(3), cv(3);
    for (int i = 0; i < su; i++) {
        cu[u[i] - 'A']++;
    }
    for (int i = 0; i < sv; i++) {
        cv[v[i] - 'A']++;
    }
    for (int i = 0; i < 3; i++) {
        if ((cu[i] % 2) != (cv[i] % 2)) {
            cout << "NO" << '\n';
            return;
        }
    }
    string uu, vv;
    for (int i = 0; i < su; i++) {
        if (u[i] == 'B') continue;
        if (uu.length() == 0) {
            uu.push_back(u[i]);
        } else if (uu.back() == u[i]) {
            uu.pop_back();
        } else {
            uu.push_back(u[i]);
        }
    }
    for (int i = 0; i < sv; i++) {
        if (v[i] == 'B') continue;
        if (vv.length() == 0) {
            vv.push_back(v[i]);
        } else if (vv.back() == v[i]) {
            vv.pop_back();
        } else {
            vv.push_back(v[i]);
        }
    }
    cout << (uu == vv ? "YES" : "NO") << '\n';
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