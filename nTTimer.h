#ifndef _NTTIMER_
#define _NTTIMER_

#include <stdio.h>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

struct nTTimer{
	private:
	static const int _nTnano=1;
	static const int _nTmicro=1000;
	static const int _nTmili=1000000;
	static const int _nTsec=1000000000;

	int scale=_nTmili;

	string name="";
	unsigned long _start=0;
	unsigned long _end=0;
	bool started=false;
	public:
	void start(string codeName){
		name=codeName;
		started=true;
		_start=high_resolution_clock::now().time_since_epoch().count();
	}

	void start(){
		started=true;
		_start=high_resolution_clock::now().time_since_epoch().count();
	}

	void end(){
		_end=high_resolution_clock::now().time_since_epoch().count();
		started=false;
	}

	void run(){
		if(started){
			_end=high_resolution_clock::now().time_since_epoch().count();
			started=false;
		}else{
			started=true;
			_start=high_resolution_clock::now().time_since_epoch().count();
		}
	}

	void run(string codeName){
		name=codeName;
		if(started){
			_end=high_resolution_clock::now().time_since_epoch().count();
			started=false;
		}else{
			started=true;
			_start=high_resolution_clock::now().time_since_epoch().count();
		}
	}

	void print(){
		printf("Time for %-15s: %10ld (s/%d)",name.c_str(),count(),(1000000000/scale));
	}

	unsigned long count(){
		return (_end-_start)/scale;
	}

};
#endif