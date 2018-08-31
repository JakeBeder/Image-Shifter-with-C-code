#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef IMAGE_H
#define IMAGE_H

class Pixel{
public:
	unsigned char 	R;
	unsigned char 	G;
	unsigned char 	B;
};

class Source;

class Image: public Pixel
{

private:
	int 	height, width, maxvalue;
	Pixel 	*pixel;
	Source* s;
public:
		Image(void);
		Image(int width, int height, int maxvalue, Pixel * pixel);
		Image (Image &);
		~Image();
	void	ResetSize(int width, int height);
	void	setMaxvalue(int x);
	void 	setPixel(Pixel* pixel);
	int 	getHeight(){ return height;};
	int 	getWidth(){return width;};
	int	getMaxvalue(){return maxvalue;};
	Pixel*	getPixel(){return pixel;};
	void	setSource(Source*);
	void 	Update();
	Source*	getSource(){return s;};
};

#endif
