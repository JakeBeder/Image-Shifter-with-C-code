#include <PNMreader.h>
#include <source.h>
#include <image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <logging.h>
PNMreader::PNMreader(char* fileName){
	filename = new char[strlen(fileName) + 1];
	strcpy(filename, fileName);
	GetOutput()->setSource(this);
	

};

PNMreader::~PNMreader(void){
	delete [ ](filename);
	
};


void PNMreader::Execute(){
	Image* output = GetOutput();
	FILE* f_in = fopen(filename, "rb");
	char magicNum[128];
	int width, height, maxval;
	Pixel* pix;
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	pix = (Pixel*) malloc(width * height * sizeof(Pixel));
	output->ResetSize(width, height);
	output->setPixel(pix);
	output->setMaxvalue(255);
	fread(pix, sizeof(Pixel), output->getWidth() * output->getHeight(), f_in);
	fclose(f_in);
};


void PNMreader::Update(){
	char msg[128];
	sprintf(msg, "PNMreader: about to execute");
	Logger::LogEvent(msg);
	Execute();	
	sprintf(msg, "PNMreader: done executing");
	Logger::LogEvent(msg);

};
