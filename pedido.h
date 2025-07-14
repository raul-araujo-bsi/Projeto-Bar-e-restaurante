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
  int id_cmd;
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