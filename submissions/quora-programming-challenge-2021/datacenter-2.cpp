#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int N = 5e5;

int n;
vector<int> vals;
ll val[N + 5];
ll pre[N + 5];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        val[i] = x;
        vals.emplace_back(x);
    }
    sort(vals.begin(), vals.end());
    ll idx = -1, ans = INF;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + vals[i];
    }
    for (int i = 0; i < n; i++) {
        int bawah = lower_bound(vals.begin(), vals.end(), val[i]) - vals.begin();
        int atas = upper_bound(vals.begin(), vals.end(), val[i]) - vals.begin();
        ll sumBawah = pre[bawah];
        ll sumAtas = pre[n] - pre[atas];
        ll tmp = sumAtas - sumBawah + 1LL * (bawah - (n - atas)) * val[i];
        if (tmp < ans) {
            ans = tmp;
            idx = i;
        }
    }
    cout << idx + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}