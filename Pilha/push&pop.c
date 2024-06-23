//PUSH - Adiciona um novo elemento na PILHA.
#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    Data data;
    char nome[50];
}Pessoa;

typedef struct no {
    Pessoa pessoa;
    struct no *proximo;
}No;

Pessoa ler_pessoa() {
    Pessoa pessoa;

    printf("Digite o nome e a data de nascimento (DD MM AAAA):\n");
    scanf("%49s[^\n]%d%d%d",pessoa.nome, &pessoa.data.dia, &pessoa.data.mes, &pessoa.data.ano);
    return pessoa;
}

void imprimir_pessoa(Pessoa pessoa) {
    printf("Nome: %s\nData: %2d/%2d%4d\n",pessoa.nome, pessoa.data.dia, pessoa.data.mes, pessoa.data.ano);
}

//Função para a operação push (empilhar).
*** empilhar(No *topo) {
    No *novo = malloc(sizeof(No));
    if(novo == NULL) {
        printf("Error.\n");
    }else {
        novo->pessoa = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }
}

int main(void) {
    No *topo = NULL;
    int opcao;

    do {
        printf("0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d",&opcao);
        getchar();

        switch(opcao) {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:

            break;
        case 3:
                
            break;
        default:
            if(opcao != 0)
                printf("Opcao Invalida.\n");
        }
    } while(opcao != 0);

    return 0;
}