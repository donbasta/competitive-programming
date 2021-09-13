#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;

void solve() {
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i = 0; i < 20; i++) {
        if (n & (1 << i)) {
            pq.emplace(i);
        }
    }
    if ((int)pq.size() > k) {
        cout << "No" << '\n';
        return;
    }
    while ((int) pq.size() < k) {
        int lg = pq.top();
        pq.pop();
        pq.emplace(lg - 1);
        pq.emplace(lg - 1);
    }
    assert((int) pq.size() == k);
    for (int i = 0; i < k; i++) {
        cout << pq.top() << ' ';
        pq.pop();
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