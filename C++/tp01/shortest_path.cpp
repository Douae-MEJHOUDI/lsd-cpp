

#include "shortest_path.hpp"

/////////////////MAIN Function: 
int main()
{
	int v, src, dest;
	cout<<"please give: number of vertices, the source and the destination \n";
	cin>>v>>src>>dest;
	vector<int> adj[v];
	int line[v][v];
	for(int i=0;i<v;i++)
	{
		for (int j=0;j<v;j++)
		{
			int a;
			cin>>a;
			line[i][j]=a;
		}
	}
	
	for(int i=0;i<v;i++)
	{
		for (int j=0;j<i;j++)
		{
			if(line[i][j] == 1)
				add_edge(adj, i, j);
		}
	}

	printShortestPath(adj, src-1, dest-1, v);
	
	return 0;
}


//////////// Functions' Implementation:

void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}
/*
BFS: Breadth-first search 
The main idea of this algorithm is doing a BFS to find and store the shortest distance from Src to 
all the other vertices and  maintain a predescessor list for all the vertices.
(predescessor list for a node A is a list that contains the nodes who leads to node A or connected to the node A )
Then, for each node, it will store all the parents for which it has the shortest distance from the source node.
we recover all the paths using preced array and at any instant, we will push one vertex in the path array and 
then call for all its parents. Once “-1” in the above steps,it means a path has been found.

*/
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[])
{
	//we create queue to store the vertices, and visited to be sure not to visit a node twice
	list<int> queue;
	bool visited[v];
	//we initialise all the nodes as not visited and the predescessor as -1 (none for now)
	for (int i = 0; i < v; i++) 
	{
		visited[i] = false;
		pred[i] = -1;
	}
	
	//we start with the first node: the source, we mark it as visited and we push it to the queue.
	visited[src] = true;
	queue.push_back(src);
	
	while (!queue.empty())
	{
		//we take the front node from the queue and process it
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) //adj[u].size() is how many nodes are connected to u
		{
			//if we find a connected node that has been already visited, we skip to the next
			if (visited[adj[u][i]] == false) 
			{
				//if adj[u][i] not visited yet, we mark it as visited
				visited[adj[u][i]] = true;
				//since this is the first time to be visited (from node u), the closet predescessor from adj[u][i] to the source is u.
				pred[adj[u][i]] = u;
				// and finally, we push that node to the queue to process its connections
				queue.push_back(adj[u][i]);
				//once we reach the destination, no need to continue the work and we quit the loop and return true as there is a path between the given source and destination
				if (adj[u][i] == dest)
				return true;
			}
		}
	}
	//if we treated every node and none leads to dest then there isn't any path between the source and the destination
	return false;
}

void printShortestPath(vector<int> adj[], int s, int dest, int v)
{
	int pred[v];
	
	if (BFS(adj, s, dest, v, pred) == false)
	{
		cout << "The source and destination are not connected";
		return;
	}
	//we creat a path vector to store the shortest path between src and dest using pred list
	vector<int> path;
	int target = dest;
	path.push_back(target);
	while (pred[target] != -1) 
	{
		path.push_back(pred[target]);
		target = pred[target];
	}
	
	cout << "\nPath is: ";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i]+1 << " ";
	cout<<endl;
}


