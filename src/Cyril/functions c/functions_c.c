# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

struct cpu {
  char* RAM;
  uint32_t* An; //32 bits adress reg, it is unisigned
  uint32_t* Dn;
  char CCR;
  uint32_t pc;
};

int s_size (int *reg, int size){//retourne la partie du registre de la taille voulue
	if (size==1){
		return(*reg%256);
	}
	if (size==2){
		return(*reg%(256*256));
	}
	return(*reg);
}



void r_size(int *reg, int new_size,int size){//écris dans le registre avec la taille demandée
	if (size==1){
		*reg=(*reg/256+new_size);
	}
	if (size==2){
		*reg=(*reg/(256*256)+new_size);
	}
	*reg=(new_size);

}

void add (struct cpu cp, uint32_t opcode){
	uint32_t ea_reg=opcode%8, ea_mode=opcode%64/8,opmode=opcode%512/64,reg=opcode%4096/512,*ea,size;
	//SIZE
	if(opmode%4==0){
        size=1;
	}
	if(opmode%4==1){
        size=2;
	}
	if(opmode%4==2){
        size=4;
	}
	//EA
	if(ea_mode==0){
        ea=&(cp->Dn[ea_reg]);
	}
	if(ea_mode==1){
        ea=&(cp->An[ea_reg]);
	}
	if(ea_mode==2){
        ea=&(cp->RAM[cpu->An[ea_reg]-size]);
	}
	if(ea_mode==3){
        ea=&(cp->RAM[cpu->An[ea_reg]-size]);
        cpu->An[ea_reg]++;
	}
	if(ea_mode==4){
        ea=&(cp->RAM[(--cpu->An[ea_reg])-size]);
	}
/*	if(ea_mode==5){
        ea=&(cpu->Dn[ea_reg]);
	}
	if(ea_mode==6){
        ea=&(cpu->Dn[ea_reg]);
	}
	if(ea_mode==7){
        ea=&(cpu->Dn[ea_reg]);
	}

	Note: à organiser
*/
    uint32_t t=1;
    for(uint32_t i=0,i<size,i++){t=t*256;}

    if (opmode/4){
        ea*=(ea*/t*t)+((ea*+cp->Dn[reg])%t);
    }
    else{
        cp->Dn[reg]=(cp->Dn[reg]/t*t)+((ea*+cp->Dn[reg])%t);
    }
}

void and (struct cpu cpu, uint32_t opcode){
    int r=0;
    int n=1;
    for(int i=0;i<size;i++){
        n=2*n;
        r=r+(n/2)*(((*src/n)%n)&&((*dst/n)%n));
    }
    r_size(dst,r,size);
}

/*uint32_t *get_ea(struct cpu cpu, uint32_t opcode){
    uint32_t reg=opcode%8, mode=(opcode%64)/8;
    if(mode==0){
        return(cpu->Dn+reg);
    }
    else{
        if(mode==7){
            return(&(cpu->opcode/65536));
        }
        else{
            if(mode==1){
                return(cpu->An+reg);
            }
            else{
                if(mode==2){
                    return(&(*cpu->An[reg]));
                }
                else{
                    if(mode==3){
                        return(&((*cpu->An[reg])++));
                    }
                    else{
                        if(mode==4){
                            return(&(--(*cpu->An[reg])));
                        }
                    }
                }
            }
        }
    }
    return(NULL);
}
*/

void convert_opcode(struct cpu cpu, uint32_t opcode){
    //ADD
    if (((opcode%65536)/4096==13) & ((opcode%16 777 216)/64!=3))
        {add(cpu,opcode);}
    if (((opcode%65536)/4096==13) & ((opcode%16 777 216)/64==3))
        {adda(cpu,opcode);}
    if (((opcode%65536)/4096==13) & (opcode/65536))
        {addi(cpu,opcode);}


    //AND
    if (((opcode%65536)/4096==12) & (opcode/65536==0))
        {and(cpu,opcode);}
    if (((opcode%65536)/4096==12) & (opcode/65536!=0))
        {andi(cpu,opcode);}


    //MOVE
    if ((opcode%65536)/16384 & (opcode%65536)/4096)
        {move(cpu,opcode);}
}
