#include <stdio.h>

#include <stdlib.h>




bst_t *createTree() {
  bst_t *tree = (bst_t *) malloc(sizeof(bst_t));
  if (tree == NULL) {
    printf("Malloc error! Cannot create tree");
    exit(1);
  }
  tree->root = NULL;
  return tree;
}

/*
 * Insere um elemento na �rvore de forma recursiva. Caminhamos at�
 * a posi��o correta de acordo com o valor do novo n�. O caminhanmento �
 * feito chamando a mesma fun��o para o filho da esquerda ou direita.
 */
void _insertValueRecursive(node_t *parent, node_t *newNode) {
  //Caminha para esquerda
  if ((newNode->value <= parent->value)) { 
    if (parent->leftChild == NULL) {
      parent->leftChild = newNode;
    } else {
      _insertValueRecursive(parent->leftChild, newNode);
    }
  }
  
  //Caminha para direita
  if ((newNode->value > parent->value)) { 
    if (parent->rightChild == NULL) {
      parent->rightChild = newNode;
    } else {
      _insertValueRecursive(parent->rightChild, newNode);
    }
  }
}

/*
 * Insere um elemento na �rvore de forma N�O recursiva. Caminhamos at�
 * a posi��o correta de acordo com o valor do novo n�. O caminhamento �
 * feito atualizando um apontador. Caso o valor do novo n� seja menor do
 * que o apontador, vamos para esquerda, caso contr�rio, direita.
 * Quando n�o temos para onde caminhar achamos o local de inser��o.
 */
void _insertValueNonRecursive(node_t *root, node_t *newNode) {
  node_t *candidateParent = root; //Usado apenas para controle, termina NULL
  node_t *actualParent = NULL;  //Ap�s o la�o, vai apontar para o pai do n�
  while (candidateParent != NULL) {
    actualParent = candidateParent;
    if ((newNode->value <= candidateParent->value)) { //Caminha esquerda
      candidateParent = candidateParent->leftChild; 
    } else {
      candidateParent = candidateParent->rightChild; //Caminha direita
    }
  }
  
  //Inserindo o n�
  if ((newNode->value <= actualParent->value)) {
    actualParent->leftChild = newNode; 
  } else {
    actualParent->rightChild = newNode;
  }
}

void insertValue(bst_t *tree, int value) {
  node_t *node = (node_t *) malloc(sizeof(node_t));
  if (node == NULL) {
    printf("Malloc error! Cannot create node");
    exit(1);
  }
  node->value = value;
  node->leftChild = NULL;
  node->rightChild = NULL;

  if (tree->root == NULL) {
    tree->root = node;
  } else {
    //Mude este c�digo para chamar o n�o recursivo
    _insertValueRecursive(tree->root, node);
  }
}

/*
 * Acha um n� com um dado valor de forma recusiva. Para isto, caminhamos para
 * esquerda ou direita caso o valor do n� atual seja menor ou maior do que
 * estamos procurando. Se em algum momento acharmos NULL, n�o temos mais para
 * aonde caminhar (valor n�o existe).
 */
int _hasValueRecursive(node_t *currentlyVisiting, int value) {
  if (currentlyVisiting == NULL)
    return 0;
  if (value == currentlyVisiting->value)
    return 1;

  if (value < currentlyVisiting->value) {
    return _hasValueRecursive(currentlyVisiting->leftChild, value);
  } else {
    return _hasValueRecursive(currentlyVisiting->rightChild, value);
  }
}

int _hasValueNonRecursive(node_t *currentlyVisiting, int value) {
  node_t *nextVisit = currentlyVisiting;
  while(nextVisit != NULL) {
    if (value == nextVisit->value)
      return 1;

    if (value < nextVisit->value) {
      nextVisit = nextVisit->leftChild;
    } else {
      nextVisit = nextVisit->rightChild;
    }
  }

  return 0;
}

int hasValue(bst_t *tree, int value) {
  return _hasValueRecursive(tree->root, value);
}

node_t *_findMin(node_t *node) {
  if (node->leftChild == NULL)
    return node;
  return _findMin(node->leftChild);
}

void _removeValue(bst_t *tree, node_t *node, node_t *parent, int value) {
  node_t* replacement; //Guarda quem vai substituir o n�
  if (value == node->value) { //Achamos quem temos que remover!
    if (node->leftChild == NULL || node->rightChild == NULL) { //Caso 1 ou 2
      //Caso 1: Sem Filhos
      if (node->leftChild == NULL && node->rightChild == NULL) {
        replacement = NULL;
      }
      //Caso 2: Apenas 1 Filho. ^ � um our exclusivo, ou left ou right != null
      else if (node->leftChild != NULL) {
        replacement = node->leftChild;
      } else {
        replacement = node->rightChild;
      }
      //A partir daqui o replacement vai ocupar o local do n�.
      //Atualizamos o parent
      if (parent != NULL) {
        if (node == parent->leftChild) {
          parent->leftChild = replacement;
        } else {
          parent->rightChild = replacement;
        }
      }
      //Atualizamos a raiz se necess�rio
      if (node == tree->root) {
        tree->root = replacement;
      }
      free(node);
    }
    //Caso 3: 2 Filhos. Achar um n� para substituir. Menor valor a direita
    //        Precisamos do menor valor a direita para garantir que a �rvore
    //        mantenha a esquerda < n� < direita.
    //        Aqui n�o fazemos free do n�, mudamos o valor dele com um correto,
    //        menor da �rvore a direita, e removemos este n�.
    else {
      replacement = _findMin(node->rightChild);
      node->value = replacement->value;
      //Essa chamada vai na �rvore da direita e remove o n� que copiamos
      //o valor!
      _removeValue(tree, node->rightChild, node, replacement->value);
    }
  } else {
    if (value < node->value) {
      _removeValue(tree, node->leftChild, node, value);
    } else {
      _removeValue(tree, node->rightChild, node, value);
    }
  }
}

int removeValue(bst_t *tree, int value) {
  if (tree->root == NULL)
    return 0;
  if (hasValue(tree, value) == 0) //Valor n�o se encontra na �rvore
    return 0;
  _removeValue(tree, tree->root, NULL, value);
  return 1;
}

void _printInOrder(node_t *node) {
  if (node == NULL) {
    return;
  }
  _printInOrder(node->leftChild);
  printf("%d ", node->value);
  _printInOrder(node->rightChild);
}

void printInOrder(bst_t *tree) {
  return _printInOrder(tree->root);
}

void _printPreOrder(node_t *node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->value);
  _printPreOrder(node->leftChild);
  _printPreOrder(node->rightChild);
}

void printPreOrder(bst_t *tree) {
  return _printPreOrder(tree->root);
}

void _printPostOrder(node_t *node) {
  if (node == NULL) {
    return;
  }
  _printPostOrder(node->leftChild);
  _printPostOrder(node->rightChild);
  printf("%d ", node->value);
}


void printPostOrder(bst_t *tree) {
  return _printPostOrder(tree->root);
}

void bstFree(bst_t *tree) {
  while(tree->root != NULL)
    removeValue(tree, tree->root->value);
  free(tree);
}

int main() {
  bst_t *tree = createTree();
  insertValue(tree, 10);
  insertValue(tree, 5);
  insertValue(tree, 20);
  insertValue(tree, 12);
  insertValue(tree, 0);
  insertValue(tree, 4);
  insertValue(tree, 6);

  printf("In Order ");
  printInOrder(tree);
  printf("\n");
  printf("Post Order ");
  printPostOrder(tree);
  printf("\n");
  printf("Pre Order ");
  printPreOrder(tree);
  printf("\n");

  printf("The tree contains: 12 %d\n", hasValue(tree, 12));
  printf("The tree contains: 10 %d\n", hasValue(tree, 10));
  printf("The tree contains: 5 %d\n", hasValue(tree, 5));
  printf("The tree contains: 54 %d\n", hasValue(tree, 54));
  
  printf("Removing 4\n");
  removeValue(tree, 4);
  printf("In Order ");
  printInOrder(tree);
  printf("\n");

  printf("Removing 20\n");
  removeValue(tree, 20);
  printf("In Order ");
  printInOrder(tree);
  printf("\n");

  printf("Removing 5\n");
  removeValue(tree, 5);
  printf("In Order ");
  printInOrder(tree);
  printf("\n");
  
  //Brincando um pouco...
  insertValue(tree, 4);
  insertValue(tree, 4);
  insertValue(tree, 4);
  insertValue(tree, 4);
  insertValue(tree, 4);
  insertValue(tree, 4);
  insertValue(tree, 4);
  insertValue(tree, 32);
  insertValue(tree, 32);
  insertValue(tree, 32);
  removeValue(tree, tree->root->value);
  bstFree(tree);

  return 0;
}
