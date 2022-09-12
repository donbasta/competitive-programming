#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> job(n + 1);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        job[x]++;
    }
    set<pair<int, int>> se;
    for (int i = 1; i <= n; i++) {
        se.emplace(job[i], i);
    }
    while (true) {
        auto a = *se.begin();
        auto b = *se.rbegin();
        if (b.first - a.first <= 1) {
            break;
        }
        pair<int, int> a1 = make_pair(a.first + 2, a.second);
        pair<int, int> b1 = make_pair(b.first - 1, b.second);
        se.erase(a);
        se.erase(b);
        se.insert(a1);
        se.insert(b1);
    }
    int time = (*se.rbegin()).first;
    cout << time << '\n';
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