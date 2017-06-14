#include "../nTAnalysis.h"

using namespace std;

int main (int argc, char **argv){
	analyse("","","Mediana.csv",false,false);
	for(int i=1;i<argc;i++)
		analyse(argv[i],"../results/saida.csv","Mediana.csv",false,false);
	return 0;
}