#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string a, b;
    cin >> a >> b;
    int na = (int) a.length();
    int nb = (int) b.length();
    int db = (b[nb - 1] - '0');
    int ans = 0;
    for (int i = nb - 1; i < na; i++) {
        int tmp = (a[i] - '0');
        if ((tmp + db) == 1) {
            ans++;
        }
    }
    cout << ans << '\n';
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