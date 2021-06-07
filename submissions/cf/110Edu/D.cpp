#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 20;

int k, q;
string s;

int tr[(1 << N) + 5];

void init(int idx) {
    if (idx >= k && idx < 2 * k) {
        tr[idx] = 1;
        return;
    }
    init(2 * idx);
    init(2 * idx + 1);
    if (s[k - 1 - idx] == '1') {
        tr[idx] = tr[2 * idx];
    } else if (s[k - 1 - idx] == '0') {
        tr[idx] = tr[2 * idx + 1];
    } else if (s[k - 1 - idx] == '?') {
        tr[idx] = tr[2 * idx] + tr[2 * idx + 1];
    }
}

void recalc(int idx) {
    if (idx == 0) return;
    if (s[k - 1 - idx] == '1') {
        tr[idx] = tr[2 * idx];
    } else if (s[k - 1 - idx] == '0') {
        tr[idx] = tr[2 * idx + 1];
    } else if (s[k - 1 - idx] == '?') {
        tr[idx] = tr[2 * idx] + tr[2 * idx + 1];
    }
    recalc(idx / 2);
}

void update(int idx, char cc) {
    if (cc == '1') {
        tr[idx] = tr[2 * idx];
    } else if (cc == '0') {
        tr[idx] = tr[2 * idx + 1];
    } else if (cc == '?') {
        tr[idx] = tr[2 * idx] + tr[2 * idx + 1];
    }
    recalc(idx / 2);
}

void solve() {
    cin >> k >> s >> q;
    k = (1 << k);

    init(1);

    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        s[p - 1] = c;
        update(k - p, c);
        cout << tr[1] << '\n';
    }
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