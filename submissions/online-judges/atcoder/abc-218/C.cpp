#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<string> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int bs = -1, as = n, ds = -1, cs = n;
    int bt = -1, at = n, dt = -1, ct = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '#') {
                as = min(as, j);
                bs = max(bs, j);
                cs = min(cs, i);
                ds = max(ds, i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (t[i][j] == '#') {
                at = min(at, j);
                bt = max(bt, j);
                ct = min(ct, i);
                dt = max(dt, i);
            }
        }
    }
    if ((at - bt == as - bs) && (ct - dt == cs - ds)) {
        bool ok = true;
        for (int i = cs; i <= ds; i++) {
            for (int j = as; j <= bs; j++) {
                ok &= (s[i][j] == t[i + ct - cs][j + at - as]);
            }
        }
        if (ok) {
            cout << "Yes" << '\n';
            return;
        }
        ok = true;
        for (int i = cs; i <= ds; i++) {
            for (int j = as; j <= bs; j++) {
                ok &= (s[i][j] == t[ct + dt - (i + ct - cs)][at + bt - (j + at - as)]);
            }
        }
        if (ok) {
            cout << "Yes" << '\n';
            return;
        }
    }
    if ((at - bt == cs - ds) && (ct - dt == as - bs)) {
        // cerr << "haha";
        // cerr << at << ' ' << bt << ' ' << ct << ' ' << dt << '\n';
        int cat = at, cbt = bt, cct = ct, cdt = dt;
        at = n - 1 - cdt;
        bt = n - 1 - cct;
        ct = cat;
        dt = cbt;
        // cerr << at << ' ' << bt << ' ' << ct << ' ' << dt << '\n';
        vector<string> tt(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) tt[i].push_back('#');
            for (int j = 0; j < n; j++) tt[i][j] = t[n - 1 - j][i];
        }
        bool ok = true;
        for (int i = cs; i <= ds; i++) {
            for (int j = as; j <= bs; j++) {
                ok &= (s[i][j] == tt[i + ct - cs][j + at - as]);
            }
        }
        if (ok) {
            cout << "Yes" << '\n';
            return;
        }
        ok = true;
        for (int i = cs; i <= ds; i++) {
            for (int j = as; j <= bs; j++) {
                ok &= (s[i][j] == tt[ct + dt - (i + ct - cs)][at + bt - (j + at - as)]);
            }
        }
        if (ok) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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