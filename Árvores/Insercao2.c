#include <stdio.h>
#include <stdlib.h>

typedef struct apeli_no{
    int conteudo;
    struct apeli_no *esquerda, *direita;
}No;

No *inserir (No *raiz, int valor){
    if (raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else {
        if (valor < raiz->conteudo){
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        if (valor > raiz->conteudo){
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }
    
}

void imprimir(No *raiz){
    if (raiz != NULL){
        imprimir(raiz->esquerda);
        printf(" %d ", raiz->conteudo);
        imprimir(raiz->direita);
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
            arv = inserir(arv, valor);
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