#ifndef _NTSELECTION
#define _NTSELECTION
#include "../nTVector.h"

void selectionSort(nTVector *v){
	int min;
	for(int i=0;i<v->getSize();i++){
		min=i;
		for(int j=i+1;j<v->getSize();j++){
			if(v->at(min)>v->at(j))
				min=j;
		}
		v->swap(i,min);
	}
}
#endif