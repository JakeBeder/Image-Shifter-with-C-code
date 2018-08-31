#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>

class Source: public Image{
	private:
	
	Image image;
	
	public:
			Source(void);
	virtual	void	Execute() = 0;
	Image*		GetOutput();

};

#endif
