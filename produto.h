typedef struct produto Produto;
struct produto
{
  int id;
  char fornecedor [30];
  char produto [20];
  int quantidade;
  float valor;
  int status;
};


void modulo_produtos(void);
char tela_produtos(void);
void cadastrar_produto(void);
void pesquisar_produto(void);
void atualizar_produto(void);
void excluir_produto(void);
void ler_fornecedor(char* );
void ler_produto(char* );
void ler_quantidade(int* );
void ler_valor(float* );