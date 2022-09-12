#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    map<int, int> buf;
    set<pair<int, int>> se;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (auto e : mp) {
        se.emplace(e.second, e.first);
    }
    int ptr = 0;
    int avail = k;
    while (true) {
        if (se.empty()) {
            break;
        }
        if (mp.find(ptr) != mp.end()) {
            se.erase(make_pair(mp[ptr], ptr));
        }

        if (mp.find(ptr) != mp.end()) {
            ptr++;
        } else {
            if (buf.find(ptr) == buf.end()) {
                if (avail == 0) {
                    break;
                }
            } else {
                while (buf[ptr] > 0) {
                    if (se.empty()) {
                        break;
                    }
                    auto k = *se.begin();
                    se.erase(se.begin());
                    buf[k.second]++;
                    mp[k.second]--;
                    if (mp[k.second] == 0) {
                        mp.erase(k.second);
                    }
                    if (k.first > 1) {
                        se.emplace(k.first - 1, k.second);
                    }
                    buf[ptr]--;
                }
                if (buf[ptr] == 0) {
                    buf.erase(ptr);
                }
                if (avail == 0 || se.empty()) {
                    break;
                }
            }
            avail--;
            auto k = *se.begin();
            se.erase(se.begin());
            buf[k.second]++;
            mp[k.second]--;
            if (mp[k.second] == 0) {
                mp.erase(k.second);
            }
            if (k.first > 1) {
                se.emplace(k.first - 1, k.second);
            }
            ptr++;
        }
    }
    cout << se.size() << '\n';
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