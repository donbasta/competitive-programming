#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int n, m;
int bit[N + 5];

void upd(int pos, int val) {
    while (pos <= m) {
        bit[pos] += val;
        pos += (pos & (-pos));
    }
}

int get(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += bit[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    assert(n == 1);
    vector<pair<int, int>> ve;
    vector<int> ar(m + 1), pos(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> ar[i];
        ve.emplace_back(ar[i], -i);
    }
    sort(ve.begin(), ve.end());
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        pos[-ve[i].second] = i + 1;
    }
    for (int i = 1; i <= m; i++) {
        ans += get(pos[i]);
        upd(pos[i], 1);
    }
    cout << ans << '\n';

    for (int i = 1; i <= m; i++) {
        bit[i] = 0;
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