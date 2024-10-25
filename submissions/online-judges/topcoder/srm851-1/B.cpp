#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

class ANewFence {
   public:
    int build(vector<int> wood) {
        int n = wood.size();
        map<int, int> cnt;
        for (auto w : wood) cnt[w]++;
        int ret = 1;
        set<int> alr;
        for (int i = 0; i < n; i++) {
            int len = wood[i];
            if (alr.count(len)) continue;
            alr.insert(len);
            int tmp = cnt[len];
            for (auto c : cnt) {
                if (c.first * 2 > len)
                    break;
                else if (c.first * 2 == len) {
                    tmp += (c.second) / 2;
                } else {
                    if (cnt.count(len - c.first)) {
                        tmp += min(c.second, cnt[len - c.first]);
                    }
                }
            }
            ret = max(ret, tmp);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = wood[i] + wood[j];
                if (alr.count(len)) continue;
                alr.insert(len);
                int tmp = 0;
                if (cnt.count(len)) tmp += cnt[len];
                for (auto c : cnt) {
                    if (c.first * 2 > len)
                        break;
                    else if (c.first * 2 == len) {
                        tmp += (c.second) / 2;
                    } else {
                        if (cnt.count(len - c.first)) {
                            tmp += min(c.second, cnt[len - c.first]);
                        }
                    }
                }
                ret = max(ret, tmp);
            }
        }

        return ret;
    }
};

void el_psy_congroo() {
    ANewFence A;
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    cout << A.build(ve) << '\n';
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