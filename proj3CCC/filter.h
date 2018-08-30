#ifndef FILTER_H
#define FILTER_H
#include <image.h>
#include <sink.h>
#include <source.h>
#include <PNMreader.h>
class Filter: public Sink, public Source{

public:

	virtual void 	Execute() = 0;

};

class Shrinker: public Filter{

public:
	virtual void 	Execute();	

	
};

class LRCombine: public Filter{

public:
	virtual void 	Execute();
};

class TBCombine: public Filter{


public:
	virtual void	Execute();
};

class Blender: public Filter{
private:
	double factor;
public:
	void SetFactor(double fact);
	virtual void Execute();
};
#endif
