#include <bits/stdc++.h>

using namespace std;

string go(const string& s) {
    int n = (int)s.length();
    vector<pair<int, int>> p(n);
    for (int i = 0, pre = 0; i < n; i++) {
        p[i] = {pre, -i};
        if (s[i] == '(') {
            pre++;
        } else {
            pre--;
        }
    }
    sort(p.begin(), p.end());
    string ret;
    for (int i = 0; i < n; i++) {
        int j = -p[i].second;
        ret.push_back(s[j]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> idx;
    vector<string> ve;
    for (int i = 0; i < 14; i++) {
        string ss;
        cin >> ss;
        ve.push_back(ss);
        idx[ss] = i;
    }

    for (int i = 0; i < 14; i++) {
        cerr << idx[ve[i]] << ' ' << idx[go(ve[i])] << '\n';
        cerr << ve[i] << ' ' << go(ve[i]) << '\n';
        cerr << '\n';
    }

    return 0;
}