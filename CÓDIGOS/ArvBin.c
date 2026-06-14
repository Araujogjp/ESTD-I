#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int info;
    struct No *esq;
    struct No *dir;
} No;

typedef struct No* ArvBin;

void imprime_NO(No* no, const char *prefixo, int ehUltimo, char lado)
{
    if(no == NULL)
    {
        return;
    }
    printf("%s", prefixo);
    if(ehUltimo)
    {
        printf("└── ");
    }
    else
    {
        printf("├── ");
    }
    if(lado == 'E')
    {
        printf("E: ");
    }
    else if(lado == 'D')
    {
        printf("D: ");
    }
    printf("%d\n", no->info);
    char novoPrefixo[1000];
    snprintf(novoPrefixo,sizeof(novoPrefixo),"%s%s",prefixo,ehUltimo ? "    " : "│   ");
    if(no->esq != NULL)
    {
        imprime_NO(no->esq, novoPrefixo, no->dir == NULL, 'E');
    }
    if(no->dir != NULL)
    {
        imprime_NO(no->dir, novoPrefixo, 1, 'D');
    }
}
/* Função principal de impressão */
void imprime_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL || *raiz == NULL)
    {
        printf("Árvore vazia.\n");
        return;
    }
    printf("%d\n", (*raiz)->info);
    if((*raiz)->esq != NULL)
    {
        imprime_NO((*raiz)->esq, "", (*raiz)->dir == NULL, 'E');
    }
    if((*raiz)->dir != NULL)
    {
        imprime_NO((*raiz)->dir, "", 1, 'D');
    }
}

//-----------------------------------------------------//

ArvBin* cria_arvBin()
{
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz!=NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}

//-----------------------------------------------------//
int inserir_ArvBin(ArvBin *raiz, int valor)
{
    if(raiz == NULL)
    {
        return 0;
    }

    No* no = (No*)malloc(sizeof(No));
    if(no == NULL)
    {
        return 0;
    }

    no->esq = NULL;
    no->dir = NULL;
    no->info = valor;

    if(*raiz == NULL){
        *raiz = no;
        return 1;
    }
    
    No* temp = *raiz;

    while(temp != NULL)
    {
        if(no->info == temp->info)
        {
            free(no);
            return 0;
        }
        if(no->info < temp->info)
        {
            if(temp->esq == NULL)
            {
                temp->esq = no;
                return 1;
            }
            else
            {
                temp = temp->esq;
            }
        }
        else
        {
            if(temp->dir == NULL)
            {
                temp->dir = no; 
                return 1;
            }
            else
            {
                temp = temp->dir;
            }
        }
    }
    return 0;
}

//-----------------------------------------------------//

int consulta(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    if(raiz* == NULL){
        return 0;
    }
    No* temp = *raiz;
    No* ant = NULL;
    
    while(temp != NULL){
        if(valor == temp->info){
            return 1;
        }
        if(valor < temp->info){
            temp = temp->esq;
        }
        else{
            temp = temp->dir;
        }
        return 0;
    }
}

//-----------------------------------------------------//
int totalNosArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    
    No* temp = *raiz;
        return 1 + totalNosArvBin(&(temp->esq)) + totalNosArvBin(&(temp->dir));
}

No* remove_atual(No *atual){
    No *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    
    no1 = atual;
    no2 = atual->esq;
    
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    
    no2->dir = atual->dir;
    free(atual);
    
    return no2;
}

int removeArvoreBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    
    No* ant = NULL;
    No *atual = *raiz;
    
    while(atual!=NULL){
        if(valor == atual->info){
            if(atual == *raiz){
                *raiz = remove_atual(atual);
            }
            else{
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }
                else{
                    ant->esq = remove_atual(atual);
                }
            }
        }
        // anda na arvore 
        ant = atual;
        if(valor>atual->info){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL){
        return 0;
    }
    if (*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir){
        return (alt_esq + 1);
    }
    else{
        return (alt_dir + 1);
    }
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int maior_ABB(ArvBin *raiz){
    if (raiz == NULL || *raiz == NULL){
        printf("Arvore vazia!\n");
        return -1;
    }
    
    No *atual = *raiz;
    
    while (atual->dir != NULL){
        atual = atual->dir;
    }
    
    return atual->valor;
}

int main()
{
    printf("Árvore Binária de Busca\n");
    ArvBin* arv = cria_arvBin();
    printf("%d\n", inserir_ArvBin(arv, 10));
    printf("%d\n", inserir_ArvBin(arv, 29));
    printf("%d\n", inserir_ArvBin(arv, 6));
    printf("%d\n", inserir_ArvBin(arv, 6));
    printf("%d\n", inserir_ArvBin(arv, 90));
    printf("%d\n", inserir_ArvBin(arv, 67));
    printf("%d\n", inserir_ArvBin(arv, 69));
    printf("%d\n", inserir_ArvBin(arv, 495));
    printf("%d\n", inserir_ArvBin(arv, 8));
    printf("%d\n", inserir_ArvBin(arv, 5));
    printf("\n");
    imprime_ArvBin(arv);
    return 0;
}
