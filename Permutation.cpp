#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>ans;

bool solution_found(int id,vector<int>state)
{
    return id == n;
}

vector<int>get_candidates(vector<int>state)
{
    map<int,int>taken;
    for(int x:state)
        taken[x]=1;

    vector<int>candidates;

    for(int i=1;i<=n;i++){
        if(taken.count(i) == 0)
            candidates.push_back(i);
    }
    return candidates;
}

void back_track(int id,vector<int>state)
{
    // base case handling
    if(solution_found(id,state)){
        ans.push_back(state);
        return ;
    }
    // loop over the candidates
    vector<int>candidates=get_candidates(state);

    for(int candidate : candidates){
        // - add candidate to state
        state[id] = candidate;

        // - back_track(state)
        back_track(id+1,state);

        // - remove candidate from state
        state[id]=0;
    }
}

int main()
{
    cin>>n;
    vector<int>initial_state(n);
    back_track(0,initial_state);

    for(vector<int>permutation : ans){
        for(int x : permutation)
            cout<<x<<" ";
        cout<<endl;
    }
}
