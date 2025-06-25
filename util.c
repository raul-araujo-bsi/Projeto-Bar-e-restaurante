#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "produto.h"
#include "util.h"

void delay(int segundos) {
  int tempo = 1000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo
  }
  limpaTela();
}


///////////////////////////////////////////////////////////////////////////////
/// Limpa a tela; funciona em Linux / MacOS / Windows
///
void limpaTela(void) {
 system("clear || cls");
}


void grava_cliente(Cliente* cli) {
  FILE* fp = fopen("clientes.bin", "ab");  // "ab" para acrescentar no final
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de clientes!\n");
    return;
  }
  fwrite(cli, sizeof(Cliente), 1, fp);
  fclose(fp);
  printf("Cliente salvo com sucesso!\n");
  delay(3);
}



void grava_produto(Produto *prod) {
  FILE *fp = fopen("produtos.bin", "ab");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  fwrite(prod, sizeof(Produto), 1, fp);
  fclose(fp);
}


int gera_id(void) {
    FILE *fp = fopen("id_produto.bin", "rb+");
    int id = 0;

    if (fp == NULL) {
      fp = fopen("id_produto.bin", "ab+");
      if (fp == NULL) {
        printf("Erro ao criar o arquivo de ID!\n");
        exit(1);
      }
    } else {
        fread(&id, sizeof(int), 1, fp);
    }

    id++;
    rewind(fp);
    fwrite(&id, sizeof(int), 1, fp);
    fclose(fp);

    return id;
}
