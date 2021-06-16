#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll c, d, x;

void generateDivisors(int curIdx, ll curDiv, vector<pair<ll, ll>>& ar, vector<ll>& div) {
    if (curIdx == ar.size()) { div.emplace_back(curDiv); return; }
    for (int i = 0; i <= ar[curIdx].second; i++) {
        generateDivisors(curIdx + 1, curDiv, ar, div);
        curDiv *= ar[curIdx].first;
    }
}

const int N = 2e7;
int cp[N + 5];

void sieve() {
    for (int i = 2; i <= N; i++) {
        if (cp[i]) continue;
        for (int j = i; j <= N; j += i) {
            cp[j]++;
        }
    }
}

void solve() {
    cin >> c >> d >> x;
    vector<ll> div;
    vector<pair<ll, ll>> pr;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int pw = 0;
            while (x % i == 0) x /= i, pw++;
            pr.emplace_back(i, pw);
        }
    }
    if (x > 1) pr.emplace_back(x, 1);
    generateDivisors(0, 1, pr, div);
    ll ans = 0;
    for (auto& e : div) {
        if ((e + d) % c != 0) continue;
        ll cur = (e + d) / c;
        int cnt_prime = cp[cur];
        ans += (1LL << cnt_prime);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    sieve();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}