#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<bool> ve(n * m);
    vector<int> pref(n * m), pr(n * m), pc(n * m), pcr(n * m);
    for (int i = 0; i < n * m; i++) {
        ve[i] = (s[i] == '1');
        pref[i] = (i ? (pref[i - 1] + ve[i]) : ve[i]);
    }

    for (int i = 0; i <= m - 1; i++) {
        if (ve[i]) pr[i] = 1;
        else if (i > 0) pr[i] = pr[i - 1];
        else pr[i] = ve[i];
    }
    for (int i = m; i < m * n; i++) {
        pr[i] = pr[i - m] + (pref[i] > pref[i - m]);
    }
    for (int i = 0; i <= m - 1; i++) {
        pcr[i] = ve[i];
        pc[i] = (i ? pc[i - 1] + ve[i] : ve[i]);
    }
    for (int i = m; i < m * n; i++) {
        pcr[i] = pcr[i - m] + ve[i];
    }
    for (int i = m; i < m * n; i++) {
        pc[i] = pc[i - 1] + ((pcr[i - m] == 0) && ve[i]);
    }
    for (int i = 0; i < m * n; i++) {
        cout << pr[i] + pc[i] << ' ';
    }
    cout << '\n';
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