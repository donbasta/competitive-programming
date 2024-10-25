#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

bool is_palindrome(const string& s) {
    string cs = s;
    reverse(cs.begin(), cs.end());
    return s == cs;
}

string reverse(const string& s) {
    string cs = s;
    reverse(cs.begin(), cs.end());
    return cs;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> s(n);
    set<string> se;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        se.insert(s[i]);
        if (is_palindrome(s[i])) {
            ok = true;
        }
    }
    if (ok) {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (se.count(reverse(s[i]))) {
            cout << "YES" << '\n';
            return;
        }
    }
    se.clear();
    se.insert(s[0]);
    for (int i = 1; i < n; i++) {
        int len = s[i].length();
        assert(len != 1);
        if (len == 2) {
            string cs = reverse(s[i]);
            for (int j = 0; j < 26; j++) {
                string tmp = cs;
                tmp.push_back((char)(j + 'a'));
                if (se.count(tmp)) {
                    cout << "YES" << '\n';
                    return;
                }
            }
        } else if (len == 3) {
            string cs = reverse(s[i]);
            if (se.count(cs.substr(0, 2))) {
                cout << "YES" << '\n';
                return;
            }
        }
        se.insert(s[i]);
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}