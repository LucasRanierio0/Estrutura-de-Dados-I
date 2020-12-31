#include <iostream>
#include <string.h>
#include <locale.h>
#include "listasstr.h"

typedef struct {
	char nome[30];
	char telefone[15];
	char email[15];
} registro;

void cadastra(FILE *); // variável do tipo arquivo;
void consulta(FILE *);
int tamarq(FILE *);
void relatorio(FILE *);
void relatorioord(FILE *);

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	FILE *arq;
	arq = fopen("dados.dat","rb+"); // arquivo arq recebe um .dat com o nome dados; rb+ -> lê e grava em um arquivo binário;
	if (arq == 0) { // arquivo não existe no disco ou não pode ser aberto;
		arq = fopen("dados.dat","wb+"); // wb+ -> lê e grava em um arquivo binário, porém cria um arquivo do zero;
	}
	int op;
	do {
		system("cls");
		printf("==============Agenda 1.0==============\n");
		printf("1. Cadastrar\n");
		printf("2. Consultar\n");
		printf("3. Relatório\n");
		printf("4. Relatório ordenado\n");
		printf("5. Excluir\n");
		printf("6. Sair\n");
		printf("======================================\n");
		printf("Sua opção:");
		scanf("%d",&op);
		fflush(stdin);
		switch (op) {
			case 1:
				cadastra(arq);
				break;
			case 2:
				consulta(arq);
				break;
			case 3:
				relatorio(arq);
				break;
			case 4:
				relatorioord(arq);
				break;
			case 5:
				break;
		}
	} while (op != 6);
	fclose(arq); // fechando o arquivo antes de encerrar o programa;
	return 1;
}

void cadastra(FILE *arq) {
	printf("Cadastrando o registro número:%d\n",tamarq(arq)+1); // se ftell for executado com sucesso, retornará o valor 0, senão -1;
	registro reg;
	printf("Nome.........:");
	gets(reg.nome);
	printf("Telefone.....:");
	gets(reg.telefone);
	printf("E-mail.......:");
	gets(reg.email);
	fseek(arq,0,SEEK_END); // fseek -> posiciona a agulha no disco; arquivo arq inicializando da posição 0 indo até 59 (que é a posição do SEEK_END, a última posição da soma dos vetores);
	fwrite(&reg,sizeof(registro),1,arq); // escreve as entradas reg dentro do registro em questão, indo de 0 a 59, nesse caso, o valor do sizeof registro, que é a soma de todos os vetores da struct registro; grava somente 1 arquivo por vez na variável do tipo arquivo (arq);
	printf("Registro gravado com sucesso!\n");
	system("pause");
}

void consulta(FILE *arq) {
	int nr;
	printf("Entre com o número do registro:");
	scanf("%d",&nr);
	fflush(stdin);
	registro reg;
	fseek(arq,(nr-1)*sizeof(registro),SEEK_SET); // posiciona a agulha no disco; arquivo arq inicializando da posição 0 se a consulta for no registro 1, ou na posição 60 se a consulta for no registro 2, etc; SEEK_SET -> inicializando a consulta do início do primeiro vetor entre todos os vetores;
	fread(&reg,sizeof(registro),1,arq); // lê as entradas reg dentro do registro em questão, indo de 0 a 59, nesse caso, o valor do sizeof registro, que é a soma de todos os vetores da struct registro; lê somente 1 arquivo por vez na variável do tipo arquivo (arq);
	printf("Nome.........:%s\n",reg.nome);
	printf("Telefone.....:%s\n",reg.telefone);
	printf("E-mail.......:%s\n",reg.email);
	system("pause");
}

void relatorio(FILE *arq) {
	FILE *arqtxt = fopen("Relatorio.txt","w"); // cria uma variável arqtxt do tipo arquivo que recebe o arquivo Relatorio.txt; abre e escreve no mesmo o conteúdo abaixo; 
	fprintf(arqtxt,"Relação de contatos cadastrados na Agenda\n");
	fprintf(arqtxt,"Nome                           Telefone        E-mail\n");
	fprintf(arqtxt,"==============================================================\n");
	int nr;
	registro reg;
	for(nr=0;nr<tamarq(arq);nr++) {
		fseek(arq,nr*sizeof(registro),SEEK_SET);
		fread(&reg,sizeof(registro),1,arq);
		fprintf(arqtxt,"%-30s %-15s %-15s\n",reg.nome,reg.telefone,reg.email);
	}
	fprintf(arqtxt,"==============================================================\n");
	fclose(arqtxt); // fecha o arquivo arqtxt;
	printf("Relatório gerado com sucesso.\n");
	system("pause");
}

void relatorioord(FILE *arq) {
	lista l;
	linit(&l);
	int nr;
	registro reg;
	elem x;
	for (nr=0;nr<tamarq(arq);nr++) {
		fseek(arq,nr*sizeof(registro),SEEK_SET);
		fread(&reg,sizeof(registro),1,arq);
		strcpy(x.nome,reg.nome);
		x.nr = nr;
		lins(&l,x);
	}
	FILE *arqtxt = fopen("RelatorioOrdenado.txt","w");
	fprintf(arqtxt,"Relação de contatos cadastrados na Agenda\n");
	fprintf(arqtxt,"Nome                           Telefone        E-mail\n");
	fprintf(arqtxt,"==============================================================\n");
	int c;
	for(c=0;c<tamarq(arq);c++) {
		nr = l.m[c].nr;
		fseek(arq,nr*sizeof(registro),SEEK_SET);
		fread(&reg,sizeof(registro),1,arq);
		fprintf(arqtxt,"%-30s %-15s %-15s\n",reg.nome,reg.telefone,reg.email);
	}
	fprintf(arqtxt,"==============================================================\n");
	fclose(arqtxt);
	printf("Relatório gerado com sucesso.\n");
	system("pause");
}

int tamarq(FILE *arq) {
	fseek(arq,0,SEEK_END); // fseek -> posiciona a agulha no disco; arquivo arq inicializando da posição 0 indo até 59 (que é a posição do SEEK_END, a última posição da soma dos vetores);
	return ftell(arq)/sizeof(registro); // ftell -> pega o tamanho completo do arq (se for 3 registros, 3 * 60 = 180); o valor do ftell nesse caso é 180; e divide pelo sizeof(registro), que é o valor da soma de todos os vetores da struct registro, nesse caso 60;
}
