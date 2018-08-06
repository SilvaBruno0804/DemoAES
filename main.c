#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Encrypt.h"


int main(){

        unsigned int cont = 0;
        unsigned char arg[2000000] = "";
        char cTemp;
        //Aqui coloca-se o caminho do arquivo que deseja criptografar e onde serão salvos os arquivos cifrados e decifrados
        FILE *fpSourceFile = fopen("C:\\Users\\6765254\\pictures\\teste.PNG", "rb");
        FILE *fpTargetFileCipher = fopen("C:\\Users\\6765254\\Pictures\\cifrado.aes", "wb");
        FILE *fpTargetFile = fopen("C:\\Users\\6765254\\Pictures\\decifrado.PNG", "wb");

        //Se não achou o arquivo retorna erro
        if(fpSourceFile == NULL){
            printf("Nao foi possivel abrir o arquivo!\n");
            return 1;
        }

        //Lê cada byte do arquivo
        while(fread(&cTemp, 1, 1, fpSourceFile) == 1)
        {
            arg[cont] = cTemp;
            cont++;
        }
        //Criptografa o arquivo
        Encrypt(arg, cont);

        //Cria o arquivo criptografado
        for(int i = 0; i < cont; i++){
            fwrite(&arg[i], 1, 1, fpTargetFileCipher);
        }

        //Descriptografa o texto
        Decrypt(arg, cont);

        //Cria o arquivo com os bytes descriptografados
        for(int i = 0; i < cont; i++){
            fwrite(&arg[i], 1, 1, fpTargetFile);
        }

        return 0;

}

