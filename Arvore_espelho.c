#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------
//STRUCTS

struct Node{
    int value;
    struct Node * right;
    struct Node * left;
};

typedef struct Node node;
typedef node * tree;

tree * tree_start();
node * node_start(int value);
void tree_inserir(tree * root, int value);
void tree_inOrdem(tree * root);
void mirror(tree * old, tree * new);

int main(){

  //T1
  tree * t1 = tree_start();
  tree * t1Mirror = tree_start();

  tree_inserir(t1,5);
  tree_inserir(t1,3);
  tree_inserir(t1,7);
  tree_inserir(t1,2);
  tree_inserir(t1,6);
  tree_inserir(t1,4);
  tree_inserir(t1,8);

  mirror(t1,t1Mirror);

  printf("T1\n");
  tree_inOrdem(t1); printf("\n");
  tree_inOrdem(t1Mirror);printf("\n");

  //T2
  tree * t2 = tree_start();
  tree * t2Mirror = tree_start();

  tree_inserir(t2,1);
  tree_inserir(t2,2);
  tree_inserir(t2,3);
  tree_inserir(t2,4);
  tree_inserir(t2,5);
  tree_inserir(t2,6);
  tree_inserir(t2,7);

  mirror(t2,t2Mirror);

  printf("T2\n");
  tree_inOrdem(t2); printf("\n");
  tree_inOrdem(t2Mirror);printf("\n");

  //T3
  tree * t3 = tree_start();
  tree * t3Mirror = tree_start();

  tree_inserir(t3,20);
  tree_inserir(t3,30);
  tree_inserir(t3,80);
  tree_inserir(t3,65);
  tree_inserir(t3,48);
  tree_inserir(t3,96);
  tree_inserir(t3,39);
  tree_inserir(t3,666);
  tree_inserir(t3,8);
  tree_inserir(t3,2);
  tree_inserir(t3,3);
  tree_inserir(t3,67);
  
  mirror(t3,t3Mirror);

  printf("T2\n");
  tree_inOrdem(t3); printf("\n");
  tree_inOrdem(t3Mirror);printf("\n");


  return 0;
}


//------------------------------------------------------
//INICIADORES

//nova arvore
tree * tree_start(){
  tree * new = (tree*)malloc(sizeof(tree));
  *new = NULL;
  return new;
}

//novo nó
node * node_start(int value){
  node * new = (node*)malloc(sizeof(node));
  new->value = value;
  new->right = NULL;
  new->left = NULL;
  return new;
}

//-----------------------------------------------------
//FUNÇÕES

//Inserir em ordem

void tree_inserir(tree * root, int value){
  if((*root) == NULL){
      node * new = node_start(value);
      (*root) = new;
      //printf("%d adicionado!\n",(*root)->value );
      return ;
  }
  else if(value < (*root)->value){
      tree_inserir((&(*root)->left), value);
  }else if(value > (*root)->value){
      tree_inserir((&(*root)->right), value);
  }
}

//IN-ORDEM
void tree_inOrdem(tree * root){
  if((*root)!=NULL){
    tree_inOrdem(&(*root)->left);
    printf("%d ",(*root)->value);
    tree_inOrdem(&(*root)->right);
  }
}


void mirror(tree * old, tree * new){
  if(*old != NULL){
    *new = node_start((*old)->value);
    mirror(&(*old)->left, &(*new)->right);
    mirror(&(*old)->right, &(*new)->left);
  }else return ;
}
