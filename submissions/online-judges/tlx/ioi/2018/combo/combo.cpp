#include "combo.h"

#include <bits/stdc++.h>
using namespace std;

std::string guess_sequence(int N) {
    std::string lets = "ABXY";
    std::string cur;

    int fi = -1;
    if (press("AB") >= 1) {
        if (press("A") == 1) {
            fi = 0;
        } else {
            fi = 1;
        }
    } else if (press("X") == 1) {
        fi = 2;
    } else {
        fi = 3;
    }
    assert(fi != -1);
    cur.push_back(lets[fi]);
    if (N == 1) return cur;

    vector<int> idx;
    for (int i = 0; i < 4; i++) {
        if (i == fi) continue;
        idx.push_back(i);
    }
    for (int i = 1; i < N - 1; i++) {
        std::string tmp;
        cur.push_back(lets[idx[1]]);
        tmp += cur;
        cur.pop_back();
        cur.push_back(lets[idx[2]]);
        for (int j = 0; j < 3; j++) {
            cur.push_back(lets[idx[j]]);
            tmp += cur;
            cur.pop_back();
        }
        cur.pop_back();
        int ans = press(tmp);
        if (ans == i) {
            cur.push_back(lets[idx[0]]);
        } else if (ans == i + 1) {
            cur.push_back(lets[idx[1]]);
        } else if (ans == i + 2) {
            cur.push_back(lets[idx[2]]);
        }
    }

    for (int i = 0; i < 2; i++) {
        cur.push_back(lets[idx[i]]);
        if (press(cur) == N) {
            break;
        } else {
            cur.pop_back();
        }
    }
    if ((int)cur.length() < N) cur.push_back(lets[idx[2]]);
    // cout << "CUR: " << cur << '\n';

    return cur;
}
