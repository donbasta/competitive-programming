#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;

void solve() {
    cin >> s;
    vector<int> dig;
    for (auto c : s) dig.emplace_back(c - '0');
    int n = (int) dig.size();
    int cur = dig[0];
    int len = 1;
    int pos[2];
    pos[0] = pos[1] = -1;
    for (int i = 1; i < n; i++) {
        if (dig[i] == cur) {
            len++;
        } else {
            if (len > 1 && pos[cur] != -1) {
                cout << "NO\n";
                return;
            }
            if (len > 1) {
                pos[cur] = i - 1;
            }
            len = 1;
            cur = dig[i];
        }
    }
    if (len > 1 && pos[cur] != -1) {
        cout << "NO\n";
        return;
    }
    if (pos[1] != -1 && pos[0] != -1 && pos[1] < pos[0]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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