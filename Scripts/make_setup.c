#include<stdio.h>

int make(char *argv)
{
	FILE *op;
	op = fopen("setup.py","w+");
	if(op == NULL)
		return 0;
	fprintf(op,"%s","# filename : setup.py\n\n");
	fprintf(op,"%s","from distutils.core import setup\n");
	fprintf(op,"%s","from distutils.extension import Extension\n");
	fprintf(op,"%s","from Cython.Distutils import build_ext\n\n");
	fprintf(op,"%s","ext_modules = [Extension(\"");
	fprintf(op,"%s",argv);
	fprintf(op,"%s","\",[\"");
	fprintf(op,"%s",argv);
	fprintf(op,"%s",".pyx\"");
	fprintf(op,"%s","])]\n\n");
	fprintf(op,"%s","setup(\n");
	fprintf(op,"%s","name = '");
	fprintf(op,"%s",argv);
	fprintf(op,"%s"," app',\n");
	fprintf(op,"%s","cmdclass = {'build_ext':build_ext},\n");
	fprintf(op,"%s","ext_modules = ext_modules\n");
	fprintf(op,"%s",")");
	fclose(op);
	return 1;
}

int main(int argc, char *argv[])
{
	int prog;
	prog=make(argv[1]);
	if (prog)
		printf("Successfull\n");
	else 
		printf("Not Successfull\n");
	return 0;
}