#include <stdio.h>
#include <ctype.h>

int valida_nome (char *nome){
    int i;
    i = 0;
    do {
        if (nome[0] == '\0') {
        return 0;
        } else if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0;
        }
        i++;
    } while (nome[i] != '\0');
    return 1;
}


int valida_cpf (void){

}


int valida_fone (void) {

}


int valida_email (void){

}