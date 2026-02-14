//originally named (FUN_80065004)
#include "include/Game/CActor/CActor.h"


void healthSub(void* player, void* damageSource)
{
  
  int Health;
  
  if (*(int *)((char*)player + 0x228) <= 0) {  //I guess checks to see if the player is already dead
    return;

  }
  
  if (damageSource == 0) goto decrement;
  
  if (*(int *)((char*)damageSource + 0x1d8) < 200) goto decrement;
    
  if (300 <= *(int *)((char*)damageSource + 0x1d8)) goto decrement;
  
  if ((Health = *(int *)((char*)player + 0x228) - *(int *)((char*)damageSource + 0x228),
       
       *(int *)((char*)player + 0x228) = Health,
       
       Health < 0)) {
    *(int *)((char*)player + 0x228) = 0;    
  }
    
  goto check_death;
  
decrement:
  *(int *)((char*)player + 0x228) = *(int *)((char*)player + 0x228) + -1;
  
check_death:
  if (*(int *)((char*)player + 0x228) != 0) {
    return;
      
  }
  *(int *)((char*)player + 0x240) = 7;  //Sets player to death state
}
