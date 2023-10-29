#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define KURUMI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define BAR(i,a,b) for(ll i = a-1; i >= b; i--)
#define nya << '\n'

int main(){
    KURUMI
    int n;
    cin >> n;
    string r,c;
    cin >> r >> c;
    int o = 1;
    FOR(i,0,n){
        if(i == 0){
            if(r[i] != c[i]){
                o = 0;
                break;
            }
        }
        else{
            if(r[i] == c[i]){
                o = 0;
                break;
            }
        }
    }
    if(o == 0){
        cout << "No" nya;
    }
    else{
        char s[n][n];
        FOR(i,0,n){
            FOR(j,0,n){
                s[i][j] = '.';
            }
        }

        s[0][0] = r[0];
        FOR(i,1,n){
            int j = 0;
            FOR(k,0,i){
                if(c[k] == c[i]){
                    j++;
                }
            }
            s[j][i] = c[i];
        }
        FOR(i,1,n){
            int j = 0;
            FOR(k,0,n){
                
                FOR(a,0,n){
                    if(s[a][k] == r[i]){
                        j++;
                        break;
                    }
                }
            }
            s[i][j] = r[i];
        }
        FOR(i,0,n){
            FOR(j,0,n){
                cout << s[i][j];
            }
            cout nya;
        }
    }
}

