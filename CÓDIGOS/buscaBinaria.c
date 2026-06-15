int buscaBinaria(int array[], int tamanho, int valor){
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        
        if (array[meio] == valor)
            return meio;
        else if (array[meio] < valor)
            inicio = meio + 1;  // procura à direita
        else
            fim = meio - 1;     // procura à esquerda
    }
    
    return -1;  // não encontrou
}
