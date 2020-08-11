#include<bits/stdc++.h>
using namespace std;
pair<int,int> getNextMove(int i,int j)
{
  if(i%2==0)
  {
    j = j + 1;
    if(j>9)
    {
      i = i+1;
      j = 9 - (j%10);
    }

    return make_pair(i,j);
  }
  else
  {
    j = j - 1;
    if(j<0)
    {
      i = i + 1;
      j = 0 - j - 1;
    }
    return make_pair(i,j);
  }
}
pair<int,int> getPrevMove(int i,int j,int k)
{
  if(i%2==0)
  {
    j = j - k;
    if(j<0)
    {
      i = i -1;
      j = 0 - j - 1;
    }
    return make_pair(i,j);
  }
  else
  {
    j = j + k;
    if(j>9)
    {
      i = i - 1;
      j = 9 - (j%10);
    }
    return make_pair(i,j);
  }
}
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes)
{
  unordered_map<int,vector<int>> adj;
  for(int i=1;i<=100;i++)
    for(int k=1;k<=6;k++)
      if((i+k)<=100)
        adj[i].push_back(i+k);

  unordered_map<int,int> lad;
  unordered_map<int,int> sna;
  for(int i=0;i<ladders.size();i++)
    lad[ladders[i][0]] = ladders[i][1];

  for(int i=0;i<snakes.size();i++)
    sna[snakes[i][0]] = snakes[i][1];

  int dist = 0;
  vector<bool> visited(101,false);
  deque<pair<int,int>> q;
  q.push_back(make_pair(1,0));
  while(!q.empty())
  {
    auto node = q.front();
    q.pop_front();
    if(node.first==100)
      return node.second;
    visited[node.first] = true;
    if(lad.count(node.first)>0)
      q.push_back(make_pair(lad[node.first],node.second));

    if(sna.count(node.first)>0)
    {
      if(!visited[sna[node.first]])
        q.push_back(make_pair(sna[node.first],node.second));
      continue;
    }

    for(int i=0;i<adj[node.first].size();i++)
    {
      if(!visited[adj[node.first][i]])
        q.push_back(make_pair(adj[node.first][i],node.second+1));
    }
  }

  return -1;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,a,b,m;
    cin>>n;
    vector<vector<int>> snakes;
    vector<vector<int>> ladders;
    for(int i=0;i<n;i++)
    {
      cin>>a>>b;
      ladders.push_back({a,b});
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      snakes.push_back({a,b});
    }

    int ans = quickestWayUp(ladders,snakes);
    cout<<ans<<endl;
  }
  return 0;
}
