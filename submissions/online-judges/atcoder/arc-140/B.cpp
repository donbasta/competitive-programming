#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    priority_queue<int> lengths;
    int units = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'R') continue;
        int l = 0;
        while ((i >= (l + 1)) && (i + l + 1 < n) && (s[i - (l + 1)] == 'A') && (s[i + (l + 1)] == 'C')) {
            l++;
        }
        if (l > 0) {
            if (l > 1) lengths.emplace(l);
            else units++;
        }
    }
    int moves = 0;
    while (lengths.size() + units > 0) {
        if (units > 0) {
            while (units > 0) {
                if (lengths.size() == 0) {
                    cout << moves + units << '\n';
                    return;
                }
                int tmp = lengths.top();
                lengths.pop();
                if (tmp > 2) {
                    lengths.emplace(tmp - 1);
                } else if (tmp == 2) {
                    units++;
                }
                moves += 2;
                units--;
            }
        } else {
            int mv = 0;
            while (units == 0) {
                int len = lengths.size();
                moves += len;
                int bound = (len + 1 - mv) / 2;
                vector<int> buffers;
                for (int t = 0; t < bound; t++) {
                    int tmp = lengths.top();
                    lengths.pop();
                    if (tmp > 2) {
                        buffers.emplace_back(tmp - 1);
                    } else if (tmp == 2) {
                        units++;
                    }
                }
                while (!lengths.empty()) {
                    lengths.pop();
                }
                for (auto e : buffers) {
                    lengths.emplace(e);
                }
                mv = (mv + len) % 2;
            }
        }
    }


    cout << moves << '\n';
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