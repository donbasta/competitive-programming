#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int PT[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

void solve() {
    int t;
    cin >> t;
    unordered_map<string, int> driver_pts;
    unordered_map<string, vector<int>> pos;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (i < 10) driver_pts[s] += PT[i];
            if (pos[s].empty()) pos[s].resize(50);
            pos[s][i]++;
        }
    }
    vector<string> drivers;
    for (auto e : pos) {
        drivers.push_back(e.first);
    }
    sort(drivers.begin(), drivers.end(), [&](string a, string b) -> bool {
        if (driver_pts[a] == driver_pts[b]) {
            return pos[a] > pos[b];
        }
        return driver_pts[a] > driver_pts[b];
    });
    cout << drivers[0] << '\n';
    sort(drivers.begin(), drivers.end(), [&](string a, string b) -> bool {
        if (pos[a][0] == pos[b][0]) {
            if (driver_pts[a] == driver_pts[b]) {
                return pos[a] > pos[b];
            }
            return driver_pts[a] > driver_pts[b];
        }
        return pos[a][0] > pos[b][0];
    });
    cout << drivers[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}