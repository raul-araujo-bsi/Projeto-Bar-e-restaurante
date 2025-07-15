#ifndef PEDIDO_H //sugestão do GPT
#define PEDIDO_H //sugestão do GPT

typedef struct cmd Comanda;
typedef struct ped Pedido;

struct ped
{
  int mesa;
  int id_produto;
  int quantidade;
  char data[11];
  char hora[6];
  int status;
};


struct cmd 
{
  char id_cmd[15];
  int mesa;
  char cpf[13];
  float valor;
  int status;
};

void modulo_pedido(void);
char tela_pedido(void);
void abrir_comanda(void);
void pesquisar_comanda(void);
void atualizar_comanda(void);
void cancelar_comanda(void);
void ler_mesa(int* mesa);
void exibe_valor(float valor);


#endif //sugestão do GPT