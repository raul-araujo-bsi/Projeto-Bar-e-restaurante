#include <stdio.h>
#include "cliente.h"
#include "pedido.h"
#include "gestao.h"
#include "valida.h"

//ASSINATURA DAS FUNÇÕES
char tela_principal(void);
void sobre(void);
void saida(void);

//PROGRAMA PRINCIPAL
int main (void) {
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
            case '5': sobre();
        }
    } while (opcao != '0');
    saida();
    return 0;
}
char tela_principal(void) {
    char op;
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|        1 - CLIENTE         | \n");
    printf("|        2 - PEDIDO          | \n");
    printf("|        3 - GESTÃO          | \n");
    printf("|        4 - RELATÓRIOS      | \n");
    printf("|        5 - SOBRE           | \n");
    printf("|        0 - SAIR            | \n");
    printf("|                            | \n");
    printf("#============================# \n");
    scanf("%c", &op);
    getchar();
    return op;
}


void sobre(void) {
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


void saida(void) {
    printf("#============================# \n");
    printf("|                            | \n");
    printf("|    OBRIGADO PELA VISITA!   | \n");
    printf("|       ATÉ A PRÓXIMA!       | \n");
    printf("|                            | \n");
    printf("#============================# \n");
}
