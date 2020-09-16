//Igor Korobenko IU4-33B

#include <stdio.h>
#include <stdlib.h>

void PutIn(int ch, int* p);
int GetOut(int* p);
void newel(int N,int* p);
void view(int* p);

int start;
int fin;


int main(void){

	int N;
	printf("Size of array ");
	scanf("%d", &N);
	if (N < 1) return 0;

	int* p = calloc(sizeof(int), N);

	start = N;
	fin = N;

	int c;

	printf("1 - new element of queue\n");
	printf("2 - out one\n");
	printf("3 - view all queue\n");
	printf("4 - quit\n");

	for(;;){
		printf("\n");
		
		printf("choice: ");
		scanf("%d", &c);
		
		switch (c) {
			case 1:
			newel(N, p);
			break;

			case 2:
			printf("%d\n", GetOut(p));
			break;

			case 3:
			view(p);
			break;

			case 4:
			return 0;
			break;
		}
	}
}

void newel(int N,int* p){
	int ch;
	printf("Put in queue: ");
	scanf("%d", &ch);
	PutIn(ch, p);
}

void view(int* p){
	for(int i = start; i > fin; i--){
		printf("%d ", p[i]);
	}
	putchar('\n');
}


void PutIn(int ch, int* p){
	if(fin<0){
		printf("Queue is full\n");
	} else {

	p[fin] = ch;
	fin--;

    }
}

int GetOut(int* p){
	if(start == fin){
		printf("Queue is empty\n");
		return 0;
	}
	start--;
	return p[start + 1];
}