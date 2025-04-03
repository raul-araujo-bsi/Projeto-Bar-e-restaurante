#include <stdio.h>
#include "cliente.h"
#include "pedido.h"
#include "gestao.h"

//ASSINATURA DAS FUNÇÕES
char tela_principal(void);
// void tela_sobre(void);
// void gestao(void);
// void cadastro_produto(void);
// void produtos(void);
void saida(void);

//PROGRAMA PRINCIPAL
int main (void) {
//     tela_informacoes();
//     return 0;
// }
    char opcao;
    
    do {
        opcao = tela_principal();
        switch(opcao){
            case '1': modulo_cliente();
                      break;
            case '2': modulo_pedido();
                      break;
            case '3': modulo_gestao();
                      break;
            case '4': //modulo_relatorios();
                      break;
            case '5': //sobre();
        }
    } while (opcao != '0');
    saida();
    return 0;
}
char tela_principal(void) {
    char op;
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|        1 - CADASTRO        | \n");
    printf("|        2 - PEDIDO          | \n");
    printf("|        3 - GESTÃO          | \n");
    printf("|        4 - SOBRE           | \n");
    printf("|        0 - SAIR            | \n");
    printf("|                            | \n");
    printf("#============================# \n");
    scanf("%c", &op);
    getchar();
    return op;
}
// //MÓDULO DE INFORMAÇÕES DO PROGRAMA
// void tela_sobre(void) {
//     printf("#===========================================================# \n");
//     printf("|        SISTEMA DE GESTÃO PARA BARES E RESTAURANTES        | \n");
//     printf("|                                                           | \n");
//     printf("|           Desenvolvido por Raul Breno de Araújo           | \n");
//     printf("| Este programa utiliza funcionalidades necessárias para a  | \n");
//     printf("|gestão de bares e restaurantes, conectando as necessidades | \n");
//     printf("|do cliente aos serviços oferecidos pelo estabelecimento.   | \n");
//     printf("|                                                           | \n");
//     printf("|               Informações do desenvolvedor                | \n");
//     printf("|                                                           | \n");
//     printf("| Nome: Raul Breno de Araújo                                | \n");
//     printf("| E-mail: raul.araujo.101@ufrn.edu.br                       | \n");
//     printf("|                                                           | \n");
//     printf("#===========================================================# \n");
// }
// //MÓDULO DE SAÍDA DO PROGRAMA
void saida(void) {
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|    OBRIGADO PELA VISITA!   | \n");
    printf("|       ATÉ A PRÓXIMA!       | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}
// //MÓDULO PARA GESTORES
// void modulo_gestao(void) {
//     printf("#============================# \n");
//     printf("|                            | \n");
//     printf("|  1 - Cadastrar produtos    | \n");
//     printf("|  2 - Ver produtos          | \n");
//     printf("|  3 - Editar produtos       | \n");
//     printf("|  4 - Excluir produtos      | \n");
//     printf("|  5 - Relatórios            | \n");
//     printf("|  0 - Sair                  | \n");
//     printf("|                            | \n");
//     printf("#============================# \n");
// }
// void cadastro_produto(void) {
//     printf("#============================# \n");
//     printf("|    CADASTRO DE PRODUTOS    | \n");
//     printf("|                            | \n");
//     printf("|  Id:                       | \n");
//     printf("|  Fornecedor:               | \n");
//     printf("|  Produto:                  | \n");
//     printf("|  Quantidade:               | \n");
//     printf("|  Valor:                    | \n");
//     printf("|                            | \n");
//     printf("#============================# \n");
// }
// void produtos(void) {
//     printf("#=================================# \n");
//     printf("|              PRODUTOS           | \n");
//     printf("#=================================# \n");
//     printf("   Id   Produto            Valor    \n");
//     printf("#=================================# \n");
// }