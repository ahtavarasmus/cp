#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

int n;
unordered_map<string,int> tin,low;
unordered_set<string> visited;
map<string,vector<string>> nodes;
vector<string> artpoints;
int timer;

void dfs(string v, string p = "")
{
    visited.insert(v);
    tin[v] = low[v] = timer++;
    int kids = 0;
    for (string to : nodes[v]){
        if (visited.find(to) != visited.end()){
            low[v] = min(low[v],tin[to]);
        } else {
            dfs(to,v);
            low[v] = min(low[v],low[to]);
            if (low[to] >= tin[v] && p != ""){
                artpoints.push_back(v);
            }
            kids++;
        }
    }
    if (p == "" && kids > 1)
        artpoints.push_back(v);

}

int main(int argc, char *argv[])
{
    string filename = argv[1];
    ifstream infile(filename);

    string line,u,v;
    timer = 0;
    string start;
    while (getline(infile,line)){
        istringstream linestream(line);
        linestream >> u >> v;
        start = u;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    dfs(start);
    cout << "Found " << artpoints.size() << " articulation nodes:";
    sort(artpoints.begin(),artpoints.end());
    for (auto p : artpoints){
        cout << " " << p;
    }
    cout << endl;
    
}
