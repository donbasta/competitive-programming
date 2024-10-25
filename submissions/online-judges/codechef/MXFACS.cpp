#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    unordered_map<int, int> fp;
    for (int i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        int pw = 0;
        while (n % i == 0) {
            pw++, n /= i;
        }
        fp[i] = pw;
    }
    if (n > 1) fp[n]++;
    int mx = -1;
    int pr = -1;
    for (auto e : fp) {
        if (e.second == mx) {
            pr = min(pr, e.first);
        } else if (e.second > mx) {
            mx = e.second, pr = e.first;
        }
    }
    cout << pr << '\n';
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