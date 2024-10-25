#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

int s;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    pre[0] = ar[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + ar[i];
    }
    if (s == 0) {
        ll sum = 0;
        for (int i = 0; i <= (n / 2); i++) {
            sum += ar[i];
        }
        if (n % 2 == 0) sum -= ar[0];
        cout << sum << '\n';
    } else if (s == 1) {
        ll score = 0;
        int len = 1;
        for (int i = n - 1; i >= 0; i -= 2) {
            ll cur_score = pre[i + len - 1] - (i ? pre[i - 1] : 0);
            score = max(score, cur_score);
            len++;
        }
        cout << score << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC >> s;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}