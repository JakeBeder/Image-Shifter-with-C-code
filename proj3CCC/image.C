#include <image.h>

Image::Image(void){
	ResetSize(0,0);
	setMaxvalue(0);;
	width = 0;
	maxvalue = 0;
	pixel = (Pixel*) malloc (width * height * sizeof(Pixel));
};
Image::Image(int wid, int heit, int maxval, Pixel * pix){
	ResetSize(wid, heit);
	setMaxvalue(maxval);
	setPixel(pix);
};
Image::Image(Image &i){
	ResetSize(i.width, i.height);
	setMaxvalue(i.maxvalue);
	setPixel(i.pixel);

};
Image::~Image(){
	free(pixel);
};

void 	Image::ResetSize(int wid, int heit){
	this->width = wid;
	this->height = heit;
};
void 	Image::setMaxvalue(int mv){
	this->maxvalue = mv;
};

void 	Image::setPixel(Pixel* pix){
	this->pixel = pix;
};

