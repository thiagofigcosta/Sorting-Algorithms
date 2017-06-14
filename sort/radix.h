#ifndef _NTRADIX
#define _NTRADIX
#include "../nTVector.h"

void radixSort(nTVector *v){
	nTVector *count=new nTVector;
	nTVector *sort=new nTVector;
	nTtype max=v->at(0);
	for(int i=1;i<v->getSize();i++)
		if(v->at(i)>max)
			max=v->at(i);
	count->alloc(10);
	for(int exp=1;max/exp>0;exp*=10){//count
		v->copyTo(sort);
		for(int i=0;i<10;i++)
			count->set(i,0);
		for(int i=0;i<sort->getSize();i++)
			count->add((sort->at(i)/exp)%10,1);
		for(int i=1;i<10;i++)
			count->add(i,count->at(i-1));
		for(int i=sort->getSize()-1;i>=0;i--){
			nTtype at=(sort->at(i)/exp)%10;
			v->set(count->at(at)-1,sort->at(i));
			count->add(at,-1);
		}
	}
	count->dispose();
	sort->dispose();
}
#endif