/*

# Dijkstra's Algorithm – Deep Understanding Questions

## Level 1: Foundation

1. Why does Dijkstra always choose the node with the minimum distance?
2. Why is the distance of a node final once it is popped from the priority queue?
3. Why does Dijkstra fail when there is a negative edge?
4. Why is a priority queue used instead of a queue, stack, vector, or map?
5. Why can the priority queue contain duplicate entries for the same node?
6. Why is the following check necessary?

   * `if (dis > dist[node]) continue;`
   * or `if (vis[node]) continue;`
7. What happens if we remove the above check?

---

## Level 2: Understanding the Algorithm

8. What is edge relaxation, and why do we perform it?
9. Can a node's shortest distance be updated multiple times before it becomes final?
10. Why are non-negative edge weights sufficient for Dijkstra's correctness?
11. Can Dijkstra stop early? If yes, exactly when?
12. Why do we process a node only when it is popped from the priority queue instead of when it is first discovered?
13. Can two different nodes have the same shortest distance? Does that affect the algorithm?

---

## Level 3: Time Complexity

14. Why is the time complexity of Dijkstra's algorithm (O(E \log V))?
15. Why is it not (O(V \log V))?
16. Why is it not (O(E \log E))?
17. How many times can a single node enter the priority queue?
18. How many times can an edge be relaxed?
19. Why is a priority queue generally faster than a set for Dijkstra?
20. What are the advantages and disadvantages of using a `set` instead of a `priority_queue`?

---

## Level 4: Algorithm Variations

21. When should BFS be used instead of Dijkstra?
22. When should Bellman-Ford be preferred over Dijkstra?
23. When should Floyd-Warshall be used instead of Dijkstra?
24. Why is Topological Sort preferred over Dijkstra for a Directed Acyclic Graph (DAG)?
25. If every edge has weight 1, should we still use Dijkstra?
26. If every edge has weight 0 or 1, what algorithm is more efficient than Dijkstra?
27. Can Dijkstra be used on undirected graphs?
28. Can Dijkstra be used on directed graphs? What changes, if any?

---

## Level 5: Implementation Details

29. Why do we store `(distance, node)` instead of `(node, distance)` in the priority queue?
30. Why do we initialize:

    * `dist[source] = 0`
    * `dist[other] = INT_MAX`
31. Why do we use:

    * `if (dis + wt < dist[adjNode])`
      instead of
    * `if (dis + wt <= dist[adjNode])`
32. What happens if we mark a node as visited when it is pushed into the priority queue instead of when it is popped?
33. How does `greater<pair<int,int>>` compare two pairs inside the priority queue?
34. Can integer overflow occur while computing `dis + wt`? How can it be prevented?

---

## Level 6: Advanced Concepts

35. How can Dijkstra be modified to reconstruct the shortest path?
36. What happens if multiple shortest paths exist?
37. Can Dijkstra be used to count the number of shortest paths?
38. Can Dijkstra work correctly if the graph changes while the algorithm is running?
39. Why is Dijkstra considered a greedy algorithm?
40. Can Dijkstra's correctness be proved using mathematical induction?
41. Why is Dijkstra guaranteed to produce the optimal shortest path?

---

# Challenge Questions (Interview Level)

42. Why is popping the destination node enough to stop the algorithm?
43. Can a node ever receive a shorter distance after it has been popped? Why or why not?
44. Why do negative edge weights invalidate Dijkstra's greedy choice?
45. What is the worst-case number of elements that can exist in the priority queue?
46. Can Dijkstra be implemented without a visited array? If yes, how?
47. How would you modify Dijkstra to find the second shortest path?
48. How would you find the shortest path between every pair of vertices?
49. How would you modify Dijkstra if edge weights changed dynamically?
50. In what situations should Dijkstra not be used?

---

# Mastery Checklist

You have truly mastered Dijkstra's algorithm if you can confidently explain:

* Why the minimum-distance node is always processed first.
* Why a popped node's distance is final.
* Why negative edge weights break the algorithm.
* Why duplicate entries in the priority queue are safe.
* Why nodes are marked visited only when popped.
* Why the time complexity is (O(E \log V)).
* How to reconstruct the shortest path.
* When to use BFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Topological Sort, and 0-1 BFS.

*/

//  LINK -> https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>graph(V);
        
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            graph[u].push_back({wt,v});
            graph[v].push_back({wt,u});
        }
        vector<int>dist(V,INT_MAX);
        
        dist[src] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto ele : graph[node]){
                if(ele.first+wt < dist[ele.second]){
                    dist[ele.second] = ele.first+wt;
                    pq.push({ele.first+wt,ele.second});
                }
            }
        }
        return dist;
    }
};



// TO FIND THE SHORTEST DISTANCE WE USE THIS CONCEPT 

/*

Maintaining a parent array -> so whenever you find the shortest path we update the both dist and the parent 
After the algo finish  start from the destination and repeatedly follow the parent pointer until reaching the source, then reverse the collected 
sequence to obtain the shortest path

dist[adjNode] = newDist;
parent[adjNode] = node;

*/


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>graph(n+1);
        
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            graph[u].push_back({wt, v});
            graph[v].push_back({wt, u});    
        }
        
        vector<int>dist(n+1, INT_MAX);
        
        dist[1] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        pq.push({0,1});
        
        vector<int>parent(n+1);
        
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(wt > dist[node]) continue;
            
            for(auto x : graph[node]){
                if(x.first+wt < dist[x.second]){
                    dist[x.second] = x.first+wt;
                    parent[x.second] = node;
                    pq.push({x.first+wt, x.second});
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int>ans;
        
        ans.push_back(dist[n]);
      
      stack<int>st;
      int i = n;
      while(i != 1){
          st.push(i);
          i = parent[i];
      }
      st.push(1);
      
      while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
      }
      
      return ans;
        
    }
};