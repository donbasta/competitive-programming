#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    if (n <= 3) {
        cout << -1 << '\n';
        return;
    }
    vector<int> riMin(n, n), riMax(n, n);
    vector<int> leMin(n, -1), leMax(n, -1);
    vector<pair<int, int>> tmpMin, tmpMax;
    for (int i = 0; i < n; i++) {
        while (!tmpMin.empty() && tmpMin.back().first > ar[i]) {
            riMin[tmpMin.back().second] = i;
            tmpMin.pop_back();
        }
        tmpMin.emplace_back(ar[i], i);
        while (!tmpMax.empty() && tmpMax.back().first < ar[i]) {
            riMax[tmpMax.back().second] = i;
            tmpMax.pop_back();
        }
        tmpMax.emplace_back(ar[i], i);
    }
    tmpMin.clear(), tmpMax.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!tmpMin.empty() && tmpMin.back().first > ar[i]) {
            leMin[tmpMin.back().second] = i;
            tmpMin.pop_back();
        }
        tmpMin.emplace_back(ar[i], i);
        while (!tmpMax.empty() && tmpMax.back().first < ar[i]) {
            leMax[tmpMax.back().second] = i;
            tmpMax.pop_back();
        }
        tmpMax.emplace_back(ar[i], i);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << ' ' << leMin[i] << ' ' << leMax[i] << ' ' << riMin[i] << ' ' << riMax[i] << '\n';
    // }
    priority_queue<pair<int, int>> pq;
    for (int i = n - 1; i >= n - 3; i--) {
        int hihi = min(leMin[i], leMax[i]);
        if (hihi == -1) continue;
        pq.push(make_pair(hihi, i));
    }
    for (int i = n - 4; i >= 0; i--) {
        int bruh = max(riMin[i], riMax[i]);
        if (bruh == n) continue;
        if (!pq.empty() && pq.top().first > i) {
            cout << i + 1 << ' ' << pq.top().second + 1 << '\n';
            return;
        }
        int hihi = min(leMin[i], leMax[i]);
        if (hihi == -1) continue;
        pq.push(make_pair(hihi, i));
    }
    cout << -1 << '\n';
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