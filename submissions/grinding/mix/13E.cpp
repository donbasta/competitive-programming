#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int B = 300;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<int> pw(n), nx(n), lst_bl(n), nx_bl(n), cnt(n);

    int nb_block = n / B;
    if (n % B != 0) nb_block++;

    for (int i = 0; i < n; i++) {
        cin >> pw[i];
        nx[i] = i + pw[i];
    }
    for (int i = 0; i < nb_block; i++) {
        int LB = i * B, RB = min(n - 1, LB + B - 1);
        for (int j = RB; j >= LB; j--) {
            if (nx[j] >= RB + 1)
                nx_bl[j] = nx[j], cnt[j] = 1, lst_bl[j] = j;
            else
                nx_bl[j] = nx_bl[nx[j]], cnt[j] = cnt[nx[j]] + 1, lst_bl[j] = lst_bl[nx[j]];
        }
    }
    for (int i = 0; i < m; i++) {
        int tp, a, b;
        cin >> tp;
        if (tp == 0) {
            cin >> a >> b;
            --a;
            int LB = (a / B) * B;
            int RB = min(n - 1, LB + (B - 1));
            pw[a] = b;
            nx[a] = a + pw[a];
            if (nx[a] >= RB + 1) {
                nx_bl[a] = nx[a], cnt[a] = 1, lst_bl[a] = a;
            } else {
                nx_bl[a] = nx_bl[nx[a]], cnt[a] = cnt[nx[a]] + 1, lst_bl[a] = lst_bl[nx[a]];
            }
            for (int j = a - 1; j >= LB; j--) {
                if (nx[j] >= RB + 1 || nx[j] >= n) continue;
                nx_bl[j] = nx_bl[nx[j]];
                cnt[j] = cnt[nx[j]] + 1;
                lst_bl[j] = lst_bl[nx[j]];
            }
        } else if (tp == 1) {
            cin >> a;
            --a;
            int cur = a;
            int steps = 0;
            int lst = -1;
            while (cur < n) {
                steps += cnt[cur];
                lst = lst_bl[cur];
                cur = nx_bl[cur];
            }
            cout << (lst + 1) << ' ' << steps << '\n';
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