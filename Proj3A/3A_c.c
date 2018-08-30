#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Got some code from starter code and YouTube lecture 9 */

typedef struct{
	unsigned char R;
	unsigned char G;
	unsigned char B;
} Pixel;


typedef struct
{	
	char *buffer;
	int height, width;
	Pixel *pixel;
} Image;



Image * ReadImage(char *filename)
{
	FILE* f_in = fopen(filename, "r");
	char magicNum[128];

	int width, height, maxval;

	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

	Image *image = malloc (sizeof(Image));
	image ->width = width;
	image ->height = height;
	image ->pixel = malloc(width * height * sizeof(Pixel));

	fread(image->pixel, sizeof(Pixel), width * height, f_in);
	fclose(f_in);
	return image;


}


void WriteImage(Image *img, char *filename)
{
	
	FILE* f_out;
	f_out = fopen(filename, "w");
	fprintf(f_out,"%s\n", "P6");
	fprintf(f_out,"%d ", img->width);
	fprintf(f_out,"%d\n", img->height);
	fprintf(f_out,"%d\n", 255);
	fwrite(img->pixel, sizeof(Pixel), img->width * img->height, f_out);
	fclose(f_out);
}

Image *
YellowDiagonal(Image *input)
{
	Image* copyImage = malloc(sizeof(Image));
	copyImage->width = input->width;
	copyImage->height = input->height;
	copyImage->pixel = malloc(input->width * input->height*sizeof(Pixel));
	memcpy(copyImage->pixel, input->pixel, input->width * input->height* sizeof(Pixel));
	for (int i = 0; i < copyImage -> width; i++){
		for (int j = 0; j < copyImage ->height; j++){
			if (i == j){
				copyImage ->pixel[i * copyImage->width + j].R = 255;
				copyImage ->pixel[i * copyImage->width + j].G = 255;
				copyImage ->pixel[i * copyImage->width + j].B = 0;
				}
			}
		}
	return copyImage;
}

int main(int argc, char *argv[])
{
	Image* x;
	Image*y;
	if (argc !=3) {
		printf("Usage %s <file1> <file2>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	x = ReadImage(argv[1]);	
	y = YellowDiagonal(x);
	WriteImage(y, argv[2]);
	free(y->pixel);
	free(y);
	free(x->pixel);
	free(x);

	return 0;
}
