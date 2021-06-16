#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int n;
pair<int, int> ar[N + 5];
int pre[N + 5];

void solve() {
    cin >> n;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int idx = 1;
    for (auto e : cnt) {
        ar[idx++] = make_pair(e.second, e.first);
    }
    sort(ar + 1, ar + idx);
    for (int i = 1; i < idx; i++) {
        pre[i] = pre[i - 1] + ar[i].first;
    }
    int ans = n;
    for (int i = 0; i < idx - 1; i++) {
        ans = min(ans, n - (idx - 1 - i) * ar[i + 1].first);
    }
    cout << ans << '\n';
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