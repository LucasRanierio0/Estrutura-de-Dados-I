#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "listas.h"

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	lista l1;
	
	linit(&l1);
	
	lins(&l1,'b');
	lins(&l1,'m');
	lins(&l1,'d');
	lins(&l1,'a');
	lins(&l1,'p');
	lins(&l1,'c');
	lins(&l1,'d');
	
	lmostra(&l1);
	
	return 1;
}
