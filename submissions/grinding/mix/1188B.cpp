#include <bits/stdc++.h>
using namespace std;

int n;
long long p, k, ans;
map<long long, int> mp;

long long f(long long a) {
    long long sq = a * a % p;
    long long ret = sq * sq % p - k * a;
    ret %= p;
    if (ret < 0)
        ret += p;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        mp[f(x)]++;
    }
    for (auto i : mp) {
        ans += 1LL * (i.second) * (i.second - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}