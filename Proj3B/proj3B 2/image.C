#include <image.h>

Image::Image(void){
	height = 0;
	width = 0;
	maxvalue = 0;
	pixel = (Pixel*) malloc (width * height * sizeof(Pixel));
};
Image::Image(int wid, int heit, int maxval, Pixel * pix){
	height = heit;
	width = wid;
	maxvalue = maxval;
	pixel  = pix;
};
Image::Image(Image &i){
	height = i.height;
	width = i.width;
	maxvalue = i.maxvalue;
	pixel = i.pixel;	

};

void Image::ResetSize(int wid, int heit){
	width = wid;
	height = heit;
};
