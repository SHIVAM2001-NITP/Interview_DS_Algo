/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=CMTlE0W01Pk
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/similar-string-groups/
*/

//Approach-1 : Using DFS
class Solution {
public:
    
    bool isSimilar(string &s1, string &s2) {
        
        int n = s1.length();
        int diff = 0;
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i])
                diff++;
        }
        
        
        return diff == 2 || diff == 0;
    }
    
    void DFS(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited) {
        visited[u] = true;
        
        for(int &v : adj[u]) {
            if(!visited[v])
                DFS(v, adj, visited);
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        
        //build graph
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                DFS(i, adj, visited);
                count++;
            }
        }
        
        return count;
    }
};



//Approach-2 : Using BFS
class Solution {
public:
    
    bool isSimilar(string &s1, string &s2) {
        
        int n = s1.length();
        int diff = 0;
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i])
                diff++;
        }
        
        
        return diff == 2 || diff == 0;
    }
    
    void BFS(int i, unordered_map<int, vector<int>> &adj, vector<bool>& visited) {
        queue<int> que;
        
        
        que.push(i);
        visited[i] = true;
        
        while(!que.empty()) {
            
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                if(!visited[v]) {
                    que.push(v);
                    visited[v] = true;
                }
            }
            
        }
        
        
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        
        //build graph
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                BFS(i, adj, visited);
                count++;
            }
        }
        
        return count;
    }
};



//Approach-3 (Using DSU)
//Find this in my Disjoint Set Repo
class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    bool isSimilar(string &s1, string &s2) {
        
        int n = s1.length();
        int diff = 0;
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i])
                diff++;
        }
        
        
        return diff == 2 || diff == 0;
    }
    
   
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        parent.resize(n);
        rank.resize(n);
        
        for(int i = 0; i<n; i++)
            parent[i] = i;
        
        int groups = n; //Initially all strings represent themselves
 
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                
                if(isSimilar(strs[i], strs[j]) && find(i) != find(j)) {
                    groups--;
                    Union(i, j);
                }
                
            }
        }
        
        return groups;
    }
};


//JAVA

// Approach 1 — DFS
class Solution {
    boolean isSimilar(String s1, String s2) {
        int n = s1.length();
        int diff = 0;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(i))
                diff++;
        }

        return diff == 2 || diff == 0;
    }

    void DFS(int u, Map<Integer, List<Integer>> adj, boolean[] visited) {
        visited[u] = true;

        for (int v : adj.getOrDefault(u, new ArrayList<>())) {
            if (!visited[v])
                DFS(v, adj, visited);
        }
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;

        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                    adj.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
                }
            }
        }

        boolean[] visited = new boolean[n];
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, adj, visited);
                count++;
            }
        }

        return count;
    }
}
// Approach 2 — BFS
class Solution {
    boolean isSimilar(String s1, String s2) {
        int n = s1.length();
        int diff = 0;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(i))
                diff++;
        }

        return diff == 2 || diff == 0;
    }

    void BFS(int i, Map<Integer, List<Integer>> adj, boolean[] visited) {
        Queue<Integer> que = new LinkedList<>();

        que.offer(i);
        visited[i] = true;

        while (!que.isEmpty()) {
            int u = que.poll();

            for (int v : adj.getOrDefault(u, new ArrayList<>())) {
                if (!visited[v]) {
                    que.offer(v);
                    visited[v] = true;
                }
            }
        }
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;

        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    adj.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                    adj.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
                }
            }
        }

        boolean[] visited = new boolean[n];
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                BFS(i, adj, visited);
                count++;
            }
        }

        return count;
    }
}
// Approach 3 — DSU
class Solution {
    int[] parent;
    int[] rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    boolean isSimilar(String s1, String s2) {
        int n = s1.length();
        int diff = 0;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(i))
                diff++;
        }

        return diff == 2 || diff == 0;
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;

        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int groups = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j]) && find(i) != find(j)) {
                    groups--;
                    Union(i, j);
                }
            }
        }

        return groups;
    }
}
// Complexity

// Let N = strs.length and L = length of each string.

// Checking similarity costs O(L), and we check every pair:

// DFS: O(N² × L) time, O(N²) graph space + O(N) DFS space.
// BFS: O(N² × L) time, O(N²) graph space + O(N) BFS space.
// DSU: O(N² × L × α(N)) time, O(N) extra space.
