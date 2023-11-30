#include<bits/stdc++.h>
using namespace std;

#define I INT_MAX

int edges [3][9] = {{1,1,2,2,3,4,4,5,5},
                    {2,6,3,7,4,5,7,6,7},
                    {25,5,12,10,8,16,14,20,18}};

int Set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

int included[9] = {0};

int t[2][6];

void Union(int u, int v){
    if(Set[u] < Set[v]){
        Set[u] += Set[v];
        Set[v] = u;
    }
    else{
        Set[v] += Set[u];
        Set[u] = v;
    }
}

int find(int x){
    int u = x, v = 0;
    while(Set[x] > 0){
        x = Set[x];
    }

    while(u!=x){
        v = Set[u];
        Set[u] = x;
        u = v;
    }
    return x;
}

int main(){

    int i , n = 7,k,u,v; 

    while(i < n-1){
        int mini = I; 
        for(int j = 0; j < 9; j++){
            if(edges[2][j] < mini and included[j] == 0){
                mini = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }

        if(find(u) != find(v)){
            t[0][i] = u;
            t[1][i] = v;
            Union(find(u),find(v));
            i++;
        }
        included[k] = 1;
    }

    for(int i = 0; i < 6; i++){
        cout <<'(' <<  t[0][i] << "," << t[1][i]  << ')' << '\n'; 
    }

    return 0;
}