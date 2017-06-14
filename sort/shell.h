#ifndef _NTSHELL
#define _NTSHELL
#include "../nTVector.h"

void shellSort(nTVector *v){//faster
	int steep=v->getSize()/2;
	while(steep>0){
		for(int i=0;i<v->getSize();i++){
			if(i+steep>=v->getSize())
				break;
			if(v->at(i)>v->at(i+steep)){
				v->swap(i,i+steep);
				for(int j=i-1;j>=0;j--)
					if(v->at(j)>v->at(j+steep))
						v->swap(j,j+steep);
					else break;			
			}
		}
		steep/=2;
	}
}

void shell2Sort(nTVector *v){//slower h=3h+1
	int steep=1;
	while(steep<v->getSize()) steep=3*steep+1;
	steep/=3;
	while(steep>0){
		for(int i=0;i<v->getSize();i++){
			if(i+steep>=v->getSize())
				break;
			if(v->at(i)>v->at(i+steep)){
				v->swap(i,i+steep);
				for(int j=i-1;j>=0;j--)
					if(v->at(j)>v->at(j+steep))
						v->swap(j,j+steep);
					else break;			
			}
		}
		steep/=3;
	}
}
#endif