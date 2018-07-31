# DemoAES

O arquivo main.C mostra um exemplo utilizando a Encrypt.h criada e os arquivos AES (aes.c e aes.h).
Basta adicionar a Encrypt.h, aes.c e aes.h no projeto e incluir a Encrypt.h para poder utilizar as funções Encrypt e Decrypt.
O tamanho de texto está limitado a 64 caracteres, isto pode ser mudado nos laços onde in recebe arg e vice-versa e também no tamanho do array
da variável in.

for(int i = 0; i < 64; i++){
        arg[i] = in[i];
    }
    Exemplo dos laços que devem ser modificados, além do tamanho da variável in.
    
Importante lembrar que as chaves precisam ser iguais na encriptação e decriptação, caso modifique em uma, lembrar de fazer a mesma modificação na outra.
O algoritmo suporta chaves de 128/192 e 256 bits.

Mais detalhes nos comentários do código

Futuramente implementar leitura de arquivos (pdf, doc, multimídia) e medição de tempo de execução para comparação com tamanhos de pacotes
diferentes.

Contato: silvabruno@edu.univali.br
