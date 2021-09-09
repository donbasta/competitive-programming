#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 4e6;

int n, MOD;
int dp[N + 5];
int lpf[N + 5];

void init() {
    for (int i = 2; i <= n; i++) {
        if (lpf[i]) continue;
        for (int j = i; j <= n; j += i) {
            lpf[j] = i;
        }
    }
}

void generateDivisors(int curIdx, int curDiv, vector<pair<int, int>>& ar, vector<int>& div) {
    if (curIdx == ar.size()) { div.emplace_back(curDiv); return; }
    for (int i = 0; i <= ar[curIdx].second; i++) {
        generateDivisors(curIdx + 1, curDiv, ar, div);
        curDiv *= ar[curIdx].first;
    }
}

vector<int> gen_div(int x) {
    vector<pair<int, int>> p;
    vector<int> d;
    while (x > 1) {
        int pw = 0;
        int cur = lpf[x];
        while (x % cur == 0) {
            pw++, x /= cur;
        }
        p.emplace_back(cur, pw);
    }
    generateDivisors(0, 1, p, d);
    return d;
}

void solve() {
    cin >> n >> MOD;
    init();

    dp[1] = 1;
    dp[2] = 2;
    if (n < 3) {
        cout << n << '\n';
        return;
    }
    for (int i = 3; i <= n; i++) {
        int tmp = (1LL * dp[i - 1] * 2 + 1) % MOD;
        vector<int> lol = gen_div(i);
        for (auto j : lol) {
            if (j == i || j == 1) continue;
            tmp = (tmp + dp[i / j] - dp[(i - 1) / j]) % MOD;
        }
        if (tmp < 0) tmp += MOD;
        dp[i] = tmp;
    }
    int ans = (dp[n] % MOD);
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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