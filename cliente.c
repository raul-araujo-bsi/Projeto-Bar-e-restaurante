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
      case '1': cadastro_cliente();
        break;
      case '2': pesquisar_cliente();
        break;
      case '3': atualizar_cliente();
        break;
      case '4': excluir_cliente();
        break;
    }
  } while (opcao != '0');
}


char tela_cliente(void){
  system("cls||clear");
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


void pesquisar_cliente (void){
  system("cls||clear");
  char cpf[13];
  printf("#============================# \n");
  printf("|           PESQUISA           \n");
  printf("|                              \n");
  printf("| Informe o CPF do cliente:    \n");
  ler_cpf(cpf);
  printf("|                              \n");
  printf("#============================# \n"); 
}


void atualizar_cliente(void){
  system("cls||clear");
  char fone[13];
  char email[30];
  printf("#============================# \n");
  printf("             CADASTRO          \n");
  printf("                               \n");
  printf("  TELEFONE:                    \n");   
  ler_fone(fone); 
  printf("  E-MAIL:                      \n");
  ler_email(email);
  printf("                               \n");
  printf("#============================# \n");
}


void excluir_cliente(void){
  system("cls||clear");
  char cpf[13];
  printf("#============================# \n");
  printf("            EXCLUIR            \n");
  printf("                               \n");
  printf("  Informe o CPF do cliente:    \n");
  ler_cpf(cpf);
  printf("                               \n");
  printf("#============================# \n"); 
}


void ler_nome(char*nome) {
  do {
    printf ("Digite o nome do cliente: ");
    fgets(nome,50,stdin);
    if(!valida_nome(nome)) {
        printf("Nome inválido!");
    }
  } while(!valida_nome(nome));
}


void ler_cpf(char*cpf) {
  do {
    printf("Digite o CPF do cliente: ");
    fgets(cpf,13,stdin);
    if (!valida_cpf(cpf)) {
      printf("CPF inválido!\n");
    }
  } while(!valida_cpf(cpf));
}


void ler_fone(char*fone) {
  do{
    printf("Informe o telefone do cliente: ");
    fgets(fone,13,stdin);
    if (!valida_fone(fone)) {
      printf("Telefone inválido!");
    }
  } while (!valida_fone(fone));
}


void ler_email(char*email) {
  do{
    printf("Informe o Email do cliente: ");
    fgets(email,30,stdin);
    if (!valida_email(email)) {
      printf("Formato de email inválido!");
    }
  } while(!valida_email(email));
}