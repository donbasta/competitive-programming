#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string a, b;
    cin >> a >> b;
    int la = (int) a.length();
    int lb = (int) b.length();
    set<string> se;
    for (int i = 0; i < la; i++) {
        string tmp;
        for (int j = i; j < la; j++) {
            tmp.push_back(a[j]);
            se.insert(tmp);
        }
    }
    int mx = 0;
    for (int i = 0; i < lb; i++) {
        string tmp;
        for (int j = i; j < lb; j++) {
            tmp.push_back(b[j]);
            if (se.count(tmp)) {
                int cur = (int) tmp.length();
                if (cur > mx) {
                    mx = cur;
                }
            }
        }
    }
    cout << la + lb - 2 * mx << '\n';
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