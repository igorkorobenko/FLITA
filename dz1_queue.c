//Igor Korobenko IU4-33B

#include <stdio.h>
#include <stdlib.h>

void putIn(int ch, int* p);
int getOut(int* p);
void newEl(int n, int* p);
void view(int* p);

int start;
int fin;


int main(void){

	int n;
	printf("Size of array ");
	scanf("%d", &n);
	if (n < 1) return 0;

	int* p = (int *) calloc(sizeof(int), n);

	start = n;
	fin = n;

	int c;

	printf("1 - new element of queue\n");
	printf("2 - out one\n");
	printf("3 - view all queue\n");
	printf("4 - quit\n");

	while(1){
		printf("\n");
		
		printf("choice: ");
		scanf("%d", &c);
		
		switch (c) {
			case 1:
			newEl(n, p);
			break;

			case 2:
			printf("%d\n", getOut(p));
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

void newEl(int n, int* p){
	int ch;
	printf("Put in queue: ");
	scanf("%d", &ch);
	putIn(ch, p);
}

void view(int* p){
	for(int i = start; i > fin; i--){
		printf("%d ", p[i]);
	}
	putchar('\n');
}


void putIn(int ch, int* p){
	if(fin < 0){
		printf("Queue is full\n");
	} else {

	p[fin] = ch;
	fin--;

    }
}

int getOut(int* p){
	if(start == fin){
		printf("Queue is empty\n");
		return 0;
	}
	start--;
	return p[start + 1];
}