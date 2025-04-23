#include <stdio.h>
#include <stdlib.h>
#include "gestao.h"

void modulo_gestao(void){
    system("cls||clear");
    char opcao;

    do {
        opcao = tela_gestao();
        switch(opcao){
            case '1': cadastrar_produto();
                    break;
            case '2': pesquisar_produto();
                    break;
            case '3': atualizar_produto();
                    break;
            case '4': excluir_produto();
                    break;
        }
    } while (opcao != '0');
}


char tela_gestao(void) {
    system("cls||clear");
    char op;
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|  1 - Cadastrar produtos    | \n");
    printf("|  2 - Ver produtos          | \n");
    printf("|  3 - Editar produtos       | \n");
    printf("|  4 - Excluir produtos      | \n");
    printf("|  5 - Relatórios            | \n");
    printf("|  0 - Sair                  | \n");
    printf("|                            | \n");
    printf("#============================# \n");
    scanf("%c", &op);
    getchar();
    return op;
}


void cadastrar_produto(void) {
    system("cls||clear");
    printf("#============================# \n");
    printf("|    CADASTRO DE PRODUTOS    | \n");
    printf("|                            | \n");
    printf("|  Id:                       | \n");
    printf("|  Fornecedor:               | \n");
    printf("|  Produto:                  | \n");
    printf("|  Quantidade:               | \n");
    printf("|  Valor:                    | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}


void pesquisar_produto(void) {
    system("cls||clear");
    printf("#=================================# \n");
    printf("|              PRODUTOS           | \n");
    printf("#=================================# \n");
    printf("   Id   Produto            Valor    \n");
    printf("#=================================# \n");
}


void atualizar_produto(void) {
    system("cls||clear");
    printf("#==========================================# \n");
    printf("|           ATUALIZAR PRODUTO              | \n");
    printf("#==========================================# \n");
    printf(" Informe o Id do produto a ser atualizado:   \n");
    printf("                                             \n");
    printf("#==========================================# \n"); 
}


void excluir_produto(void) {
    system("cls||clear");
    printf("#==========================================# \n");
    printf("|            CANCELAR PRODUTO              | \n");
    printf("#==========================================# \n");
    printf(" Informe o Id do produto a ser cancelado:    \n");
    printf("                                             \n");
    printf("#==========================================# \n");
}