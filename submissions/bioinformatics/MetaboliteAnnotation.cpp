#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int M, K, N;

void solve() {
    cin >> M >> K >> N;
    vector<double> a(K), s(N);
    vector<pair<double, int>> m(M);
    for (int i = 0; i < M; i++) {
        cin >> m[i].first;
        m[i].second = i + 1;
    }
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    sort(m.begin(), m.end());
    for (int i = 0; i < N; i++) {
        pair<int, int> ans = make_pair(-1, -1);
        double mn = 1e18;
        for (int j = 0; j < K; j++) {
            double sel = s[i] - a[j];
            int id = upper_bound(m.begin(), m.end(), make_pair(sel, 0)) - m.begin();
            int bef = id - 1;
            if (abs(sel - m[id].first) < mn) {
                mn = abs(m[id].first - sel);
                ans = make_pair(m[id].second, j + 1);
            }
            if (bef >= 0 && abs(sel - m[bef].first) < mn) {
                mn = abs(sel - m[bef].first);
                ans = make_pair(m[bef].second, j + 1);
            }
        }
        cout << ans.first << ' ' << ans.second << '\n';
    }
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