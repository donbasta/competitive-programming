#include <bits/stdc++.h>
using namespace std;

long long calc(int i, int j, int k){
    return 1ll * 2 * (1ll*i*i+1ll*j*j+1ll*k*k-1ll*i*j-1ll*j*k-1ll*k*i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int tc;
    cin >> tc;
    while(tc--){
        int col[3];
        for(int i=0; i<3; i++) cin >> col[i];
        vector<int> ve[3];
        for(int i=0; i<3; i++){
            for(int j=0; j<col[i]; j++){
                int x;
                cin >> x;
                ve[i].push_back(x);
            }
            sort(ve[i].begin(),ve[i].end());
            // for(auto j : ve[i]) cout << j << " ";
            // cout << "\n";
        }
        int ord[] = {0,1,2};

        long long ans = 4e18;

        do {
            // for(auto i : ord) cout << i << " - ";
            for(int i : ve[ord[0]]){
                int ij = lower_bound(ve[ord[1]].begin(),ve[ord[1]].end(),i) - ve[ord[1]].begin();
                if(ij == ve[ord[1]].size()) break;
                int j = ve[ord[1]][ij];
                int ik = lower_bound(ve[ord[2]].begin(),ve[ord[2]].end(),(i+j)/2) - ve[ord[2]].begin();
                int k;
                long long cur;
                if(ik == ve[ord[2]].size()){
                    k = ve[ord[2]][ik-1];
                    if(k>=i && k<=j) ans = min(ans, calc(i,j,k));
                } else if(ik == 0){
                    k = ve[ord[2]][ik];
                    if(k>=i && k<=j) ans = min(ans, calc(i,j,k));
                } else{
                    k = ve[ord[2]][ik-1];
                    if(k>=i && k<=j) ans = min(ans, calc(i,j,k));
                    k = ve[ord[2]][ik];
                    if(k>=i && k<=j) ans = min(ans, calc(i,j,k));
                }
            }
        } while (next_permutation(ord, ord+3));

        cout << ans << "\n";
        
    }
    

}