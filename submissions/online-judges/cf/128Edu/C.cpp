#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s;
    cin >> s;
    int one = 0;
    int n = s.length();
    vector<int> ze(n + 1), on(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one++;
        }
        ze[i + 1] = ze[i] + (s[i] == '0');
        on[i + 1] = on[i] + (s[i] == '1');
    }

    const auto check = [&](int m) -> bool {
        for (int i = 1; i <= n; i++) {
            int a = lower_bound(on.begin(), on.end(), one - m + on[i - 1]) - on.begin();
            int b = upper_bound(ze.begin(), ze.end(), m + ze[i - 1]) - ze.begin();
            --b;
            if (b >= a) {
                return true;
            }
        }
        return false;
    };

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << '\n';
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