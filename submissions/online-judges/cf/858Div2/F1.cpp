#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void generate_divisors(int curIdx, int curDiv, const vector<pair<int, int>>& ar, vector<int>& div) {
    if (curIdx == ar.size()) {
        div.emplace_back(curDiv);
        return;
    }
    for (int i = 0; i <= ar[curIdx].second; i++) {
        generate_divisors(curIdx + 1, curDiv, ar, div);
        curDiv *= ar[curIdx].first;
    }
}

vector<int> divisors(int x) {
    int cx = x;
    vector<pair<int, int>> fp;
    for (int i = 2; i * i <= cx; i++) {
        if (cx % i != 0) continue;
        int pw = 0;
        while (cx % i == 0) {
            pw++, cx /= i;
        }
        fp.emplace_back(i, pw);
    }
    if (cx > 1) fp.emplace_back(cx, 1);
    vector<int> d;
    generate_divisors(0, 1, fp, d);
    return d;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end(), greater<>());
    vector<set<pair<int, int>>> se(m + 1);
    vector<int> t(n - k);
    for (int i = 0; i < n - k; i++) {
        t[i] = ar[i];
        for (auto x : divisors(ar[i])) {
            se[x].emplace(t[i], i);
        }
    }
    for (int i = n - k; i < n; i++) {
        int mn = INT_MAX;
        int idx = -1;
        int bef;
        for (auto x : divisors(ar[i])) {
            if (se[x].empty()) continue;
            if (se[x].begin()->first - x < mn) {
                mn = se[x].begin()->first - x;
                idx = se[x].begin()->second;
                bef = se[x].begin()->first;
            } else if (se[x].begin()->first - x == mn && se[x].begin()->first < bef) {
                idx = se[x].begin()->second;
                bef = se[x].begin()->first;
            }
        }
        for (auto x : divisors(t[idx])) {
            se[x].erase(make_pair(t[idx], x));
        }
        t[idx] = __gcd(t[idx], ar[i]);
        for (auto x : divisors(t[idx])) {
            se[x].emplace(t[idx], idx);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n - k; i++) {
        ans += t[i];
    }
    cout << ans << '\n';
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