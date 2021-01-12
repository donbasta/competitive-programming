#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;
bool gpf[N + 5];
vector<int> primes;

void sieve() {
    memset(gpf, -1, sizeof(gpf));
    for (int i = 2; i <= N; i++) {
        if (!pr[i]) continue;
        primes.emplace_back(i);
        for (int j = i + i; j <= N; j += i) {
            pr[j] = false;
        }
    }
}

void solve() {
    sieve();
    cout << (int)primes.size() << '\n';
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