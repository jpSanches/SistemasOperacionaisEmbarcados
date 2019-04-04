1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
>1, pois vem antes do fork

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```
>2, um no processo pai, outro no filho

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

>SIGHUP: sinal emitido aos processo associados a um terminal quando este se desconecta

>SIGINT: sinal emitido aos processos do terminal quando teclas de interrupção são acionadas

>SIGQUIT: sinal emitido aos processos do terminal quando a tecla de abandono do teclado são acionadas

>SIGILL: emitido quando uma instrução ilegal é detectada

>SIGTRAP: emitido após cada instrução emcaso de geração de traces dos processos

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?

>Apesar de ser consideravelmente precisos os alarmes, é questionável sua utilização para aplicações de tempo real, dependendo da criticidade da operação em questão. Sua imprecisão vem do fato de o sistema operacional tratar diversos processos alternadamente, não havendo garantias do tempo de execução de maneira detterminística.
