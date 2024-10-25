#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    int cur = 0;

    auto answer = [&](int p, int q, int r) {
        for (int i = 0; i < p; i++) cout << 1;
        for (int i = 0; i < q; i++) cout << 2;
        for (int i = 0; i < r; i++) cout << 3;
        cout << '\n';
        return;
    };

    for (int i = 1; i <= 15; i++) {
        for (int a = i; a >= 0; a--) {
            for (int b = i - a - 1; b >= 0; b--) {
                cur++;
                if (cur == n) {
                    answer(a, b, i - a - b);
                    return;
                }
            }
        }
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