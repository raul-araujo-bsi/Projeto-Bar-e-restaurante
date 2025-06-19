#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "valida.h"
#include "util.h"

typedef struct cliente Cliente;

void modulo_cliente(void){
  char opcao;

  do {
    opcao = tela_cliente();
    switch(opcao){
      char cpf_busca[13];
      case '1': cadastro_cliente();
        break;
      case '2': pesquisar_cliente(cpf_busca);
        break;
      case '3': atualizar_cliente(cpf_busca);
        break;
      case '4': excluir_cliente(cpf_busca);
        break;
    }
  } while (opcao != '0');
}


char tela_cliente(void){
  system("cls||clear");
  char op;
  printf("\n#============================# \n");
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
  system("cls||clear");

  Cliente *cli;
  cli = (Cliente*) malloc(sizeof(Cliente));

  printf("#============================# \n");
  printf("           CADASTRO            \n");
  printf("                               \n");
  ler_nome(cli->nome);
  ler_cpf(cli -> cpf);    
  ler_fone(cli -> fone);
  ler_email(cli -> email);
  printf("                               \n");
  printf("#============================# \n");   

  grava_cliente(cli);
  free(cli);
}


Cliente* pesquisar_cliente(char* cpf_busca) {
  FILE* fp = fopen("clientes.bin", "rb");
  if (fp == NULL) {
    printf("Sem clientes cadastrados.\n");
    return NULL;
  }
  char cpf[13];
  ler_cpf(cpf);
  Cliente* cli = (Cliente*) malloc(sizeof(Cliente));
  fread(cli, sizeof(Cliente), 1, fp);
  
  char opcao;
  do {

    if (cli != NULL) {
      printf("\nCliente encontrado:\n");
      printf("Nome: %s\n", cli->nome);
      printf("CPF: %s\n", cli->cpf);
      printf("Telefone: %s\n", cli->fone);
      printf("Email: %s\n", cli->email);
      free(cli);
    } else {
      printf("\nCliente não encontrado.\n");
    }

    printf("\nDeseja buscar outro cliente? (s/n): ");
    scanf(" %c", &opcao);

  } while (opcao == 's' || opcao == 'S');
  return cli;
}


void atualizar_cliente(char* cpf_busca) {
  FILE* fp = fopen("clientes.bin", "r+b");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de clientes!\n");
    return;
  }

  Cliente cli;
  while (fread(&cli, sizeof(Cliente), 1, fp)) {
    if (cli.status == 1 && strcmp(cli.cpf, cpf_busca) == 0) {
      Cliente novo_cli;

      ler_nome(novo_cli.nome);
      ler_cpf(novo_cli.cpf);
      ler_fone(novo_cli.fone);
      ler_email(novo_cli.email);
      novo_cli.status = 1;

      fseek(fp, -sizeof(Cliente), SEEK_CUR);
      fwrite(&novo_cli, sizeof(Cliente), 1, fp);
      printf("Cliente atualizado com sucesso!\n");
      fclose(fp);
      return;
    }
  }

  printf("Cliente não encontrado para atualização.\n");
  fclose(fp);
}




void excluir_cliente(char* cpf_busca) {
  FILE* fp = fopen("clientes.bin", "r+b");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de clientes!\n");
    return;
  }

  Cliente cli;
  while (fread(&cli, sizeof(Cliente), 1, fp)) {
    if (cli.status == 1 && strcmp(cli.cpf, cpf_busca) == 0) {
      cli.status = 0;
      fseek(fp, -sizeof(Cliente), SEEK_CUR);
      fwrite(&cli, sizeof(Cliente), 1, fp);
      printf("Cliente removido com sucesso!\n");
      fclose(fp);
      return;
    }
  }

  printf("Cliente não encontrado.\n");
  fclose(fp);
}



void ler_nome(char*nome) {
  do {
    printf ("Digite o nome do cliente: ");
    fgets(nome,50,stdin);
    nome[strcspn(nome, "\n")] = '\0';
    if(!valida_nome(nome)) {
        printf("Nome inválido!");
    }
  } while(!valida_nome(nome));
}


void ler_cpf(char*cpf) {
  do {
    printf("Digite o CPF do cliente: ");
    fgets(cpf,13,stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    if (!valida_cpf(cpf)) {
      printf("CPF inválido!\n");
    }
  } while(!valida_cpf(cpf));
}


void ler_fone(char*fone) {
  do{
    printf("Informe o telefone do cliente: ");
    fgets(fone,13,stdin);
    fone[strcspn(fone, "\n")] = '\0';
    if (!valida_fone(fone)) {
      printf("Telefone inválido!");
    }
  } while (!valida_fone(fone));
}


void ler_email(char*email) {
  do{
    printf("Informe o Email do cliente: ");
    fgets(email,30,stdin);
    email[strcspn(email, "\n")] = '\0';
    if (!valida_email(email)) {
      printf("Formato de email inválido!");
    }
  } while(!valida_email(email));
}