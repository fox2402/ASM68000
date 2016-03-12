//static oid dumpMem (char *p, unsigned int s);

#define DUMPINT(x) do{printf("%s: %d\n",#x,x);dumpMem((char*)(&x),sizeof(int));}while(0)
#define DUMPSTR(x) do{printf("%s: %s\n",#x,x);dumpMem(x,strlen(x));}while(0)
#define DUMPMEM(x,s) do{printf("%s:\n",#x);dumpMem((char*)(&x),s);}while(0)

