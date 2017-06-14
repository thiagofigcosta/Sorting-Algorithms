#ifndef _NTHEAP
#define _NTHEAP
#include "../nTVector.h"

void heapSort(nTVector *v){
	v->buildHeap();
	for(int i=v->getSize();i>=2;i--){
		v->swap(0,i-1);
		//fixdown
		int father=1,son=2;
		nTtype t=v->at(0);
	   	while (son<=(i-1)){
			if(son<(i-1)&&v->at(son-1)<v->at(son)) son++;
			if(t>=v->at(son-1)) break;
			v->set(father-1,v->at(son-1));
			father=son;
			son=2*father;
	   	}
	   	v->set(father-1,t);
	}
}
#endif