/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mbR1XSXidEE
    Company Tags                : Microsoft, Adobe, Amazon, Morgan Stanley, Samsung
    Leetcode Link               : https://leetcode.com/problems/find-if-path-exists-in-graph/
*/

//NOTE : Soon, I will upload the Union Find approach for this Qn as well

//Using DFS : O(m+n)
class Solution {
public:
    
    bool check(unordered_map<int, vector<int>>& mp, int node, int dest, vector<bool>& visited) {
        if(node == dest)
            return true;
        
        if(visited[node])
            return false;
        
        visited[node] = true;
        for(auto &it : mp[node]) {
            if(check(mp, it, dest, visited))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination)
            return true;
        
        unordered_map<int, vector<int>> mp;
        
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        return check(mp, source, destination, visited);
    }
};


//Using BFS : O(m+n)
class Solution {
public:    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        queue<int> que;
        que.push(source);
        visited[source] = true;
        
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            if(node == destination)
                return true;

            for(auto &it : mp[node]) {
                if(!visited[it]) {
                    visited[it] = true;
                    que.push(it);
                }
            }
        }
        
        return false;
    }
};


//  JAVA
//DFS
class Solution {
    boolean check(Map<Integer,List<Integer>> mp,int node,int dest,boolean[] visited) {
        if(node==dest)
            return true;

        if(visited[node])
            return false;

        visited[node]=true;

        for(int next:mp.getOrDefault(node,new ArrayList<>())) {
            if(check(mp,next,dest,visited))
                return true;
        }

        return false;
    }

    public boolean validPath(int n,int[][] edges,int source,int destination) {
        if(source==destination)
            return true;

        Map<Integer,List<Integer>> mp=new HashMap<>();

        for(int[] edge:edges) {
            int u=edge[0],v=edge[1];

            mp.computeIfAbsent(u,k->new ArrayList<>()).add(v);
            mp.computeIfAbsent(v,k->new ArrayList<>()).add(u);
        }

        boolean[] visited=new boolean[n];

        return check(mp,source,destination,visited);
    }
}
//BFS
class Solution {
    public boolean validPath(int n,int[][] edges,int source,int destination) {
        Map<Integer,List<Integer>> mp=new HashMap<>();

        for(int[] edge:edges) {
            int u=edge[0],v=edge[1];

            mp.computeIfAbsent(u,k->new ArrayList<>()).add(v);
            mp.computeIfAbsent(v,k->new ArrayList<>()).add(u);
        }

        boolean[] visited=new boolean[n];

        Queue<Integer> queue=new LinkedList<>();
        queue.offer(source);
        visited[source]=true;

        while(!queue.isEmpty()) {
            int node=queue.poll();

            if(node==destination)
                return true;

            for(int next:mp.getOrDefault(node,new ArrayList<>())) {
                if(!visited[next]) {
                    visited[next]=true;
                    queue.offer(next);
                }
            }
        }

        return false;
    }
}

Time: O(V + E)
Space: O(V + E)
