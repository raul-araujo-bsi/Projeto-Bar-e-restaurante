int valida_nome (char *nome){
    int i = 0;
    do {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0;
        }
        i++;
    } while (nome[i] != '\0');


// void valida_cpf (void){

// }


// void valida_fone (void) {

// }


// void valida_email (void){

// }