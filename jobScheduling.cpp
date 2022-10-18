#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<pair<int, pii>> viii;
typedef pair<int, pii> piii;
typedef pair<float, pair<pii,pii>> pfpp;
#define pb push_back
#define fi first
#define se second



bool compare(pii p1, pii p2){
    return p1.se < p2.se;
}

vpii max_cardinality(vpii &jobs){
    sort(jobs.begin(), jobs.end(), compare);
    vpii ans;
    
    for(int i=0; i<jobs.size(); i++){
        ans.pb(jobs[i]);
        int j=i+1;
        while(j<jobs.size() && jobs[j].fi < jobs[i].se){
            j++;
        }
        i=j-1;
    }
    return ans;
}

void conflicts(vpii &jobs, vpii &conflict){
    sort(jobs.begin(), jobs.end());
    // vpii conflict(jobs.size() , make_pair(0, 0));
    for(int i=0; i<jobs.size(); i++){
        int j =i+1;
        conflict[i].se=i;
        while(j<jobs.size() &&  (jobs[i].se > jobs[j].fi) ){
            conflict[i].fi+=1;
            conflict[j].fi+=1;
            j++;
        }        
    }
} 

int main(){
    // vpii jobs = {{1,2}, {3,4}, {5,6}, {1,3}, {2,6}};
    vpii jobs;
    cout<<"enter the no of jobs: ";
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int x, y;
        cin>> x >>y;
        jobs.pb({x,y});
    }
    vpii ans = max_cardinality(jobs);
    cout<<"\njobs that are going to run\n";
    for(auto it: ans){
        cout<< it.fi <<" "<< it.se<<" \n";
    }
    cout<<"\n";
    vpii conflict(jobs.size() , make_pair(0, 0));
    conflicts(jobs, conflict);
    for(auto it: conflict){
        cout<< jobs[it.se].fi <<" "<< jobs[it.se].se<<": ";
        cout<< it.fi<<"\n";
    }

    sort(conflict.begin(), conflict.end());
    int j=0;
    cout<<"\njobs with minimum conflicts: \n";
    while(conflict[0].fi==conflict[j].fi){
        int k = conflict[j].se;
        cout<< jobs[k].fi <<" "<< jobs[k].se<<": ";
        cout<< conflict[j].fi <<"\n";
        j++;
    }
    cout<<"\n";
    j=conflict.size()-1;
    cout<<"jobs with max conflicts: \n";
    while(conflict[conflict.size()-1].fi==conflict[j].fi){
        int k = conflict[j].se;
        cout<< jobs[k].fi <<" "<< jobs[k].se<<": ";
        cout<< conflict[j].fi <<"\n";
        j--;
    }
}