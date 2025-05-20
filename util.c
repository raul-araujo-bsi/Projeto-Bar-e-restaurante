#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util.h>


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


void grava_cliente(void) {
  FILE *fp;
  fp = fopen("clientes.txt","wt");
  if (fp == NULL){
    printf("Erro na criacao do arquivo\n!");
  }
fprintf(fp,"cli");
fclose(fp);
};