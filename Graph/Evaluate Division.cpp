/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=C6cm6IvqmyA
    Company Tags                : Amazon, Meta
    Leetcode Link               : https://leetcode.com/problems/evaluate-division/
*/

class Solution {
public:
    
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, unordered_set<string>& visited, double product, double &ans) {
        if(visited.find(src) != visited.end())
            return;
        
        visited.insert(src);
        if(src == dst) {
            ans = product;
            return;
        }
        
        for(auto p : adj[src]) {
            
            string v   = p.first;
            double val = p.second;
            
            dfs(adj, v, dst, visited, product*val, ans);
                
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        
        unordered_map<string, vector<pair<string, double>>> adj;
        
        for(int i = 0; i<n; i++) {
            
            string u   = equations[i][0];
            string v   = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});        //To handle a/c
            adj[v].push_back({u, 1.0/val});    //To handle c/a
        }
        
        vector<double> result;
        
        for(auto &query : queries) {
            
            string src = query[0];
            string dst = query[1];
            
            double ans     = -1.0;
            double product = 1.0;
            
            
            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                
                dfs(adj, src, dst, visited, product, ans);
                
            }
            
            result.push_back(ans);
            
        }
        
        return result;
    }
};

// JAVA

class Solution {
    void dfs(Map<String, List<Map.Entry<String, Double>>> adj, String src, String dst,
             Set<String> visited, double product, double[] ans) {
        if (visited.contains(src))
            return;

        visited.add(src);

        if (src.equals(dst)) {
            ans[0] = product;
            return;
        }

        for (Map.Entry<String, Double> p : adj.getOrDefault(src, new ArrayList<>())) {
            String v = p.getKey();
            double val = p.getValue();

            dfs(adj, v, dst, visited, product * val, ans);
        }
    }

    public double[] calcEquation(List<List<String>> equations, double[] values,
                                 List<List<String>> queries) {
        int n = equations.size();

        Map<String, List<Map.Entry<String, Double>>> adj = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String u = equations.get(i).get(0);
            String v = equations.get(i).get(1);
            double val = values[i];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new AbstractMap.SimpleEntry<>(v, val));
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new AbstractMap.SimpleEntry<>(u, 1.0 / val));
        }

        double[] result = new double[queries.size()];

        for (int i = 0; i < queries.size(); i++) {
            String src = queries.get(i).get(0);
            String dst = queries.get(i).get(1);

            double[] ans = {-1.0};

            if (adj.containsKey(src)) {
                Set<String> visited = new HashSet<>();
                dfs(adj, src, dst, visited, 1.0, ans);
            }

            result[i] = ans[0];
        }

        return result;
    }
}

//USING BFS

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        int n = equations.size();

        Map<String, List<Map.Entry<String, Double>>> adj = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String u = equations.get(i).get(0);
            String v = equations.get(i).get(1);
            double val = values[i];

            adj.computeIfAbsent(u, k -> new ArrayList<>())
               .add(new AbstractMap.SimpleEntry<>(v, val));

            adj.computeIfAbsent(v, k -> new ArrayList<>())
               .add(new AbstractMap.SimpleEntry<>(u, 1.0 / val));
        }

        double[] result = new double[queries.size()];

        for (int i = 0; i < queries.size(); i++) {
            String src = queries.get(i).get(0);
            String dst = queries.get(i).get(1);

            double ans = -1.0;

            if (adj.containsKey(src)) {
                Queue<String> que = new LinkedList<>();
                Map<String, Double> product = new HashMap<>();

                que.offer(src);
                product.put(src, 1.0);

                while (!que.isEmpty()) {
                    String u = que.poll();

                    if (u.equals(dst)) {
                        ans = product.get(u);
                        break;
                    }

                    for (Map.Entry<String, Double> p : adj.getOrDefault(u, new ArrayList<>())) {
                        String v = p.getKey();
                        double val = p.getValue();

                        if (!product.containsKey(v)) {
                            product.put(v, product.get(u) * val);
                            que.offer(v);
                        }
                    }
                }
            }

            result[i] = ans;
        }

        return result;
    }
}

// Let V = number of variables, E = number of equations, Q = number of queries.

// Time: O(E + Q × (V + E))
// Space: O(V + E) for the graph, plus O(V) BFS space per query.
