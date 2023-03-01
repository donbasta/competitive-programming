#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

char flip(char x) {
    if (x == '0') return '1';
    return '0';
};

vector<int> go(string a, string b) {
    vector<int> ans;
    int n = a.length();

    if (a[0] == '0') {
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] == '1') {
                ans.push_back(i);
                break;
            }
        }
    }
    a[0] = '1';

    for (int i = 1; i < n; i++) {
        if (a[i] != b[i]) {
            ans.push_back(-i);
            for (int j = n - 1; j >= i + 1; j--) {
                if (a[j - i] == '1') a[j] = flip(a[j]);
            }
            a[i] = b[i];
        }
    }
    if (b[0] == '0') {
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] == '1') {
                ans.push_back(i);
                break;
            }
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    string copy_a = a, copy_b = b;

    int ca = 0, cb = 0;
    for (auto c : a) {
        ca += (c == '0');
    }
    for (auto c : b) {
        cb += (c == '0');
    }
    if (ca == n) {
        if (cb == n) {
            cout << 0 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    if (cb == n) {
        if (ca == n) {
            cout << 0 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }

    vector<int> ans = go(a, b);

    if (ans.size() > n) {
        reverse(copy_a.begin(), copy_a.end());
        reverse(copy_b.begin(), copy_b.end());
        ans = go(copy_a, copy_b);
        for (auto& e : ans) {
            e *= -1;
        }
    }

    cout << ans.size() << '\n';
    if (ans.size() == 0) return;
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}