#define tam 100

typedef struct {
	int topo;
	int m[tam];
} pilha;

void init(pilha *p) {
	p->topo = 0;
}

void push(pilha *p,int x) {
	if (p->topo < tam) {
		p->m[p->topo] = x;
		p->topo++;
	}
}

int pop(pilha *p) {
	if (p->topo > 0) {
		p->topo--;
		return p->m[p->topo];
	}
}

char isfull(pilha *p) {
	if (p->topo == tam)
		return 1;
	else
		return 0;
}

char empty(pilha *p) {
	if (p->topo == 0)
		return 1;
	else
		return 0;
}
