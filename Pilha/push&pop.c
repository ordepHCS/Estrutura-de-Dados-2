//PUSH - Adiciona um novo elemento na PILHA (empilhar).
//POP - Remove e retorna o elemento do topo da PILHA (desempilhar).
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

//Função para a operação PUSH (empilhar).
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
//Função para a operação POP (desempilhar).
No* desempilhar(No **topo) {
    if(*topo != NULL) {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }else {
        printf("Pilha vazia.\n");
        return NULL;
    }
}

int main(void) {
    No *topo, *remover = NULL;
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
            remover = desempilhar(&topo);
            if(remover) {
                printf("Elemento removido com sucesso!.\n");
                imprimir_pessoa(remover->pessoa);
            }else {
                printf("Sem no a remover.\n");
            }
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