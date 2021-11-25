#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll N;
    cin >> N;
    vector<int> dig;
    while (N) {
        dig.emplace_back(N % 5);
        N /= 5;
    }
    reverse(dig.begin(), dig.end());
    int len = dig.size();
    for (int i = 0; i < len; i++) {
        if (dig[i] == 2) {
            cout << "NO" << '\n';
            return;
        }
        if (dig[i] == 3) {
            if (i == 0 || i == len - 1) {
                cout << "NO" << '\n';
                return;
            }
            if (dig[i + 1] != 3 && dig[i + 1] != 4) {
                cout << "NO" << '\n';
                return;
            }
            if (dig[i - 1] == 1) {
                cout << "NO" << '\n';
                return;
            }
        }
        if (dig[i] == 4) {
            if ((i > 0) && (dig[i - 1] == 1)) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    return;    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}