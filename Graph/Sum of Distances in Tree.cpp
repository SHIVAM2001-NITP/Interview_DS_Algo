/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=b6DrMMHFiL0
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/sum-of-distances-in-tree/
*/

//Time : O(n), Space : O(n)
class Solution {
public:
    //store count of subtrees of each node
    long result_base_node = 0;
    vector<int> count;
    int N;
    int dfsBase(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        
        result_base_node += curr_depth;
        
        for(int &child : adj[curr_node]) {
            if(child == prev_node)
                continue;
            
            total_node += dfsBase(adj, child, curr_node, curr_depth+1);
        }
        
        //store count of subtrees of each node
        count[curr_node] = total_node;
        
        return total_node;
    }
    
    void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int>& result) {
        
        for(int &child : adj[parent_node]) {
            if(child == prev_node)
                continue;
            
            result[child] = result[parent_node] - count[child] + (N - count[child]);
            DFS(adj, child, parent_node, result);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        N = n;
        count.resize(n, 0);
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        result_base_node = 0;
        
        dfsBase(adj, 0, -1, 0);
        
        vector<int> result(n, 0);
        
        result[0] = result_base_node;
        
        DFS(adj, 0, -1, result);
        
        return result;
    }
};

//JAVA

class Solution {
    long resultBaseNode = 0;
    int[] count;
    int N;

    int dfsBase(Map<Integer,List<Integer>> adj,int curr,int prev,int depth) {
        int totalNodes=1;
        resultBaseNode+=depth;
        for(int child:adj.getOrDefault(curr,new ArrayList<>())) {
            if(child==prev)
                continue;

            totalNodes+=dfsBase(adj,child,curr,depth+1);
        }
        count[curr]=totalNodes;
        return totalNodes;
    }

    void dfs(Map<Integer,List<Integer>> adj,int parent,int prev,int[] result) {
        for(int child:adj.getOrDefault(parent,new ArrayList<>())) {
            if(child==prev)
                continue;

            result[child]=result[parent]-count[child]+(N-count[child]);
            dfs(adj,child,parent,result);
        }
    }

    public int[] sumOfDistancesInTree(int n,int[][] edges) {
        N=n;
        count=new int[n];
        Map<Integer,List<Integer>> adj=new HashMap<>();
        for(int[] edge:edges) {
            int u=edge[0],v=edge[1];
            adj.computeIfAbsent(u,k->new ArrayList<>()).add(v);
            adj.computeIfAbsent(v,k->new ArrayList<>()).add(u);
        }
        resultBaseNode=0;
        dfsBase(adj,0,-1,0);  // To Fill Count of SubTree Sizes for each Node
        int[] result=new int[n];
        result[0]=(int)resultBaseNode;
        dfs(adj,0,-1,result);  // To Fill Answers

        return result;
    }
}

// Time: O(n)
// Space: O(n)

// Main Formulae
// Main Formulae — Sum of Distances in Tree

// Let node 0 be the root.

// 1. Subtree size
// count[node] = 1 + Σ count[child]

// 2. Distance sum for root
// result[0] = Σ depth[node]

// 3. Re-rooting formula
// For a child child of parent:
// result[child]
// = result[parent] - count[child] + (N - count[child])

// Or simplified:
// result[child]
// = result[parent] + N - 2 × count[child]
// Why?

// When moving from parent → child:
// count[child] nodes become 1 step closer → -count[child]
// Remaining N - count[child] nodes become 1 step farther → +(N-count[child])
