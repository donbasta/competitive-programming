#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo(int n) {
    int day_limit = 9 * 60 * 60 + 30 * 60;
    int day_earliest = 8 * 60 * 60 + 30 * 60;
    int evening_limit = 12 * 60 * 60 + 30 * 60;
    int evening_earliest = 8 * 60 * 60 + 30 * 60;
    int day_duration = 8 * 60 * 60;
    int evening_duration = 9 * 60 * 60;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char type = s[0];
        int n = s.length();
        vector<int> ve;
        string cur(1, s[2]);
        for (int i = 3; i < n; i++) {
            if (s[i] == ':') {
                ve.push_back(stoi(cur));
                cur.clear();
            } else {
                cur += s[i];
            }
        }
        ve.push_back(stoi(cur));
        bool ok = true;
        int enter_time = ve[0] * 60 * 60 + ve[1] * 60 + ve[2];
        int exit_time = ve[3] * 60 * 60 + ve[4] * 60 + ve[5];
        if (type == 'D') {
            if (enter_time > day_limit) {
                ok = false;
            }
            enter_time = max(enter_time, day_earliest);
            if (exit_time - enter_time < day_duration) {
                ok = false;
            }
        } else if (type == 'E') {
            if (enter_time > evening_limit) {
                ok = false;
            }
            enter_time = max(enter_time, evening_earliest);
            if (exit_time - enter_time < evening_duration) {
                ok = false;
            }
        }
        if (!ok) {
            bad++;
        }
    }
    if (bad == 0) {
        cout << "All OK" << '\n';
    } else if (bad <= 3) {
        cout << bad << " Point(s) Deducted" << '\n';
    } else {
        cout << "Issue Show Cause Letter" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n != 0) {
        el_psy_congroo(n);
        cin >> n;
    }

    return 0;
}
