#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ret(n, vector<int>(n));
    auto printMatrix = [&]() -> void {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ret[i][j] << ' ';
            }
            cout << '\n';
        }
    };
    if (k & 1) {
        cout << "No" << '\n';
        return;
    }
    if (k % 4 == 0) {
        cout << "Yes" << '\n';
        int cx = 0, cy = 0;
        for (int i = 0; i < k / 4; i++) {
            ret[cx][cy] = ret[cx][cy + 1] = ret[cx + 1][cy] = ret[cx + 1][cy + 1] = 1;
            cy += 2;
            if (cy == n) {
                cx += 2, cy = 0;
            }
        }
        printMatrix();
        return;
    }
    if (k == 2) {
        if (n == 2) {
            cout << "Yes" << '\n';
            cout << "1 1\n0 0\n";
        } else {
            cout << "No" << '\n';
        }
        return;
    }
    if (k == n * n - 2) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    int sisa = k - 6;
    ret[0][0] = ret[0][1] = ret[1][0] = ret[1][2] = ret[2][1] = ret[2][2] = 1;
    vector<vector<pair<int, int>>> avail;
    vector<pair<int, int>> tmp;
    for (int i = 4; i < n; i += 2) {
        tmp.emplace_back(i, 0);
        tmp.emplace_back(i, 1);
        tmp.emplace_back(i + 1, 0);
        tmp.emplace_back(i + 1, 1);
        avail.emplace_back(tmp);
        tmp.clear();
        tmp.emplace_back(i, 2);
        tmp.emplace_back(i, 3);
        tmp.emplace_back(i + 1, 2);
        tmp.emplace_back(i + 1, 3);
        avail.emplace_back(tmp);
        tmp.clear();
    }
    tmp.emplace_back(0, 2);
    tmp.emplace_back(0, 3);
    tmp.emplace_back(3, 2);
    tmp.emplace_back(3, 3);
    avail.emplace_back(tmp);
    tmp.clear();
    for (int i = 0; i < n; i += 2) {
        for (int j = 4; j < n; j += 2) {
            tmp.emplace_back(i, j);
            tmp.emplace_back(i, j + 1);
            tmp.emplace_back(i + 1, j);
            tmp.emplace_back(i + 1, j + 1);
            avail.emplace_back(tmp);
            tmp.clear();
        }
    }
    int idx = 0;
    while (sisa > 0) {
        for (auto e : avail[idx]) {
            ret[e.first][e.second] = 1;
        }
        sisa -= 4;
        idx++;
    }
    printMatrix();
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