#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
      case '3': realizar_pedido();
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
    printf("| 1 - ABRIR COMANDA          | \n");
    printf("| 2 - PESQUISAR COMANDA      | \n");
    printf("| 3 - REALIZAR PEDIDO        | \n"); 
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

  
  char op_ped;
  do {
    Comanda *cmd;
    cmd = (Comanda*) malloc(sizeof(Comanda));
  
  
    printf("#============================# \n");
    printf("|           COMANDA          | \n");
    printf("#============================# \n");
    gerar_id_comanda(cmd->id_cmd, sizeof(cmd->id_cmd));
    cmd -> status = 1;
    cmd -> valor = calcular_total(cmd -> cpf);
    ler_cpf(cmd -> cpf);
    printf("#============================# \n");
    getchar();
    grava_comanda(cmd);
    free(cmd);
    faz_pedido();
    op_ped = cria_pedido();
  } while (toupper(op_ped) != 'N');
}


void pesquisar_comanda(void) {

  exibe_comanda();
}


void realizar_pedido(void){
  faz_pedido();
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

  exibe_pedido();
}


void ler_mesa(int* mesa){
  printf("Digite o número da mesa: ");
  scanf("%d", mesa);
  getchar();
}


float exibe_valor(float valor){
  FILE* fp = fopen("pedidos.dat", "rb");
  
  Pedido ped;
  float total = 0;
  char cpf_alvo [13];

  ler_cpf(cpf_alvo);

  while (fread(&ped, sizeof(Pedido), 1, fp)) {
    if (strcmp(ped.cpf, cpf_alvo) == 0) {
      total += ped.valor;
    }
  }

  fclose(fp);
  return total;
}


char cria_pedido(void){
  char op;
  printf("Deseja fazer um novo pedido (S/N)? ");
  scanf(" %c", &op);
  getchar();
  return op;
}


void faz_pedido(void){
  system("cls||clear");

  Pedido *ped;
  ped = (Pedido*) malloc(sizeof(Pedido));
  
  printf("#============================# \n");
  printf("|           PEDIDO           | \n");
  printf("#============================# \n");
  ler_cpf(ped -> cpf);
  ler_mesa(&ped -> mesa);
  valida_prod(&ped -> id_produto);
  ler_quantidade(&ped -> quantidade);
  float valor = calcula_valor(ped->id_produto, ped->quantidade);
  ped -> valor = valor;
  gravar_horario(ped -> hora, sizeof(ped -> hora));
  ped -> status = 1;
  grava_pedido(ped);
  free(ped);
}


void exibe_comanda(void) {
  limpaTela();

  FILE *fp = fopen("comandas.dat", "rb");
  if (fp == NULL) {
  printf("Sem comandas cadastradas.\n");
  return;
  }
  
  Comanda cmd;
  char nome[50];
  char cpf[13];
  float valor_total;
  int encontrada = 0; //sugestão GPT
  
  ler_cpf(cpf);
  
  while (fread(&cmd, sizeof(Comanda), 1, fp)) {
    if (strcmp(cmd.cpf, cpf) == 0 && cmd.status == 1) {
      encontrada = 1;
      break;
    }
  }

  fclose(fp);
  
 if (!encontrada) {
    printf("\nNenhuma comanda ativa encontrada para esse CPF.\n");
    getchar();
    return;
  }

  buscar_nome(cpf, nome, sizeof(nome));
  valor_total = calcular_total(cpf);
  
  printf("\n#========================================#\n");
  printf("|             COMANDA ATUAL              |\n");
  printf("#========================================#\n");
  printf("ID da Comanda : %s\n", cmd.id_cmd);
  printf("CPF do Cliente: %s\t", cmd.cpf);
  printf("Nome do cliente: %s\n", nome);
  printf("Valor Total   : R$ %.2f\n", valor_total);
  printf("Status        : %s\n", cmd.status == 1 ? "Ativa" : "Finalizada");
  printf("#========================================#\n");
  getchar();
}


void exibe_pedido(void){
  limpaTela();

  FILE *fp = fopen("pedidos.dat", "rb");
  if (fp == NULL) {
  printf("Sem pedidos cadastrados.\n");
  return;
  }
  Pedido ped;

  while (fread(&ped, sizeof(Pedido), 1, fp)) {
    printf("CPF: %s\n", ped.cpf);
    printf("Mesa: %d\n", ped.mesa);
    printf("Id. Produto: %d\n",ped.id_produto );
    printf("Quantidade: %d\n", ped.quantidade);
    printf("Hora do pedido: %s\n", ped.hora);
    printf("Valor: %.2f\n", ped.valor);
  }
  delay(5);
}


void comandas_ativas(void){
  
  FILE* fp = fopen("comandas.dat", "rb");
  if (fp == NULL) {
    printf("Arquivo 'comandas.dat' não encontrado.\n");
    return;
  }

  Comanda cmd;
  char nome[50];
  float valor_total;
  int encontrou = 0;

  printf("\n#========= COMANDAS ATIVAS =========#\n");

  while (fread(&cmd, sizeof(Comanda), 1, fp)) {
    if (cmd.status == 1) {
      encontrou = 1;

      if (buscar_nome(cmd.cpf, nome, sizeof(nome)) == NULL) {
        strcpy(nome, "Cliente não encontrado");
      }

      valor_total = calcular_total(cmd.cpf);

      printf("\n#-----------------------------------#\n");
      printf("ID da Comanda : %s\n", cmd.id_cmd);
      printf("CPF do Cliente: %s\n", cmd.cpf);
      printf("Nome do Cliente: %s\n", nome);
      printf("Valor Total    : R$ %.2f\n", valor_total);
      printf("Status         : %d\n", cmd.status);
    }
  }

  fclose(fp);

  if (!encontrou) {
    printf("\nNenhuma comanda ativa encontrada.\n");
  }

  printf("\n#-----------------------------------#\n");
  printf("Pressione ENTER para continuar...");
  getchar();
}