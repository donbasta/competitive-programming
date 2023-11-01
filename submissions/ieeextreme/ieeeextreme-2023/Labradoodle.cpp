#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, vector<int>> pre, suf;
    vector<string> ss(n);
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
        int len = ss[i].length();
        if (len < 3) continue;
        string tmp = ss[i].substr(0, 3);
        pre[tmp].push_back(i);
        for (int j = 3; j < len; j++) {
            tmp += ss[i][j];
            pre[tmp].push_back(i);
        }
        tmp = ss[i].substr(len - 3, 3);
        reverse(tmp.begin(), tmp.end());
        suf[tmp].push_back(i);
        for (int j = len - 4; j >= 0; j--) {
            tmp += ss[i][j];
            suf[tmp].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int len = s.length();
        if (len < 5) {
            cout << "none" << '\n';
            continue;
        }
        int a = -1, b = -1;
        bool done = false;
        if (len >= 6) {
            string ki = s.substr(0, len - 3), ka = s.substr(len - 3, 3);
            reverse(ka.begin(), ka.end());
            for (int i = len - 4; i >= 2; i--) {
                if (pre.count(ki) && suf.count(ka)) {
                    if (pre[ki].size() > 1 || suf[ka].size() > 1) {
                        cout << "ambiguous" << '\n';
                        ki.pop_back();
                        ka.push_back(s[i]);
                        done = true;
                        break;
                    }
                    int aa = pre[ki][0], bb = suf[ka][0];
                    if (a == -1 && b == -1) {
                        a = aa, b = bb;
                    } else {
                        if (a != aa || b != bb) {
                            cout << "ambiguous" << '\n';
                            ki.pop_back();
                            ka.push_back(s[i]);
                            done = true;
                            break;
                        }
                    }
                }
                ki.pop_back();
                ka.push_back(s[i]);
            }
        }
        if (done) {
            continue;
        }
        {
            string ki = s.substr(0, len - 2), ka = s.substr(len - 3, 3);
            reverse(ka.begin(), ka.end());
            for (int i = len - 3; i >= 2; i--) {
                if (pre.count(ki) && suf.count(ka)) {
                    if (pre[ki].size() > 1 || suf[ka].size() > 1) {
                        cout << "ambiguous" << '\n';
                        ki.pop_back();
                        ka.push_back(s[i - 1]);
                        done = true;
                        break;
                    }
                    int aa = pre[ki][0], bb = suf[ka][0];
                    if (a == -1 && b == -1) {
                        a = aa, b = bb;
                    } else {
                        if (a != aa || b != bb) {
                            cout << "ambiguous" << '\n';
                            ki.pop_back();
                            ka.push_back(s[i - 1]);
                            done = true;
                            break;
                        }
                    }
                }
                ki.pop_back();
                ka.push_back(s[i - 1]);
            }
        }
        if (done) {
            continue;
        }
        if (a == -1 && b == -1) {
            cout << "none" << '\n';
        } else {
            cout << ss[a] << ' ' << ss[b] << '\n';
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