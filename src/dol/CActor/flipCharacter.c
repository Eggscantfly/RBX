// Originally named (FUN_800650b8)
#include "include/Game/CPlayer/CPlayer.h"

void flipCharacter(int param_1)
{
    CVector2 target;
    CVector2 pos;
    int isLeft;
    
    target.typeInfo = CVector2_TypeInfo;
    target.x = *(float *)(param_1 + 0x1f8);
    target.y = *(float *)(param_1 + 0x1fc);
    
    pos.typeInfo = CVector2_TypeInfo;
    pos.x = *(float *)(param_1 + 0x8);
    pos.y = *(float *)(param_1 + 0xc);
    
    isLeft = target.x < pos.x;
    if (isLeft) {
        *(int *)(param_1 + 0x1e8) = 1; // flip left
    }
    else {
        *(int *)(param_1 + 0x1e8) = 0; // flip right
    }
}
