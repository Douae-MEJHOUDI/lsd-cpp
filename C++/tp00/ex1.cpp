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


/////MAIN:
int main()
{
    int c;
    cin>>c;
    stack P= NULL;
    push(c,&P);
    print_stack(P);
    int val= pop(&P);
    //cout<<val<<endl;
    if (P == NULL)
        cout<<0;

    return 0;
}

/////FUNCTIONS:

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
