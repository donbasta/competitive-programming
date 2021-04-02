#include<bits/stdc++.h>
#include<string.h>
using namespace std;

using ll = long long;
using ld = long double;

string t;

void solve() {
    cin >> t;
    cout << (int) t.length() << '\n';
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