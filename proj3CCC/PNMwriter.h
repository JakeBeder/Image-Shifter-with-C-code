#ifndef PNMWRITER_H
#define PNMWRITER_H
#include <image.h>
#include <sink.h>


class PNMwriter:public Sink{
private:
	char*	filename;

public:

		PNMwriter(void);
		
	void	Write(char* Filename);



};


#endif
