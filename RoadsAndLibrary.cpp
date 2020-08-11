#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> visited;
unordered_map<long,vector<long>> adj;
void dfs(int node, int& count)
{
  count++;
  visited[node] = true;
  for(auto j:adj[node])
    if(!visited[j])
      dfs(j,count);

}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
  visited.resize(n,false);

  for(int i=0;i<cities.size();i++)
  {
    adj[cities[i][0]-1].push_back(cities[i][1]-1);
    adj[cities[i][1]-1].push_back(cities[i][0]-1);
  }
  long ans = 0;
  for(int i = 0;i<n;i++)
  {
    if(!visited[i])
    {
      int nodes = 0;
      dfs(i,nodes);
      ans+=c_lib;
      if(c_lib<c_road)
        ans+=c_lib*(nodes-1);
      else
        ans+=c_road*(nodes-1);
    }
  }
  return ans;

}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,c_lib,c_road;
    cin>>n>>m>>c_lib>>c_road;
    vector<vector<int>> cities;
    for(int i=0;i<m;i++)
    {
      int a,b;
      cin>>a>>b;
      cities.push_back({a,b});
    }
    cout<<roadsAndLibraries(n,c_lib,c_road,cities)<<endl;
    for(int i=0;i<n;i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
  }
}
