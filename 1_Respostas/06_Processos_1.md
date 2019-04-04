1. Como se utiliza o comando `ps` para:

(a) Mostrar todos os processos rodando na máquina?

>$ ps -A

(b) Mostrar os processos de um usuário?

>$ ps -u "user"

(c) Ordenar todos os processos de acordo com o uso da CPU?

>$ ps --sort=-pcpu

(d) Mostrar a quanto tempo cada processo está rodando?

>ps -e -o etime

2. De onde vem o nome `fork()`?

>vem de bifurcação

3. Quais são as vantagens e desvantagens em utilizar:

(a) `system()`?

>pertime execução de processos e comandos dentro de um programa. suceptível a falhas pois depende muito do sistema

(b) `fork()` e `exec()`?

>fork permite criar uma cópia exata do processo pai, já o exec substitui o processo pai por um novo

4. É possível utilizar o `exec()` sem executar o `fork()` antes?

>é possível, porém o processo pai será perdido.

5. Quais são as características básicas das seguintes funções:

(a) `execp()`?

>execucao de um programa no lugar atual (current path)

(b) `execv()`?

>permite que a lista de argumentos do novo processo seja nula

(c) `exece()`?

>permite argumento adicional no novo processo

(d) `execvp()`?

>permite lista de argumentos nula e procura do programa no current path

(e) `execve()`?

>permite argumento adicional e procura do programa no current path

(f) `execle()`?

>permite utilização de var agrs e argumento adicional
