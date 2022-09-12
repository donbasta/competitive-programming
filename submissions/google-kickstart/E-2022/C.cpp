#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
 
void solve() {
    int n;
    string p;
    cin >> n;
    cin >> p;
    string pr = p;
    reverse(pr.begin(), pr.end());
    p += pr;
    vector<int> Z = z_function(p);
    int mn = -1;
    for (int i = n + 1; i < 2 * n; i++) {
        int j = 3 * n - i;
        if (Z[i] == 2 * n - i && Z[j] == 2 * n - j) {
            mn = 2 * n - i;
        }
    }  
    if (mn == -1) {
        cout << pr << '\n';
        return;
    }
    cout << pr.substr(0, mn) << '\n';

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
