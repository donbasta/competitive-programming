#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
const ll INF = 1e18;

int n, a, b;
int ar[N + 5];
vector<int> primes;
map<int, vector<int>> pos;

void check(int x) {
    for (int j = x - 1; j <= x + 1; j++) {
        int cj = j;
        for (int k = 2; k * k <= cj; k++) {
            if (cj % k == 0) {
                primes.push_back(k);
                while (cj % k == 0) cj /= k;
            }
        }
        if (cj > 1) primes.push_back(cj);
    }
}

void solve() {
    cin >> n >> b >> a;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    check(ar[1]);
    check(ar[n]);
    sort(primes.begin(), primes.end());
    primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
    for (int i = 1; i <= n; i++) {
        for (auto e : primes) {
            if (ar[i] % e == 0) pos[e].emplace_back(i);
            if ((ar[i] + 1) % e == 0 || (ar[i] - 1) % e == 0) pos[e].emplace_back(-i);
        }
    }
    ll ans = INF;
    for (auto e : pos) {
        int pr = e.first;
        auto ve = e.second;
        int sz = (int)ve.size();
        int kiri = 1, kanan = n;
        for (int i = 0; i < sz; i++) {
            if (abs(ve[i]) != i + 1) break;
            kiri++;
        }
        for (int i = sz - 1; i >= 0; i--) {
            if (abs(ve[i]) != i + 1 + n - sz) break;
            kanan--;
        }
        ll tmp = 0;
        vector<ll> preL(sz + 5), preR(sz + 5);
        if (kiri > kanan) {
            assert(sz == n);
            int cekKiri = 0, cekKanan = n + 1;
            for (int i = 0; i < sz; i++) {
                if (ve[i] < 0) cekKanan = (i + 1);
            }
            for (int i = sz - 1; i >= 0; i--) {
                if (ve[i] < 0) cekKiri = (i + 1);
            }
            if (cekKanan == 0 || cekKiri == n + 1) {
                cout << 0 << '\n';
                return;
            }
            assert(cekKanan >= cekKiri);
            tmp = 1LL * b * (cekKanan - cekKiri + 1);
            for (int i = cekKiri - 1; i <= cekKanan - 1; i++) {
                preL[i + 1] = preL[i] + (ve[i] < 0 ? a : 0);
            }
            tmp = min(tmp, preL[cekKanan]);
            for (int i = cekKanan - 1; i >= cekKiri - 1; i--) {
                preR[i + 1] = preR[i + 2] + (ve[i] < 0 ? a : 0);
            }
            tmp = min(tmp, preR[cekKiri]);
            set<ll> se;
            se.emplace(preL[cekKiri - 1] - 1LL * b * (cekKiri - 1));
            for (int i = cekKiri - 1; i <= cekKanan - 1; i++) {
                ll mn = *se.begin();
                tmp = min(tmp, preR[i + 1] + mn + 1LL * b * i);
                se.emplace(preL[i + 1] - 1LL * b * (i + 1));
            }
            ans = min(ans, tmp);
        } else {
            ll tamKiri = 1LL * b * (kiri - 1), tamKanan = 1LL * b * (n - kanan);
            for (int i = 0; i < kiri - 1; i++) {
                preL[i + 1] = preL[i] + (ve[i] < 0 ? a : 0);
            }
            for (int i = 0; i < kiri - 1; i++) {
                tamKiri = min(tamKiri, preL[i + 1] + 1LL * b * (kiri - i - 2));
            }
            for (int i = sz - 1; i >= sz - n + kanan; i--) {
                preR[i + 1] = preR[i + 2] + (ve[i] < 0 ? a : 0);
            }
            for (int i = sz - 1; i >= sz - n + kanan; i--) {
                tamKanan = min(tamKanan, preR[i + 1] + 1LL * b * (i - sz + n - kanan));
            }
            tmp = 1LL * b * (kanan - kiri + 1) + tamKiri + tamKanan;
            ans = min(ans, tmp);
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
        solve();
    }

    return 0;
}