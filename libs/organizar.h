#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char curso[256];
    int matricula;
 } Matricula;

int contarLinhas(char* fileName, int ignore) {
    FILE *fp = fopen(fileName, "r");
    int contador = 0;
    char linha[256]; 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        contador++; 
    }
    fclose(fp);
    return contador - ignore;
}

void ordenarPorNome(char* inFile, char* outFile) {
    int tamanho = contarLinhas(inFile, 2);
    Matricula matriculas[tamanho];

    FILE *fp = fopen(inFile, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de entrada");
    }

    char linha[256];
    int contador = 0;

    //ignorar as duas primeiras linhas
    for (int i = 0; i < 2; i++) {
        fgets(linha, sizeof(linha), fp);
    }
    
    while (fgets(linha, sizeof(linha), fp) != NULL && contador < tamanho) {
        char* separador = strtok(linha, ",");
        strcpy(matriculas[contador].nome, separador);

        separador = strtok(NULL, ",");
        strcpy(matriculas[contador].curso, separador);

        separador = strtok(NULL, ",");
        matriculas[contador].matricula = atoi(separador);

        contador++;
    }

    fclose(fp);

    

    //ordenar as matriculas usando bubbleSort
    Matricula temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcasecmp(matriculas[j].nome, matriculas[j + 1].nome) > 0) {
                temp = matriculas[j];
                matriculas[j] = matriculas[j + 1];
                matriculas[j + 1] = temp;
            }
        }
    }

    //escrever as matriculas ordenadas no arquivo definido pelo usuario
    FILE *fpOut = fopen(outFile, "w");
    if (fpOut == NULL) {
        printf("Erro ao abrir o arquivo de saida");
    }

    fprintf(fpOut, "Nome,Curso,Matricula\n\n");

    for (int i = 0; i < tamanho; i++) {
        fprintf(fpOut, "%s,%s,%d\n", matriculas[i].nome, matriculas[i].curso, matriculas[i].matricula);
    }

    fclose(fpOut);
}

void ordenarPorMateria(char* inFile, char* outFile) {
    int tamanho = contarLinhas(inFile, 2);
    Matricula matriculas[tamanho];

    FILE *fp = fopen(inFile, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de entrada");
    }

    char linha[256];
    int contador = 0;

    for (int i = 0; i < 2; i++) {
        fgets(linha, sizeof(linha), fp);
    }

    while (fgets(linha, sizeof(linha), fp) != NULL && contador < tamanho) {
        char* separador = strtok(linha, ",");
        strcpy(matriculas[contador].nome, separador);

        separador = strtok(NULL, ",");
        strcpy(matriculas[contador].curso, separador);

        separador = strtok(NULL, ",");
        matriculas[contador].matricula = atoi(separador);

        contador++;
    }

    fclose(fp);

    //ordenar as matriculas usando bubbleSort pelo campo curso
    Matricula temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcasecmp(matriculas[j].curso, matriculas[j + 1].curso) > 0) {
                temp = matriculas[j];
                matriculas[j] = matriculas[j + 1];
                matriculas[j + 1] = temp;
            }
        }
    }

    //escrever as matriculas ordenadas no arquivo definido pelo usuário
    FILE *fpOut = fopen(outFile, "w");
    if (fpOut == NULL) {
        printf("Erro ao abrir o arquivo de saída");
    }

    fprintf(fpOut, "Nome,Curso,Matricula\n\n");

    for (int i = 0; i < tamanho; i++) {
        fprintf(fpOut, "%s,%s,%d\n", matriculas[i].nome, matriculas[i].curso, matriculas[i].matricula);
    }

    fclose(fpOut);
}

void ordenarPorMatricula(char* inFile, char* outFile) {
    int tamanho = contarLinhas(inFile, 2);
    Matricula matriculas[tamanho];

    FILE *fp = fopen(inFile, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de entrada");
    }

    char linha[256];
    int contador = 0;

    //ignorar as duas primeiras linhas
    for (int i = 0; i < 2; i++) {
        fgets(linha, sizeof(linha), fp);
    }

    while (fgets(linha, sizeof(linha), fp) != NULL && contador < tamanho) {
        char* separador = strtok(linha, ",");
        strcpy(matriculas[contador].nome, separador);

        separador = strtok(NULL, ",");
        strcpy(matriculas[contador].curso, separador);

        separador = strtok(NULL, ",");
        matriculas[contador].matricula = atoi(separador);

        contador++;
    }

    fclose(fp);

    //ordenar as matriculas usando bubbleSort por matricula
    Matricula temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (matriculas[j].matricula > matriculas[j + 1].matricula) {
                temp = matriculas[j];
                matriculas[j] = matriculas[j + 1];
                matriculas[j + 1] = temp;
            }
        }
    }

    //escrever as matriculas ordenadas no arquivo definido pelo usuário
    FILE *fpOut = fopen(outFile, "w");
    if (fpOut == NULL) {
        printf("Erro ao abrir o arquivo de saida");
    }

    fprintf(fpOut, "Nome,Curso,Matricula\n\n");

    for (int i = 0; i < tamanho; i++) {
        fprintf(fpOut, "%s,%s,%d\n", matriculas[i].nome, matriculas[i].curso, matriculas[i].matricula);
    }

    fclose(fpOut);
}

void exibirPaginas(char* inFile) {
    int tamanho = contarLinhas(inFile, 2);
    Matricula matriculas[tamanho];

    FILE *fp = fopen(inFile, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        return;
    }

    char linha[256];
    int contador = 0;

    // Ignorar as duas primeiras linhas
    for (int i = 0; i < 2; i++) {
        fgets(linha, sizeof(linha), fp);
    }

    while (fgets(linha, sizeof(linha), fp) != NULL && contador < tamanho) {
        char* separador = strtok(linha, ",");
        strcpy(matriculas[contador].nome, separador);

        separador = strtok(NULL, ",");
        strcpy(matriculas[contador].curso, separador);

        separador = strtok(NULL, ",");
        matriculas[contador].matricula = atoi(separador);

        contador++;
    }

    fclose(fp);

    int pagina = 1;
    int linhasPorPagina = 10;

    while (1) {
        printf("Digite o numero da pagina (0 para sair): ");
        scanf("%d", &pagina);

        if (pagina == 0) {
            break;
        }

        int inicio = (pagina - 1) * linhasPorPagina;
        int fim = inicio + linhasPorPagina;

        if (inicio >= tamanho) {
            printf("Pagina inválida. Exibindo a ultima pagina disponível.\n");
            pagina = (tamanho + linhasPorPagina - 1) / linhasPorPagina;
            inicio = (pagina - 1) * linhasPorPagina;
            fim = inicio + linhasPorPagina;
        }
        system("cls");
        printf("Exibindo pagina %d:\n", pagina);
        for (int i = inicio; i < fim && i < tamanho; i++) {
            printf("#%i Nome: %s, Curso: %s, Matricula: %d\n",i, matriculas[i].nome, matriculas[i].curso, matriculas[i].matricula);
        }
    }
}
