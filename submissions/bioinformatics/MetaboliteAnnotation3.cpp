#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int M, K, N;

void solve() {
    cin >> M >> K >> N;
    vector<double> m(M), a(K), s(N);
    for (int i = 0; i < M; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    vector<pair<double, pair<int, int>>> lol;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            double tot = m[i] + a[j];
            pair<int, int> id = make_pair(i + 1, j + 1);
            lol.emplace_back(tot, id);
        }
    }
    sort(lol.begin(), lol.end());
    for (int i = 0; i < N; i++) {
        int id = upper_bound(lol.begin(), lol.end(), make_pair(s[i], make_pair(0, 0))) - lol.begin();
        if (id == 0) {
            cout << lol[id].second.first << ' ' << lol[id].second.second << '\n';
            continue;
        }
        int bef = id - 1;
        if (lol[id].first - s[i] <= s[i] - lol[bef].first) {
            cout << lol[id].second.first << ' ' << lol[id].second.second << '\n';
        } else {
            cout << lol[bef].second.first << ' ' << lol[bef].second.second << '\n';
        }
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