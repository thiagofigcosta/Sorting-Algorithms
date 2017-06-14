#include "../nTAnalysis.h"

using namespace std;

int main (int argc, char **argv){
	analyse("","","Quantis.csv",true,true);
	for(int i=1;i<argc;i++)
		analyse(argv[i],"../results/saida.csv","Quantis.csv",true,true);
	return 0;
}