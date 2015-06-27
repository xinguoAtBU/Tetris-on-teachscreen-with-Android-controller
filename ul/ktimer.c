#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char **argv) {
        char buf[3];
	FILE * pFile;
	FILE * pFiletemp;
	pFile = fopen("/dev/rfcomm0", "r");
	
	while (fread(buf,3,1,pFile)!=0) {
	  pFiletemp= fopen("/home/root/proejct/dahu","ab");
	  printf("%s\n",buf);	  
	  fprintf(pFiletemp,"%c%c%c\n",buf[0],buf[1],buf[2]);
	  fclose(pFiletemp);
	}
	fclose(pFile);	
	return 0;
}


