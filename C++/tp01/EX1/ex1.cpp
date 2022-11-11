//// le header part02.h contains the prototype of all functions along whith a brief descreption

//////the used algorithm is explained in the rows before the last 3 functions at the end of this file(rows 331 to 338)


#include "ex1.h"


int main()
{
    int n=6;
    
    int** adj_matrix=adjency_matrix(n);
    int output_read_matrix[6][6] = {{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,1,0,0},{0,0,1,0,1,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
    for (int i=0; i<6; i++)
    {
        for(int j=0;j<6;j++)
        {
            adj_matrix[i][j]=output_read_matrix[i][j];
        }
        
    }
    affichage_adj_matrix(adj_matrix,6);
    printf("\n");
    
    int dest =3;
    
    int nb=number(adj_matrix,n,0,dest);//nb number of shortest paths between S and E
    
    res paths=shortestPaths(adj_matrix,n,0,dest,nb);//paths is struct with liste* (route) where the program stock the shortest paths as lists 
    int length= longueur(paths->route[0])-1;//length of a single shortest path
    printf("\nThere are %d shortest paths in this map between node 0 and %d with a length of %d hours, they are:\n",nb,dest,length);
    for (int i=0;i<nb;i++)
    {
        affichageListe_city(reversed(paths->route[i]),dest);
    }
    
    free_adj_matrix(adj_matrix, n);
    
    return 0;
}



/////////////////////////////////////////Functions:

////////////For adjacency Matrix:
int** adjency_matrix(int n)
{
    int** adj_matrix=(int**)malloc(n*sizeof(int*));
    for (int i=0;i<n;i++)
    {
        adj_matrix[i]=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            adj_matrix[i][j]=0;
        }
    }
    
    return adj_matrix;
}

liste node_neighbors(int node, int** M, int n){
    liste neighbors = NULL;
    for(int i=0;i<n;i++){
        if(M[i][node] ==  1) 
            ajoutFin(i,&neighbors);
    }
    return neighbors;
}

int number(int** adj_matrix, int n,int S, int D)
{
    int* dist=(int*)malloc(n*sizeof(int));
    int* paths=(int*)malloc(n*sizeof(int));
    int* visited=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        dist[i]=maxsize;
        paths[i]=0;
        visited[i]=0;
    }
    file f={NULL,NULL};
    enfiler(S,&f);
    dist[S]=0;
    paths[S]=1;
    while(f.debut!=NULL)
    {
        int current= defiler(&f);
        liste adj_liste=node_neighbors(current,adj_matrix,n);
        liste temp=adj_liste;
        while (temp!=NULL)
        {
            int child= temp->element;
            if (visited[child]==0)
            {
                enfiler(child,&f);
                visited[child]=1;
            }
            if (dist[child]>dist[current]+1)
            {
                dist[child]=dist[current]+1;
                paths[child]=paths[current];
            }
            else if(dist[child]==dist[current]+1)
            {
                paths[child]+=paths[current];
            }
            temp=temp->suivant;
        }
        
    }
    return paths[D];
    
}

void affichage_adj_matrix(int** adj_matrix,int n)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}


void free_adj_matrix(int** adj_matrix, int n)
{
    if (adj_matrix!= NULL)
    {
        for (int i=0;i<n;i++)
        {
            if (adj_matrix[i] != NULL)
                free(adj_matrix[i]);
        }
    }
    return;
}


////////////TASK 2: 

/*
BFS + backtrack of DFS
The main idea of this algorithm is doing a BFS to find and store the shortest distance from S to 
each of the other cities and  maintain a parent list for each of the cities.
(parent list for a node A is a list that contains the nodes who leads to node A or connected to the node A )
Then, for each node, it will store all the parents for which it has the shortest distance from the source node.
we recover all the paths using parent array and at any instant, we will push one vertex in the path array and 
then call for all its parents. Once “-1” in the above steps,it means a path has been found and can be stored 
in the paths array(route).

*/

void find_shortestPaths(res paths, liste path, liste* parent, int n, int u)
{
    if(u == -1)
    {
        int n=paths->taille;
        liste path_copy=cloneListe(path);
        paths->route[n]=path_copy;
        paths->taille++;
        return;
    }
    
    liste temp=parent[u];
    while(temp!=NULL)
    {
        int par=temp->element;
        ajoutFin(u,&path);
        find_shortestPaths(paths,path,parent,n,par);
        suppressionFin(&path);
        temp=temp->suivant;
    }
}
 
void BFS(int** adj,liste* parent, int n, int start)
{
    int* dist=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        dist[i]=maxsize;
    file f={NULL,NULL};
    enfiler(start,&f);
    ajoutFin(-1,&parent[start]);
    dist[start]=0;
    
    while (f.debut!=NULL)
    {
        int u=defiler(&f);
        //printf("u=%d \n",u);
        liste temp=node_neighbors(u,adj,n);
        while(temp!=NULL)
        {
            int v=temp->element;
            //printf("v=%d \n",v);
            if(dist[v] > dist[u]+1)
            {
                dist[v]=dist[u]+1;
                enfiler(v,&f);
                libererListe(&(parent[v]));
                parent[v]=NULL;
                ajoutFin(u,&(parent[v]));
            }
            else if(dist[v]==dist[u]+1)
                ajoutFin(u,&(parent[v]));
            
            temp=temp->suivant;
        
        }
    }
    
}

res shortestPaths(int** adj, int n, int start, int end, int number)
{
  
    res paths;
    
    paths->route=(liste*)malloc(number*sizeof(liste));
    paths->taille=0;
    
    for(int i=0;i<number;i++)
        paths->route[i]=NULL;
    liste path=NULL;
    liste* parent=(liste*)malloc(n*sizeof(liste));
    for(int i=0;i<number;i++)
        parent[i]=NULL;
    
    BFS(adj, parent, n,start);
    
    find_shortestPaths(paths,path,parent,n,end);
    return paths;
    
}

