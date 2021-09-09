#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int N = 10;
ll ar[N];

int k;
ll A, h;

bool next_combination(vector<int>& a, int n) {
    int k = (int)a.size();
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] < n - k + i + 1) {
            a[i]++;
            for (int j = i + 1; j < k; j++)
                a[j] = a[j - 1] + 1;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> k >> A >> h;
    ar[0] = A;
    ar[1] = A;
    ar[2] = (ar[1] * ar[1]) % MOD;
    ar[3] = (ar[2] * ar[2]) % MOD;
    ar[4] = (ar[3] * ar[3]) % MOD;
    ar[5] = (ar[4] * ar[4]) % MOD;
    for (int i = 1; i <= 5; i++) {
        ar[i] = (ar[i] * A) % MOD;
    }
    if (k == 1) {
        ll x = (ar[0] + ar[1] * 2) % MOD;
        ll y = (ar[1] + ar[0] * 2) % MOD;
        if (x == h) {
            cout << 1 << ' ' << 2 << '\n';
        } else if (y == h) {
            cout << 2 << ' ' << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    else if (k <= 3) {
        int pk = (1 << k);
        vector<ll> ve;
        for (int i = 1; i <= pk; i++) {
            ve.emplace_back(i);
        }
        do {
            ll now = (ve[0] * ar[0]) % MOD;
            now = (now + ve[1] * ar[1]) % MOD;
            now = (now + (ve[2] + ve[3]) * ar[2]) % MOD;
            if (k == 3) {
                now = (now + (ve[4] + ve[5] + ve[6] + ve[7]) * ar[3]) % MOD;
            }
            if (now == h) {
                vector<int> ans(pk);
                ans[ve[0] - 1] = 1;
                ans[ve[1] - 1] = 2;
                ans[ve[2] - 1] = ans[ve[3] - 1] = 3;
                if (k == 3) {
                    ans[ve[4] - 1] = ans[ve[5] - 1] = ans[ve[6] - 1] = ans[ve[7] - 1] = 5;
                }
                for (int i = 0; i < n; i++) {
                    cout << ans[i] << ' ';
                }
                return;
            }
        } while (next_permutation(ve.begin(), ve.end()));
    }
    else if (k == 4) {
        int pk = 16
        vector<ll> haha;
        for (int i = 1; i <= 8; i++) {
            haha.emplace_back(i);
        }
        vector<ll> ve(9);
        ve[0] = 1;
        for (int i = 1; i < 9; i++) {
            ve[i] = (ve[i - 1] * A) % MOD;
        }
        vector<ll> coef(4);
        coef[0] = (ve[1] - ve[9]);
        coef[1] = (ve[2] - ve[9]);
        coef[2] = (ve[3] - ve[9]);
        coef[3] = (ve[5] - ve[9]);
        ll res = (h - (ve[9] * 126)) % MOD;
        if (res < 0) res += MOD;
        do {
            ll now = (haha[0] * coef[0]) % MOD;
            now = (now + haha[1] * coef[1]) % MOD;
            now = (now + (haha[2] + haha[3]) * coef[2]) % MOD;
            now = (now + (haha[4] + haha[5] + haha[6] + haha[7]) * coef[3]) % MOD;
            if (now < 0) now += MOD;
            if (now == res) {
                vector<int> ans(pk);
                ans[ve[0] - 1] = 1;
                ans[ve[1] - 1] = 2;
                ans[ve[2] - 1] = ans[ve[3] - 1] = 3;
                if (k == 3) {
                    ans[ve[4] - 1] = ans[ve[5] - 1] = ans[ve[6] - 1] = ans[ve[7] - 1] = 5;
                }
                for (int i = 0; i < n; i++) {
                    cout << ans[i] << ' ';
                }
                return;
            }
        } while (next_combination(haha, 16))

    }
    else if (k == 5) {

    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}