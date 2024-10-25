#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j <= i; j++) {
            tmp.push_back(p[j]);
        }
        sort(tmp.begin(), tmp.end());
        int milk = 0, bis = (i + 1);
        bool ok = (bis <= k && milk <= m);
        for (int j = 0; j <= i; j++) {
            milk += tmp[j];
            bis--;
            ok = ok || (bis <= k && milk <= m);
        }
        if (ok) {
            ans = max(ans, i + 1);
        }
    }
    cout << ans << '\n';
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