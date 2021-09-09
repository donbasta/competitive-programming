#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;
int k;

bool pr[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};

void solve() {
    cin >> k;
    cin >> s;
    if (k == 1) {
        cout << 1 << '\n';
        cout << s << '\n';
        return;
    }
    int id = 0;
    int id2 = -1, id5 = -1;
    for (auto c : s) {
        int dig = c - '0';
        if (!pr[dig]) {
            cout << 1 << '\n';
            cout << c << '\n';
            return;
        }
        if (dig == 5) {
            id5 = id;
        }
        if (dig == 2) {
            id2 = id;
        }
        id++;
    }
    if (k == 2) {
        cout << 2 << '\n';
        cout << s << '\n';
        return;
    }
    if (id2 > 0) {
        cout << 2 << '\n';
        cout << s.substr(id2 - 1, 2) << '\n';
        return;
    }
    if (id5 > 0) {
        cout << 2 << '\n';
        cout << s.substr(id5 - 1, 2) << '\n';
        return;
    }
    for (int i = 1; i < k; i++) {
        if (s[i] == s[i - 1]) {
            cout << 2 << '\n';
            cout << s.substr(i - 1, 2) << '\n';
            return;
        }
    }
    string wow = s.substr(0, 2);
    if (wow == "27" || wow == "57") {
        cout << 2 << '\n';
        cout << wow << '\n';
        return;
    } else if (wow == "23" || wow == "53") {
        cout << 2 << '\n';
        cout << s[0] << '7' << '\n';
        return;
    } else if (wow == "37") {
        cout << 2 << '\n';
        cout << 33 << '\n';
        return;
    } else if (wow == "73") {
        cout << 2 << '\n';
        cout << 77 << '\n';
        return;
    }
    assert(false);
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