#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    if (n % 7 == 0) {
        cout << n << '\n';
        return;
    } else {
        string sn = to_string(n);
        for (int i = 0; i < sn.length(); i++) {
            for (char j = '0'; j <= '9'; j++) {
                if (i == 0 && j == '0') continue;
                char tmp = sn[i];
                sn[i] = j;
                int num = stoi(sn);
                if (num % 7 == 0) {
                    cout << num << '\n';
                    return;
                }
                sn[i] = tmp;
            }
        }
    }
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