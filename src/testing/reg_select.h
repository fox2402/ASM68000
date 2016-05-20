# include <stdlib.h>
# include <stdint.h>

# ifndef REG_SELECT_H_
# define REG_SELECT_H_

uint32_t* selectReg(uint16_t input, int sel);
uint32_t* selectMod(uint16_t input);
uint32_t* selectModRE(uint16_t input);


# endif
