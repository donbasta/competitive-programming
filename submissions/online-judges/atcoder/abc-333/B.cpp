#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    string s, t;
    cin >> s >> t;
    auto dis = [&](const string& ss) -> int {
        int p = ss[0] - 'A', q = ss[1] - 'A';
        int sel = abs(p - q) % 5;
        if (sel == 1 || sel == 4) return 1;
        return 2;
    };
    bool ok = (dis(s) == dis(t));
    cout << (ok ? "Yes" : "No") << '\n';
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