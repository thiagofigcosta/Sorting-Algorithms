#ifndef _NTINSERTION
#define _NTINSERTION
#include "../nTVector.h"

void insertionSort(nTVector *v){
	for(int i=1;i<v->getSize();i++){
		nTtype pivo=v->at(i);
		int j=i-1;
		while(j>=0&&pivo<v->at(j)){
			v->set(j+1,v->at(j));
			j--;
		}
		v->set(j+1,pivo);
	}
}

void insertion2Sort(nTVector *v){//slow
	for(int i=1;i<v->getSize();i++){
		nTtype pivo=v->at(i);
		for(int j=i-1;j>=0;j--){
			if(pivo<v->at(j)){
				v->swap(j+1,j);
			}
		}
	}
}

#endif