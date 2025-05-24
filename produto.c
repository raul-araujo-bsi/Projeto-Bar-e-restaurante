#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "valida.h"

typedef struct produto Produto;

void modulo_produtos(void){
  system("cls||clear");
  char opcao;

  do {
    opcao = tela_produtos();
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


char tela_produtos(void) {
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

  Produto *prod;
  prod = (Produto*) malloc(sizeof(Produto));

  printf("#============================# \n");
  printf("           CADASTRO            \n");
  printf("                               \n");
  ler_fornecedor(prod -> fornecedor);
  ler_produto(prod -> produto);
  ler_quantidade(prod -> quantidade);    
  ler_valor(prod -> valor);
  printf("                               \n");
  printf("#============================# \n");   

  grava_cliente(prod);
  free(prod);
}


void pesquisar_produto(void) {
  system("cls||clear");
  printf("#=================================# \n");
  printf("|              PRODUTOS           | \n");
  printf("#=================================# \n");
  printf("   Id   Produto            Valor    \n");
  printf("#=================================# \n");
  getchar();
}


void atualizar_produto(void) {
  system("cls||clear");
  printf("#==========================================# \n");
  printf("|           ATUALIZAR PRODUTO              | \n");
  printf("#==========================================# \n");
  printf(" Informe o Id do produto a ser atualizado:   \n");
  printf("                                             \n");
  printf("#==========================================# \n"); 
  getchar();
}


void excluir_produto(void) {
  system("cls||clear");
  printf("#==========================================# \n");
  printf("|            CANCELAR PRODUTO              | \n");
  printf("#==========================================# \n");
  printf(" Informe o Id do produto a ser cancelado:    \n");
  printf("                                             \n");
  printf("#==========================================# \n");
  getchar();
}


ler_fornecedor(char* fornecedor){
  do {
  printf ("Digite o nome do cliente: ");
  fgets(fornecedor,30,stdin);
  fornecedor[strcspn(fornecedor, "\n")] = '\0';
  if(!valida_nome(fornecedor)) {
    printf("Nome inválido!");
  }
} while(!valida_nome(fornecedor));
}
ler_produto(char* produto){
  do {
  printf ("Digite o nome do cliente: ");
  fgets(produto,20,stdin);
  produto[strcspn(produto, "\n")] = '\0';
  if(!valida_nome(produto)) {
    printf("Nome inválido!");
  }
} while(!valida_nome(produto));
}
ler_quantidade(char* quantidade){

}    
ler_valor(char* valor){

}