#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> from(n), to(n);
    vector<int> out(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        out[a]++;
        to[b].push_back(a);
        from[a].push_back(b);
    }
    vector<ld> prob(n);
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (out[i] == 0) {
            Q.emplace(i);
        }
    }

    vector<vector<ld>> F(n + 5);
    F[2].resize(2);
    F[2][0] = 0.5;
    for (int i = 4; i <= n; i += 2) {
        F[i].resize(i);
        F[i][0] = 1;
        for (int j = 1; j <= i - 2; j++) {
            ld P = (j >= 2 ? F[i - 2][j - 2] : 0);
            ld Q = F[i - 2][j - 1];
            F[i][j] = P * (j - 1) + Q * (i - j - 1);
        }
        for (int j = 0; j <= i - 1; j++) {
            F[i][j] /= ld(i);
        }
    }

    auto compute_prob = [&](int idx) -> void {
        int sz = from[idx].size();
        if (sz == 0) {
            if (idx == n - 1)
                prob[idx] = 1;
            else
                prob[idx] = 0;
            return;
        }
        ld tmp = 0;
        if (sz & 1) {
            for (auto c : from[idx]) {
                tmp += prob[c];
            }
            tmp /= ld(sz);
        } else {
            vector<ld> ve;
            for (auto c : from[idx]) {
                ve.push_back(prob[c]);
            }
            sort(ve.begin(), ve.end(), greater<>());
            for (int i = 0; i < sz; i++) {
                tmp += F[sz][i] * ve[i];
            }
        }
        prob[idx] = tmp;
    };

    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        compute_prob(now);
        for (auto c : to[now]) {
            out[c]--;
            if (out[c] == 0) {
                Q.emplace(c);
            }
        }
    }
    cout << fixed << setprecision(12) << prob[0] << '\n';
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