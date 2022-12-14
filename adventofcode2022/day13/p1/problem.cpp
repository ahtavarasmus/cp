#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif

/*!
    return 0 if right order, 1 if equal, 2 if wrong order 
*/
int compare_integers(int left,int right)
{
    if (left < right)
        return 0;
    if (left == right)
        return 1;
    return 2;
}

int compare_list(string left,string right)
{
    int li = -1,ls = left.size();
    int ri = -1, rs = right.size();
    int lstart,rstart;
    int order;


    debug("reg")
    debug(left)
    debug(right)
    int open_par = 0;
    string right_sub;
    string left_sub;
    bool llist,rlist;

    while (li+1 < ls and ri+1 < rs){
        lstart = li+1;
        left_sub = "";
        debug("NEW ROUND")
        debug(lstart)
        debug(left[lstart])
        if (left[lstart] == '['){ // if list
            debug("at the left list") 
            open_par = 0;
            int lwidth = 0;
            while (++li < ls){
                if (left[li] == '[') ++open_par;
                if (left[li] == ']') --open_par;
                if (left[li] == ',' and !open_par){
                    left_sub = left.substr(lstart+1,lwidth-2);
                    break;
                }
                if (li+1 == ls and !open_par){
                    left_sub = left.substr(lstart+1,lwidth-1);
                    break;
                }
                lwidth++;
            }
            llist = true;
        } else { // if number
            int lwidth = 0;
            debug("at left number")
            while (left[++li] != ',' and li < ls){
                lwidth++;
            }
            left_sub = left.substr(lstart,lwidth);
            llist = false;
        }
        rstart = ri+1;
        right_sub = "";
        if (right[rstart] == '['){ // if list
            debug("at the right list")
            open_par = 0;
            int rwidth = 0;
            while (++ri < rs){
                if (right[ri] == '[') ++open_par;
                if (right[ri] == ']') --open_par;
                if (right[ri] == ',' and !open_par){
                    right_sub = right.substr(rstart+1,rwidth-2);
                    break;
                }
                if (ri+1 == rs and !open_par){
                    right_sub = right.substr(rstart+1,rwidth-1);
                    break;
                }
                rwidth++;
            }
            rlist = true;
        } else { // if number    
            debug("at right number")
            int rwidth = 0;
            while (right[++ri] != ',' and ri < rs){
                rwidth++;
            }
            right_sub = right.substr(rstart,rwidth);
            rlist = false;
            rwidth++;
        }
        debug(left_sub)
        debug(right_sub)

        if (!left_sub.size() and right_sub.size())
            return 0;
        else if (left_sub.size() and !right_sub.size())
            return 2;
        debug(llist)
        debug(rlist)
        if (!llist and rlist){ // left is number
            llist = true;
            debug("left is number")
        }
        if (llist and !rlist){ // right is number
            rlist = true;
            debug("right is number")
        }
        debug(llist)
        debug(rlist)
        if (llist and rlist){ // both are lists (recursion)
            debug("both lists")
            order = compare_list(left_sub,right_sub);
            if (order != 1)
                return order;
        } else if (!llist and !rlist){ // both numbers
            debug("both numbers")
            if (stoi(left_sub) < stoi(right_sub))
                return 0;
            if (stoi(left_sub) > stoi(right_sub))
                return 2;
        } 
               /*
        if (order != 1)
            return order;
            */
        
    }
    if (ls < rs)
        return 0;
    if (ls > rs)
        return 2;
    return 0;

}


void solve(){
    string left,right,empty;
    vector<int> l;
    vector<int> r;

    vector<int> indices;
    int i = 1;
    while (getline(cin,left)){
        getline(cin,right);
        debug(i)
        int o = compare_list(left,right);

        debug("haha")
        debug(o)

        if (o == 0)
            indices.push_back(i);
        getline(cin,empty);
        ++i;
    }
    int sum = 0;
    for (int i = 0; i < indices.size(); ++i){
        sum += indices[i];
    }
    cout << sum;
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
