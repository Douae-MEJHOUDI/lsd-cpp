

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "liste_simple.h"
#include "file.h"
//the last two files are given by our teacher M.KAHOUI 

#define INFINITY 9999
#define maxsize 100

struct result
{
    liste* route;
    int taille;
}; 

typedef struct result result ;
typedef struct result* res ;



////////PROTOTYPES:

int** adjency_matrix(int n);//creates an empty squere matrix of n row and column
void affichage_adj_matrix(int** adj_matrix,int n);//print the matrix
void free_adj_matrix(int** adj_matrix, int n);//delocate the adjency' matrix
liste node_neighbors(int node, int** M, int n);//returns a list whith nodes neighbors to the node given in argument
int number(int** adj_matrix, int n,int S, int D);//calculates the number of shortest paths in the given map between S and E
void find_shortestPaths(res paths, liste path, liste* parent, int n, int u);//recursive function to find the shortest paths
void BFS(int** adj,liste* parent, int n, int start);// excutes the breadth first searching algorithm  
res shortestPaths(int** adj, int n, int start, int end, int number);//the function that initialize the last two functions
