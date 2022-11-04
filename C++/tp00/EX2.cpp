#include <iostream>

using namespace std;

struct node{
    int valeur;
    struct node* next;
};

typedef struct node node;
typedef node* stack;

//////////PROTOTYPES:
void push(int x, stack* P);
int pop(stack* P);
void print_stack(stack P);
int len(stack P);
stack reverse_stack(stack* P);
void vider(stack* P, stack* V);
stack reverse_part( stack* P, int k);

/////MAIN:
int main()
{
    //int c;
    //cin>>c;
    stack P= NULL;
    push(1,&P);
    push(2,&P);
    push(3,&P);
    push(4,&P);
    push(5,&P);
    push(6,&P);
    push(7,&P);
    push(8,&P);
    print_stack(P);
    //int val= pop(&P);
    //cout<<len(P)<<endl;
    stack V = reverse_part(&P , 3);
    print_stack(V);
    //if (P == NULL)
        //cout<<0;

    return 0;
}

/////FUNCTIONS:

stack reverse_part( stack* P, int k)
{
    int n= len(*P);
    int r = n%k;
    stack total= NULL;
    stack R=NULL;
    for (int i=0;i<r;i++)
    {
        int val=pop(P);
        push(val,&R);
    }
    vider(&total,&R);
    for(int j=0; j<(n-r)/k; j++)
    {
        stack v= NULL;
        for(int s=0; s < k; s++)
        {
            int val= pop(P);
            push(val,&v);
        }
        vider(&total, &v);
    }
    return reverse_stack(&total);
}
void vider(stack* P, stack* V)
{
    int n= len(*V);
    for (int i =0;i<n; i++)
    {
        int val=pop(V);
        push(val,P);
    }
    return;
}


stack reverse_stack(stack* P)
{
    int n= len(*P);
    stack V= NULL;
    for (int i=0;i<n;i++)
    {
        int val= pop(P);
        push(val,&V);
    }
     return V;
}


int len(stack P)
{
	int n =0;
	stack temp =P;
	while(temp!=NULL)
	{
		n++;
		temp=temp->next;
	}
	return n;
}

void print_stack(stack P)
{
    stack temp=P;
    while(temp->next!=NULL)
    {
        printf("%d, ",temp->valeur);
        temp=temp->next;
    }
    if(temp!=NULL)
        printf("%d\n",temp->valeur);
}

void push(int x, stack* P)
{
    stack C=(node*)malloc(sizeof(node));
    C->valeur=x;
    C->next=*P;
    *P=C;
    return;
}

int pop(stack* P)
{
    if(*P != NULL)
    {
        int val=(*P)->valeur;
        stack temp=*P;
        *P=(*P)->next;
        free(temp);
        return val;
    }
    else
        exit(EXIT_FAILURE);
}

