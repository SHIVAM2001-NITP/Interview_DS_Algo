/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Y02Muq_xoCg
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/number-of-good-paths/submissions/
*/

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
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        parent.resize(n);
        rank.resize(n, 1);
        
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        map<int, vector<int>> val_to_nodes;
        
        for (int i = 0; i < n; i++) {
            int value = vals[i];
            
            val_to_nodes[value].push_back(i);
        }
        
        int result = n;
        
        vector<bool> is_active(n, false); //non active in the beginning
        
        for (auto &it : val_to_nodes) {
            
            vector<int> nodes = it.second;
            
            for (int &u : nodes) {
                
                for (int &v: adj[u]) {
                    if (is_active[v]) {
                        Union(u, v);
                    }
                }
                is_active[u] = true;
            }
            
            vector<int> tumhare_parents;
            
            for (int &u : nodes) 
                tumhare_parents.push_back(find(u));
            
            sort(tumhare_parents.begin(), tumhare_parents.end());
                        
            int sz = tumhare_parents.size();
            
            for (int j = 0; j < sz; j++) {
                long long count = 0;
                
                int cur_parent = tumhare_parents[j];
                
                while (j < sz && tumhare_parents[j] == cur_parent) {
                    j++, 
                    count++;
                }
                j--;
                
                result += (count * (count - 1))/2;
            }
        }
        
        return result;
    }
};

//JAVA


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

    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length;
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        Map<Integer, List<Integer>> val_to_nodes = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            int value = vals[i];
            val_to_nodes.computeIfAbsent(value, k -> new ArrayList<>()).add(i);
        }

        int result = n;
        boolean[] is_active = new boolean[n];

        for (Map.Entry<Integer, List<Integer>> it : val_to_nodes.entrySet()) {
            List<Integer> nodes = it.getValue();

            for (int u : nodes) {
                for (int v : adj.getOrDefault(u, new ArrayList<>())) {
                    if (is_active[v])
                        Union(u, v);
                }
                is_active[u] = true;
            }

            List<Integer> tumhare_parents = new ArrayList<>();

            for (int u : nodes)
                tumhare_parents.add(find(u));

            Collections.sort(tumhare_parents);

            int sz = tumhare_parents.size();

            for (int j = 0; j < sz; j++) {
                long count = 0;
                int cur_parent = tumhare_parents.get(j);

                while (j < sz && tumhare_parents.get(j) == cur_parent) {
                    j++;
                    count++;
                }
                j--;

                result += (int) (count * (count - 1) / 2);
            }
        }

        return result;
    }
}

// Time: O((V + E) α(V) + V log V)
// Space: O(V + E)
