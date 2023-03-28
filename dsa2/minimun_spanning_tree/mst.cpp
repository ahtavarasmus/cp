#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <fstream>  

using namespace std;

struct edge {
    int from,to,w;
};


struct  edgescomp {
    bool operator()(const edge& i, const edge& j) const {
        if (i.w == j.w){
            if (i.from == j.from ){
                return i.to > j.to;
            } else {
                return i.from > j.from;
            }
        }
        return i.w > j.w;
    }
};

vector<edge> mst(vector<edge> edges,int s)
{
    vector<edge> mstree;
    set<int> in_mst = {s};
    priority_queue<edge, std::vector<edge>, edgescomp> pq;
    for (edge e : edges){
        if (e.from == s or e.to == s){
            cout << "Adding the edge (" << e.from << ", " << e.to << ", " << 
                e.w << ") to the priority queue" << endl;
            pq.push(e);
        }
    }
    int i = 1;
    while (!pq.empty()){
        cout << "** Iteration " << i << " **"<< endl;
        edge e = pq.top();
        pq.pop();
        int u = -1;
        if (in_mst.find(e.from) == in_mst.end()){
            u = e.from;
        } else if (in_mst.find(e.to) == in_mst.end()){
            u = e.to;
        }
        // if e.from or e.to not yet in mstree
        if (u != -1){
            // add edge e to mstree
            mstree.push_back(e);
            in_mst.insert(u);
            cout << "Adding the edge (" << e.from << ", " << e.to << ", " << 
                e.w << ") with the new node " << u << endl;
            for (edge f : edges){
                if (f.from == u or f.to == u){
                    if (in_mst.find(f.from) == in_mst.end() 
                            or in_mst.find(f.to) == in_mst.end()){
                        pq.push(f);
                    }
                }
            }
        }
        i++;
    }
    int total_weight = 0;
    for (edge e : mstree){
        total_weight += e.w;
    }
    cout << "MST(" << total_weight << "):";
    sort(mstree.begin(),mstree.end(),[](edge i, edge j){
            if (i.from == j.from){
                return i.to < j.to;
            }
            return i.from < j.from;
        });
    for (edge e : mstree){
        cout << " " << e.from << "-" << e.to;
    }
    cout << endl;
    return mstree;
}

int main(int argc, char *argv[]){
    string inputfile = argv[1];
    int starting_node = stoi(argv[2]);

    ifstream infile(inputfile);

    vector<edge> edges;

    string line,u,v,x;
    while (getline(infile,line)){
        istringstream linestream(line);
        linestream >> u >> v >> x;
        edge ne;
        ne.from = stoi(u);
        ne.to = stoi(v);
        ne.w = stoi(x);
        edges.push_back(ne);
    }
    infile.close();

    vector<edge> mstree = mst(edges,starting_node);
}
