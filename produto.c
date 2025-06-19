#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "valida.h"
#include "util.h"

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

  prod->id = gera_id();

  printf("#============================# \n");
  printf("           CADASTRO            \n");
  printf("                               \n");
  ler_fornecedor(prod -> fornecedor);
  ler_produto(prod -> produto);
  ler_quantidade(&prod -> quantidade);    
  ler_valor(&prod -> valor);
  printf("                               \n");
  printf("#============================# \n");   

  grava_produto(prod);
  free(prod);
}


void pesquisar_produto(void) {
  FILE *fp = fopen("produtos.bin", "rb");
  Produto prod;
  int id;

  printf("Digite o ID do produto: ");
  scanf("%d", &id);

  if (fp == NULL) {
    printf("Arquivo não encontrado.\n");
    return;
  }

  while (fread(&prod, sizeof(Produto), 1, fp)) {
    if (prod.id == id && prod.status == 1) {
      printf("Fornecedor: %s\n", prod.fornecedor);
      printf("Produto: %s\n", prod.produto);
      printf("Quantidade: %d\n", prod.quantidade);
      printf("Valor: %.2f\n", prod.valor);
      fclose(fp);
      return;
    }
  }

  printf("Produto não encontrado.\n");
  fclose(fp);
}


void atualizar_produto(void) {
  FILE *fp = fopen("produtos.bin", "r+b");
  if (!fp) {
      printf("Erro ao abrir arquivo de produtos.\n");
      return;
  }

  int id_busca;
  printf("Digite o ID do produto para atualizar: ");
  scanf("%d", &id_busca);
  getchar();

  Produto prod;
  int encontrado = 0;

  while (fread(&prod, sizeof(Produto), 1, fp)) {
    if (prod.id == id_busca && prod.status == 1) {
      encontrado = 1;
      printf("Produto encontrado:\n");
      printf("Fornecedor: %s\n", prod.fornecedor);
      printf("Produto: %s\n", prod.produto);
      printf("Quantidade: %d\n", prod.quantidade);
      printf("Valor: %.2f\n", prod.valor);

      int opcao;
      printf("Qual campo deseja atualizar?\n");
      printf("1 - Quantidade\n2 - Valor\n");
      printf("Digite a opção: ");
      scanf("%d", &opcao);
      getchar();

      switch (opcao) {
        case 1:
          ler_quantidade(&prod.quantidade);
          break;
        case 2:
          ler_valor(&prod.valor);
          break;
        default:
          printf("Opção inválida.\n");
          fclose(fp);
          return;
      }
      fseek(fp, -sizeof(Produto), SEEK_CUR);
      fwrite(&prod, sizeof(Produto), 1, fp);
      printf("Produto atualizado com sucesso!\n");
      break;
    }
  }

  if (!encontrado) {
      printf("Produto com ID %d não encontrado.\n", id_busca);
  }

  fclose(fp);
} //função desenvolvida com auxilio do ChatGPT


void excluir_produto(void) {
  FILE *fp = fopen("produtos.bin", "r+b");
  if (!fp) {
    printf("Erro ao abrir arquivo de produtos.\n");
    return;
  }

  int id_busca;
  printf("Digite o ID do produto para excluir: ");
  scanf("%d", &id_busca);
  getchar();

  Produto prod;
  int encontrado = 0;

  while (fread(&prod, sizeof(Produto), 1, fp)) {
    if (prod.id == id_busca && prod.status == 1) {
      encontrado = 1;
      printf("Produto encontrado:\n");
      printf("Fornecedor: %s\n", prod.fornecedor);
      printf("Produto: %s\n", prod.produto);
      printf("Quantidade: %d\n", prod.quantidade);
      printf("Valor: %.2f\n", prod.valor);

      printf("Confirma exclusão? (s/n): ");
      char confirma = getchar();
      getchar();
      if (confirma == 's' || confirma == 'S') {
        prod.status = 0;
        fseek(fp, -sizeof(Produto), SEEK_CUR);
        fwrite(&prod, sizeof(Produto), 1, fp);
        printf("Produto excluído com sucesso.\n");
      } else {
        printf("Exclusão cancelada.\n");
      }
      break;
    }
  }

  if (!encontrado) {
    printf("Produto com ID %d não encontrado ou já excluído.\n", id_busca);
  }

  fclose(fp);
}


void ler_fornecedor(char* fornecedor){
  do {
  printf ("Digite o nome do fornecedor: ");
  fgets(fornecedor,30,stdin);
  fornecedor[strcspn(fornecedor, "\n")] = '\0';
  if(!valida_nome(fornecedor)) {
    printf("Nome inválido!");
  }
  } while(!valida_nome(fornecedor));
}


void ler_produto(char* produto){
  do {
  printf ("Digite o nome do produto: ");
  fgets(produto,20,stdin);
  produto[strcspn(produto, "\n")] = '\0';
  if(!valida_nome(produto)) {
    printf("Nome inválido!");
  }
  } while(!valida_nome(produto));
}


void ler_quantidade(int* quantidade){
  char qntd[5];
  printf("Digite a quantidade: ");
  fgets(qntd, sizeof(qntd), stdin);
  qntd[strcspn(qntd, "\n")] = '\0';
  *quantidade = atoi(qntd);
}


void ler_valor(float* valor){
  char valor_char[7];

  printf("Digite o valor: R$ ");
  fgets(valor_char, sizeof(valor_char), stdin);
  valor_char[strcspn(valor_char, "\n")] = '\0';
  *valor = atof(valor_char);
}