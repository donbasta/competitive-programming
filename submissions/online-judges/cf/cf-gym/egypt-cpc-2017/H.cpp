#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string sb;
ll a, b;

vector<ll> prime_factors(ll x) {
    vector<ll> ret;
    for (ll j = 2; j * j <= x; j++) {
        if (x % j == 0) {
            ret.emplace_back(j);
            while (x % j == 0) x /= j;
        }
    }
    if (x > 1) ret.emplace_back(x);
    return ret;
}

void solve() {
    cin >> a >> sb;
    int len = (int) sb.length();
    ll b = stoll(sb);
    ll b1 = stoll(sb.substr(0, len / 2));
    ll b2 = stoll(sb.substr((len + 1) / 2, len / 2));
    ll pw10 = (ll) pow(10, len - (len / 2));
    ll lul = (ll) pow(10, len / 2) - 1;
    ll fpb = __gcd(b1, b2);
    if (a == b && fpb == 1) {
        cout << "impossible\n"; 
        return;
    }
    if (fpb > 1 && b2 > 0) {
        cout << b << '\n';
        return;
    }
    vector<ll> primes = prime_factors(b1);
    ll mx = -1;
    for (auto e : primes) { mx = max(mx, (b2 / e) * e); }
    if (mx <= 0) {
        if (b1 <= 2) {
            if (a >= 100) {
                cout << "impossible\n";
            } else if (a > 99 || b < 99) {
                cout << "impossible\n";
            } else {
                cout << 99 << '\n';
            }
            return;
        }
        primes = prime_factors(b1 - 1);
        mx = -1;
        for (auto e : primes) { mx = max(mx, (lul / e) * e); }
        ll ans = (b1 - 1) * pw10 + mx;
        if (len & 1) ans += ((ll) (sb[len / 2] - '0')) * (lul + 1);
        if (ans < a) {
            cout << "impossible";
        } else {
            cout << ans;
        }
    } else {
        ll ans = b - b2 + mx;
        if (ans < a) {
            cout << "impossible";
        } else {
            cout << ans;
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("halfnice.in", "r", stdin);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
  
    return 0;
}