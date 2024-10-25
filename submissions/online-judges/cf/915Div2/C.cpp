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
    char c = *max_element(s.begin(), s.end());
    string ret = s;

    vector<pair<int, int>> suf(n);
    suf[n - 1] = make_pair(s[n - 1], n - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] >= suf[i + 1].first) {
            suf[i] = make_pair(s[i], i);
        } else {
            suf[i] = suf[i + 1];
        }
    }

    vector<int> pos;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            pos.push_back(i);
            last = i;
        }
    }
    int cmax = pos.size();
    int cur = last + 1;
    while (cur < n) {
        int k = suf[cur].second;
        pos.push_back(k);
        cur = k + 1;
    }
    int sz = pos.size();
    int steps = sz - cmax;
    // cerr << sz << ' ' << cmax << ' ' << steps << '\n';
    vector<char> tmp;
    for (int j = 0; j < sz - cmax; j++) {
        tmp.push_back(ret[pos[j + cmax]]);
    }
    reverse(tmp.begin(), tmp.end());
    for (int j = 0; j < sz - cmax; j++) {
        ret[pos[j]] = tmp[j];
    }
    for (int j = sz - cmax; j < sz; j++) {
        ret[pos[j]] = c;
    }
    // cerr << ret << '\n';
    sort(s.begin(), s.end());
    if (s == ret) {
        cout << steps << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}