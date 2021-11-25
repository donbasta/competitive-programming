#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> c1(m, vector<pair<int, int>>(n)), c2(m, vector<pair<int, int>>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            c1[j][i] = c2[j][i] = make_pair(x, i);
        }
    }
    for (int i = 0; i < m; i++) {
        sort(c1[i].begin(), c1[i].end());
        sort(c2[i].begin(), c2[i].end());
        reverse(c2[i].begin(), c2[i].end());
    }
    vector<vector<int>> c3(n, vector<int>(m)), suf(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        int st = 0;
        while (st < n) {
            int it = st + 1;
            while (it < n && c2[i][it].first == c2[i][it - 1].first) {
                it++;
            }
            for (int j = st; j < it; j++) {
                c3[c2[i][j].second][i] = it - 1;
            }
            st = it;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i < m - 1) {
                suf[j][i] = max(suf[j][i + 1], c3[j][i]);
            } else {
                suf[j][i] = c3[j][i];
            }
        }
    }
    vector<vector<int>> c4(n, vector<int>(m)), pref(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        int st = n - 1;
        while (st >= 0) {
            int it = st - 1;
            while (it >= 0 && c1[i][it].first == c1[i][it + 1].first) {
                it--;
            }
            for (int j = st; j > it; j--) {
                c4[c1[i][j].second][i] = it + 1;
            }
            st = it;
        }
    }
    for (int i = 0; i < m; i--) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                pref[j][i] = min(pref[j][i - 1], c4[j][i]);
            } else {
                pref[j][i] = c4[j][i];
            }
        }
    }

    const auto iris = [&](pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            swap(a, b);
        }
        if (a.second < b.first) {
            return make_pair(-1, -1);
        }
        return make_pair(b.first, min(a.second, b.second));
    };

    for (int i = 0; i < m - 1; i++) {
        vector<pair<int, int>> A, B;
        for (int j = 0; j < n - 1; j++) {
            A.emplace_back(pref[i][j], j);
            B.emplace_back(suf[i + 1][j], j);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        pair<int, int> interval = make_pair(0, n - 1);
        for (int j = 0; j < n; j++) {
            int kiri = pref[i][j], kanan = suf[i + 1][j];
            if (kiri > kanan) {
                swap(kiri, kanan);
            }
            interval = iris(interval, make_pair(kiri, kanan));
        }
        if (interval == make_pair(-1, -1)) {
            continue;
        } else {
            for (int j = interval.first; j <= interval.second; j++) {
                int cekKanan = lower_bound(B.begin(), B.end(), make_pair(j + 1, -1)) - B.begin();
                int cekKiri = lower_bound(A.begin(), A.end(), make_pair(j + 1, -1)) - A.begin();
                if ((cekKanan == (j + 1)) && (cekKiri == (j + 1))) {
                    cout << "YES" << '\n';
                    string s(n, 'R');
                    for (int i = 0; i < cekKanan; i++) {
                        s[B[i].second] = 'B';
                    }
                    cout << i + 1 << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO" << '\n';
    return;
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