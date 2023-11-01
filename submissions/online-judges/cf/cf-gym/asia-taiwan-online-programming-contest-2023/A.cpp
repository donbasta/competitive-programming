#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void good() {
    cout << "GOOD" << '\n';
    exit(0);
}

void late() {
    cout << "TOO LATE" << '\n';
    exit(0);
}

void el_psy_congroo() {
    string s;
    cin >> s;
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));
    if (m >= 10) {
        late();
    } else if (m <= 8) {
        good();
    } else if (m == 9) {
        if (d >= 17) {
            late();
        } else {
            good();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}