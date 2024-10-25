#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() <= p[i]) {
            ans += p[i] - pq.top();
            pq.pop();
            pq.push(p[i]);
        }
        pq.push(p[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}