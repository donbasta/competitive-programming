#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, x;
ll ans;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    pq.push(x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        x -= i;
        pq.push(x);
        if (pq.top() > x) {
            ans += pq.top() - x;
            pq.pop();
            pq.push(x);
        }
    }
    cout << ans << '\n';
    return 0;
}
