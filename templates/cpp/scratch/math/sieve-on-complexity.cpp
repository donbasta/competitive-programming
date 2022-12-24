#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int mn[N];  // mn[i] stores the minimal divisor of i greater than 1;
int euler[N];
int mobius[N];
bool composite[N];

void build_sieve() {
    vector<int> pr;  // primes
    mn[0] = mn[1] = 1;
    for (int i = 2; i < N; i++) {
        if (mn[i] == 0) {
            pr.push_back(i);
            mn[i] = i;
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= mn[i] && i * pr[j] < N; j++) {
            mn[i * pr[j]] = pr[j];
        }
    }
}

void sieveEuler() {
    vector<int> pr;
    euler[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!composite[i]) {
            euler[i] = i - 1;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size(); j++) {
            if (i * pr[j] > N)
                break;
            composite[i * pr[j]] = true;
            if (i % pr[j] != 0) {
                euler[i * pr[j]] = euler[i] * (pr[j] - 1);
            } else {
                euler[i * pr[j]] = euler[i] * pr[j];
                break;
            }
        }
    }
}

void sieveMobius() {
    vector<int> pr;
    mobius[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!composite[i]) {
            mobius[i] = -1;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size(); j++) {
            if (i * pr[j] > N)
                break;
            composite[i * pr[j]] = true;
            if (i % pr[j] != 0) {
                mobius[i * pr[j]] = mobius[i] * (-1);
            } else {
                mobius[i * pr[j]] = 0;
                break;
            }
        }
    }
}

// driver
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // build_sieve();
    sieveMobius();
    memset(composite, 0, sizeof(composite));
    sieveEuler();
    cout << "eul   mob   \n";
    for (int i = 2; i <= 50; i++) {
        cout << i << ' ' << euler[i] << ' ' << mobius[i] << '\n';
    }
}
