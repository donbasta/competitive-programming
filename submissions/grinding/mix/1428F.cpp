#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> nx(n, n);
    for (int i = n - 2; i >= 0; i--) {
        if (s[i + 1] == '1')
            nx[i] = i + 1;
        else
            nx[i] = nx[i + 1];
    }

    vector<ll> f(n);
    f[n - 1] = s.back() == '1';
    int pref = s.back() == '1';
    vector<pair<int, int>> ve;
    if (pref == 1) {
        ve.emplace_back(n - 1, 1);
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '0') {
            f[i] = f[i + 1];
            pref = 0;
        } else if (s[i + 1] == '0') {
            f[i] = f[i + 1] + (nx[i] - i);
            pref = 1;
            ve.emplace_back(i, pref);
        } else if (s[i + 1] == '1') {
            pref++;
            ve.pop_back();
            while (!ve.empty() && ve.back().second < pref) ve.pop_back();
            int until;
            if (ve.empty())
                until = n - 1;
            else
                until = ve.back().first + pref - 2;
            f[i] = f[i + 1] + (until - i + 1);
            ve.emplace_back(i, pref);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f[i];
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