#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pii pair<int,int>

int direction(pii p, pii q, pii r){
    // pr × pq

    int prx = r.ff - p.ff;
    int pry = r.ss - p.ss;

    int pqx = q.ff - p.ff;
    int pqy = q.ss - p.ss;

    return (prx * pqy) - (pry * pqx);
}

int main(){
    
    vector<pii> v = {{0,0},{3,1},{4,4},{1,2},{0,5},{2,2},{-1,3}};
    int n = v.size();

    // -------------------- calcutale p0 starts ----------------------------------
    pii p0 = v[0];
    int idx0 = 0;
    for(int i = 1; i < n; i++){
        if((v[i].ss < p0.ss) && (v[i].ss == p0.ss && v[i].ff < p0.ff)){
            p0 = v[i];
            idx0 = i;
        }
    }
    // -------------------- calcutale p0 ends ----------------------------------

    // -------------------- step 2 starts ---------------------------------
    vector<pair<double,int>> polar;
    for(int i = 0; i < n; i++){
        if(v[i].ff != p0.ff || v[i].ss != p0.ss){             // if(i != idx0)
            int d_b = v[i].ss - p0.ss;
            int c_a = v[i].ff - p0.ff;
            double angle = atan2(d_b,c_a);
            if(angle < 0){
                angle += 180;
            }
            polar.push_back({angle,i});
        }
    }
    sort(polar.begin(), polar.end());
    // -------------------- step 2 ends ---------------------------------

    // -------------------- step 3 starts ---------------------------------
    stack<int> s;
    s.push(idx0);
    s.push(polar[0].ss);
    s.push(polar[1].ss);

    for(int i = 2; i < polar.size(); i++){
        int top = s.top();
        s.pop();
        int next_to_top = s.top();
        s.push(top);
        while(direction(v[next_to_top], v[top], v[i]) >= 0){
            // cout << "kaik to thayu\n";
            s.pop();
            top = s.top();
            s.pop();
            next_to_top = s.top();
            s.push(top);
        }
        s.push(i);
    }

    // -------------------- step 3 ends ---------------------------------

    // cout << s.size();
    while(!s.empty()){
        int i = s.top();
        s.pop();

        cout << "(" << v[i].ff << ", " << v[i].ss << ")\n";
    }

    return 0;
}