#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    string s;
    cin >> s;
    int N;
    cin >> N;

    int n = s.length();
    assert(s.substr(0, 2) == "0.");
    string k = s.substr(2, n - 2);
    ll num = stoll(k);
    ll den = 1;
    for (int i = 0; i < n - 3; i++) den *= 10;
    ll fpb = __gcd(num, den);
    num /= fpb, den /= fpb;

    ll tmp = __gcd(num, 10ll);
    if (den <= N * tmp / 10) {
        cout << (num / tmp) << ' ' << (den * 10) << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}