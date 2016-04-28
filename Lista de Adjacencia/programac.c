#include <stdio.h>
#include <stdlib.h>


/*
*	Esse programa implementa uma solução de lista de adjacência 
*   e utiliza o BFS para realizar a busca em largura.
*	Autor: Antonio Ricardo Alexandre Brasil
*   Sistemas de Informação, IFES Serra
*/

#define TOTAL_NOS  6
#define COR_PRETA  0
#define COR_CINZA  1
#define COR_BRANCA 2

struct no {
	int id;
	int cor;
	int dist;
	struct no* prox;
};
typedef struct no No;

struct pilha {
	No* no;
};
typedef struct pilha Pilha;

No* cria(){
	return NULL;
}

No* inicializa(int id) {
	No* novo = (No*) malloc(sizeof(No));
	novo->id = id;
	novo->cor = COR_BRANCA;
	novo->prox = NULL;
	return novo;
}

void insere(No* pai, int v){
	No* filho = (No*) malloc(sizeof(No));
	filho->id = v;
	filho->prox = NULL;
	if(pai->prox == NULL) {
		pai->prox = filho;
	} else {
		No* vertice = pai;
		No* temp;
		while(vertice != NULL){
			temp = vertice;
			vertice = vertice->prox;
		}
		temp->prox = filho;
	}
	printf("Inserindo no pai: %d o filho: %d\n", pai->id, v);
}

void printa(No* n){
	printf("%d\n", n->id);
}


void printa_filho(No* n) {

	if(n == NULL)
		return;	
	
	printf("%d ", n->id);
	printa_filho(n->prox);
}

void printa_pai(No* n) {
	if(n == NULL)
		return;
	
	printf("Pai: %d ", n->id);
	printf("Filho(s): ");
	printa_filho(n->prox);
	printf("\n");
}


void BFS(No** lista, int no_inicial){
	if( no_inicial < 0 || no_inicial > TOTAL_NOS) {
		return printf("No inicial nao pode exceder o tamanho %d total de nos.",TOTAL_NOS);
	}
		
	No* s = lista[no_inicial];
	No* aux;
	int i=0;
	for(; i< TOTAL_NOS; i++){		
		aux = lista[i];
		if(aux->id != no_inicial) {
			aux->cor = COR_BRANCA;
			aux->dist = NULL;
		}
	}
	s->cor = COR_CINZA;
	s->dist = 0;
	// Tem que criar a pilha
		
	
	
	
}




int main() {
	No** lista = (No**) malloc(sizeof(No*));
	
	int i = 0;
	
	for (i = 0; i < TOTAL_NOS; i++ ){
		lista[i] = inicializa(i+1);		
	}
	
	for (i = 0; i < TOTAL_NOS; i++){
		printa(lista[i]);
	}
	
	insere(lista[0], 2);
	insere(lista[0], 4);
		
	insere(lista[1], 5);
	
	insere(lista[2], 6);
	insere(lista[2], 5);
	
	insere(lista[3], 2);
	
	insere(lista[4], 4);

	insere(lista[5], 6);

	for (i = 0; i < TOTAL_NOS; i++ ){
		printa_pai(lista[i]);
	}	
	
	BFS(lista, 0);
	
	free(lista);
	
	return 0;
}











