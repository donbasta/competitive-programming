#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        if (n == 1) {
            cout << 0 << '\n'
                 << ar[0] << '\n';
            continue;
        }
        sort(ar.begin(), ar.end(), greater<>());
        if (ar[0] == ar.back()) {
            cout << (1ll * (n - 1) * ar[0] * ar[0]) << '\n';
            for (int i = 0; i < n; i++) {
                cout << ar[i] << ' ';
            }
            cout << '\n';
            continue;
        }
        deque<int> de1, de2;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                de1.push_front(ar[i]);
                de2.push_back(ar[i]);
            } else {
                de1.push_back(ar[i]);
                de2.push_front(ar[i]);
            }
        }
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += 1ll * de1[i] * de1[i - 1];
        }
        cout << ans << '\n';
        while (1ll * de1.back() * de1.front() == de1.back() * de1[n - 2] && de1.back() <= de1.front()) {
            int x = de1.back();
            de1.pop_back();
            de1.push_front(x);
        }
        while (1ll * de2.back() * de2.front() == de2.back() * de2[n - 2] && de2.back() <= de2.front()) {
            int x = de2.back();
            de2.pop_back();
            de2.push_front(x);
        }
        deque<int> de = min(de1, de2);
        for (auto e : de) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}
