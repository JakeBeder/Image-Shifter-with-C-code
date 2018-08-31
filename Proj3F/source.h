#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>

class Source: public Image{
	
	protected:
	Image image;
	virtual void Execute() = 0;	
	public:
			Source(void);
	Image*		GetOutput();
	virtual void Update();
	virtual const char *SourceName() = 0;
};

#endif
