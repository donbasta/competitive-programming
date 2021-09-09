#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
int n;

void solve() {
    cin >> n;
    int sum = 0;
    int mn = INF;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        mn = min(mn, x);
    }
    sum -= mn;
    int ans = sum * 10 / (n - 1);
    string dans = to_string(ans);
    int sz = (int) dans.length();
    if (sz == 1) {
        cout << "0." << dans[0] << '\n';
    } else {
        for (int i = 0; i < sz - 1; i++) {
            cout << dans[i];
        }
        cout << '.';
        cout << dans[sz - 1] << '\n';
    }
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