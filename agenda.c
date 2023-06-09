#include <stdio.h>

void adiciona_contato(char *nome, char *tel) {
    FILE *f;
    f = fopen("agenda.csv", "a");

    if (f != NULL) {
        fprintf(f, "\n%s,%s", nome, tel);
    } else {
        printf("nao foi possivel abrir o arquivo");
    }

    fclose(f);
}

void lista_contatos() {
    FILE *f;
    f = fopen("agenda.csv", "r");

    if (f != NULL) {
        char linha[100];
        while (fgets(linha, 100, f)) {
            printf("%s", linha);
        }
    } else {
        printf("nao foi possivel abrir o arquivo");
    }

    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        adiciona_contato(argv[1], argv[2]);
    } else {
        lista_contatos();
    }
    return 0;
}