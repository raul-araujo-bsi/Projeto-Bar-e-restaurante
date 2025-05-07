typedef struct cliente Cliente;

struct cliente {
  char nome[50];
  char cpf[13];
  char fone[13];
  char email[30];
};


void modulo_cliente(void);
char tela_cliente(void);
void cadastro_cliente(void);
void pesquisar_cliente (void);
void atualizar_cliente(void);
void excluir_cliente(void);
void ler_nome(char nome[50]);
void ler_cpf(char cpf[13]);
void ler_fone(char fone[13]);
void ler_email(char email[30]);