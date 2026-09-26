/*
  MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9qWMS8GLvdI
  Company Tags                : Amazon, Microsoft
  Leetcode Qn Link            : https://leetcode.com/problems/all-paths-from-source-to-target/
*/


//Approach - 1 (More like a Graph DFS)
class Solution {
public:
    void DFS(vector<vector<int>>& adj, int start, vector<int>& temp,  vector<vector<int>>& result) {
        
        temp.push_back(start);
        if(start == adj.size()-1) {
            result.push_back(temp);
        } else {
            for(auto x:adj[start]) {
                DFS(adj, x, temp, result);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {        
        vector<vector<int>> result;
        for(int x : adj[0]) {
            vector<int> temp;
            temp.push_back(0);
            DFS(adj, x, temp, result);
        }
        return result;
    }
};


//Approach-2 (Similar to approach-1 but a little simple)
class Solution {
public:
    int target;
    void dfs(vector<vector<int>>& adj, int start, vector<int>& temp, vector<vector<int>>& result ) {
        if(start == target) {
            result.push_back(temp);
            return;
        }
        
        for(int &x : adj[start]) {
            temp.push_back(x);
            dfs(adj, x, temp, result);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        target = graph.size()-1;
        temp.push_back(0);
        dfs(graph, 0, temp, result);
        
        return result;
    }
};


//Approach-3 (Using BFS)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int source = 0;
        int target = n-1;
        
        vector<vector<int>> result;
        vector<int> temp;
        
        queue<vector<int>> que;
        temp.push_back(0);
        que.push(temp);
        
        while(!que.empty()) {
            vector<int> currPath = que.front();
            que.pop();
            
            int lastNode = currPath.back();
            
            if(lastNode == target) {
                result.push_back(currPath);
            } else {
                for(int &v : graph[lastNode]) {
                    vector<int> path = currPath;
                    path.push_back(v);
                    que.push(path);
                }
            }
        }
      
        
        return result;
    }
};
//Java

Approach 1 — DFS
class Solution {
    void dfs(List<List<Integer>> graph,int start,List<Integer> temp,
             List<List<Integer>> result) {

        temp.add(start);

        if(start==graph.size()-1) {
            result.add(new ArrayList<>(temp));
        } else {
            for(int next:graph.get(start))
                dfs(graph,next,temp,result);
        }

        temp.remove(temp.size()-1);
    }

    public List<List<Integer>> allPathsSourceTarget(List<List<Integer>> graph) {
        List<List<Integer>> result=new ArrayList<>();

        for(int next:graph.get(0)) {
            List<Integer> temp=new ArrayList<>();
            temp.add(0);
            dfs(graph,next,temp,result);
        }

        return result;
    }
}
Approach 2 — DFS ⭐ Simpler
class Solution {
    int target;

    void dfs(List<List<Integer>> graph,int node,List<Integer> path,
             List<List<Integer>> result) {

        if(node==target) {
            result.add(new ArrayList<>(path));
            return;
        }

        for(int next:graph.get(node)) {
            path.add(next);
            dfs(graph,next,path,result);
            path.remove(path.size()-1);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(List<List<Integer>> graph) {
        target=graph.size()-1;

        List<List<Integer>> result=new ArrayList<>();
        List<Integer> path=new ArrayList<>();

        path.add(0);
        dfs(graph,0,path,result);

        return result;
    }
}
Approach 3 — BFS
class Solution {
    public List<List<Integer>> allPathsSourceTarget(List<List<Integer>> graph) {
        int target=graph.size()-1;

        List<List<Integer>> result=new ArrayList<>();
        Queue<List<Integer>> queue=new LinkedList<>();

        queue.offer(new ArrayList<>(List.of(0)));

        while(!queue.isEmpty()) {
            List<Integer> path=queue.poll();
            int last=path.get(path.size()-1);

            if(last==target) {
                result.add(path);
                continue;
            }

            for(int next:graph.get(last)) {
                List<Integer> newPath=new ArrayList<>(path);
                newPath.add(next);
                queue.offer(newPath);
            }
        }

        return result;
    }
}
