#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>ans;

bool solution_found(int id)
{
    return id==0;
}

vector<int>get_candidates(vector<int>state)
{
    map<int,int>taken;
    for(int x : state){
        taken[x]=1;
    }
    vector<int>candidates;

    for(int i=n;i>0;i--){
        if(taken.count(i)==0)
            candidates.push_back(i);
    }
    return candidates;
}

void back_track(int id,vector<int>state)
{
    if(solution_found(id)){
        ans.push_back(state);
        return ;
    }
    vector<int>candidates=get_candidates(state);

    for(int candidate: candidates){
        state.push_back(candidate);

        back_track(id-1,state);

        state.pop_back();
    }
}

int main()
{
    cin>>n;
    vector<int>initial_state;
    back_track(n,initial_state);

    for(vector<int>permutation:ans){
        for(int x:permutation)
            cout<<x<<" ";
        cout<<endl;
    }
}
