#ifndef FILTER_H
#define FILTER_H
#include <image.h>
#include <sink.h>
#include <source.h>
#include <PNMreader.h>
class Filter: public Sink, public Source{

public:

	virtual void 	Execute() = 0;
	virtual void 	Update() = 0;
};

class Shrinker: public Filter{
private:
	bool trueupdate;
public:
			Shrinker(void);
	virtual void 	Execute();	
	virtual void	Update();
	void setUpdateTrue(){ trueupdate = 0;};
};

class LRCombine: public Filter{
private:
	bool trueupdate;
public:
			LRCombine(void);
	virtual void 	Execute();
	virtual void	Update();

	void setUpdateTrue(){ trueupdate = 0;};
};

class TBCombine: public Filter{
private:
	bool trueupdate;

public:

			TBCombine(void);
	virtual void	Execute();
	virtual void	Update();
	void setUpdateTrue(){ trueupdate = 0;};

};

class Blender: public Filter{
private:
	bool trueupdate;
	double factor;
public:
			Blender(void);
	void 		SetFactor(double fact);
	virtual void 	Execute();
	virtual void 	Update();
	
	void setUpdateTrue(){ trueupdate = 0;};
};
#endif
