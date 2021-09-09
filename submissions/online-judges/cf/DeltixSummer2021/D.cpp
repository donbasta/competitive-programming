#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e4;
ll ar[N + 5];

int n, k;

ll query(int a, int b) {
    ll ret = 0;
    ll tmp;
    cout << "or " << a << " " << b << endl;
    cin >> tmp;
    ret += tmp;
    cout << "and " << a << " " << b << endl;
    cin >> tmp;
    ret += tmp;
    return ret;
}

void solve() {
    cin >> n >> k;
    vector<ll> sum(n + 1);
    for (int i = 2; i <= n; i++) {
        sum[i] = query(1, i);
    }
    int haha = query(2, 3);
    int sum123 = (sum[2] + sum[3] + haha) / 2;
    ar[1] = sum123 - haha;
    for (int i = 2; i <= n; i++) {
        ar[i] = sum[i] - ar[1];
    }
    sort (ar + 1, ar + n + 1);
    cout << "finish " << ar[k] << endl;
    exit(0);
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