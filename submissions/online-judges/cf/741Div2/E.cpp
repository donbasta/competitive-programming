#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    set<string> se;
    vector<tuple<string, int, int>> ve;
    for (int i = 0; i < n; i++) {
        string cur;
        cur.push_back(s[i]);
        int now = i;
        bool nope = false;
        while (se.count(cur)) {
            now++;
            if (now == n) {
                nope = true;
                break;
            }
            cur.push_back(s[now]);
        }
        if (!nope) {
            se.insert(cur);
            ve.emplace_back(cur, n - now, i);
        }
    }

    int sz = (int)ve.size();
    for (int i = 0; i < sz; i++) {
        cerr << i << ' ';
        cerr << get<0>(ve[i]) << ' ';
        cerr << get<1>(ve[i]) << '\n';
        // cerr << get<2>(ve[i]) << '\n';
    }
    
    vector<vector<int>> in(sz);
    vector<int> dp(sz), deg(sz);
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            int si = get<2>(ve[i]);
            if (get<0>(ve[j]) > s.substr(si, n - si)) {
                in[j].push_back(i);
                deg[i]++;
            }
        }
    }

    for (int i = 0; i < sz; i++) {
        cerr << get<0>(ve[i]) << ' ' << i << ':';
        for (auto t : in[i]) {
            cerr << t << ' ';
        }
        cerr << '\n';
    }

    queue<int> Q;
    for (int i = 0; i < sz; i++) {
        if (deg[i] == 0) {
            Q.emplace(i);
        }
    }
    while (!Q.empty()) {
        int fr = Q.front();
        Q.pop();
        dp[fr] += get<1>(ve[fr]);
        for (auto c : in[fr]) {
            deg[c]--;
            dp[c] = max(dp[c], dp[fr]);
            if (deg[c] == 0) {
                Q.emplace(c);
            }
        }
    }
    for (int i = 0; i < sz; i++) {
        cerr << i << ' ' << dp[i] << '\n';
    }
    int ans = -1;
    for (int i = 0; i < sz; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}