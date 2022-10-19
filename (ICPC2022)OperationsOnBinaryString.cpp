#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
typedef priority_queue <int> pque;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define rep(i,b) for(int i=0;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REPR(i,a,b) for(int i=a;i>=b;i--)
#define prefixSum(a,pre,n) pre[0]=a[0]; for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
#define suffixSum(a,suf,n) suf[n-1]=a[n-1]; for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+a[i];
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub uppper_bound
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define res(i) cout << "Case #" << i << ": "

void solve(){
    ll n, x;
    string s;
    cin>> n >> x;
    cin >> s;
    int c=0, f=0, count_1=0;
    vi v;
    rep(i,s.size()){
    	if(s [i] =='0'){
    		c++;
    		f=1;
    	}
    	else if(f){
    		f=0;
    		v.pb(c);
    		count_1++;
    		c=0;
    	}
    	else{
    		count_1++;
    		f=0;
    		c=0;
    	}
    }
    if(s[s.size()-1]=='0') v.pb(c);
    //cout<< v.size()<<"cou \n";
    sort(all(v), greater<int>());
    int i=0;
    while(x>0 && i<v.size()){
    	int m = v[i];
    	//cout<< m<<"m\n";
    	//x-=(2*m + 1);
    	if(x-(2*m + 1)>=0){
    		x-=(2*m + 1);
    		count_1+=m;
    	}  
    	else{
    		count_1+=(x-1)/2;
    		break;
    	}
    	i++;
    }
    cout<< count_1<< "\n";	
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>> t;
    while(t--){
        //res(i);
        solve();
    }
    return 0;
}