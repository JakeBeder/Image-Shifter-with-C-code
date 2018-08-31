#include <source.h>
#include <logging.h>
Source::Source(void){};

Image* Source::GetOutput(){
	return &image;
}

void 	Source::Update(){
	char msg [128];
	sprintf(msg, "%s: about to execute", SourceName());
	Logger::LogEvent(msg);
	Execute();
	sprintf(msg, "%s: done executing", SourceName());
	Logger::LogEvent(msg);
	};
