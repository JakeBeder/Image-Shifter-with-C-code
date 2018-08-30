#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef IMAGE_H
#define IMAGE_H

struct Pixel{
public:
	unsigned char 	R;
	unsigned char 	G;
	unsigned char 	B;
};


struct Image
{
public:
		Image(void);
		Image(int width, int height, int maxvalue, Pixel * pixel);
	int 	height, width, maxvalue;
	Pixel 	*pixel;
	void	ResetSize(int width, int height);
		Image(Image &);
};

#endif
