#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
string s;
int n;
ll b;
set<tuple<ll, int, int>> se[100005];

int f(int idx, ll bat) {
    if (idx == -1) return 0;
    auto ptr = se[idx].lower_bound(make_tuple(bat, INF, INF));
    int ans = INF;
    int st = idx;
    if (ptr != se[idx].begin()) {
        --ptr;
        st = get<2>(*ptr);
        ans = get<1>(*ptr);
    }
    for (int i = st - 1; i >= -1; i--) {
        if (s[i + 1] == '0') continue;
        if (idx - i >= 20) break;
        if (idx - i == 19 && to_string(LLONG_MAX) < s.substr(i + 1, idx - i)) {
            break;
        }
        ll cek = stoll(s.substr(i + 1, idx - i));
        if (cek > bat) {
            break;
        }
        ans = min(ans, 1 + f(i, cek));
        se[idx].emplace(make_tuple(cek, ans, i + 1));
    }
    return ans;
}

void el_psy_congroo() {
    cin >> s;
    cin >> b;

    bool all_zero = true;
    for (auto c : s) all_zero &= (c == '0');

    if (b == 0) {
        if (all_zero) {
            cout << 0 << '\n';
        } else {
            cout << "NO WAY" << '\n';
        }
        return;
    }
    if (all_zero) {
        cout << "NO WAY" << '\n';
        return;
    }

    n = s.length();
    int ans = f(n - 1, b);

    if (ans == INF) {
        cout << "NO WAY" << '\n';
    } else {
        cout << ans - 1 << '\n';
    }
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