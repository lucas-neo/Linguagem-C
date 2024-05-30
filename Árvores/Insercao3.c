#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no {
    int conteudo;
    struct apelido_no *esquerdo, *direito;
} No;


void inserir (No **raiz, int valor){
    No *aux = *raiz;
    while (aux){
        if(valor < aux->conteudo)
            // raiz sem o "*" é o valor do escopo local da variávael raiz
            raiz=&aux->esquerdo;
        if(valor > aux->conteudo)
            raiz=&aux->direito;
        aux = *raiz;
    }
    aux=malloc(sizeof(No));
    aux->conteudo = valor;
    aux->esquerdo = NULL;
    aux->direito = NULL;
    *raiz=aux;
    
}

void imprimir(No *raiz){
    if (raiz != NULL){
        imprimir(raiz->esquerdo);
        printf(" %d ", raiz->conteudo);
        imprimir(raiz->direito);
    }
}

int main(){

    int op, valor;
    No *arv = NULL;
    do
    {
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Insira um valor: ");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            imprimir(arv);
            break;
        default:
            break;
        }
    } while (op!=0);
    

    return 0;
}    