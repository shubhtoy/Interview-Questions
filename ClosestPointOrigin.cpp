#include<bits/stdc++.h>
using namespace std;
#define p pair<int,pair<int,int>>;
void closestDist(int arr[4][2],int r,int c,int k){

    priority_queue<pair<int,pair<int,int>>> maxh;
    for (int i = 0; i < r; i++)
    {   
        maxh.push(make_pair(pow(arr[i][0],2)+pow(arr[i][1],2),make_pair(arr[i][0],arr[i][1])));
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    while(!maxh.empty()){
        pair<int,int> pp =maxh.top().second;
        cout<<pp.first<<" "<<pp.second<<"\n";
        maxh.pop();
    }
    

}

int main(){
    int arr[4][2]={{1,3},{-2,2},{5,8},{0,1}};
    closestDist(arr,4,2,3);
    return 0;
}