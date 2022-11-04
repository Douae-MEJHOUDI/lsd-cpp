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
int check(int x, stack P);
stack supp_double(stack* P);

/////MAIN:
int main()
{
    //int c;
    //cin>>c;
    stack P= NULL;
    push(1,&P);
    push(1,&P);
    push(3,&P);
    push(4,&P);
    push(4,&P);
    push(7,&P);
    push(7,&P);
    print_stack(P);
    //cout<<check(7,P);
    stack V = supp_double(&P);
    print_stack(V);
    return 0;
}

/////FUNCTIONS:

stack supp_double(stack* P)
{
    int n=len(*P);
    stack D= NULL;
    for(int i=0;i<n ; i++)
    {
        int val = pop(P);
        if (not(check(val,D)))
            push(val,&D);
    }
    return reverse_stack(&D);
}


int check(int x, stack P)
{
    stack temp= P;
    while(temp != NULL)
    {
        if (temp->valeur == x)
            return 1;
        temp=temp->next;
    }
    return 0;
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

