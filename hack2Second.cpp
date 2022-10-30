/**
 *    author:  Himanshu Singh
 *    created: 08.10.2022 21:43:33
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef HIMANSHU_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

int solve(int n, vector<int> &a, int k) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = a[i] ^ k;
        ans += __builtin_popcount(val);   
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n,a,k);
    return 0;
}
