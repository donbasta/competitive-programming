#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    int nt = t.length();
    vector<int> suf(n), pref(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ns = s.length();
        int ptr = 0;
        for (int j = 0; j < ns; j++) {
            if (s[j] == t[ptr]) ptr++;
            if (ptr == nt) break;
        }
        pref[i] = ptr;
        ptr = nt - 1;
        for (int j = ns - 1; j >= 0; j--) {
            if (s[j] == t[ptr]) ptr--;
            if (ptr == -1) break;
        }
        suf[i] = nt - ptr - 1;
    }
    sort(pref.begin(), pref.end());
    sort(suf.begin(), suf.end());
    int ptr = n - 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (ptr >= 0 && pref[i] + suf[ptr] >= nt) ptr--;
        ans += (n - ptr - 1);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}