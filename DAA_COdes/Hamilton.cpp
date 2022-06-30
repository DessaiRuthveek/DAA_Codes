#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >rv;
int n,edges;
void recur(int strt,int src,vector<int>&tmp,vector<bool>&vis,vector<int>adj[]){
int sz=tmp.size();
if(sz==0){
    for(int j=0;j<adj[0].size();j++){
            int des=adj[0][j];
            tmp.push_back(0);
            tmp.push_back(des);
            vis[0]=true;
            vis[des]=true;
            // cout<<"new strt "<<i<<" "<<des<<" ";
            recur(0,des,tmp,vis,adj);
            tmp.pop_back();
            // cout<<endl;
              vis[0]=false;
            vis[des]=false;
            tmp.pop_back();
    }
}
else{
    if(sz==n){
        // cout<<"Entered"<<endl;
        for(int i=0;i<adj[src].size();i++){
                int des=adj[src][i];
                if(des==strt){
                tmp.push_back(des);
                 rv.push_back(tmp);
                 tmp.pop_back();
                 return;
                }
        }
    }
    else if(sz>n){
        //  cout<<"Larger Size"<<endl;
        return ;
    }
    int ssz=adj[src].size();
        for(int i=0;i<ssz;i++){
            int des=adj[src][i];
            if(!vis[des]){
                tmp.push_back(des);
                vis[des]=true;
                // cout<<"called "<<des<<endl;
                recur(strt,des,tmp,vis,adj);
                vis[des]=false;
                tmp.pop_back();
            }
        }
    }
}

int main() {
    //n vertices, edges
    cout<<"Enter VErtices: ";
    cin>>n;
    cout<<"Enter edges: ";
    cin>>edges;

    cout<<"Enter paths.. ";
    vector<int>adj[n];
    for(int i=0;i<edges;i++){
        int from=0,to=0;
        cin>>from>>to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vector<int>tmp;
    vector<bool>vis(n,false);
    recur(-1,-1,tmp,vis,adj);
    cout<<"Requried Paths "<<endl;
    for(auto it:rv){
        for(auto ot:it)cout<<ot<<" ";
        cout<<endl;
    }
    rv.clear();
    return 0;
}