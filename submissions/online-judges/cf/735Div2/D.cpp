#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    string s;
    if (n % 2 == 1) {
        if (n == 1) s = "a";
        else if (n == 3) s = "abc";
        else {
            int q = (n - 3) / 2;
            s = "aac";
            for (int i = 0; i < q; i++) s.push_back('b');
            s.push_back('a');
            for (int i = 0; i < q - 1; i++) s.push_back('b');
        }
    } else {
        if (n == 2) s = "ab";
        else if (n == 4) s = "abcd";
        else {
            int q = (n - 4) / 2;
            s = "aac";
            for (int i = 0; i < q; i++) s.push_back('b');
            s.push_back('a');
            s.push_back('d');
            for (int i = 0; i < q - 1; i++) s.push_back('b');
        }
    }
    assert(n == s.length());
    cout << s << '\n';
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