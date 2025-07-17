#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "produto.h"
#include "pedido.h"
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
  FILE* fp = fopen("clientes.dat", "ab"); 
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
  FILE *fp = fopen("produtos.dat", "ab");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  fwrite(prod, sizeof(Produto), 1, fp);
  fclose(fp);
}


void grava_comanda(Comanda *cmd) {
  FILE *fp = fopen("comandas.dat", "ab");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  fwrite(cmd, sizeof(Comanda), 1, fp);
  fclose(fp);
}


void grava_pedido(Pedido *ped) {
  FILE *fp = fopen("pedidos.dat", "ab");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  fwrite(ped, sizeof(Pedido), 1, fp);
  fclose(fp);
}


void gravar_horario(char* hora, int tamanho) {
  time_t agora;
  struct tm *infoTempo;

  time(&agora);                    // obtém o tempo atual
  infoTempo = localtime(&agora);  // converte para tempo local

  strftime(hora, tamanho, "%H:%M", infoTempo);  // formato: HH:MM (24h)
} //gerada pelo GPT


int gera_id(void) {
    FILE *fp = fopen("id_produto.dat", "rb+");
    int id = 0;

    if (fp == NULL) {
      fp = fopen("id_produto.dat", "ab+");
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


void gerar_id_comanda(char* buffer, int tamanho) {
  time_t agora;
  struct tm *infoTempo;

  time(&agora);                        // Captura o tempo atual do sistema
  infoTempo = localtime(&agora);      // Converte para struct de data/hora local

  strftime(buffer, tamanho, "%Y%m%d%H%M%S", infoTempo);  
} //FUNÇÃO GERADA PELO CHATGPT


char* buscar_nome(char* cpf_alvo, char* nome, int tamanho) {
  FILE* fp = fopen("clientes.dat", "rb");
  Cliente cliente;

  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de clientes!\n");
    return NULL;
  }

  while (fread(&cliente, sizeof(Cliente), 1, fp)) {
    if (strcmp(cliente.cpf, cpf_alvo) == 0) {
      strncpy(nome, cliente.nome, tamanho);
      nome[tamanho - 1] = '\0';
      fclose(fp);
      return nome;
    }
  }

  fclose(fp);
  return NULL;
}


float calcular_total(char* cpf) {
  FILE* fp_ped = fopen("pedidos.dat", "rb");
  Pedido ped;
  float total = 0;

  while (fread(&ped, sizeof(Pedido), 1, fp_ped)) {
    if (strcmp(ped.cpf, cpf) == 0 && ped.status == 1) {
      total += ped.valor;
    }
  }

  fclose(fp_ped);
  return total;
}



float calcula_valor(int id_produto, int quantidade) {
  FILE* fp_prod = fopen("produtos.dat", "rb");
  if (fp_prod == NULL) {
    printf("Erro ao abrir o arquivo produtos.dat\n");
    return 0;
  }

  Produto prod;

  while (fread(&prod, sizeof(Produto), 1, fp_prod)) {
    if (prod.id == id_produto && prod.status == 1) {
      fclose(fp_prod);
      return quantidade * prod.valor;
    }
  }

  fclose(fp_prod);
  return 0;
}
