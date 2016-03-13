# include "../read/head.h"
# include "exec.h"

void exec_line(char **arg) {
  switch(strlwr(arg[1])) {
    case NULL :
      break;
    case "move" : 
      move(arg[2],arg[3],arg[4]);
      break;
    default :
      err(1,"Unknown cmd");
      break;
  }
}
