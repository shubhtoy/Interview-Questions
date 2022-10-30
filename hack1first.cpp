/**
 *    author:  Himanshu Singh
 *    created: 08.10.2022 21:39:29
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef HIMANSHU_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

/*
a -> sum of numbers
b -> sum of squares of number
find the two missing number
*/

vector<int> solve(int n, int a, int b) {
    int sum = 0, sqSum = 0;
    for (int i = 1; i <= n; i++) {
       sum += i, sqSum += i*i;
    }
    sum -= a, sqSum -= b;
    for (int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(i + j == sum and (i*i) + (j*j) == sqSum) {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> ans = solve(n,a,b);
    return 0;
}
