#include <stdio.h>
#include <stdlib.h>
#include "Encrypt.h"

int main(){
        char arg[64] = "";
        printf("Digite o plain text: ");
        scanf(" %[^\n]", &arg);
        Encrypt(arg);
        printf("\n\nTexto cifrado a ser enviado: %s \n",arg);
        Decrypt(arg);
        printf("\nTexto decifrado:%s\n", arg);
        return 0;

}
