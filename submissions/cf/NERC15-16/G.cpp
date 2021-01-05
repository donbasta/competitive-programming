#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<vector<pair<int, int>>> ve(n), can(n);
    for (int i = 0; i < n; i++) {
        int x, a, b, c;
        cin >> x >> a >> b >> c;
        vector<bool> udah(c);
        int cur = 0;
        while (!udah[x]) {
            udah[x] = 1;
            ve[i].emplace_back(x, cur);
            x = (a * x + b) % c;
            cur++;
        }
        sort(ve[i].begin(), ve[i].end(), greater<pair<int, int>>());
        can[i].push_back(ve[i][0]);
        int lul = ve[i][0].first % k;
        int tmp = 1;
        int sz = (int)ve[i].size();
        while (tmp < sz && ve[i][tmp].first % k == lul) {
            tmp++;
        }
        if (tmp < sz) {
            can[i].push_back(ve[i][tmp]);
        }
    }
    int Ans = 0;
    int mn = INF;
    int idx = -1;
    vector<int> pilih(n);
    for (int i = 0; i < n; i++) {
        Ans += can[i][0].first;
        pilih[i] = can[i][0].second;
        if ((int)can[i].size() > 1) {
            if (can[i][0].first - can[i][1].first < mn) {
                mn = can[i][0].first - can[i][1].first;
                idx = i;
            }
        }
    }
    if (Ans % k == 0) {
        if (mn != INF) {
            Ans -= mn;
            pilih[idx] = can[idx][1].second;
        } else {
            Ans = -1;
        }
    }
    cout << Ans << '\n';
    if (Ans != -1) {
        for (auto e : pilih) {
            cout << e << ' ';
        }
        cout << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("generators.in", "r", stdin);
    freopen("generators.out", "w", stdout);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}