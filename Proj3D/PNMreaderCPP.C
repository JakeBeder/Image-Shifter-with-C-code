#include <PNMreaderCPP.h>
#include <source.h>
#include <image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
//learned more about iostreams from www.tutorialspoint.com/cplusplus/cpp_files_streams.htm

using std::cout;
using std::endl;
using std::cerr;
using namespace std;


PNMreaderCPP::PNMreaderCPP(char* fileName){
/*	int leng = strlen(fileName);
	filename = (char*) malloc(sizeof(leng) +1);
	strcpy(filename, fileName); 
*/	filename = new char[strlen(fileName) + 1];
	strcpy(filename, fileName);

	

};

PNMreaderCPP::~PNMreaderCPP(void){
	delete [ ](filename);
	
};


void PNMreaderCPP::Execute(){
	Image* output = GetOutput();
	ifstream f_in;
	f_in.open(filename, ios::in);
	char magicNum[128];
	int width, height, maxval;
	Pixel* pix;
	f_in >> magicNum;
	f_in >> width; 
	f_in >> height;
	f_in  >> maxval;
	//fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	pix = (Pixel*) malloc(width * height * sizeof(Pixel));
	output->ResetSize(width, height);
	output->setMaxvalue(255);
	//f_in.ignore();
	f_in.read((char *)pix, sizeof(Pixel) * output->getWidth() * output->getHeight());
	output->setPixel(pix);
	f_in.close();
};

