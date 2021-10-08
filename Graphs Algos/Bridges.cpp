// Find bridges in an undirected graph
vector<pair<int, int>> bridge;
vector<int> low(n, 0), disc(n, 0);
int timer = 1;

void dfs_bridge(int cur, int prev) // Run this for each connected component
{
    disc[cur] = low[cur] = timer++;
    for (int next : adj[cur])
    {
        if (disc[next] == 0)
        {
            dfs_bridge(next, cur);
            low[curr] = min(low[curr], low[next]);
        }
        else if (next != prev) // Back edges can never be bridges, so we have to check only tree edges
        {
            low[curr] = min(low[curr], disc[next]); //checking backedge with its ancestor node, and not parent node bcz we are considering parent child as current edge
        }

        if (low[next] > disc[cur])
            bridge.push_back({cur, next});
    }
}
/*
Example :
Problem - https://leetcode.com/problems/critical-connections-in-a-network/
Solution : 
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto conn : connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time++;
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev)    //if visited, but not parent, can be ancestor (back edge)
                low[curr] = min(low[curr], disc[next]); //min of ancestoe in time(or discovery)
            if (low[next] > disc[curr]) //if child ka low time should be greater than in time of parent , tabhi cycle mai nahe rahenga
                ans.push_back({curr, next});
        }
    }
private:
    vector<int> disc{0}, low{0};
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
};
*/