#ifndef PNMREADER_H
#define PNMREADER_H
#include <image.h>
#include <source.h>
class PNMreader: public Source
{
private:

 char* filename;


public:

			PNMreader(char* filename);
			~PNMreader(void);

	virtual void	Execute(void);
};

#endif
