#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n), cnt(n + 1), pref(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }
    int mn = INF, ax = -1, ay = -1;
    for (int i = 1; i <= n; i++) {
        int r = i;
        int cari = pref[i] - (n + k + 1) / 2;
        if (cari < 0) continue;
        int l = upper_bound(pref.begin(), pref.end(), cari) - pref.begin();
        int len = (r - l + 1);
        if (len < mn) {
            mn = len, ax = l, ay = r;
        }
    }
    cout << ax << ' ' << ay << '\n';
    vector<int> flag(n);
    for (int i = 0; i < n; i++) {
        bool tmp = ((ar[i] >= ax) && (ar[i] <= ay));
        flag[i] = (tmp ? 1 : -1);
    }
    int cur = flag[0], le = 0;
    vector<pair<int, int>> ve;
    if (k == 1) {
        cout << 1 << ' ' << n << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        if (cur > 0) {
            ve.emplace_back(le, i - 1);
            if (ve.size() == k - 1) {
                ve.emplace_back(i, n - 1);
                break;
            }
            cur = flag[i], le = i;
        } else {
            cur += flag[i];
        }
    }
    assert(ve.size() == k);
    for (auto e : ve) {
        cout << (e.first + 1) << ' ' << (e.second + 1) << '\n';
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