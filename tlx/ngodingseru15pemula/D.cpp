#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    vector<int> ve;
    cin >> N;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        ve.push_back(x);
    }
    for(auto i : ve){
        if(i<0) cout << i << "\n";
    }
    for(auto i : ve){
        if(i==0) cout << i << "\n";
    }
    for(auto i : ve){
        if(i>0) cout << i << "\n";
    }
}