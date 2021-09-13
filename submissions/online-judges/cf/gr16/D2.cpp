#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int n, m;
vector<vector<int>> bit;

void upd(int pos, int val, int id) {
    while (pos <= m) {
        bit[id][pos] += val;
        pos += (pos & (-pos));
    }
}

int get(int pos, int id) {
    int ret = 0;
    while (pos > 0) {
        ret += bit[id][pos];
        pos -= (pos & (-pos));
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    bit.assign(n, vector<int>(m + 1));

    vector<pair<int, int>> ve;
    vector<int> pos(m * n + 1);
    for (int i = 1; i <= n * m; i++) {
        int a;
        cin >> a;
        ve.emplace_back(a, -i);
    }
    sort(ve.begin(), ve.end());

    int last = ve[0].first;
    int idx = 1;
    int left = 0, right = 0;
    while (idx < m * n) {
        if (ve[idx].first == last) {
            right++;
        } else {
            if ((left / m) == (right / m)) {
                for (int i = left; i <= right; i++) {
                    pos[-ve[i].second] = i;
                }
            } else {
                int k = ((left / m) + 1) * m - 1;
                int kk = ((right / m)) * m - 1;
                for (int i = right; i >= (right + left - k); i--) {
                    pos[-ve[i].second] = (i - right + k);
                }
                for (int i = right + left - k - 1; i >= right - kk + left; i--) {
                    pos[-ve[i].second] = (i + k + 1 - left + kk - right);
                }
                for (int i = right - kk - 1 + left; i >= left; i--) {
                    pos[-ve[i].second] = i + kk + 1 - left;
                }
            }
            last = ve[idx].first;
            left = right = idx;
        }
        idx++;
    }
    if ((left / m) == (right / m)) {
        for (int i = left; i <= right; i++) {
            pos[-ve[i].second] = i;
        }
    } else {
        int k = ((left / m) + 1) * m - 1;
        for (int i = right; i >= (right + left - k); i--) {
            pos[-ve[i].second] = (i - right + k);
        }
        for (int i = right + left - k - 1; i >= left; i--) {
            pos[-ve[i].second] = (i + k + 1 - left);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n * m; i++) {
        int row = (pos[i]) / m;
        int col = (pos[i] % m);  
        ans += get(col + 1, row);
        upd(col + 1, 1, row);
    }
    cout << ans << '\n';

    bit.clear();
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