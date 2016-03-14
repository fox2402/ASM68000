void dumpMem (char *p, unsigned int s);

#define DUMPMEM(x,s) do{printf("%s:\n",#x);dumpMem((char*)(&x),s);}while(0)

