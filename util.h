#include "cliente.h"
#include "produto.h"
#include "pedido.h"

void limpaTela(void);
void delay(int segundos);
void grava_cliente(Cliente* cli);
void grava_produto(Produto* prod);
void grava_comanda(Comanda* cmd);
void grava_pedido(Pedido* ped);
void gravar_horario(char* hora, int tamanho);
int gera_id(void);
void gerar_id_comanda(char* buffer, int tamanho);
char* buscar_nome(const char* cpf_alvo, char* nome, int tamanho);
float calcular_total(const char* cpf);
float calcula_valor(int id_produto, int quantidade);