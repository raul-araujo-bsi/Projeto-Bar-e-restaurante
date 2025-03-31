#include <stdio.h>

//ASSINATURA DAS FUNÇÕES
void tela_principal(void);
void cadastro(void);
void pedido(void);
void resumo_pedido(void);
void tela_informacoes(void);
void gestao(void);
void cadastro_produto(void);
void tela_saida(void);

//PROGRAMA PRINCIPAL
int main (void) {
    tela_principal();
    tela_informacoes();
    return 0;
}
//FUNÇÕES
void tela_principal(void) {
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|        1 - CADASTRO        | \n");
    printf("|        2 - PEDIDO          | \n");
    printf("|        3 - INFORMAÇÕES     | \n");
    printf("|        0 - SAIR            | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}
void cadastro(void) {
    printf("#============================# \n");
    printf("|           CADASTRO         | \n");
    printf("|                            | \n");
    printf("|  Id:                       | \n");
    printf("|  Nome:                     | \n");
    printf("|  Sobrenome:                | \n");
    printf("|  Data de nascimento:       | \n");    
    printf("|  CPF:                      | \n");
    printf("|  E-mail:                   | \n");
    printf("|  Login desejado:           | \n");
    printf("|  Senha desejada:           | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}
void pedido(void) {
    printf("#============================# \n");
    printf("|           PEDIDO           | \n");
    printf("|                            | \n");
    printf("|  Id do pedido:             | \n");
    printf("|  Mesa:                     | \n");
    printf("|  Id do produto:            | \n");    
    printf("|  Quantidade:               | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}
void resumo_pedido(void) {
    printf("#===============================# \n");
    printf("|  Id do Pedido:                | \n");
    printf("|                               | \n");
    printf("|  Id    Produto     Quantidade | \n");
    printf("|                               | \n");
    printf("|  Valor total:                 | \n");
    printf("|                               | \n");
    printf("#===============================# \n");
}
void tela_informacoes(void) {
    printf("#===========================================================# \n");
    printf("|        SISTEMA DE GESTÃO PARA BARES E RESTAURANTES        | \n");
    printf("|                                                           | \n");
    printf("|           Desenvolvido por Raul Breno de Araújo           | \n");
    printf("| Este programa utiliza funcionalidades necessárias para a  | \n");
    printf("|gestão de bares e restaurantes, conectando as necessidades | \n");
    printf("|do cliente aos serviços oferecidos pelo estabelecimento.   | \n");
    printf("|                                                           | \n");
    printf("|               Informações do desenvolvedor                | \n");
    printf("|                                                           | \n");
    printf("| Nome: Raul Breno de Araújo                                | \n");
    printf("| E-mail: raul.araujo.101@ufrn.edu.br                       | \n");
    printf("|                                                           | \n");
    printf("#===========================================================# \n");
}
void tela_saida(void) {
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|    OBRIGADO PELA VISITA!   | \n");
    printf("|       ATÉ A PRÓXIMA!       | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}
void gestao(void) {
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|  1 - Pedidos               | \n");
    printf("|  2 - Cadastrar produtos    | \n");
    printf("|  3 - Ver produtos          | \n");
    printf("|  4 - Editar produtos       | \n");
    printf("|  5 - Excluir produtos      | \n");
    printf("|  6 - Relatórios            | \n");
    printf("|  0 - Sair                  | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}
void cadastro_produto(void) {
    printf("#============================# \n");
    printf("|    CADASTRO DE PRODUTOS    | \n");
    printf("|                            | \n");
    printf("|  Fornecedor:               | \n");
    printf("|  Produto:                  | \n");
    printf("|  Quantidade:               | \n");
    printf("|  Valor:                    | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}