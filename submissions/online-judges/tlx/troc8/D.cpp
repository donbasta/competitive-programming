#include <bits/stdc++.h>
using namespace std;

int arr[4][1000];
vector<int> v1,v2;
int n,k;

int main(){
    cin >> n >> k;
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v1.push_back(arr[0][i]+arr[1][j]);
            v2.push_back(arr[2][i]+arr[3][j]);
        }
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    long long ans = 0;
    for(auto i : v1){
        if(i > k) break;
        int t = upper_bound(v2.begin(),v2.end(),k-i) - v2.begin();
        ans += 1ll * t;
    }

    cout << ans << "\n";

}