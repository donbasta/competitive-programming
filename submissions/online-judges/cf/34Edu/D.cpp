#include <bits/stdc++.h>
using namespace std;

using ll = __int128;
using ld = long double;

const int INF = 2e9;

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    ll ans = 0;
    ll c = 1 - n;
    for (int i = 0; i < n; i++) {
        ans += c * ar[i];
        c += 2;
    }
    for (int i = 0; i < n; i++) {
        cnt[ar[i]]--;
        if (cnt[ar[i]] == 0) cnt.erase(ar[i]);
        if (cnt.count(ar[i] + 1)) ans -= cnt[ar[i] + 1];
        if (cnt.count(ar[i] - 1)) ans += cnt[ar[i] - 1];
    }
    print(ans);
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