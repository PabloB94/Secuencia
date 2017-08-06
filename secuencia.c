#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sysexits.h>
#include <errno.h>

int main(int argc , char*argv[]){

	double hasta=10;
	double desde=1;
	double paso=1;
 
	if((argc==2) && ((strcmp(argv[1],"-help")==0)||strcmp(argv[1],"-h")==0)){
	        fprintf(stdout,"secuencia: Uso: secuencia [ hasta [ desde [ paso ]]]\n");
	        fprintf(stdout,"secuencia: Genera la secuencia de numeros en el intervalo y paso dados \n");
	        exit(EX_OK);}

	if(argc >4){
		fprintf(stderr,"secuencia: Error(EX_USAGE), error en la ejecucion del programa secuencia \n");
	        fprintf(stderr,"secuencia+ \"paso\"  Error el numero de argumentos es incorrecto \n");
	        exit(EX_USAGE);
	}else{
    	        
		if (argc>1){
			hasta = strtod(argv[1],NULL);
			if(errno!=0){
				fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
	        	        fprintf(stderr,"secuencia+ El parametro \"hasta\" no es un numero real valido \n");
	        	        exit(EX_USAGE);	
			}
		}

		if (argc>2){
			desde = strtod(argv[2],NULL);
			if(errno!=0){
				fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
	        	        fprintf(stderr,"secuencia+ El parametro \"desde\" no es un numero real valido \n");
	        	        exit(EX_USAGE);	
			}
		}
		if (argc>3){
			paso = strtod(argv[3],NULL);
			if(errno!=0){
				fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
	        	        fprintf(stderr,"secuencia+ El parametro \"paso\" no es un numero real valido \n");
	        	        exit(EX_USAGE);	
			}
		}
		if(((hasta>desde)&&(paso<0))||((hasta<desde)&&(paso>0))){
        	        fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto del mandato. \"Success\"\n");
        	        fprintf(stderr,"secuencia+ El signo de \"paso\" no permite recorrer el intervalo en el sentido \"desde\" a \"hasta\"\n");
        	        exit(EX_USAGE);
		}
		if(paso==0){
	                fprintf(stderr,"secuencia: Error(EX_USAGE), Uso incorrecto \n");
	                fprintf(stderr,"secuencia+ El parametro \"paso\"  no puede ser igual a 0 \n");
	                exit(EX_USAGE);
		}

		char *variable= getenv("MAX_OUTPUT");
		double v;
		double maximo;

		if(variable!= NULL){
			v=strtod(variable,NULL);
			if(errno!=0 && v>0){
				maximo=v;
			}else{
				maximo=100;
			}
		}else{          
			maximo=100;
		}

		double aux = (desde-hasta)/paso;
		int lim = aux;
		lim = abs(lim);

		for(int i = 0; i <= lim; i++){
			double n = desde + (i * paso);	
			if(n>maximo){
				fprintf(stderr,"secuencia: Error(EX_NOPERM), permiso denegado \"Success\"\n");
				fprintf(stderr,"secuencia+ Se intento superar el limite de salida\n");
				exit(EX_NOPERM);
			} 
			fprintf(stdout,"\t%g\n",n);
		}
	}
	exit(EX_OK);
}

	
