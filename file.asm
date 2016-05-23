  org $500
main
\loop 
  add.l #1,d1
  add.b d1,(a0)
  bne \loop
  illegal
