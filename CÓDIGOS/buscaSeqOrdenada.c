int buscaSeqOrdenada(int array[], int tamanho, int valor){
    for (int i = 0; i < tamanho; i++){
        if (array[i] == valor)
            return i;
        if (array[i] > valor)
            return -1;  // passou, não existe
    }
    return -1;
}
