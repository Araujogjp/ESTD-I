#include <stdio.h>
#include<stdlib.h>

typedef struct cel{
  int conteudo;
  struct cel *seg;
  struct cel *ant;

}cel;
typedef struct cel* ListaDup;

void imprimir_lista(Lista* lista){
    if(lista == NULL){
        printf("\nLista nao existe\n");
    }
    else{
        if(*lista == NULL){
            printf("\nLista vazia\n");
        }else{
            cel *temp;
            temp  = *lista;
            printf("\nLista:");
            while(temp !=NULL){
                printf(" %d |", temp->conteudo);
                temp = temp->seg;
            }
            printf("\n");
        }
    }
}

Lista* cria_lista(){
  Lista *li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL){
    *li=NULL;
  }
  return li;
}

int insere_lista_fim(Lista* lista, int x){
  if(lista==NULL) {return 0;}
  cel* aux = (cel*) malloc(sizeof(cel));
  if(aux==NULL){return 0;}
  aux->conteudo = x;
  aux->seg = NULL;
  if((*lista)==NULL){ *lista = aux;}
  else{
    cel *temp;
    temp = *lista;
    while(temp->seg!= NULL){ //caminha at  o utlimo elemento
      temp= temp->seg;
    }
    temp->seg = aux;
  }
  return 1;
}

int insere_lista_inicio(Lista* lista, int x) {
  if (lista == NULL) { return 0; }

  cel* aux = (cel*) malloc(sizeof(cel));
  if (aux == NULL) { return 0; }

  aux->conteudo = x;
  aux->seg = *lista;

  *lista = aux;
  return 1;

}
int busca(Lista *lista, int valor){
  cel *p;
  for(p=*lista;p!=NULL;p=p->seg){
    if(p->conteudo == valor){
      return 1;
    }
  }
  return 0;
}

void libera_lista(Lista *lista){
    if(lista != NULL){
        cel *aux;
        while(*lista != NULL){
            aux = *lista;
            *lista = (*lista)->seg;
            free(aux);
        }
        free(lista);
    }
}

int remove_lista(Lista *lista, int x){
    if(lista == NULL) {return 0;}
    if(*lista == NULL) {return 0;}

    cel *aux = *lista, *ant;

    while (aux!=NULL && aux->conteudo != x){
        ant = aux;
        aux = aux->seg;
    }

    if (aux == NULL){ return 0;}

    if(aux == *lista){
        *lista = aux->seg;
    }else{
    ant->seg = aux->seg;
    }

    free(aux);
    return 1;



}


int main(void) {
  Lista *lst;
  lst = cria_lista();
  insere_lista_fim(lst, 1);
  insere_lista_fim(lst, 2);
  insere_lista_fim(lst, 3);
  insere_lista_fim(lst, 4);
  insere_lista_fim(lst, 5);
  imprimir_lista(lst);

  remove_lista(lst, 3);
  imprimir_lista(lst);

  printf("\nA busca retornou %d\n",busca(lst,7));
  imprimir_lista(lst);

  libera_lista(lst);
  //imprimir_lista(lst);
  return 0;
}
