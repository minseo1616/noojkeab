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
int dy[41] = {0,};

int fibo(int a){
    if(dy[a] > 0)
        return dy[a];
    if(a == 0)
        return 0;
    else if(a == 1)
        return 1;
    else
        return dy[a] = fibo(a-2) + fibo(a-1);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    
    for(int i=0;i<t;i++){
        cin >> n;
        if(n == 0)
            cout << "1 0" << "\n";
        else
            cout << fibo(n-1) << " " << fibo(n) << "\n";
    }
    
    
    
    return 0;
}

