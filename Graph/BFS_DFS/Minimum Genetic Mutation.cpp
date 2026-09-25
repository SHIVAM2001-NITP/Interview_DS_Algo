/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=H3kSFSv-t30
    Company Tags                : Twitter
    Leetcode Link               : https://leetcode.com/problems/minimum-genetic-mutation/
*/

//Just like Word Ladder
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        
        unordered_set<string> visited;
        queue<string> que;
        que.push(start);
        visited.insert(start);
        
        int level = 0;
        
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                string curr = que.front();
                que.pop();
                
                if(curr ==  end)
                    return level;
                
                for(char ch : "ACGT") {
                    for(int i = 0; i<curr.length(); i++) {
                        string neighbour = curr;
                        neighbour[i] = ch;
                        
                        if(visited.find(neighbour) == visited.end() && 
                           bankset.find(neighbour) != bankset.end()) {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};

// Java

import java.util.*;

class Solution {
    public int minMutation(String start, String end, String[] bank) {

        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));

        Set<String> visited = new HashSet<>();

        Queue<String> queue = new LinkedList<>();
        queue.offer(start);
        visited.add(start);

        int level = 0;

        while (!queue.isEmpty()) {

            int n = queue.size();

            while (n-- > 0) {

                String curr = queue.poll();

                if (curr.equals(end)) {
                    return level;
                }

                for (char ch : new char[]{'A', 'C', 'G', 'T'}) {

                    for (int i = 0; i < curr.length(); i++) {

                        char[] chars = curr.toCharArray();
                        chars[i] = ch;

                        String neighbour = new String(chars);

                        if (!visited.contains(neighbour)
                                && bankSet.contains(neighbour)) {

                            visited.add(neighbour);
                            queue.offer(neighbour);
                        }
                    }
                }
            }

            level++;
        }

        return -1;
    }
}
