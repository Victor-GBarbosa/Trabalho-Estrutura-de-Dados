#include <stdio.h>

int main() {

    const char *fname = "Arquivo.txt";

    FILE *arquivo = fopen(fname, "r+");

    if (arquivo == NULL) {
        printf("Criando Arquivo.\n");
        arquivo = fopen(fname, "w");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo");
            return 1;
        }
        
    } else {
        printf("Arquivo encontrado. Pronto para manipulação\n");
    }

    //Arquivo aberto ou criado 

    
    
    //Finalizando o programa

    fclose(arquivo);
    
   return 0;
}