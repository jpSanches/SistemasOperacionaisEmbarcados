Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  FILE * fp;

  fp = fopen("ola_mundo.txt", "w");
  if(!fp){
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  if(fwrite("Ola mundo\n", sizeof("Ola mundo\n"), 1,fp) == 0)
    printf("Erro na escrita do arquivo");

  fclose(fp);

  return 0;
}
```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char nome[16], nome_arquivo[20];
  int idade;
  FILE * fp;

  printf("Digite seu nome: ");
  scanf("%s", nome);

  strcpy(nome_arquivo, nome);
  strcat(nome_arquivo, ".txt");

  printf("Digite sua idade: ");
  scanf("%d", &idade);

  fp = fopen(nome_arquivo, "w");
  if(!fp){
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  fprintf(fp,"Nome: %s\n", nome);
  fprintf(fp,"Idade: %d anos", idade);

  fclose(fp);

  return 0;
}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  FILE * fp;
  char nome_arquivo[20];

  strcpy(nome_arquivo,argv[1]);
  strcat(nome_arquivo,".txt");

  fp = fopen(nome_arquivo, "w");
  if(!fp){
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  fprintf(fp,"Nome: %s\n", argv[1]);
  fprintf(fp,"Idade: %s anos\n", argv[2]);

  fclose(fp);

  return 0;
}
```
4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```C
#include <stdio.h>
#include <stdlib.h>
#include "bis_arqs.h"

int tam_arq_texto(char *nome_arquivo){
  FILE * fp;
  int tamanho = 0;
  fp = fopen(nome_arquivo, "r");
  if(!fp){
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  while (!(getc(fp))){
    tamanho++;
  }
  fclose(fp);

  return tamanho;
}

```
5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `char* le_arq_texto(char *nome_arquivo);` Repare que o conteúdo do arquivo é armazenado em um vetor interno à função, e o endereço do vetor é retornado ao final. (Se você alocar este vetor dinamicamente, lembre-se de liberar a memória dele quando acabar o seu uso.) Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```C

char* le_arq_texto(char *nome_arquivo){
  char * texto;
  FILE * fp;
  int tamanho = tam_arq_texto(nome_arquivo);

  texto = (char*)malloc(sizeof(char) * tamanho);

  fp = fopen(nome_arquivo, "r");
  if(!fp){
    printf("Erro ao abrir o arquivo. Saindo do programa.\n");
    exit(1);
  }

  fgets(texto,tamanho,fp);
  fclose(fp);

  free(texto);

  return texto;
}
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```
```C
#include <stdio.h>
#include <stdlib.h>

#include "bis_arqs.h"

int tam_arq_texto(char *nome_arquivo){
  FILE * fp;
  int tamanho = 0;

  fp = fopen(nome_arquivo, "r");
  if(!fp){
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }

  while(getc(fp) != EOF){
    tamanho++;
  }

  fclose(fp);

  return tamanho;
}

char* le_arq_texto(char *nome_arquivo){
  char * texto;
  FILE * fp;
  char rt;
  int tamanho = tam_arq_texto(nome_arquivo);

  texto = (char*)malloc(sizeof(char)* tamanho);

  fp = fopen(nome_arquivo, "r");
  if(!fp){
    printf("Erro ao abrir o arquivo. Saindo do programa.\n");
    exit(1);
  }
  fgets(texto,tamanho,fp);
   /*
  if (fgets(texto,tamanho,fp) != tamanho) {
    printf("Erro ao ler o arquivo\n");
  }
  \*/
  fclose(fp);

  return texto;
}

```

```C
#include <stdio.h>
#include <stdlib.h>
#include "bis_arqs.h"

int main(int argc, char const *argv[]) {

  int tamanho = tam_arq_texto((char *) argv[1]);
  char * texto;

  texto = malloc(sizeof(char) * tamanho);
  printf("%s",le_arq_texto((char *) argv[1]));
  free(texto);
  return 0;
}

```
7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bis_arqs.h"

int main(int argc, char const *argv[]) {

  int tamanho = tam_arq_texto((char *) argv[2]);
  int palavra_chave = 0;
  char \*texto;

  texto = malloc(sizeof(char) * tamanho);

  for (int i = 0; i <= tamanho-strlen(argv[1]); i+=sizeof(char)) {
    if (!strncmp(argv[1], texto + i, strlen(argv[1]))) {
      palavra_chave++;
    }
  }

  printf("'%s' ocorre %d vezes no arquivo '%s'\n", argv[1], palavra_chave, argv[2]);

  free(texto);
  return 0;
}

```
