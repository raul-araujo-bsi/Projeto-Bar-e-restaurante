#include <stdio.h>
#include "cliente.h"

void modulo_cliente(void){
    char opcao;

    do {
        opcao = tela_cliente();
        switch(opcao){
            case '1': cadastro_cliente();
                    break;
            case '2': pesquisar_cliente();
                    break;
            case '3': //modulo_produtos();
                    break;
        }
    } while (opcao != '0');
}


char tela_cliente(void){
    char op;
    printf("#============================# \n");
    printf("|           CLIENTES         | \n");
    printf("|                            | \n");
    printf("|  1 - CADASTRO              | \n");
    printf("|  2 - PESQUISAR             | \n");
    printf("|  3 - ALTERAR               | \n");
    printf("|  4 - EXCLUIR               | \n");    
    printf("|  0 - RETORNAR              | \n");
    printf("|                            | \n");
    printf("#============================# \n");
    scanf("%c", &op);
    getchar();
    return op;
}


void cadastro_cliente(void){
    printf("#============================# \n");
    printf("             CADASTRO          \n");
    printf("                               \n");
    printf("  Id.:                         \n");
    printf("  NOME:                        \n");
    printf("  CPF:                         \n");
    printf("  TELEFONE:                    \n");    
    printf("  E-MAIL:                      \n");
    printf("                               \n");
    printf("#============================# \n");   
}


void pesquisar_cliente (void){
    printf("#============================# \n");
    printf("|           PESQUISA          \n");
    printf("|                             \n");
    printf("| Informe o CPF do cliente:  \n");
    printf("|                             \n");
    printf("#============================# \n"); 
}