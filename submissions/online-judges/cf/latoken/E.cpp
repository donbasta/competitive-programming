#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;

void ask(int s) {
    cout << "? ";
    for (int cnt = 1; cnt <= k; cnt++) {
        cout << s << ' ';
        s = (s + 1) % n;
        if (s == 0) s = n;
    }
    cout << endl;
}

bool ok(int d) {
    bool ok1 = ((k * d) % 2) == (n % 2);
    int base = (k * d) / n;
    if (base % 2 == 0) base--;
    bool ok2 = (((k * d) % n == 0) || (((k * d) % n != 0) && (base + 2 <= d)));
    return ok1 && ok2;
}

void solve() {
    cin >> n >> k;
    if ((k % 2 == 0) && (n % 2 == 1)) {
        cout << -1 << endl;
        return;
    }
    if (n % k == 0) {
        int ans = 0;
        for (int i = 1; i <= n / k; i++) {
            ask(1 + (i - 1) * k);
            int tmp;
            cin >> tmp;
            ans ^= tmp;
        }
        cout << "! " << ans << endl;
        return;
    }
    int d = max(3, ((n + k - 1) / k));
    // while (((k * d) % 2) != (n % 2)) d++;

    while(!ok(d)) d++;

    // cerr << d << '\n';

    int tot = k * d;
    int base = (k * d) / n;
    if (base % 2 == 0) base--;
    vector<int> ar(n + 1, base);
    tot -= base * n;
    for (int i = 1; i <= n; i++) {
        if (tot == 0) break;
        tot -= 2;
        ar[i] += 2;
    }
    assert(tot == 0);

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        pq.emplace(ar[i], i);
    }
    int ans = 0;
    for (int i = 0; i < d; i++) {
        vector<pair<ll, ll>> ve;
        for (int j = 0; j < k; j++) {
            auto pa = pq.top();
            pq.pop();
            ve.emplace_back(pa);
        }
        cout << "? ";
        for (auto el : ve) {
            cout << el.second << " "; 
        }
        cout << endl;
        int tmp;
        cin >> tmp;
        ans ^= tmp;
        for (int j = 0; j < k; j++) {
            pq.emplace(ve[j].first - 1, ve[j].second);
        }
    }
    cout << "! " << ans << '\n';
}

int main() {
    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}