#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"
#include "valida.h"
#include "util.h"


void modulo_pedido(void){
  system("cls||clear");
  char opcao;

  do {
    opcao = tela_pedido();
    switch(opcao){
      case '1': abrir_comanda();
        break;
      case '2': pesquisar_comanda();
        break;
      case '3': atualizar_comanda();
        break;
      case '4': cancelar_comanda();
        break;
      //case '5': pagamento();
        break;
      //case '6': relatorio_pedidos();
        break;
    }
  } while (opcao != '0');
}


char tela_pedido(void){
    system("cls||clear");
    char op;
    printf("#============================# \n");
    printf("|          PEDIDOS           | \n");
    printf("|                            | \n");
    printf("| 1 - REALIZAR PEDIDO        | \n");
    printf("| 2 - RESUMO DO PEDIDO       | \n");
    printf("| 3 - EDITAR PEDIDO          | \n");
    printf("| 4 - CANCELAR PEDIDO        | \n"); 
    printf("| 5 - PAGAMENTO              | \n");
    printf("| 6 - RELATÓRIO              | \n");
    printf("| 0 - SAIR                   | \n");
    printf("|                            | \n");
    printf("#============================# \n");
    scanf("%c", &op);
    getchar();
    return op;
}


void abrir_comanda(void) {
  system("cls||clear");

  Comanda *cmd;
  cmd = (Comanda*) malloc(sizeof(Comanda));


  printf("#============================# \n");
  printf("|           COMANDA          | \n");
  printf("#============================# \n");
  gerar_id_comanda(cmd->id_cmd, sizeof(cmd->id_cmd));
  ler_mesa(&cmd -> mesa);
  ler_cpf(cmd -> cpf);
  exibe_valor(cmd->valor);
  printf("#============================# \n");
  getchar();
}


void pesquisar_comanda(void) {
  system("cls||clear");
  printf("#===============================# \n");
  printf("|             PEDIDO            | \n");
  printf("#===============================# \n");
  printf("  Id do Pedido:                   \n");
  printf("                                  \n");
  printf("  Id    Produto     Quantidade    \n");
  printf("                                  \n");
  printf("  Valor total:                    \n");
  printf("                                  \n");
  printf("#===============================# \n");
  getchar();
}


void atualizar_comanda(void){
  system("cls||clear");
  printf("#============================# \n");
  printf("|           PEDIDO           | \n");
  printf("#============================# \n");
  printf("   Id do pedido:               \n");
  printf("   Mesa:                       \n");
  printf("   Id do produto:              \n");    
  printf("   Quantidade:                 \n");
  printf("#============================# \n"); 
  getchar();
}


void cancelar_comanda(void) {
  system("cls||clear");
  printf("#==========================================# \n");
  printf("|             CANCELAR PEDIDO              | \n");
  printf("#==========================================# \n");
  printf(" Informe o Id do pedido a ser cancelado:     \n");
  printf("                                             \n");
  printf("#==========================================# \n");    
  getchar();
}


void ler_mesa(int* mesa){
  printf("Digite o número da mesa: ");
  scanf("%d", mesa);
  getchar();
}


void exibe_valor(float valor){
  printf("Valor total: %.2f \n", valor);
}