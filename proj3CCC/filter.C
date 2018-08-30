#include <filter.h>
#include <image.h>
#include <sink.h>
#include <source.h>
#include <PNMreader.h>


void Shrinker::Execute(){
	Image* output = GetOutput();
	Image * input = getInput();
	output->setMaxvalue(255);
	output->ResetSize(input->getWidth()/2, input->getHeight()/2);
	Pixel* pix = (Pixel*) malloc (input->getWidth()/2 * input->getHeight()/2 * sizeof(Pixel));
	for (int i = 0; i < output->getHeight(); i++){
		for (int j = 0; j < output->getWidth(); j++){
			pix[i * input->getWidth()/2 + j].R= input->getPixel()[2*i * input->getWidth() + 2 *j].R;
			pix[i * input->getWidth()/2 + j].G = input->getPixel()[2*i * input->getWidth() + 2 *j].G;
			pix[i * input->getWidth()/2 + j].B = input->getPixel()[2*i * input->getWidth() + 2 *j].B;
		};
	}
output->setPixel(pix);
};


void LRCombine::Execute(){
	Image*	input = getInput();
	Image*	input2 = getInput2();
	Image*	output = GetOutput();
//	int x = input->getWidth();
//	int y = input2->getWidth();
	int total_width = input->getWidth() + input2->getWidth();
	Pixel* pix = (Pixel *) malloc (total_width * input->getHeight() * sizeof(Pixel));
for (int i = 0; i < input->getHeight(); i++){
	for (int j = 0; j < input->getWidth(); j++){
		
		pix[i * (total_width) + (j)].R = input->getPixel()[i * input->getWidth() + (j)].R;
		pix[i * (total_width) + (j)].G = input->getPixel()[i * input->getWidth() + (j)].G;
		pix[i * (total_width) + (j)].B = input->getPixel()[i * input->getWidth() + (j)].B;
	}
	for (int j = 0; j < total_width; j++){
		
		pix[i * (total_width) + (j + input->getWidth())].R = input2->getPixel()[i *input2->getWidth() + j].R;
		pix[i* (total_width)+ (j + input->getWidth())].G = input2->getPixel()[i*input2->getWidth() + j].G;
		pix[i * (total_width) + (j + input->getWidth())].B = input2->getPixel()[i*input2->getWidth() + j].B;
		}
}
output->ResetSize(total_width, input->getHeight());
output->setMaxvalue(255);
output->setPixel(pix);
};


void TBCombine::Execute(){
	Image* output = GetOutput();
	Image* input = getInput();
	Image* input2 = getInput2();
	int total_height = input->getHeight() + input2->getHeight();
	output->ResetSize(input->getWidth(), total_height);
	output->setMaxvalue(255);
	Pixel* pix = (Pixel*) malloc (output->getWidth() * output->getHeight() * sizeof(Pixel));
for (int i = 0; i < input->getHeight(); i++){
	for (int j = 0; j<input->getWidth(); j++){
		pix[i*input->getWidth() + j].R = input->getPixel()[(i)*input->getWidth() + j].R;
		pix[i*input->getWidth() + j].G = input->getPixel()[(i)*input->getWidth() + j].G;
		pix[i*input->getWidth() + j].B = input->getPixel()[(i)*input->getWidth() + j].B;
		}



	for (int j = 0; j < input2->getWidth(); j++){
		pix[(i + input->getHeight()) * input2->getWidth() + j].R = input2->getPixel()[i * input2->getWidth() + j].R;
		pix[(i + input->getHeight()) * input2->getWidth() + j].G = input2->getPixel()[i * input2->getWidth() + j].G;
		pix[(i + input->getHeight()) * input2->getWidth() + j].B = input2->getPixel()[i * input2->getWidth() + j].B;
}
}

output->setPixel(pix);
};


void Blender::SetFactor(double fact){
factor = fact; 

};

void Blender::Execute(){
	Image* output = GetOutput();
	Image* input = getInput();
	Image* input2 = getInput2();
	double  other_factor = 1 - factor;
	output->ResetSize(input->getWidth(), input->getHeight());
	output->setMaxvalue(255);
	Pixel* pix = (Pixel*) malloc (output->getWidth() * output->getHeight() * sizeof(Pixel));

	for (int i =0; i < input->getHeight(); i++){
		for (int j = 0; j < input->getWidth(); j++){
			pix[i * input->getWidth() + j].R = ((input->getPixel()[i*input->getWidth() + j].R) * factor) + (input2->getPixel()[i*input2->getWidth() + j].R * (other_factor));
			pix[i * input->getWidth() + j].G = ((input->getPixel()[i*input->getWidth() + j].G) * factor) + (input2->getPixel()[i*input2->getWidth() + j].G * (other_factor));
			pix[i * input->getWidth() + j].B = ((input->getPixel()[i*input->getWidth() + j].B) * factor) + (input2->getPixel()[i*input2->getWidth() + j].B * (other_factor));
}
}

output->setPixel(pix);


};
