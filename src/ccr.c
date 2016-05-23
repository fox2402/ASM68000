
void ccr(uint32_t n, uint32_t mask) {
  n &= mask;
  struct cpu *cpu = get_cpu();
  if (n == 0) { //zero
    cpu->SR ^= (-1 ^ cpu->SR) & (1 << 2) ;
  } else {
    cpu->SR ^= (-0 ^ cpu->SR) & (1 << 2);
  }
  uint32_t tmp = mask >> 1;
  for(; tmp; tmp >>= 1 ) {
    n >>= 1;
  }
  if( n == 0) {//positive
    cpu->SR ^= (-0 ^ cpu->SR) & (1 << 3) ;
  } else {
    cpu->SR ^= (-1 ^ cpu->SR) & (1 << 3) ;
  }
}
