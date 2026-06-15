int buscaLinear(int array[], int tamanho, int valor){
    for (int i = 0; i < tamanho; i++){
        if (array[i] == valor)
            return i;  // achou! retorna a posição
    }
    return -1;  // não encontrou
}
