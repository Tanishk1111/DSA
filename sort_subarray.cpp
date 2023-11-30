#include <bits/stdc++.h>

#define SABER ios::sync_with_stdio(0);cin.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
#define BOR(i,a,b) for(int i = a; i>=b; i--)

typedef long long ll;

using namespace std;


void solve(){
    int n;
    cin >> n;
    int a[n];
    FOR(i,0,n){
        cin >> a[i];
    }
    vector<int> ax;
    FOR(i,0,n){
        if(abs(a[i] - (i+1)) > 0){
            ax.push_back(abs(a[i] - (i+1)));
        }
    }
    int final = *min_element(ax.begin(),ax.end());
    
    if(*min_element(ax.begin(),ax.end()) == 1){
        cout << 1 << '\n';
    }
    else{
        for(int i = 0 ; i < ax.size() ; i++){
            
        }

        cout << final  << '\n';
    }
}


int main(){
    SABER

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;

}

// 1 5 3 6 2 4