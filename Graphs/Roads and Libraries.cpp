/*
Only 5/13 test cases cleared.
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long DFS_util(int i, vector<vector<int> > adj, bool visited[])
{   int count = 0;
    visited[i] = true;
    for(int j=0; j<adj[i].size(); j++)
    {   
        int node = adj[i][j];
        if(!visited[node])
            count += 1+DFS_util(node, adj, visited);
    }
    return count;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    bool visited[n+1] = {false};
    vector<vector<int> > adj;
    for(int i=0; i<n+1; i++)
    {   vector<int> v;
        adj.push_back(v); 
    }
    for( int i=0; i<cities.size(); i++)
    {   int u= cities[i][0]; int v = cities[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long cost = 0;
    for(int i=1; i<=n; i++)
    {   if(!visited[i])
        {   visited[i] = true;
            long count = 1+DFS_util(i, adj, visited);
            int optimal_cost = (c_lib>c_road)?c_road:c_lib;
            cost += c_lib + (count-1)*optimal_cost;   
        }
    }
return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
