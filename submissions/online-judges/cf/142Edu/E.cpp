#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void generateDivisors(ll curIdx, ll curDiv, vector<pair<ll, ll>>& ar, vector<ll>& div) {
    if (curIdx == ar.size()) {
        div.emplace_back(curDiv);
        return;
    }
    for (ll i = 0; i <= ar[curIdx].second; i++) {
        generateDivisors(curIdx + 1, curDiv, ar, div);
        curDiv *= ar[curIdx].first;
    }
}

void solve() {
    ll n, m[2];
    cin >> n >> m[0] >> m[1];
    unordered_map<ll, ll> fp;
    for (ll i = 0; i < 2; i++) {
        ll haha = m[i];
        for (ll j = 2; j * j <= haha; j++) {
            if (haha % j == 0) {
                int pw = 0;
                while (haha % j == 0) {
                    pw++, haha /= j;
                }
                fp[j] = (fp[j] + pw);
            }
        }
        if (haha > 1) fp[haha] = (fp[haha] + 1);
    }

    vector<ll> divisors;
    vector<pair<ll, ll>> pr;
    for (auto e : fp) {
        pr.emplace_back(e.first, e.second);
    }
    generateDivisors(0, 1, pr, divisors);
    sort(divisors.begin(), divisors.end());
    ll ada = 0;
    ll ksor = 0;
    for (int d = 0; d < divisors.size(); d++) {
        if (divisors[d] > n * n) break;
        for (int t = 0; t < divisors.size(); t++) {
            if (divisors[t] > n) break;
            if (divisors[d] < divisors[t]) break;
            if (divisors[d] % divisors[t] != 0) continue;
            ll hasil_bagi = divisors[d] / divisors[t];
            if (hasil_bagi <= n) {
                ada++;
                ksor ^= divisors[t];
                break;
            }
        }
    }
    cout << ada << ' ' << ksor << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}