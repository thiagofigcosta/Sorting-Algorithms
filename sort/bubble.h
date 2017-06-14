#ifndef _NTBUBBLE
#define _NTBUBBLE
#include "../nTVector.h"

void bubbleSort(nTVector *v){
	for(int i=0;i<v->getSize();i++){
		for(int j=i+1;j<v->getSize();j++){
			if(v->at(i)>v->at(j)){
				v->swap(i,j);
			}
		}
	}
}
#endif