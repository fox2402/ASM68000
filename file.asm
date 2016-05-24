  org $500
main
\loop
  add.w #1,d0
  add.b #1,d1
  bne \loop
  illegal
