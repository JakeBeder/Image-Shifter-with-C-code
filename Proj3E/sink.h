#ifndef SINK_H
#define SINK_H
#include <image.h>
class Sink{

protected:
	Image* input;
	Image* input2;

public:
		Sink(void);
	void	SetInput(Image *Input1);
	void	SetInput2(Image *Input2);
	Image* getInput() {return input;};
	Image* getInput2() {return input2;};
};

#endif
