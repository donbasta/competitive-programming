#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;

bool isPalindrome(string ss) {
    for (int i = 0; i < ss.length(); i++) {
        if (ss[i] != ss[ss.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool isGood(string s) {
    int n = s.length();
    if (n == 1) {
        return true;
    } else if (n == 2) {
        return s[0] == s[1];
    }
    if ((s[0] == 'B') || (s[n - 1] == 'A')) {
        return true;
    }
    return false;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (isPalindrome(s)) {
        cout << "Yes" << '\n';
        return;
    }
    string ans = (isGood(s) ? "Yes" : "No");
    cout << ans << '\n';
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
