#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getarr_f(void){
    int n = 1;
    char *arr;
    char c;
    arr = calloc(n + 1, sizeof(char));
    int i = 0;

    while((c = getchar()) != '\n'){
        if( ('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')){
            char *temp_arr;
            n++;
            temp_arr = calloc(n + 1, sizeof(char));
            
            for(int j = 0; j < n - 1; j++){
                temp_arr[j] = arr[j];
            }
            temp_arr[n-1] = c;

            free(arr);
            arr = temp_arr;
        }
    }
    arr[n-1]='\0';
    return arr;
}


int main(void){

	int bg;
	printf("0 - for graph\n");
	printf("1 - for digraph\n");
	scanf("%d", &bg);

	int n;
	printf("Num of elements: ");
	scanf("%d", &n);

	while(n < 0){
        printf("Num > 0 !\n");
        scanf("%d",&n);
        printf("\n");
    }

	int mtx[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mtx[i][j] = 0;
		}
	}

	char* names[n];

	printf("Fill the names of elements\n");

	for (int i = 0; i < n; i++){
		printf("#%d ", i + 1);
		names[i] = getarr_f();
		printf("\n");

		for (int j = 0; j < i; j++){
			if(strcmp(names[n], names[j]) == 0){
				printf("There are similar elements, enter another...\n");
                i--;
			}
		}
	}

	printf("Names:\n");
	for (int i = 0; i < n; i++){
		printf("#%d: %s\n", i + 1, names[i]);
	}
	putchar('\n');

	printf("Connections\n");

	printf("Example:\n");
	printf("lol;\n");
	printf("ye;\n\n");

	for (int i = 0; i < n; i++){
		printf("#%d: %s\n", i + 1, names[i]);
		_Bool flag = 1;

		while(flag){
			char* cmp_sting;
			cmp_sting = getarr_f();

			for(int j = 0; j < n; j++){
				if (strcmp(names[j], cmp_sting) == 0){
					mtx[i][j]++;
				}
			}

			if(strcmp(cmp_sting, "") == 0){
				flag = 0;
			}

			free(cmp_sting);
		}	
	}

	// проверка на связанность графа (крест)

	_Bool goriz = 1;
	for(int i = 0; i < n; i++){
		_Bool vertic = 0;
		for(int j = 0; j < n; j++){
			if(mtx[i][j] > 0)
				vertic = 1;

			if(mtx[j][i] > 0)
				vertic = 1;
		}
		if (vertic == 0)
			goriz = 0;
	}
	if (!goriz){
		printf("Unrelated graph\n");
	}
	else {
		printf("Related graph\n");
	}

	for(int i = 0; i < n; i++){
		printf("#%d %20s: ", i + 1, names[i]);
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				printf("%d\n", mtx[i][j]);
			}
		}
	}

	char* arr = calloc(1000, sizeof(char));
	if(bg == 1){
		strcpy(arr, "digraph{");
	}
	else {
		strcpy(arr, "greph{");
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mtx[i][j] == 1){
				for(int a; a < j; a++){
					strcpy(arr, names[i]);
					if(bg == 1){
						strcpy(arr, "->");
					}
					else if(bg == 0){
						strcpy(arr, "--");
					}
				}
				strcpy(arr, names[j]);
			}
		}
	}
	strcpy(arr, "}");
	system(arr);
	free(arr);

}