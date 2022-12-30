//////////////////////////////Libraries:
#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////Functions' prototype:

void DFS(int v, bool visited[],vector<int> adj[]);
int connected_components(int V, vector<int> adj[]);

////////////////////////////////////MAIN Function: 
int main()
{
	int v;
	cout<<"please give: number of vertices \n";
	cin>>v;
	vector<int> adj[v];
	for(int i=0;i<v;i++)
	{
		for (int j=0;j<v;j++)
		{
			int a;
			cin>>a;
			if (a == 1)
				adj[i].push_back(a);
		}
	}

	cout<<connected_components(v,adj)<<endl;
	return 0;
}

/////////////////////////// Functions' Implementation:

int connected_components(int V, vector<int> adj[])
{
	
	bool visited [V];
	//the variable count to store the number of components
	int count = 0;
	//we intialise all the nodes as not visited
	for (int v = 0; v < V; v++)
		visited[v] = false;
	
	for (int v = 0; v < V; v++) 
	{	
		//if we find a not visited node we do the apply the DFS
		if (visited[v] == false) 
		{
			DFS(v, visited,adj);
			//once the DFS is done, it means that all the nodes that can be reached form the node v are marked as visited, and we just complete one new component. 
			count += 1;
		}
	}

	return count;
}


void DFS(int v, bool visited[],vector<int> adj[])
{
	//we mark the node v as visited
	visited[v] = true;
	//we visit all nodes connected to v (that are not visited yet) and we apply the DFS
	for (int i = 0; i < adj[v].size(); i++)
		if (!visited[adj[v][i]])
			DFS(adj[v][i], visited,adj);
}



