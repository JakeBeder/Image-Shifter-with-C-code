#ifndef PNMREADERCPP_H
#define PNMREADERCPP_H
#include <image.h>
#include <source.h>
class PNMreaderCPP: public Source
{
private:

 char* filename;


public:

			PNMreaderCPP(char* filename);
			~PNMreaderCPP(void);

	virtual void	Execute(void);
};

#endif
