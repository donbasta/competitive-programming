#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
int n, k;

void solve() {
    cin >> n >> k;
    vector<int> ar(n);
    set<pair<int, int>> se;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < n - 1; i++) {
        se.emplace(ar[i], ar[i + 1]);
    }
    sort(ar.begin(), ar.end());
    int cut = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!se.count(make_pair(ar[i], ar[i + 1]))) cut++;
    }
    cout << ((cut < k) ? "Yes" : "No") << '\n';
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