#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
FILE *bin_file_in, *file_out;
int *buffer;

if (argc != 3){
	printf("Usage: %s <file1> <file2>\n", argv[0]);
	exit(EXIT_FAILURE);
}

bin_file_in = fopen(argv[1], "r");
file_out = fopen(argv[2], "w");
int buff_size = 25;

fseek(bin_file_in, 0, SEEK_SET);
buffer = malloc(sizeof(int) * 25);


for (int i = 0;i < 5; i++){
	
	fread(buffer, sizeof(int),5 , bin_file_in);
	for(int j = 0; j < 1; j++){
		fprintf(file_out, "%d\n", buffer[j]);
		fprintf(file_out, "%d\n", buffer[j+1]);
		fprintf(file_out, "%d\n", buffer[j+2]);
		fprintf(file_out, "%d\n", buffer[j+3]);
		fprintf(file_out, "%d\n", buffer[j+4]);
		/* Figured out a way to incorporate loop
		unrolling :D */
	}

	fseek(bin_file_in, 20, SEEK_CUR);
	
}

free(buffer);
fclose(bin_file_in);
fclose(file_out);

return 0;

}

