/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yYBKsu27f2s
    Company Tags                : Microsoft, Flipkart, Samsung, 
    Leetcode Link               : https://leetcode.com/problems/possible-bipartition/
*/

//Using BFS - O(V+E)
class Solution {
public:
    
    bool isBipartite(unordered_map<int, vector<int>> &adj, int node, vector<int>& color) {
        queue<int> que;
        
        que.push(node);
        color[node] = 1;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                if(color[v] == color[u])
                    return false;
                
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> &vec : dislikes) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1, -1);
        
        for(int i = 1; i<=n; i++) {
            if(color[i] == -1) {
                if(!isBipartite(adj, i, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};


//Using DFS - O(V+E):

//JAVA

BFS — O(V + E)
class Solution {
    boolean isBipartite(Map<Integer,List<Integer>> adj,int node,int[] color) {
        Queue<Integer> queue=new LinkedList<>();

        queue.offer(node);
        color[node]=1;

        while(!queue.isEmpty()) {
            int u=queue.poll();

            for(int v:adj.getOrDefault(u,new ArrayList<>())) {
                if(color[v]==color[u])
                    return false;

                if(color[v]==-1) {
                    color[v]=1-color[u];
                    queue.offer(v);
                }
            }
        }

        return true;
    }

    public boolean possibleBipartition(int n,int[][] dislikes) {
        Map<Integer,List<Integer>> adj=new HashMap<>();

        for(int[] edge:dislikes) {
            int u=edge[0],v=edge[1];

            adj.computeIfAbsent(u,k->new ArrayList<>()).add(v);
            adj.computeIfAbsent(v,k->new ArrayList<>()).add(u);
        }

        int[] color=new int[n+1];
        Arrays.fill(color,-1);

        for(int i=1;i<=n;i++) {
            if(color[i]==-1) {
                if(!isBipartite(adj,i,color))
                    return false;
            }
        }

        return true;
    }
}
// DFS — O(V + E)
class Solution {
    boolean isBipartite(Map<Integer,List<Integer>> adj,int node,int[] color) {
        for(int v:adj.getOrDefault(node,new ArrayList<>())) {
            if(color[v]==color[node])
                return false;

            if(color[v]==-1) {
                color[v]=1-color[node];

                if(!isBipartite(adj,v,color))
                    return false;
            }
        }

        return true;
    }

    public boolean possibleBipartition(int n,int[][] dislikes) {
        Map<Integer,List<Integer>> adj=new HashMap<>();

        for(int[] edge:dislikes) {
            int u=edge[0],v=edge[1];

            adj.computeIfAbsent(u,k->new ArrayList<>()).add(v);
            adj.computeIfAbsent(v,k->new ArrayList<>()).add(u);
        }

        int[] color=new int[n+1];
        Arrays.fill(color,-1);

        for(int i=1;i<=n;i++) {
            if(color[i]==-1) {
                color[i]=1;

                if(!isBipartite(adj,i,color))
                    return false;
            }
        }

        return true;
    }
}
