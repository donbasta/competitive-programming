#include <bits/stdc++.h>
using namespace std;

const int N = 5e3;

int n,w,h;
int dp[N+5];
int muat[N+5];
int par[N+5];
vector<pair<int,int>,int> env;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    cin >> n >> w >> h;

    for(int i=1; i<=n; i++){
        int ww, hh;
        cin >> ww >> hh;
        env.push_back({ww,hh},i);
    }

    sort(env.begin(),env.end());

    for(int i=0; i<n; i++){
        if(env[i].first.first<=w || env[i].first.second<=h){
            continue;
        }
        dp[i] = 1;
        par[i] = -1;
        muat[i] = true;
        for(int j=0; j<i; j++){
            if(muat[j] && env[i].first.first>env[j].first.first && env[i].first.second>env[i].first.second){
                if(dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    par[i] = j;
                }
            }
        }
    }

    int ans = 0;
    int idx = 0;
    for(int i=0; i<n; i++){
        if(ans < dp[i]){
            ans = dp[i];
            idx = i;
        }
    }
    cout << dp[idx] << '\n';
    vector<int> ve;
    while(idx=-1){
        ve.push_back(idx);
        idx = par[idx];
    }
    reverse(ve.begin(),ve.end());
    for(auto i : ve){
        cout << env[i].second << ' ';
    }

}