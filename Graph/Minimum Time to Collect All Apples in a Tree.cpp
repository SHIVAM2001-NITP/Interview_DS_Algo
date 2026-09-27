/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qSBvKlUq0xo
      Company Tags                : Microsoft
      Leetcode Link               : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
*/

//DFS - O(V+E) - We visit all nodes and edges in the graph
class Solution {
public:
    
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool>& hasApple) {
        int time = 0;
        
        for(int &child : adj[curr]) {
            if(child == parent)
                continue;
            int time_from_bachha_log = DFS(adj, child, curr, hasApple); 
              
            if(time_from_bachha_log || hasApple[child])
                time += 2 + time_from_bachha_log;  
        }
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1]; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return DFS(adj, 0, -1, hasApple);
    }
};
//Java

class Solution {
    int DFS(Map<Integer, List<Integer>> adj, int curr, int parent, List<Boolean> hasApple) {
        int time = 0;
        for (int child : adj.getOrDefault(curr, new ArrayList<>())) {
            if (child == parent)
                continue;

            int timeFromChild = DFS(adj, child, curr, hasApple);

            if (timeFromChild > 0 || hasApple.get(child))
                time += 2 + timeFromChild;
        }

        return time;
    }

    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        return DFS(adj, 0, -1, hasApple);
    }
}

//Complexity:Time O(V + E) , 
//Space O(V) recursion + adjacency-list space.
// DFS
class Solution {
    int[] DFS(Map<Integer, List<Integer>> adj, int u, int parent, int[] result, String labels) {
        int[] myCount = new int[26];
        char myLabel = labels.charAt(u);

        myCount[myLabel - 'a'] = 1;

        for (int v : adj.getOrDefault(u, new ArrayList<>())) {
            if (v == parent)
                continue;

            int[] childCount = DFS(adj, v, u, result, labels);

            for (int i = 0; i < 26; i++)
                myCount[i] += childCount[i];
        }

        result[u] = myCount[myLabel - 'a'];

        return myCount;
    }

    public int[] countSubTrees(int n, int[][] edges, String labels) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int[] result = new int[n];

        DFS(adj, 0, -1, result, labels);

        return result;
    }
}
// Approach 2 → Java
class Solution {
    void DFS(Map<Integer, List<Integer>> adj, int u, int parent, int[] result, String labels, int[] count) {
        char myLabel = labels.charAt(u);

        int before = count[myLabel - 'a'];

        count[myLabel - 'a']++;

        for (int v : adj.getOrDefault(u, new ArrayList<>())) {
            if (v == parent)
                continue;

            DFS(adj, v, u, result, labels, count);
        }

        int after = count[myLabel - 'a'];

        result[u] = after - before;
    }

    public int[] countSubTrees(int n, int[][] edges, String labels) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int[] result = new int[n];
        int[] count = new int[26];

        DFS(adj, 0, -1, result, labels, count);

        return result;
    }
}

// Key difference:
// Approach 1: Each node returns a 26-size frequency array → merges child arrays.
// Approach 2: Uses one global count[26] and calculates each node's answer using after - before. This avoids repeatedly creating/merging 26-size arrays.
