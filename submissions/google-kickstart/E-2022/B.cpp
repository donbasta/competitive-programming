#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    int n;
    cin >> n;
    vector<int> rat(n);
    for (int i = 0; i < n; i++) {
        cin >> rat[i];
    }
    vector<pair<int, int>> crat;
    for (int i = 0; i < n; i++) {
        crat.emplace_back(rat[i], i);
    }
    sort(crat.begin(), crat.end());
    for (int i = 0; i < n; i++) {
        int idx = upper_bound(crat.begin(), crat.end(), make_pair(2 * rat[i], INF)) - crat.begin();
        --idx;
        if (crat[idx].second == i) {
            --idx;
        }
        if (idx == -1) {
            cout << -1 << ' ';
            continue;
        }
        cout << crat[idx].first << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}
