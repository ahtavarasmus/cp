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
    int size;   
    Node* parent;
    set<Node*> children;
};
typedef struct Node Node;

void read_graph(Node* root, set<Node*> &dirs){
    for (Node* child : root->children){
        read_graph(child,dirs);
    }

    if (root->type == "file"){
        root->parent->size += root->size;
    } else {
        if (root->parent != NULL){
            root->parent->size += root->size;
        }
        if (root->size < 100000){
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
                debug(arg)
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
                debug(cur_dir->name)
            } else {
                while (cin >> arg and arg != "$"){
                    Node* node = new Node;
                    cin >> name;
                    node->name = name;
                    if (arg != "dir"){
                        node->size = stoi(arg);
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

    read_graph(root,dirs);

    int sum = 0;
    for (auto dir : dirs){
        cout << dir->name << ": " << dir->size << endl;
        sum += dir->size;
    }
    cout << "sum: " << sum << endl;


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
