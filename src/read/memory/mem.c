# include "mem.h"
# include "../head.h"

void dumpMem (char *p, unsigned int s) {
    unsigned int i;
    unsigned char c[0x10];
//    printf (">>      ");
//    for (i = 0; i < 0x10; i++) printf (" +%x",i);
//    printf (" +");
//    for (i = 0; i < 0x10; i++) printf ("%x",i);
//    printf ("\n");
    for (i = 0; i < ((s + 15) & 0xfff0); i++) {
        if ((i % 0x10) == 0) {
            if (i != 0) printf ("  %*.*s\n", 0x10, 0x10, c);
            printf (">> %04x ",i);
        }
        if (i < s) {
            printf (" %02x", p[i]);
            c[i & 0xf] = ((p[i] < 0x20) || (p[i] > 0x7e)) ? '.' : p[i];
        } else {
            printf ("   ");
            c[i & 0xf] = ' ';
        }
    }
    printf ("  %*.*s\n", 0x10, 0x10, c);
}
#define DUMPINT(x) do{printf("%s: %d\n",#x,x);dumpMem((char*)(&x),sizeof(int));}while(0)
#define DUMPSTR(x) do{printf("%s: %s\n",#x,x);dumpMem(x,strlen(x));}while(0)
#define DUMPMEM(x,s) do{printf("%s:\n",#x);dumpMem((char*)(&x),s);}while(0)

/* TEST
typedef struct {
    char c;
    int i;
    char c2[6];
} tStruct;

int main (void) {
    int i = 42;
    char *s = "Hello world !";
    tStruct z;
    z.c = 'a'; z.i = 42; strcpy (z.c2,"Hello");

    DUMPINT (i);
    DUMPSTR (s);
    DUMPMEM (z,sizeof(z));

    return 0;
}
*/
