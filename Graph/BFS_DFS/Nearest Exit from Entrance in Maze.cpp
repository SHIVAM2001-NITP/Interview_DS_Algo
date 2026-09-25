/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q4bqto_yG6I
    Company Tags                : Similar Problem asked in Samsung
    Leetcode Link               : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
*/

//Simply Use BFS : 
//Time  - O(m*n)
//Space - O(m+n)
class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; //marking it visited
        int steps = 0;
        
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                pair<int, int> temp = que.front();
                que.pop();
                
                if(temp != make_pair(entrance[0], entrance[1]) && 
                   (temp.first == 0 || temp.first == m-1 || temp.second == 0 || temp.second == n-1))
                    return steps;
                
                for(auto &dir : directions) {
                    int i = temp.first  + dir[0];
                    int j = temp.second + dir[1];

                    if(i >= 0 && i < m && j >= 0 && j < n && maze[i][j] != '+') {
                        que.push({i, j});
                        maze[i][j] = '+'; //marking it as visited
                    }
                }
                
            }
            steps++;
        }
        
        return -1;
    }
};
//JAVA

class Solution {
    int[][] directions={{0,1},{0,-1},{1,0},{-1,0}};

    public int nearestExit(char[][] maze,int[] entrance) {
        int m=maze.length,n=maze[0].length;

        Queue<int[]> queue=new LinkedList<>();
        queue.offer(new int[]{entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';

        int steps=0;

        while(!queue.isEmpty()) {
            int size=queue.size();

            while(size-->0) {
                int[] curr=queue.poll();
                int row=curr[0],col=curr[1];

                if(!(row==entrance[0]&&col==entrance[1]) && (row==0||row==m-1||col==0||col==n-1))
                    return steps;

                for(int[] dir:directions) {
                    int r=row+dir[0],c=col+dir[1];

                    if(r>=0&&r<m&&c>=0&&c<n&&maze[r][c]!='+') {
                        queue.offer(new int[]{r,c});
                        maze[r][c]='+';
                    }
                }
            }
            steps++;
        }

        return -1;
    }
}
