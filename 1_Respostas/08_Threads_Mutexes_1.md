1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?

> cada filho executa sua própria tarega e tem seu expaço protegido de memória, mas comunicação IPC  difícil

(b) threads?

>uma aplicação roda várias threads e elas compartilham o msmo espaço na memória, tornando-a mais fácil, porém com maior risco de corrupção de dados

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)
>após os creates, coexistirão 3 threads, a principal e mais duas.

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

(b)
>apenas duas coexistirão, depois uma será finalizada, então outras duas coexistirão e após será só a main

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`
> O estado de cancelamento pode ser ativado(padrão) ou desativado. Caso esteja desativado, o cancelamento fica na fila até que o cancelamento estava em ativado. Caso estaja ativado, então o tipo de cancelamento determina quando o cancelamento vai ocorrer

(b) `pthread_setcanceltype()`
> O tipo de cancelamento pode ser tanto assincrono quanto adiado(padrão). Quando está em assíncrono, o cancelamento pode ocorrer a qualquer momento. Quando está em adiado, o cancelamento sofrerá um atraso até a thread em seguida chame uma função que seja o ponto de cancelamento.

(DICA: elas são relacionadas à função pthread_cancel().)
