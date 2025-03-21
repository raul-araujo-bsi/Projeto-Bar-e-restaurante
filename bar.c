#include <stdio.h>

//ASSINATURA DAS FUNÇÕES
void tela_principal(void);
void cadastro_cliente(void);
void login(void);
void menu_cliente(void);
void menu_adm(void);
void cadastro_produto(void);


int main (void) {

    //TELA PRINCIPAL
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|        1 - CADASTRO        | \n");
    printf("|        2 - LOGIN           | \n");
    printf("|        3 - INFORMAÇÕES     | \n");
    printf("|        0 - SAIR            | \n");
    printf("|                            | \n");
    printf("#============================# \n");

    //TELA DE CADASTRO
    printf("#============================# \n");
    printf("|           CADASTRO         | \n");
    printf("|                            | \n");
    printf("|  Nome:                     | \n");
    printf("|  Sobrenome:                | \n");
    printf("|  Data de nascimento:       | \n");    
    printf("|  CPF:                      | \n");
    printf("|  E-mail:                   | \n");
    printf("|  Login desejado:           | \n");
    printf("|  Senha desejada:           | \n");
    printf("|                            | \n");
    printf("#============================# \n");

    //TELA LOGIN
    printf("#============================# \n");
    printf("|            LOGIN           | \n");
    printf("|                            | \n");
    printf("|  Login:                    | \n");
    printf("|  Senha:                    | \n");
    printf("|                            | \n");
    printf("#============================# \n");

    //TELA DE SAÍDA
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|    OBRIGADO PELA VISITA!   | \n");
    printf("|       ATÉ A PRÓXIMA!       | \n");
    printf("|                            | \n");
    printf("#============================# \n");

    //TELA DE LOGIN - CLIENTE
    printf("#============================# \n");
    printf("|        BEM-VINDO!          | \n");
    printf("|Escolha uma opção a seguir: | \n");
    printf("|                            | \n");
    printf("|  1 - Consultar cardápio    | \n");
    printf("|  2 - Realizar pedido       | \n");
    printf("|  3 - Verificar pedido      | \n");
    printf("|  4 - Cancelar pedido       | \n");
    printf("|  5 - Ajustar cadastro      | \n");
    printf("|  0 - sair                  | \n");
    printf("|                            | \n");
    printf("#============================# \n");

    //TELA DE LOGIN - ADM
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|  1 - Cadastrar produtos    | \n");
    printf("|  2 - Ver produtos          | \n");
    printf("|  3 - Editar produtos       | \n");
    printf("|  4 - Excluir produtos      | \n");
    printf("|  5 - Vendas                | \n");
    printf("|  6 - Relatórios            | \n");
    printf("|  0 - Sair                  | \n");
    printf("|                            | \n");
    printf("#============================# \n");

    //TELA DE CADASTRO DE PRODUTO
    printf("#============================# \n");
    printf("|    CADASTRO DE PRODUTOS    | \n");
    printf("|                            | \n");
    printf("|  Fornecedor:               | \n");
    printf("|  Produto:                  | \n");
    printf("|  Quantidade:               | \n");
    printf("|  Valor:                    | \n");
    printf("|                            | \n");
    printf("#============================# \n");

    return 0;
}