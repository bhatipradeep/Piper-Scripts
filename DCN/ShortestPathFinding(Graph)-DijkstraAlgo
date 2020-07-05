#include <bits/stdc++.h>
using namespace std;


void printRoutingCostTable(vector<int>distance){
    cout<<"Shortest distance from Source to all nodes:"<<endl;
    for(int i=1;i<distance.size();i++){
        cout<<i<<"  "<<distance[i]<<endl;
    }
}
void printRoutingShortestPath(map<int,int>previousNode,int N){
    cout<<"Shortest Path to all destinations:"<<endl;
    for(int i=1;i<N+1;i++){
        vector<int>path;
        int lastNode=i;
        while(lastNode!=-1){
            path.push_back(lastNode);
            lastNode = previousNode[lastNode];
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int N,edges,source;
    cin>>N;
    cin>>edges;
    cin>>source;

    vector<pair<int,int>>graph[N+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>route;
    vector<int>distance(N+1,INT_MAX);
    map<int,int>previousNode;
    previousNode[source]=-1;
    int a,b,w;
    for(int i=0;i<edges;i++){
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    route.push({0,source});
    distance[source]=0;
    while(!route.empty()){
        int curNode = route.top().second;
        route.pop();
        for(int i=0;i<graph[curNode].size();i++){
            int v = graph[curNode][i].first;
            int cost = graph[curNode][i].second;
//            cout<<v<<" "<<cost<<endl;
            if(distance[v]>distance[curNode]+cost){
                distance[v]=distance[curNode]+cost;
                previousNode[v]=curNode;
                route.push({distance[v],v});
            }
        }
    }
    printRoutingCostTable(distance);
    printRoutingShortestPath(previousNode,N);

}
