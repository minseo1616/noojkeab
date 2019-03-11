//
//  main.cpp
//  example
//
//  Created by 민서 on 2019. 2. 26..
//  Copyright © 2019년 민서. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, v;
bool visitdfs[1001] = {0, };
bool visitbfs[1001] = {0, };
vector<int> vec[1001];

void dfs(int a) {
    visitdfs[a] = true;
    cout << a << " ";
    for(int i=0;i<vec[a].size();i++){
        if(!visitdfs[vec[a][i]]){
            dfs(vec[a][i]);
        }
    }
}

void bfs(int a){
    queue<int> q;
    q.push(a);
    visitbfs[a] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i=0;i<vec[x].size();i++){
            if(!visitbfs[vec[x][i]]){
                q.push(vec[x][i]);
                visitbfs[vec[x][i]] = true;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int a, b;

    cin >> n >> m >> v;
    
    for(int i=0;i<m;i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    for(int i=0;i<n;i++){
        sort(vec[i].begin(), vec[i].end());
    }
    
    dfs(v);
    cout << "\n";
    bfs(v);
    
    return 0;
}

