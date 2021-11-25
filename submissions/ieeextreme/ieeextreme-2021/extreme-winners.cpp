#include<bits/stdc++.h>
using namespace std;

vector<string> t = {
    "Team 1",
    "Knapsackers@UNT",
    "MoraSeekers",
    "SurpriseTeam",
    "CuSAT",
    "DongskarPedongi",
    "cofrades",
    "viRUs",
    "TeamName",
    "TeamEPFL1",
    "whatevs",
    "WildCornAncestors",
    "TheCornInTheFields",
    "Aurora"
};

void solve() {

    map<string, int> mp;
    for (int i = 0; i < t.size(); i++) {
        mp[t[i]] = i + 1;
    }
    string team;
    getline(cin, team);
    cout << mp[team] << '\n';
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