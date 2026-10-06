/*
    Company Tags  : Uber (Phone screening)
    Leetcode Link : https://leetcode.com/problems/parallel-courses/
    Since, It's a Premium Question, so I am providing here the question and examples as well:
    
    Given K courses required to graduate and array of those courses. Some needs to be taken before others.
    [i,j] - course i must be taken in a semester that is prior to course j.
    You can take as many courses as you want every semester.

    Find a minimum number of semesters you need to finish all K courses. If not possible - throw some exception or whatever.

    Example 1:

    3, [[1,0], [1,2]].

    3 courses to graduate.
    Course 1 must be take before course 0.
    Course 1 must be taken before course 2.

    First semester you take course 1. Second semester you take course 0 and 2.

    Output: 2.

    Example 2:

    2, [[0,1], [1,0]

    2 courses to graduate.
    Course 0 must be taken before course 1.
    Course 1 must be take before course 0.

    Output:
    Exception aka "not possible."
*/

//It's a variation of Kahn's algorithm
class Solution {
public:
    int topologicalSortBFS(unordered_map<int, vector<int>>& adj, int N, vector<int>& indegree) {
        queue<int> que;
        for(int i = 1; i<=N; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        int count  = 0;
        int result = 0;
        while(!que.empty()) {
            result++;
            int n = que.size();
            while(n--) {
                int curr = que.front();
                que.pop();
                count++;
                for(auto x:adj[curr]) {
                    indegree[x]--;
                    if(indegree[x] == 0) {
                        que.push(x);
                    }
                }
            }
        }
        return count==N?result:-1;
    }
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(N+1, 0);
        for(auto relation:relations) {
            int x = relation[0];
            int y = relation[1];
            adj[x].push_back(y);
            indegree[y]++;
        }

        return topologicalSortBFS(adj, N, indegree);
    }
};

//JAVA

class Solution {
    int topologicalSortBFS(Map<Integer, List<Integer>> adj, int N, int[] indegree) {
        Queue<Integer> que = new LinkedList<>();

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0)
                que.offer(i);
        }

        int count = 0;
        int result = 0;

        while (!que.isEmpty()) {
            result++;
            int n = que.size();

            while (n-- > 0) {
                int curr = que.poll();
                count++;

                for (int x : adj.getOrDefault(curr, new ArrayList<>())) {
                    indegree[x]--;
                    if (indegree[x] == 0)
                        que.offer(x);
                }
            }
        }

        return count == N ? result : -1;
    }

    public int minimumSemesters(int N, int[][] relations) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[N + 1];

        for (int[] relation : relations) {
            int x = relation[0];
            int y = relation[1];

            adj.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
            indegree[y]++;
        }

        return topologicalSortBFS(adj, N, indegree);
    }
}

// Time: O(N + E)
// Space: O(N + E)
