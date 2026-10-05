/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fGSPLQ1la90
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/detonate-the-maximum-bombs/
*/

//Approach-1 (Using DFS)
class Solution {
public:
    typedef long long LL;
    void DFS(int u, unordered_set<int> & visited, unordered_map<int, vector<int>> &adj) {
        
        visited.insert(u);
        
        for(int &v : adj[u]) {
            if(visited.find(v) == visited.end()) { //Not visited
                DFS(v, visited, adj);
            }
        }

    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        unordered_set<int> visited;
        
        for(int i = 0; i<n; i++) {
            DFS(i, visited, adj);
            int count = visited.size();
            result = max(result, count);
            visited.clear();
        }
        
        return result;
        
    }
};


//Approach-2 (Using BFS)
class Solution {
public:
    typedef long long LL;
    int BFS(int u, unordered_map<int, vector<int>> &adj) {
        unordered_set<int> visited;
        queue<int> que;
        que.push(u);
        visited.insert(u);

        while(!que.empty()) {
            
            int temp = que.front();
            que.pop();
            
            for(int &v : adj[temp]) {
                
                if(visited.find(v) == visited.end()) {
                    que.push(v);
                    visited.insert(v);
                }
                
            }
            
            
        }
        
        return visited.size();
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            int count = BFS(i, adj);
            result = max(result, count);
        }
        
        return result;
        
    }
};

//JAVA
// Approach 1 — DFS

class Solution {

    void DFS(int u, Set<Integer> visited, Map<Integer, List<Integer>> adj) {
        visited.add(u);

        for (int v : adj.getOrDefault(u, new ArrayList<>())) {
            if (!visited.contains(v)) {
                DFS(v, visited, adj);
            }
        }
    }

    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;

        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                long x1 = bombs[i][0];
                long y1 = bombs[i][1];
                long r1 = bombs[i][2];

                long x2 = bombs[j][0];
                long y2 = bombs[j][1];
                long r2 = bombs[j][2];

                long distance = (x2 - x1) * (x2 - x1)
                              + (y2 - y1) * (y2 - y1);

                if (r1 * r1 >= distance)
                    adj.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
            }
        }

        int result = 0;
        Set<Integer> visited = new HashSet<>();

        for (int i = 0; i < n; i++) {
            DFS(i, visited, adj);
            int count = visited.size();
            result = Math.max(result, count);
            visited.clear();
        }

        return result;
    }
}


// Approach 2 — BFS
class Solution {
    int BFS(int u, Map<Integer, List<Integer>> adj) {
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> que = new LinkedList<>();

        que.offer(u);
        visited.add(u);

        while (!que.isEmpty()) {
            int temp = que.poll();

            for (int v : adj.getOrDefault(temp, new ArrayList<>())) {
                if (!visited.contains(v)) {
                    que.offer(v);
                    visited.add(v);
                }
            }
        }

        return visited.size();
    }

    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;

        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                long x1 = bombs[i][0];
                long y1 = bombs[i][1];
                long r1 = bombs[i][2];

                long x2 = bombs[j][0];
                long y2 = bombs[j][1];
                long r2 = bombs[j][2];

                long distance = (x2 - x1) * (x2 - x1)
                              + (y2 - y1) * (y2 - y1);

                if (r1 * r1 >= distance)
                    adj.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
            }
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            int count = BFS(i, adj);
            result = Math.max(result, count);
        }

        return result;
    }
}
// Complexity

// Building the directed graph requires checking every pair:

// Graph construction: O(N²)
// DFS/BFS from each bomb: O(N × (N + E))
// Since E can be O(N²), worst-case:
// Time: O(N³)
// Space: O(N²) for the graph + O(N) visited/queue.

// The long is important because (x2-x1)² + (y2-y1)² can exceed the int range.
