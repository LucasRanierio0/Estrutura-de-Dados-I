#define tam 100

typedef struct {
	char m[tam];
	int fim;
} lista;

void linit(lista *l) {
	l->fim = 0;
}

void lins(lista *l,char x) {
	if (l->fim < tam) {
		int i = l->fim;
		while (i > 0 && x < l->m[i-1]) {
			l->m[i] = l->m[i-1];
			i--;
		}
		l->m[i] = x;
		l->fim++;
	}
}

void lmostra(lista *l) {
	printf("[");
	int i;
	for (i=0;i<l->fim;i++) {
		printf("%c",l->m[i]);
		if (i < l->fim-1)
			printf(",");
	}
	printf("]");
}

int lconta(lista *l,char x) {
	int i=0,no=0;
	while (i < l->fim && x > l->m[i])
		i++;
	while (i < l->fim && x == l->m[i]) {
		no++;
		i++;
	}
	return no;
}

void lmostra_intervalo(lista *l,char xi,char xf) {
	int i=0;
	while (i < l->fim && xi > l->m[i])
		i++;
	while (i < l->fim && xf >= l->m[i]) {
		printf("%c ",l->m[i]);
		i++;
	}
}

char lrem(lista *l,char x) {
	int i=0;
	while (i < l->fim && x > l->m[i])
		i++;
	if (i < l->fim && x == l->m[i]) {
		while (i < l->fim-1) {
			l->m[i] = l->m[i+1];
			i++;
		}
		l->fim--;
		return 1;
	}
	else
		return 0;
}
