#include "valida.h"
#include <stdio.h>
#include <string.h>
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


int valida_cpf (char *cpf){
    int i;
    if (strlen(cpf) != 11) {
    return 0;
    }
    else {
        for (i = 0; i < 11; i++) {
            if (!isdigit(cpf[i])) {
            return 0;
            }
        }
    }
    return 1;
}


int valida_fone (char *fone) {
    int i;
    if (strlen(fone) != 11) {
        return 0;
    }

    i = 0;
    do {
        if (!isdigit(fone[i])) {
            return 0;
        }
        i++;
    } while (fone[i] != '\0');

    return 1;
}


// int valida_email (void){

// }