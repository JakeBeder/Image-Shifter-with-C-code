#include <fstream>
#include <PNMwriterCPP.h>
#include <image.h>
#include <iostream>
using namespace std;
PNMwriterCPP::PNMwriterCPP(void){};

void PNMwriterCPP::Write(char* filename){
	Image*	writer_input = getInput();
	//FILE* f_out;
	ofstream f_out;
	f_out.open(filename);
	f_out<< "P6\n" << writer_input->getWidth() << " " <<  writer_input->getHeight() << "\n" << 255 << endl;
/*	fprintf(f_out,"%s\n", "P6");
	fprintf(f_out,"%d ", writer_input->getWidth());
	fprintf(f_out,"%d\n", writer_input->getHeight());
	fprintf(f_out,"%d\n", 255);
	fwrite(writer_input->getPixel(), sizeof(Pixel), writer_input->getWidth() * writer_input->getHeight(), f_out);
*/	
	f_out.write((char *) writer_input->getPixel(), sizeof(Pixel) * writer_input->getWidth() * writer_input->getHeight());
	f_out.close(); 


};  
