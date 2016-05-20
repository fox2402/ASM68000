# include "op_mode.h" 




int add_code(uint16_t source)
{
  /* ret mod 3: 0 = b, 1 = w, 2 = l
  ** ret < 3 => dn + <ea> -> dn
  ** ret > 3 => <ea> + dn -> <ea>
  ** also works for SUB
  */  
  source = source >> 6;
  if (source < 3)
    return source;
  else
    return source-1;
  /* 0 = B dn first
  ** 1 = W dn first
  ** 2 = L dn first 
  ** 4 = B ea first
  ** 5 = W ea first
  ** 6 = L ea first
  */ 
}

int adda_code(uint16_t source)
{

  /* only use for adda or suba.
  ** 1 means Word (source extended to 32bit)
  ** 2 means Long
  */
  source = source >> 6;
  if(source == 3)
    return 1;
  else
    return 2;

}

int move_code(uint16_t source)
{
  /*also works for movea*/
  source = source >> 12;
  if(source == 1)
    return 0;
  if(source == 2)
    return 2;
  if(souce == 3)
    return 1;
}
