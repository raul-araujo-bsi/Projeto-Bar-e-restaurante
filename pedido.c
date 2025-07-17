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
      case '4': finalizar_comanda();
        break;
      case '5': relatorios();
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
    printf("| 4 - PAGAMENTO              | \n");
    printf("| 5 - RELATÓRIO              | \n");
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
  cmd -> status = 1;
  cmd -> valor = calcular_total(cmd -> cpf);
  ler_cpf(cmd -> cpf);
  printf("#============================# \n");
  getchar();
  grava_comanda(cmd);
  free(cmd);
}


void pesquisar_comanda(void) {
  char cpf[13];
  ler_cpf(cpf);
  exibe_comanda(cpf);
}


void realizar_pedido(void){
  faz_pedido();
}


void finalizar_comanda(void) {
  FILE *fp_cmd = fopen("comandas.dat", "r+b");
  FILE *fp_ped = fopen("pedidos.dat", "r+b");
  if (!fp_cmd || !fp_ped) {
    printf("Erro ao abrir arquivos.\n");
    return;
  }

  Comanda cmd;
  Pedido ped;
  char cpf[13];
  char pag;
  limpaTela();
  ler_cpf(cpf);
  exibe_comanda(cpf);
  while (fread(&cmd, sizeof(Comanda), 1, fp_cmd)) {
    if (strcmp(cmd.cpf, cpf) == 0 && cmd.status == 1) {

      printf("Informe o modo de pagamento: \n");
      printf("1 - DINHEIRO \t 2 - PIX\n");
      printf("3 - CREDITO  \t 4-DEBITO\n");
      scanf(" %c", &pag);
      getchar();
      
      cmd.status = 0;
      fseek(fp_cmd, -sizeof(Comanda), SEEK_CUR);
      fwrite(&cmd, sizeof(Comanda), 1, fp_cmd);
      printf("Pagamento efetuado com sucesso!\n");


      rewind(fp_ped);
      while (fread(&ped, sizeof(Pedido), 1, fp_ped)) {
        if (strcmp(ped.cpf, cpf) == 0 && ped.status == 1) {
          ped.status = 0;
          fseek(fp_ped, -sizeof(Pedido), SEEK_CUR);
          fwrite(&ped, sizeof(Pedido), 1, fp_ped);
        }
      }

      fclose(fp_cmd);
      fclose(fp_ped);
      break;
    }
  }
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

  char novo_pedido;
  
  printf("#============================# \n");
  printf("|           PEDIDO           | \n");
  printf("#============================# \n");
  ler_cpf(ped -> cpf);
  ler_mesa(&ped -> mesa);
  do{
    limpaTela();
    valida_prod(&ped -> id_produto);
    ler_quantidade(&ped -> quantidade);
    float valor = calcula_valor(ped->id_produto, ped->quantidade);
    ped -> valor = valor;
    gravar_horario(ped -> hora, sizeof(ped -> hora));
    ped -> status = 1;
    grava_pedido(ped);
    cria_pedido();
  } while(toupper(novo_pedido) == 'S');
  free(ped);
}


void exibe_comanda(const char* cpf) {
  limpaTela();

  FILE *fp = fopen("comandas.dat", "rb");
  if (fp == NULL) {
  printf("Sem comandas cadastradas.\n");
  return;
  }
  
  Comanda cmd;
  char nome[50];
  float valor_total;
  int encontrada = 0; //sugestão GPT
  
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


void pedidos_ativos(void){
  limpaTela();

  FILE *fp = fopen("pedidos.dat", "rb");
  if (fp == NULL) {
  printf("Sem pedidos cadastrados.\n");
  return;
  }
  Pedido ped;
  char cpf[13];

  ler_cpf(cpf);

  while (fread(&ped, sizeof(Pedido), 1, fp)) {
    if (strcmp(ped.cpf, cpf) == 0 && ped.status == 1){
      printf("\n\nCPF: %s\n", ped.cpf);
      printf("Mesa: %d\n", ped.mesa);
      printf("Id. Produto: %d\n",ped.id_produto );
      printf("Quantidade: %d\n", ped.quantidade);
      printf("Hora do pedido: %s\n", ped.hora);
      printf("Valor: %.2f\n", ped.valor);
    }
  }

  printf("Pressione ENTER para continuar...");
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
  char cpf[13];

  ler_cpf(cpf);

  while (fread(&ped, sizeof(Pedido), 1, fp)) {
    if (strcmp(ped.cpf, cpf) == 0){
      printf("\n\nCPF: %s\n", ped.cpf);
      printf("Mesa: %d\n", ped.mesa);
      printf("Id. Produto: %d\n",ped.id_produto );
      printf("Quantidade: %d\n", ped.quantidade);
      printf("Hora do pedido: %s\n", ped.hora);
      printf("Valor: %.2f\n", ped.valor);
    }
  }
  fclose(fp);

  printf("Pressione ENTER para continuar...");
  getchar();
}


void comandas_ativas(void){
  limpaTela();

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

      printf("\n\n#-----------------------------------#\n");
      printf("ID da Comanda : %s\n", cmd.id_cmd);
      printf("CPF do Cliente: %s\n", cmd.cpf);
      printf("Nome do Cliente: %s\n", nome);
      printf("Valor Total    : R$ %.2f\n", valor_total);
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


void comandas_pagas(void){
  limpaTela();
  
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
    if (cmd.status == 0) {
      encontrou = 1;

      if (buscar_nome(cmd.cpf, nome, sizeof(nome)) == NULL) {
        strcpy(nome, "Cliente não encontrado");
      }

      valor_total = calcular_total(cmd.cpf);

      printf("\n\n#-----------------------------------#\n");
      printf("ID da Comanda : %s\n", cmd.id_cmd);
      printf("CPF do Cliente: %s\n", cmd.cpf);
      printf("Nome do Cliente: %s\n", nome);
      printf("Valor Total    : R$ %.2f\n", valor_total);
    }
  }

  fclose(fp);

  if (!encontrou) {
    printf("\nNenhuma comanda paga encontrada.\n");
  }

  printf("\n#-----------------------------------#\n");
  printf("Pressione ENTER para continuar...");
  getchar();
}


int comparar_horario(const void *a, const void *b) {
  Pedido *p1 = (Pedido *)a;
  Pedido *p2 = (Pedido *)b;
  return strcmp(p1->hora, p2->hora);
}


void ordem_pedidos(void){
limpaTela();

  FILE *fp = fopen("pedidos.dat", "rb");
  if (!fp) {
    printf("Erro ao abrir o arquivo de pedidos.\n");
    return;
  }

  Pedido pedidos[100];
  int count = 0;

  while (fread(&pedidos[count], sizeof(Pedido), 1, fp) == 1) {
    if (pedidos[count].status == 1) {
      count++;
      if (count >= 100) break;
    }
  }
  fclose(fp);

  if (count == 0) {
    printf("Não há pedidos ativos.\n");
    return;
  }

  char nome[50];

  
  qsort(pedidos, count, sizeof(Pedido), comparar_horario);
  
  printf("\n--- RELATÓRIO DE PEDIDOS ATIVOS ---\n");
  for (int i = 0; i < count; i++) {
    buscar_nome(pedidos[i].cpf, nome, sizeof(nome));
    printf("CPF: %s\t", pedidos[i].cpf);
    printf("Nome: %s\n", nome);
    printf("Código do Produto: %d\n", pedidos[i].id_produto);
    printf("Quantidade: %d\n", pedidos[i].quantidade);
    printf("Horário: %s\n", pedidos[i].hora);
    printf("------------------------------\n");
  }

  printf("Pressione ENTER para continuar...");
  getchar();
}


void relatorios(void){
  limpaTela();

  char opcao_cmd = tela_relatorios();

  switch (opcao_cmd)
  {
  case '1':
    pedidos_ativos();
    break;
  case '2':
    ordem_pedidos();
    break;
  case '3':
    comandas_ativas();
    break;
  case '4':
    comandas_pagas();
    break;
  case '5':
    exibe_pedido();
    break;
  default:
    break;
  }
}


char tela_relatorios (void){
  limpaTela();

  char op_ped;
  
  printf("Informe qual relatório deseja ver:\n");
  printf("1 - Pedido(s) ativo(s) por cliente\n");
  printf("2 - Pedidos ativos ordenados cronologicamente\n");
  printf("3 - Comandas ativas\n");
  printf("4 - Comandas pagas\n");
  scanf(" %c", &op_ped);
  getchar();
  return op_ped;
}