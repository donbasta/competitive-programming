#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 50000;

bool pr[N + 5];
int d;
vector<int> primes;

void sieve() {
    for (int i = 2; i <= N; i++) {
        pr[i] = true;
    }
    for (int i = 2; i <= N; i++) {
        if (!pr[i]) continue;
        primes.emplace_back(i);
        for (int j = i + i; j <= N; j += i) {
            pr[j] = false;
        }
    }
}

void solve() {
    cin >> d;
    int a1 = lower_bound(primes.begin(), primes.end(), d + 1) - primes.begin();
    int p1 = primes[a1];
    int a2 = lower_bound(primes.begin(), primes.end(), p1 + d) - primes.begin();
    int p2 = primes[a2];
    ll ans1 = 1LL * p1 * p1 * p1;
    ll ans2 = 1LL * p1 * p2;
    cout << min(ans1, ans2) << '\n';
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