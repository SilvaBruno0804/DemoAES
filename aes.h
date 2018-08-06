#ifndef _AES_H_

#define _AES_H_

#include <stdint.h>
#include <stdlib.h>



// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// CBC enables AES encryption in CBC-mode of operation.
// CTR enables encryption in counter-mode.
// ECB enables the basic ECB 16-byte block algorithm. All can be enabled simultaneously.

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.
//#ifndef CBC
//  #define CBC 1
//#endif


#define ECB 1

//#ifndef CTR
//  #define CTR 1
//#endif

//Aqui são definidos os tamanhos de chave (descomentar o tamanho que deseja usar):

//#define AES128 1
//#define AES192 1
#define AES256 1


#define AES_BLOCKLEN 16 //Block length in bytes AES is 128b block only

#define AES_KEYLEN 16   // Key length in bytes
#define AES_keyExpSize 176

struct AES_ctx
{
  uint8_t RoundKey[AES_keyExpSize];
};

void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);

void AES_ECB_encrypt(struct AES_ctx* ctx, const uint8_t* buf, unsigned int text_size);
void AES_ECB_decrypt(struct AES_ctx* ctx, const uint8_t* buf, unsigned int text_size);

#endif
