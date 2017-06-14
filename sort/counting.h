#ifndef _NTCOUNTING
#define _NTCOUNTING
#include "../nTVector.h"

void countingSort(nTVector *v){
	nTVector *count=new nTVector;
	nTVector *sort=new nTVector;
	v->copyTo(sort);
	count->alloc(v->randMax-v->randMin+1);
	for(int i=0;i<count->getSize();i++)
		count->set(i,0);
	for(int i=0;i<sort->getSize();i++)
		count->add(sort->at(i),1);
	for(int i=1;i<count->getSize();i++)
		count->add(i,count->at(i-1));
	for(int i=0;i<sort->getSize();i++){
		nTtype at=sort->at(i);
		v->set(count->at(at)-1,at);
		count->add(at,-1);
	}
	count->dispose();
	sort->dispose();
}
#endif