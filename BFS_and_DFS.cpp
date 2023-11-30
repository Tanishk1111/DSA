#include<bits/stdc++.h>
using namespace std;

int A[8][8] =  {{0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0, 0, 0},
                {0, 1, 1, 0, 1, 1, 0, 0},
                {0, 1, 0, 1, 0, 1, 0, 0},
                {0, 0, 0, 1, 1, 0, 1, 1},
                {0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0}};


void BFS(int i){
    queue<int> q;
    int visited[8] = {0};
    cout << i  << " ";
    visited[i] = 1;
    q.emplace(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 1; v<= 7; v++){
            if(A[u][v] == 1 and visited[v] == 0){
                cout << v << " ";
                q.emplace(v);
                visited[v] = 1;
            }
        }

    }
}

void DFS(int i){
    static int visited[8] = {0};
    if(visited[i] == 0){
        cout << i << " ";
        visited[i] = 1;
        for(int v = 1; v < 8 ; v++){
            if(A[i][v] == 1){
                DFS(v);
            }
        }
    }
}

int main(){

    DFS(2);

    return 0;
}