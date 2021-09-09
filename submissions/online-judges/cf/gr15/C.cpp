#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;

bool cut(int a, int b, int c, int d) {
    vector<pair<int, int>> ve;
    ve.emplace_back(a, 0);
    ve.emplace_back(b, 0);
    ve.emplace_back(c, 1);
    ve.emplace_back(d, 1);
    sort(ve.begin(), ve.end());
    return (ve[0].second == ve[2].second);
}

void solve() {
    cin >> n >> k;
    vector<bool> udah(2 * n + 1, false);
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
        udah[x[i]] = true;
        udah[y[i]] = true;
    }
    int A = 0;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (cut(x[i], y[i], x[j], y[j])) A++;
        }
    }
    vector<int> kosong;
    for (int i = 1; i <= 2 * n; i++) {
        if (!udah[i]) kosong.emplace_back(i);
    }
    for (int i = 0; i < n - k; i++) {
        int a = kosong[i], b = kosong[i + n - k];
        for (int j = 0; j < k; j++) {
            if (cut(a, b, x[j], y[j])) A++;
        }
    }
    A += (n - k) * (n - k - 1) / 2;
    cout << A << '\n';
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