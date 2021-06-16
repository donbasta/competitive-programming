#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    priority_queue<int> pq;
    for (auto i : cnt) {
        pq.push(i.second);
    }
    while ((int) pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        a--, b--;
        if (a) {
            pq.push(a);
        }
        if (b) {
            pq.push(b);
        }
    }
    if (pq.empty()) {
        cout << 0 << '\n';
    } else {
        cout << pq.top() << '\n';
    }
    return;
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