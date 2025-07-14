
#ifndef CLIENTE_H  //sugestão do GPT
#define CLIENTE_H  //sugestão do GPT

typedef struct cliente Cliente;
struct cliente
{
  char nome[50];
  char cpf[13];
  char fone[13];
  char email[30];
  int status;
};



void modulo_cliente(void);
char tela_cliente(void);
void cadastro_cliente(void);
Cliente* pesquisar_cliente (char* cpf_busca);
void atualizar_cliente(void);
void excluir_cliente(void);
void exibir_cliente(Cliente cli);
void relatorios_clientes(void);

#endif //sugestão do GPT

void ler_nome(char*);
void ler_cpf(char*);
void ler_fone(char*);
void ler_email(char*);
