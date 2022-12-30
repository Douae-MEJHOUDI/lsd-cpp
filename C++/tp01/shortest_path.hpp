//////////Libraries:
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

/////////Functions' prototype:
void add_edge(vector<int> adj[], int src, int dest);
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[]);
void printShortestPath(vector<int> adj[], int s, int dest, int v);
