#include <stdio.h>
#include <stdlib.h>

void enfileirar(struct No **inicio, struct No **fim, int num) {
    struct No *novo = malloc(sizeof(struct No));
    if (novo != NULL) {
        novo->valor = num;
        novo->prox = NULL; // Novo nó sempre será o último, então aponta pra NULL
        if (*inicio == NULL) { 
            // Se a fila estava vazia, o novo é o primeiro!
            *inicio = novo;
        } else {
            // Se já tinha gente, o antigo "fim" agora aponta para o novo
            (*fim)->prox = novo;  // ← LACUNA 1
        }
        
        // No final, o ponteiro de controle "fim" precisa atualizar
        *fim = novo;  // ← LACUNA 2
        printf("\n%d entrou na fila!", num);
    }
}

int desenfileirar(struct No **inicio, struct **fim){
    struct No *aux;
    int valor_removido;
    
    aux = *inicio; // Auxiliar segura o primeiro
    
    *inicio = (*inicio)->prox; // Início pula para o próximo nó
    
    // Se o início virou NULL, a fila acabou! O fim também tem que ser NULL
    if(*inicio == NULL){
        *fim = NULL;
    }
    
    free(aux); // Devolve a memória ao PC
    return valor_removido
}
