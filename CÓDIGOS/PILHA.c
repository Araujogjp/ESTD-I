#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *prox;
};

// Empilhar(Push)
void push(struct No **topo, int num){
    // Pedir memória ao pc
    struct No *novo = malloc(sizeof(struct No));
    if (novo != NULL){
        novo->valor = num;  // Colocar o dado na "caixinha"
        novo->prox = *topo;  // O novo nó aponta para quem era o topo antes
        *topo = novo;  // O topo agora é o novo nó
        printf("\nElemento empilhado com sucesso!", num);
    }
    else{
        printf("\nErro ao alocar memória");
    }
}

// Desempilhar(Pop)
int pop(struct No **topo, int valor_removido){
    struct No *aux; // Criamos o auxiliar
    
    if(*topo != NULL){
        aux = *topo; // Auxiliar recebe o topo atual
        valor_removido = aux->valor; // Guardamos o valor para retornar;
        
        *topo = (*topo)->prox; // O topo pula para o de baixo 
        
        free(aux); // Liberar memória do nó que saiu
        return valor_removido;
        
    }
    return -1;
}
