# ifndef ACCES_RAM_H_
# define ACCES_RAM_H_

#include "read/head.h"

uint32_t ram_read(uint32_t mask, uint32_t add);
void ram_write(uint32_t mask, uint32_t add, uint32_t new);

#endif
