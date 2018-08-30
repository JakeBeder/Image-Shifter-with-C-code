#include <PNMwriter.h>
#include <image.h>

PNMwriter::PNMwriter(void){};

void PNMwriter::Write(char* filename){
	Image*	writer_input = getInput();
	FILE* f_out;
	f_out = fopen(filename, "w");
	fprintf(f_out,"%s\n", "P6");
	fprintf(f_out,"%d ", writer_input->getWidth());
	fprintf(f_out,"%d\n", writer_input->getHeight());
	fprintf(f_out,"%d\n", 255);
	fwrite(writer_input->getPixel(), sizeof(Pixel), writer_input->getWidth() * writer_input->getHeight(), f_out);
	fclose(f_out);



};  
