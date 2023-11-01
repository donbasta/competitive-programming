#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MX = 2e5;

void el_psy_congroo() {
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n + 2), pre(n + 2);
    h[0] = h[n + 1] = MX;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        pre[i] = pre[i - 1] + h[i];
    }
    pre[n + 1] = pre[n] + h[n + 1];
    auto sum = [&](ll x, ll y) -> ll {
        if (x == 0) return pre[y];
        return pre[y] - pre[x - 1];
    };
    vector<int> L(n + 2, 0), R(n + 2, n + 1);
    {
        vector<pair<int, int>> tmp;
        for (int i = 0; i <= n + 1; i++) {
            while (!tmp.empty() && h[i] > tmp.back().first) {
                R[tmp.back().second] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(h[i], i);
        }
    }
    {
        vector<pair<int, int>> tmp;
        for (int i = n + 1; i >= 0; i--) {
            while (!tmp.empty() && h[i] > tmp.back().first) {
                L[tmp.back().second] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(h[i], i);
        }
    }
    ll timer = min(h[m], h[m + 1]);
    ll le = m, ri = m;  // left and right full cavity
    while (le > 0 || ri < n) {
        if (h[le] < h[ri + 1]) {
            int x = L[le];
            timer += sum(x + 1, le);
            timer += min(h[x], h[ri + 1]) - h[le];
            le = x;
        } else if (h[le] > h[ri + 1]) {
            int x = R[ri + 1];
            timer += sum(ri + 1, x - 1);
            timer += min(h[le], h[x]) - h[ri + 1];
            ri = x - 1;
        } else if (h[le] == h[ri + 1]) {
            int x = L[le], y = R[ri + 1];
            timer += max(sum(x + 1, le), sum(ri + 1, y - 1));
            timer += min(h[x], h[y]) - h[le];
            le = x, ri = y - 1;
        }
        // cerr << le << ' ' << ri << ' ' << timer << '\n';
    }
    cout << timer << '\n';
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