#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <stdint.h>
#include "aes.h"
#include <string.h>


/** AES */


void Encrypt(unsigned char * arg, unsigned int cont){

//define qual tamanho de chave a ser usado baseado no DEFINE escolhido na aes.h

#ifdef AES128
    printf("AES 128 em uso...\n");
	uint8_t key[64] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

#elif defined(AES192)
    printf("AES 192 em uso...\n");
	uint8_t key[64] = { 0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5,
		0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b };


#elif defined(AES256)
    printf("AES 256 em uso...\n");

	uint8_t key[64] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
		0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };

#endif // AES128

	//Inicializa o processo de encrypt
	struct AES_ctx ctx;
	AES_init_ctx(&ctx, key);
    //Encripta o texto

    AES_ECB_encrypt(&ctx, arg, cont);


}


//Processo inverso da fun��o Encrypt

void Decrypt(unsigned char * arg, unsigned int cont){

#ifdef AES128
	uint8_t key[64] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

#elif defined(AES192)
	uint8_t key[64] = { 0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5};

#elif defined(AES256)
	uint8_t key[64] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
		0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };

#endif // AES128
 	struct AES_ctx ctx;
	AES_init_ctx(&ctx, key);

	//�nica mudan�a com rela��o ao encrypt � esta
    AES_ECB_decrypt(&ctx, arg, cont);



}
#endif // ENCRYPT_H
