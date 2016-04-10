# include "mem.h"
# include "../head.h"

void dumpMem (char *p, unsigned int s) {
    unsigned int i;
    unsigned char c[0x10];

    for (i = 0; i < ((s + 15) & 0xfff0); i++) {
        if ((i % 0x10) == 0) {
            if (i != 0) printf ("  %*.*s\n", 0x10, 0x10, c);
            printf (">> %04x ",i);
        }
        if (i < s) {
            printf (" %02x",(unsigned)(unsigned char)p[i]);
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

int main (void) {
  int i = 42;
  char *s = "Hello world !";

  DUMPINT (i);
  DUMPSTR (s);

  struct cpu z=*get_cpu();
  DUMPMEM (z.RAM,sizeof(uint16_t));
  delete_core(&z);
  return 0;
}
*/
