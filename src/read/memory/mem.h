void dumpMem (char *p, unsigned int s);

#define DUMPMEM(x,s) do{printf("%s:\n",#x);dumpMem((char*)(&x),s);}while(0)

#define DUMPSTR(x) do{printf("%s: %s\n",#x,x);dumpMem(x,strlen(x));}while(0)
