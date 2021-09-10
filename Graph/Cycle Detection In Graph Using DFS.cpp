#include <bits/stdc++.h>
#define lli long long int
#define endl "\n"
#define MAX  100005
using namespace std;

vector <int> v[MAX];
bool visited[MAX];
bool cycle = false;

bool DFS(int i, int parent)
{
	if(visited[i] == false)
	{
		visited[i] = true;
		for(int j = 0; j<v[i].size(); j++)
			if(v[i][j] != parent)
				DFS(v [i][j], i);
	}
	else
	{
		cycle = true;
	}
}

int main()
{
	int n, e, x, y;
	cout<<"Enter the number of vertex: ";
	cin>>n;
	cout<<"Enter the number of edges: ";
	cin>>e;

	for(int i = 0; i<e; i++)
	{
		cout<<"Enter both the vertex of the edge "<<i+1<<": ";
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	DFS(1, 0);

	if(cycle)
		cout<<"cycle exists in graph";
	else
		cout<<"cycle does not exists in graph";

}
