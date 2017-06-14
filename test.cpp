#include "sort/selection.h"
#include "sort/insertion.h"
#include "sort/shell.h"
#include "sort/merge.h"
#include "sort/quick1.h"
#include "sort/quick2.h"
#include "sort/quickinsertion.h"
#include "nTVector.h"
#include "nTTimer.h"

void main(){
	nTTimer timer;
	nTVector *v=new nTVector;
	nTVector *selection=new nTVector;
	nTVector *insertion=new nTVector;
	nTVector *shell=new nTVector;
	nTVector *merge=new nTVector;
	nTVector *quick1=new nTVector;
	nTVector *quick2=new nTVector;
	nTVector *quickin=new nTVector;
	v->alloc(100);
	v->fillRand();
	selection->setSort(&selectionSort);
	insertion->setSort(&insertionSort);
	shell->setSort(&shellSort);
	merge->setSort(&mergeSort);
	quick1->setSort(&quick1Sort);
	quick2->setSort(&quick2Sort);
	quickin->setSort(&quickInsertionSort);
	v->copyTo(selection);
	v->copyTo(insertion);
	v->copyTo(shell);
	v->copyTo(merge);
	v->copyTo(quick1);
	v->copyTo(quick2);
	v->copyTo(quickin);
	v->printOrd();
	timer.start("Selection");
	selection->sort();
	timer.end();
	timer.print();
	selection->printOrd();
	timer.start("Insertion");
	insertion->sort();
	timer.end();
	timer.print();
	insertion->printOrd();	
	timer.start("Shell");
	shell->sort();
	timer.end();
	timer.print();
	shell->printOrd();
	timer.start("Merge");
	merge->sort();
	timer.end();
	timer.print();
	merge->printOrd();	
	timer.start("Quick1");
	quick1->sort();
	timer.end();
	timer.print();
	quick1->printOrd();	
	timer.start("Quick2");
	quick2->sort();
	timer.end();
	timer.print();
	quick2->printOrd();	
	timer.start("QuickIn");
	quickin->sort();
	timer.end();
	timer.print();
	quickin->printOrd();	
	insertion->dispose();
	selection->dispose();
	shell->dispose();
	quick1->dispose();
	quick2->dispose();
	merge->dispose();
	quickin->dispose();
	v->dispose();
}