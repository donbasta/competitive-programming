    #include<bits/stdc++.h>
    using namespace std;
     
    int v5(int x){
    	if(x==0) return 1e9;
    	int ans = 0;
    	while(x%5==0){
    		x/=5; ans++;
    	}
    	return ans;
    }
     
    int v2(int x){
    	if(x==0) return 1e9;
    	int ans = 0;
    	while(x%2==0){
    		x/=2; ans++;
    	}
    	return ans;
    }
     
    int main(){
     
    	int n; cin >> n;
    	pair<int,int> pos;
     
    	int a[n+2][n+2], five[n+2][n+2], two[n+2][n+2];
    	bool is_zero = false;
     
    	for(int i=1; i<=n; ++i){
    		for(int j=1; j<=n; ++j){
    			cin >> a[i][j];
    			if(a[i][j]==0) {is_zero=true; pos={i,j};}
    		}
    	}

     
    	five[n][n]=v5(a[n][n]);
    	two[n][n]=v2(a[n][n]);
     
    	for(int i=n-1; i>=1; i--){
    		five[n][i] = five[n][i+1] + v5(a[n][i]);
    		two[n][i] = two[n][i+1] + v2(a[n][i]);
    	}
     
    	for(int i=n-1; i>=1; i--){
    		five[i][n] = five[i+1][n] + v5(a[i][n]);
    		two[i][n] = two[i+1][n] + v2(a[i][n]);
    	}
     
    	for(int i=n-1; i>=1; i--){
    		for(int j=n-1; j>=1; j--){
    			five[i][j] = min(five[i][j+1],five[i+1][j]) + v5(a[i][j]);
    			two[i][j] = min(two[i][j+1],two[i+1][j]) + v2(a[i][j]);
    		}
    	}

    	int tot = min(five[1][1], two[1][1]);
    	string ans = "";

    	if(is_zero && tot>1){
    		tot = 1;
    		for(int i=1; i<pos.first; i++){
    			ans += "D";
    		}
    		for(int i=1; i<pos.second; i++){
    			ans += "R";
    		}
    		for(int i=pos.first; i<n; i++){
    			ans += "D";
    		}
    		for(int i=pos.second; i<n; i++){
    			ans += "R";
    		}
    	}

    	else {
    		int p=1, q=1, pow2=v2(a[1][1]), pow5=v5(a[1][1]);
	    	while(p!=n || q!=n){
	    		if(p==n) {q++; ans += "R";}
	    		else if(q==n) {p++; ans += "D";}
	    		else {
	    			if(min(pow5+five[p+1][q],pow2+two[p+1][q])>min(pow5+five[p][q+1],pow2+two[p][q+1])) {
	    				pow5 += v5(a[p][q+1]); pow2 += v2(a[p][q+1]);
	    				q++; ans+="R";
	    			}
	    			else {
	    				pow5 += v5(a[p+1][q]); pow2 += v2(a[p+1][q]);
	    				p++; ans += "D";
	    			}
	    		}
	    	}
    	}
     	
     	cout << tot << "\n";
	    cout << ans;
    	
    	
     
    }