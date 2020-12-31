#define tam 100

typedef struct {
	int m[tam];
	int com,fim,total;
} fila;

void qinit(fila *f) {
	f->com = 0;
	f->fim = 0;
	f->total = 0;
}

void enqueue(fila *f,int x) {
	if (f->total < tam) {
		f->m[f->fim] = x;
		f->fim++;
	if (f->fim == tam)
		f->fim = 0;
	f->total++;
	}
}

int dequeue(fila *f) {
	if (f->total > 0) {
		int x = f->m[f->com];
		f->com++;
	if (f->com == tam)
		f->com = 0;
	f->total--;
	return x;
	}
}

char qisempty(fila *f) {
	if (f->total == 0)
		return 1;
	else
		return 0;
}

char qisfull(fila *f) {
	if (f->total == tam)
		return 1;
	else
		return 0;
	}

void mostra(fila *f) {
	printf("[");
	int c,i = f->com;
	for (c=0;c<f->total;c++) {
		printf("%d",f->m[i]);
		i++;
		if (c < f->total-1)
			printf(",");
		if (i == tam)
			i=0;
	}
	printf("]");
}

int conta(fila *f,int x) {
	int i,j = f->com,c = 0;
	for (i=0;i<f->total;i++) {
		if (j == tam)
			j = 0;
		if (f->m[j] == x)
			c++;
		j++;
	}
	return c;
}

void enqueue_inicio(fila *f,int x) {
	if (f->total < tam) {
		f->com--;
		if (f->com < 0)
			f->com = tam-1;
		f->m[f->com] = x;
		f->total++;
	}
}

int dequeue_fim(fila *f) {
	if (f->total > 0) {
		f->fim--;
		if (f->fim < 0)
			f->fim = tam-1;
		int x = f->m[f->fim];
		f->total--;
	return x;
	}
}
