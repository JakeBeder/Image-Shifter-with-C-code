#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <image.h>
#include <functions.h>


void ReadImage(char *filename, Image &output)
{
	FILE* f_in = fopen(filename, "r");
	char magicNum[128];

	int width, height, maxval;

	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

	output.width = width;
	output.height = height;
	output.pixel = (Pixel*) malloc( width * height * sizeof(Pixel));

	fread(output.pixel, sizeof(Pixel), width * height, f_in);
	fclose(f_in);


}


void WriteImage( char *filename, Image &img)
{
	
	FILE* f_out;
	f_out = fopen(filename, "w");
	fprintf(f_out,"%s\n", "P6");
	fprintf(f_out,"%d ", img.width);
	fprintf(f_out,"%d\n", img.height);
	fprintf(f_out,"%d\n", 255);
	fwrite(img.pixel, sizeof(Pixel), img.width * img.height, f_out);
	fclose(f_out);
}

void HalfSize(Image &input, Image &output){
	output.width = input.width;
	output.height = input.height;
	output.pixel = (Pixel * ) malloc(output.width * output.height * sizeof(Pixel));
	for (int i = 0; i < output.height/2; i++){
		for (int j = 0; j < output.width/2; j++){
			output.pixel[i * input.width/2 + j].R= input.pixel[2*i * input.width + 2 *j].R;
			output.pixel[i * input.width/2 + j].G = input.pixel[2*i * input.width + 2 *j].G;
			output.pixel[i * input.width/2 + j].B = input.pixel[2*i * input.width + 2 *j].B;
		}	
	}
output.ResetSize(output.width/2, output.height/2);
output.maxvalue = 255;
};



void LeftRightCombine(Image &leftInput, Image &rightinput, Image &output){
	int total_width = leftInput.width + rightinput.width;
	output.pixel = (Pixel *) malloc (total_width * leftInput.height * sizeof(Pixel));
for (int i = 0; i < leftInput.height; i++){
	for (int j = 0; j < leftInput.width; j++){
		
		output.pixel[i * (total_width) + (j)].R = leftInput.pixel[i * leftInput.width + (j)].R;
		output.pixel[i * (total_width) + (j)].G = leftInput.pixel[i * leftInput.width + (j)].G;
		output.pixel[i * (total_width) + (j)].B = leftInput.pixel[i * leftInput.width + (j)].B;
	}
	for (int j = 0; j < total_width; j++){
		
		output.pixel[i * (total_width) + (j + leftInput.width)].R = rightinput.pixel[i *rightinput.width + j].R;
		output.pixel[i* (total_width)+ (j + leftInput.width)].G = rightinput.pixel[i*rightinput.width + j].G;
		output.pixel[i * (total_width) + (j + leftInput.width)].B = rightinput.pixel[i*rightinput.width + j].B;
		}
}
output.ResetSize(total_width, leftInput.height);
output.maxvalue = 255;
};


void TopBottomCombine(Image &topInput, Image &bottomInput, Image &output){
	int total_width = topInput.width *2;
	int total_height = topInput.height + bottomInput.height;
	output.pixel = (Pixel *) malloc(total_height * topInput.width * sizeof(Pixel));
	int a = topInput.width * topInput.height;
for (int i = 0; i < topInput.height; i++){
	for (int j = 0; j<topInput.width; j++){
		output.pixel[i*topInput.width + j].R = topInput.pixel[(i)*topInput.width + j].R;
		output.pixel[i*topInput.width + j].G = topInput.pixel[(i)*topInput.width + j].G;
		output.pixel[i*topInput.width + j].B = topInput.pixel[(i)*topInput.width + j].B;
		}



	for (int j = 0; j < bottomInput.width; j++){
		output.pixel[(i + topInput.height) * bottomInput.width + j].R = bottomInput.pixel[i * bottomInput.width + j].R;
		output.pixel[(i + topInput.height) * bottomInput.width + j].G = bottomInput.pixel[i * bottomInput.width + j].G;
		output.pixel[(i + topInput.height) * bottomInput.width + j].B = bottomInput.pixel[i * bottomInput.width + j].B;
}
}
	output.ResetSize(topInput.width, total_height);
	output.maxvalue = 255;
};


void Blend(Image &input1, Image &input2, double factor,Image &output){
	double  other_factor = 1 - factor;
	output.pixel = (Pixel *) malloc (input1.width * input1.height *sizeof(Pixel));

	for (int i =0; i < input1.height; i++){
		for (int j = 0; j < input1.width; j++){
			output.pixel[i * input1.width + j].R = ((input1.pixel[i*input1.width + j].R) * factor) + (input2.pixel[i*input2.width + j].R * (other_factor));
			output.pixel[i * input1.width + j].G = ((input1.pixel[i*input1.width + j].G) * factor) + (input2.pixel[i*input2.width + j].G * (other_factor));
			output.pixel[i * input1.width + j].B = ((input1.pixel[i*input1.width + j].B) * factor) + (input2.pixel[i*input2.width + j].B * (other_factor));
}
}
output.ResetSize(input1.width, input1.height);
output.maxvalue = 255;
}; 


/*
Image * YellowDiagonal(Image *input)
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
}*/
