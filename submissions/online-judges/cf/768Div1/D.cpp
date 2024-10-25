#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int fpb = 0;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
        fpb = __gcd(fpb, B[i]);
    }
    if (fpb == 1) {
        ll ans = 0;
        for (auto e : A) ans += abs(e);
        cout << ans << '\n';
        return;
    }
    vector<vector<int>> ve(fpb);
    vector<int> cnt_neg(fpb);
    vector<bool> ada_nol(fpb);
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            cnt_neg[i % fpb]++;
        }
        if (A[i] == 0) {
            ada_nol[i % fpb] = true;
        }
        ve[i % fpb].push_back(abs(A[i]));
    }
    ll sum = 0;
    // vector<int> lol(fpb);
    vector<long long> damn(2);
    for (int i = 0; i < fpb; i++) {
        if (cnt_neg[i] % 2 == 0) {
            int mn = INF;
            for (auto e : ve[i]) {
                sum += e;
                mn = min(mn, e);
            }
            damn[0] += mn;
        } else {
            if (ada_nol[i]) {
                for (auto e : ve[i]) sum += e;
            } else {
                int mn = INF;
                for (auto e : ve[i]) {
                    sum += e, mn = min(mn, e);
                }
                // lol[i] = mn;
                damn[1] += mn;
            }
        }
    }
    ll ans = sum - 2 * min(damn[0], damn[1]);
    cout << ans << '\n';
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