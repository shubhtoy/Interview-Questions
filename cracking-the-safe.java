class Solution {
    public String crackSafe(int n, int k) {
        StringBuilder sb = new StringBuilder("");
        for(int i=0;i<n;i++){
            sb.append("0");
        }
        HashSet<String> vis = new HashSet<>();
        vis.add(sb.toString());
        int lim = (int)Math.pow(k,n);
        dfs(sb,vis,n,k,lim);
        return sb.toString();
    }
    public boolean dfs(StringBuilder sb,HashSet<String> vis,int n,int k,int lim){
        if(vis.size()==lim){
            return true;
        }
        String pmo = sb.substring(sb.length()-(n-1));
        for(int i=0;i<k;i++){
            String npwd = pmo+i;
            if(!vis.contains(npwd)){
                vis.add(npwd);
                sb.append(i);
                boolean check = dfs(sb,vis,n,k,lim);
                if(check) return true;
                vis.remove(npwd);
                sb.deleteCharAt(sb.length()-1);
            }
        }
        return false;
    }
}
