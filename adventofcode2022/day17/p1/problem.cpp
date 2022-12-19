#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif


void print_chamber(const auto &chamber)
{
    for (int y = chamber.size()-1; y > -1; --y){
        for (int x = 6; x > -1; --x){
            if (chamber[y][x] == 1)
                cout << "@";
            else
                cout << ".";
        }
        cout << endl;
    }
}
set<pair<int,int>> add_shape(auto & shape, auto &chamber)
{
    vector<int> row;
    set<pair<int,int>> shape_coords;
    switch (shape){
        case 1:
            // line
            for (int i = 0; i < 7; ++i){
                if (1 <= i and i <= 4){
                    row.push_back(1);
                    shape_coords.insert({chamber.size(),i});  
                } else
                    row.push_back(2);
            }
            chamber.push_back(row);
            return shape_coords;
        case 2:
            // plus
            for (int r = 0; r < 3; ++r){
                row.clear();
                for (int i = 0; i < 7; ++i){
                    if (r == 0){
                        if (i == 3){
                            row.push_back(1);
                            shape_coords.insert({chamber.size(),i});  
                        } else
                            row.push_back(2);
                    } else if (r == 1){
                        if (2 <= i and i <= 4){
                            row.push_back(1);
                            shape_coords.insert({chamber.size(),i});  
                        } else
                            row.push_back(2);
                    } else {
                        if (i == 3){
                            row.push_back(1);
                            shape_coords.insert({chamber.size(),i});  
                        } else
                            row.push_back(2);
                    }
                }
                chamber.push_back(row);
            }
            return shape_coords;
        case 3:
            // L
            for (int i = 0; i < 7; ++i){
                if (2 <= i and i <= 4) {
                    row.push_back(1);
                    shape_coords.insert({chamber.size(),i});  
                } else row.push_back(2);
            }
            chamber.push_back(row),row.clear();

            for (int i = 0; i < 7; ++i){
                if (i == 2){ 
                    row.push_back(1);
                    shape_coords.insert({chamber.size(),i});  
                } else row.push_back(2);
            }
            chamber.push_back(row),row.clear();
            for (int i = 0; i < 7; ++i){
                if (i == 2){ 
                    row.push_back(1);
                    shape_coords.insert({chamber.size(),i});  
                } else row.push_back(2);
            }
            chamber.push_back(row),row.clear();
            return shape_coords;
                        
        case 4:
            // I
            for (int r = 0; r < 4; ++r){
                row.clear();
                for (int i = 0; i < 7; ++i){
                    if (i == 4){ 
                        row.push_back(1);
                        shape_coords.insert({chamber.size(),i});  
                    } else row.push_back(2);
                }
                chamber.push_back(row);
            }
            return shape_coords;
        case 5:
            // dot
            for (int i = 0; i < 7; ++i){
                if (3 <= i and i <= 4){ 
                    row.push_back(1);
                    shape_coords.insert({chamber.size(),i});  
                } else row.push_back(2);
            }
            chamber.push_back(row);
            row.clear();
            for (int i = 0; i < 7; ++i){
                if (3 <= i and i <= 4){ 
                    row.push_back(1);
                    shape_coords.insert({chamber.size(),i});  
                } else row.push_back(2);
            }
            chamber.push_back(row),row.clear();
            return shape_coords;
    }
    return shape_coords;
}

void push_shape(char arrow,auto &shape_coords,auto &chamber)
{
    for (auto &coord : shape_coords){
        if (arrow == '<' and 
                (coord.second+1 == 7 or 
                chamber[coord.first][coord.second+1] == 3))
            return;
        if (arrow == '>' and
                (coord.second-1 == -1 or
                 chamber[coord.first][coord.second-1] == 3))
            return;
    }
    pair<int,int> p;
    for (auto &coord : shape_coords){
        p = {coord.first,coord.second};
        shape_coords.erase(p);
        chamber[coord.first][coord.second] = 2;
        if (arrow == '<'){ 
            p.second++;
            chamber[coord.first][coord.second+1] = 1;
        } else {
            p.second--;
            chamber[coord.first][coord.second-1] = 1;
        }
        shape_coords.insert(p);
    }
    debug("survived")
}

bool gravity(auto &shape_coords,auto &chamber)
{
    bool steady = false;
    for (auto &coord : shape_coords)
        if (chamber[coord.first-1][coord.second] == 3) steady = true;

    pair<int,int> p;
    set<pair<int,int>> new_coords;
    for (auto &co : shape_coords){
        if (steady){
            chamber[co.first][co.second] = 3;
        } else {
            debug("not steady")
            p = {co.first-1,co.second};
            new_coords.insert(p);
        }
    }
    if (!steady){
        shape_coords.clear();
        shape_coords = new_coords;
        return false;
    }
    return false;

}

void solve(){
    vector<int> shapes = {1,2,3,4,5};
    vector<vector<int>> chamber;
    vector<int> row;
    for (int i = 0; i < 7; ++i){
        row.push_back(1);
    }
    chamber.push_back(row);
    row.clear();
    for (int space = 0; space < 3; ++space){
        for (int i = 0; i < 7; ++i){
            row.push_back(2);
        }
        chamber.push_back(row);
        row.clear();
    }
    // first = y, second x
    set<pair<int,int>> shape_coords;

    shape_coords = add_shape(shapes[0],chamber);
    //shape_coords = add_shape(shapes[1],chamber);
    //shape_coords = add_shape(shapes[2],chamber);
    //shape_coords = add_shape(shapes[3],chamber);
    //shape_coords = add_shape(shapes[4],chamber);

    char arrow = '>';
    push_shape(arrow,shape_coords,chamber);
    gravity(shape_coords,chamber);
/*
    push_shape(shapes[4],arrow,shape_coords,chamber);
    push_shape(shapes[4],arrow,shape_coords,chamber);
    push_shape(shapes[4],arrow,shape_coords,chamber);
    push_shape(shapes[4],arrow,shape_coords,chamber);
    push_shape(shapes[4],arrow,shape_coords,chamber);
    */

    print_chamber(chamber);



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
