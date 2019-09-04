#include <cstdio>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	function<double()> operation;
	int op;
	
	if(argc < 4){
		printf("Usage: %s {add|sub|mul|div|mod|pow} <arg1> <arg2>",argv[0]);
		putchar('\n');
		exit(1);
	}
	if(!strcmp(argv[1],"add")){
		op = 1;
	}
	else if(!strcmp(argv[1],"sub")){
		op = 2;
	}
	else if(!strcmp(argv[1],"mul")){
		op = 3;
	}
	else if(!strcmp(argv[1],"div")){
		op = 4;
	}
	else if(!strcmp(argv[1],"mod")){
		op = 5;
	}
	else if(!strcmp(argv[1],"pow")){
		op = 6;
	}
	else{
		op = -1;
	}
	
	double res;
	
	switch(op){
		case 1:
			operation = [argv]() -> auto{
				return atof(argv[2]) + atof(argv[3]);
			};
			res = operation();
			break;
		case 2:
			operation = [&argv]() -> auto{
				return atof(argv[2]) - atof(argv[3]);
			};
			res = operation();
			break;
		case 3:
			operation = [&argv]() -> auto{
				return atof(argv[2]) * atof(argv[3]);
			};
			res = operation();
			break;
		case 4:
			operation = [&argv]() -> auto{
				return atof(argv[2]) / atof(argv[3]);
			};
			res = operation();
			break;
		case 5:
			operation = [&argv]() -> auto{
				return fmod(atof(argv[2]) , atof(argv[3]));
			};
			res = operation();
			break;
		case 6:
			operation = [&argv]() -> auto{
				return pow(atof(argv[2]) , atof(argv[3]));
			};
			res = operation();
			break;
		case -1:
		default:
			printf("Usage: %s {add|sub|mul|div|mod|pow} <arg1> <arg2>",argv[0]);
			putchar('\n');
			exit(1);	
	}
	
	printf("Result: %5.2f",res);

	return 0;
}
