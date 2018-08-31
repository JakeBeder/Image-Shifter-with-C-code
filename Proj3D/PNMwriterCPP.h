#ifndef PNMWRITERCPP_H
#define PNMWRITERCPP_H
#include <image.h>
#include <sink.h>


class PNMwriterCPP:public Sink{
private:
	char*	filename;

public:

		PNMwriterCPP(void);
		
	void	Write(char* Filename);



};


#endif
