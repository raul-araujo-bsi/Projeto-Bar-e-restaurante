#ifndef PEDIDO_H //sugestão do GPT
#define PEDIDO_H //sugestão do GPT

typedef struct cmd Comanda;
typedef struct ped Pedido;

struct ped
{
  char cpf[13];
  int mesa;
  int id_produto;
  int quantidade;
  float valor;
  char hora[6];
  int status;
};


struct cmd 
{
  char id_cmd[15];
  char cpf[13];
  float valor;
  int status;
};

void modulo_pedido(void);
char tela_pedido(void);
void abrir_comanda(void);
void pesquisar_comanda(void);
void realizar_pedido(void);
void finalizar_comanda(void);
void ler_mesa(int* mesa);
float exibe_valor(float valor);
char cria_pedido(void);
void faz_pedido(void);
void exibe_comanda(const char* cpf);
void pedidos_ativos(void);
void exibe_pedido(void);
int comparar_horario(const void *a, const void *b);
void ordem_pedidos(void);
void comandas_ativas(void);
void comandas_pagas(void);
char tela_relatorios (void);
void relatorios(void);

#endif //sugestão do GPT