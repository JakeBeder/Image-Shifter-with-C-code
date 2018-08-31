#include <filter.h>
#include <logging.h>
#include <image.h>
#include <sink.h>
#include <source.h>
#include <PNMreader.h>

	Shrinker::Shrinker(){
	
	GetOutput()->setSource(this);
};

void	Shrinker::Update(){
	char msg[128];	
	if (getInput() != NULL){
	sprintf(msg, "Shrinker: about to update input1");
	Logger::LogEvent(msg);
	getInput()->Update();
	sprintf(msg, "Shrinker: done updating input1");
	Logger::LogEvent(msg);
	}
	sprintf(msg, "Shrinker: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Shrinker: done executing");
	Logger::LogEvent(msg);
};

void 	Shrinker::Execute(){
	char msg[128];
	Image* output = GetOutput();
	Image * input = getInput();

	if(input== NULL){
	sprintf(msg, "Shrinker: no input1!");
	DataFlowException e (SinkName(), msg);
	throw e;
	}


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
	LRCombine::LRCombine(){
	GetOutput()->setSource(this);
};





void 	LRCombine::Update(){
	char msg[128];	
	if (getInput() != NULL){
	sprintf(msg, "LRCombine: about to update input1");
	Logger::LogEvent(msg);	
	getInput()->Update();
	sprintf(msg, "LRCombine: done updating input1");
	Logger::LogEvent(msg);
	}
	if( getInput2() != NULL){
	sprintf(msg, "LRCombine: about to update input2");
	Logger::LogEvent(msg);
	getInput2()->Update();
	sprintf(msg, "LRCombine: done updating input2");
	Logger::LogEvent(msg);
	}
	sprintf(msg, "LRCombine: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "LRCombine: done executing");
	Logger::LogEvent(msg);
};

void 	LRCombine::Execute(){
	char msg[128];
	Image*	input = getInput();
	Image*	input2 = getInput2();
	Image*	output = GetOutput();
	
	if(input== NULL){
	sprintf(msg, "LRCombine: no input1!");
	DataFlowException e (SinkName(), msg);
	throw e;
	}

	if(input2== NULL){
	sprintf(msg, "LRCombine: no input2!");
	DataFlowException e (SinkName(), msg);
	throw e;
	}

	if(input->getHeight() != input2->getHeight()){
	sprintf(msg, "%s: heights must match: %d, %d", SinkName(), input->getHeight(), input2->getHeight());
	DataFlowException e(SinkName(),msg);
	throw e;
	}
	
	int total_width = input->getWidth() + input2->getWidth();
	Pixel* pix = (Pixel *) malloc (total_width * input->getHeight() * sizeof(Pixel));
for (int i = 0; i < input->getHeight(); i++){
	for (int j = 0; j < input->getWidth(); j++){
		
		pix[i * (total_width) + (j)].R = input->getPixel()[i * input->getWidth() + (j)].R;
		pix[i * (total_width) + (j)].G = input->getPixel()[i * input->getWidth() + (j)].G;
		pix[i * (total_width) + (j)].B = input->getPixel()[i * input->getWidth() + (j)].B;
	}
	for (int j = 0; j < input2->getWidth(); j++){
		
		pix[i * (total_width) + (j + input->getWidth())].R = input2->getPixel()[i *input2->getWidth() + j].R;
		pix[i* (total_width)+ (j + input->getWidth())].G = input2->getPixel()[i*input2->getWidth() + j].G;
		pix[i * (total_width) + (j + input->getWidth())].B = input2->getPixel()[i*input2->getWidth() + j].B;
		}
}
output->ResetSize(total_width, input->getHeight());
output->setMaxvalue(255);
output->setPixel(pix);
};

	TBCombine::TBCombine(){
      	GetOutput()->setSource(this);

}


void 	TBCombine::Update(){

	char msg[128];	
	if (getInput() != NULL){
	sprintf(msg, "Blender: about to update input1");
	Logger::LogEvent(msg);	
	getInput()->Update();
	sprintf(msg, "Blender: done updating input1");
	Logger::LogEvent(msg);
	}
	if( getInput2() != NULL){
	sprintf(msg, "Blender: about to update input2");
	Logger::LogEvent(msg);
	getInput2()->Update();
	sprintf(msg, "Blender: done updating input2");
	Logger::LogEvent(msg);
	}
	sprintf(msg, "Blender: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Blender: done executing");
	Logger::LogEvent(msg);
};


/*

void Filter::Update()
{

	if(getInput() != NULL){
		getInput() -> Update();
	}
	if(getInput2() != NULL){
		getInput2() ->Update();
	}

	this->Execute();
  //Update input image 1 : call Update on (getInput)
  //Update input image 2: call Update on (getInput2)
 //then call this->Execute

};


*/


void 	TBCombine::Execute(){
	char msg[128];
	Image* output = GetOutput();
	Image* input = getInput();
	Image* input2 = getInput2();
	int total_height = input->getHeight() + input2->getHeight();
	
	if(input== NULL){
	sprintf(msg, "TBCombine: no input1!");
	DataFlowException e (SinkName(), msg);
	throw e;
	}

	if(input2== NULL){
	sprintf(msg, "TBCombine: no input2!");
	DataFlowException e (SinkName(), msg);
	throw e;
	}

	if(input->getHeight() != input2->getHeight()){
	sprintf(msg, "%s: heights must match: %d, %d", SinkName(), input->getHeight(), input2->getHeight());
	DataFlowException e(SinkName(),msg);
	throw e;
	}

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

	Blender::Blender(){
	GetOutput()->setSource(this);
};


void 	Blender::Update(){
	char msg[128];	
	if (getInput() != NULL){
	sprintf(msg, "Blender: about to update input1");
	Logger::LogEvent(msg);	
	getInput()->Update();
	sprintf(msg, "Blender: done updating input1");
	Logger::LogEvent(msg);
	}
	if( getInput2() != NULL){
	sprintf(msg, "Blender: about to update input2");
	Logger::LogEvent(msg);
	getInput2()->Update();
	sprintf(msg, "Blender: done updating input2");
	Logger::LogEvent(msg);
	}
	sprintf(msg, "Blender: about to execute");
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "Blender: done executing");
	Logger::LogEvent(msg);
};


void 	Blender::SetFactor(double fact){
factor = fact; 

};

void 	Blender::Execute(){
	char msg[128];
	Image* output = GetOutput();
	Image* input = getInput();
	Image* input2 = getInput2();


	if(input== NULL){
	sprintf(msg, "Blender: no input1!");
	DataFlowException e (SinkName(), msg);
	throw e;
	}

	if(input2== NULL){
	sprintf(msg, "Blender: no input2!");
	DataFlowException e (SinkName(), msg);
	throw e;
	}

	if(input->getHeight() != input2->getHeight()){
	sprintf(msg, "%s: heights must match: %d, %d", SinkName(), input->getHeight(), input2->getHeight());
	DataFlowException e(SinkName(),msg);
	throw e;
	}

	if(input->getWidth() != input2->getWidth()){
	sprintf(msg, "%s: heights must match: %d, %d", SinkName(), input->getWidth(), input2->getWidth());
	DataFlowException e(SinkName(),msg);
	throw e;
	}
	
	if(factor >1){
	sprintf(msg, "Invalid factor for Blender: %f",factor);
	DataFlowException e(SinkName(), msg);
	throw e;
	}
	if (factor < 0){
	sprintf(msg, "Invalid factor for Blender: %f", factor);
	DataFlowException e(SinkName(), msg);
	throw e;
	}

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
