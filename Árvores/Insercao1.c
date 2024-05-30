#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no {
    int conteudo;
    struct apelido_no *esquerdo, *direito;
} No;

typedef struct{
    No *raiz;
} Arvore;

void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir (Arvore *arv, int valor);

void inserirEsquerda(No *no, int valor){
    if(no->esquerdo == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        no->esquerdo = novo;
    }
    else{
        if (valor < no->esquerdo->conteudo){
            inserirEsquerda(no->esquerdo, valor);}
        if (valor > no->esquerdo->conteudo) {
            inserirDireita(no->esquerdo, valor);}
    }

}
 
void inserirDireita(No *no, int valor){
    if(no->direito == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        no->direito = novo;
    }
    else{
        if (valor > no->direito->conteudo)
            inserirDireita(no->direito, valor);
        if (valor < no->esquerdo->conteudo) 
            inserirEsquerda(no->direito, valor);
    }
}

void inserir (Arvore *arv, int valor){
    // Caso onde a árvore está vazia
    if(arv->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        arv->raiz = novo;
    }
    // Caso onde a árvore não está vazia
    else {
        if(valor < arv->raiz->conteudo)
            inserirEsquerda(arv->raiz, valor);
        if(valor > arv->raiz->conteudo)
            inserirDireita(arv->raiz, valor);
    }
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
    Arvore arv;
    arv.raiz = NULL;
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
            imprimir(arv.raiz);
            break;
        default:
            break;
        }
    } while (op!=0);
    

    return 0;
}                                    