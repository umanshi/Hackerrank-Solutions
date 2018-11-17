/*Check out the resources on the page's right side to learn more about breadth-first search. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

Consider an undirected graph consisting of
nodes where each node is labeled from to and the edge between any two nodes is always of length . We define node to be the starting position for a BFS. Given a graph, determine the distances from the start node to each of its descendants and return the list in node number order, ascending. If a node is disconnected, it's distance should be

.

For example, there are
nodes in the graph with a starting node . The list of , and each has a weight of

.

image

Starting from node
and creating a list of distances, for nodes through we have

.

Function Description

Define a Graph class with the required methods to return a list of distances.

Input Format

The first line contains an integer,

, the number of queries.

Each of the following

sets of lines is as follows:

    The first line contains two space-separated integers, 

and
, the number of nodes and the number of edges.
Each of the next
lines contains two space-separated integers, and , describing an edge connecting node to node
.
The last line contains a single integer,

    , the index of the starting node.

Constraints

Output Format

For each of the
queries, print a single line of space-separated integers denoting the shortest distances to each of the other nodes from starting position . These distances should be listed sequentially by node number (i.e., ), but should not include node . If some node is unreachable from , print

as the distance to that node.

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2

Sample Output

6 6 -1
-1 6

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
class Graph {
    int V;
    vector<int> *adj;
    public:
        Graph(int n) 
        {
          this->V = n;
          adj = new vector<int>[n];
        }
        void add_edge(int u, int v) 
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start)                           
        {
            queue<int> q;
            vector<int> ans(this->V, -1);
            unordered_set<int> visited;
            q.push(start);
            visited.insert(start);
            int dist_so_far = 0;
            ans[start] = 0;
            while(!q.empty())                                         
            {
                int curr = q.front();
                q.pop();
                for(int i=0; i<adj[curr].size(); i++)               
                {
                    if(visited.find(adj[curr][i]) == visited.end())
                    {
                        ans[adj[curr][i]] = ans[curr]+6;
                        visited.insert(adj[curr][i]);
                        q.push(adj[curr][i]);                      
                    } 
                } 
            } 
            return ans;       
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
