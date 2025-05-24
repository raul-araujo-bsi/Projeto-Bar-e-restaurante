typedef struct produto Produto;
struct produto
{
  char id[20];
  char fornecedor [50];
  char produto [30];
  char quantidade [6];
  char valor [8];
};


void modulo_produtos(void);
char tela_produtos(void);
void cadastrar_produto(void);
void pesquisar_produto(void);
void atualizar_produto(void);
void excluir_produto(void);