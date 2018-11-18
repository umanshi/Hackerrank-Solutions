#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);
// Complete the findShortest function below.
/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    //make adjacency lists
    vector<long long> adj[graph_nodes+1]; // array of vectors
    for(long long i=0; i<graph_to.size(); i++)
    {
        long long u = graph_from[i];
        long long v = graph_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // iterate to find the first node of right color
    // call it start, s node
    long long s;
    for( s=0; s<ids.size(); s++)
    {
        if(ids[s]==val)
            break;
    }
    s++;
    //do a bfs from this s node and update the 
    // shortest length in case you meet a node of similar color
    queue<long long> q; unordered_set<long long> visited;
    q.push(s);
    visited.insert(s);
    long long dist[graph_nodes+1];
    dist[s] = 0;
    int found = 0;
    long long c;
    while(!q.empty())
    {
        c = q.front();
        q.pop();
        if(ids[c-1]==val && c!=s)
        {   found = 1;
            break;
        }
        for(long long i=0; i<adj[c].size(); i++)
        {   long long node = adj[c][i];
            if(visited.find(node) == visited.end())
            {
                visited.insert(node);
                dist[node] = dist[c]+1;                
                q.push(node);
            }           
        }
    }
    if(found == 0)
        return -1;
    return dist[c];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
