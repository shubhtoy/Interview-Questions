class Solution {
    public int find(int []parent,int x){
        if(parent[x]==x) return x;
        parent[x] = find(parent,parent[x]);
        return parent[x];
    }
    public void union(int []parent,int []rank,int lx,int ly){
        int px = find(parent,lx);
        int py = find(parent,ly);
        
        if(rank[px]<rank[py]){
            parent[px] = py;
        }else if(rank[py]<rank[px]){
            parent[py] = px;
        }else{
            parent[px] = py;
            rank[py]++;
        }
    }
    public List<Boolean> areConnected(int n, int threshold, int[][] queries) {
        int []parent = new int[n+1];
        int []rank = new int[n+1];
        
        for(int i=0;i<parent.length;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(int div=threshold+1;div<=n;div++){
            for(int m=1;div*m<=n;m++){
                union(parent,rank,div,div*m);
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for(int []arr:queries){
            int x = arr[0];
            int y = arr[1];
            
            boolean res = (find(parent,x)==find(parent,y));
            ans.add(res);
        }
        return ans;
    }
}
