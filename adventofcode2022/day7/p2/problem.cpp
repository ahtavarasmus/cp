#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif
struct Node {
    string name;
    string type;
    long int size;   
    Node* parent;
    set<Node*> children;
};
typedef struct Node Node;

void read_graph(Node* root){ 
    for (Node* child : root->children){
        read_graph(child);
    }

    if (root->type == "file"){
        root->parent->size += root->size;
    } else {
        if (root->parent != NULL){
            root->parent->size += root->size;
        }
    }
}

void read_graph2(Node* root, set<Node*> &dirs, long int space_needed){
    for (Node* child : root->children){
        read_graph2(child,dirs,space_needed);
    }
    if (root->type == "dir"){
        if (root->size > space_needed){
            debug("here")
            dirs.insert(root);
        }
    }
}

void solve(){
    set<Node*> nodes;
    Node* root = new Node;
    root->name = "/";
    root->type = "dir";
    root->parent = NULL;
    nodes.insert(root);
    Node* cur_dir = root;
    string line,dollar,command,change_to,item,name;
    bool skip_reading = false;

    string word,arg,dirname,filename;
    while (cin >> word){
        if (word == "$" or skip_reading){
            if (!skip_reading){
                cin >> word;
            }
            skip_reading = false;
            if (word == "cd"){
                cin >> arg;
                if (arg == "/"){
                    cur_dir = root;
                } else if (arg == ".."){
                    cur_dir = cur_dir->parent;
                } else {
                    for (Node* n : cur_dir->children){
                        if (n->name == arg){
                            cur_dir = n;
                        }
                    }
                }
            } else {
                while (cin >> arg and arg != "$"){
                    Node* node = new Node;
                    cin >> name;
                    node->name = name;
                    if (arg != "dir"){
                        node->size = stol(arg);
                        node->type = "file";
                    } else {
                        node->size = 0;
                        node->type = "dir";
                    }
                    node->parent = cur_dir;
                    cur_dir->children.insert(node);
                    nodes.insert(node);
                }
                skip_reading = true;
            }

        }
    }

    set<Node*> dirs;

    read_graph(root);

    debug(root->size)
    int unused_space = 70000000 - root->size;
    int space_needed = 30000000 - unused_space; 
    dirs.clear();

    read_graph2(root,dirs,space_needed);

    Node* cur_min = root;
    debug(dirs.size())
    for (auto dir : dirs){
        debug(dir->name)
        debug(dir->size)
        if (dir->size < cur_min->size){
            cur_min = dir;
        }
    }
    cout << "cur_min: " << cur_min->name << " with " << cur_min->size << endl;


    for (auto item : nodes){
        delete item;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    cout << "\n";
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
