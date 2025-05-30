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
}


///////////////////////////////////////////////////////////////////////////////
/// Limpa a tela; funciona em Linux / MacOS / Windows
///
void limpaTela(void) {
  if (system("clear") || system("cls")) {
    // limpa a tela, Linux, Mac e Windows
  }
}


void grava_cliente(Cliente*cli) {
  FILE *fp;
  fp = fopen("clientes.txt","rt");
  if (fp != NULL){
    fclose(fp);
    fp = fopen("clientes.txt","at");
  } else {
    fp = fopen("clientes.txt","wt");
    }
  if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
  }
fprintf(fp,"%s, %s, %s, %s\n", cli->nome, cli->cpf, cli->fone, cli->email);
fclose(fp);
}


void grava_produto(Produto*prod) {
  FILE *fp;
  fp = fopen("produtos.txt","rt");
  if (fp != NULL){
    fclose(fp);
    fp = fopen("produtos.txt","at");
  } else {
    fp = fopen("produtos.txt","wt");
    }
  if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
  }
fprintf(fp,"%d, %s, %s, %d, %.2f\n",prod->id, prod->fornecedor, prod->produto, prod->quantidade, prod->valor);
fclose(fp);
}


int gera_id(void){
  int* id = malloc(sizeof(id));
  *id = id++;
  return id;
  free(id);
}