#ifndef CPLAYER_H
#define CPLAYER_H

typedef struct {
    char* typeInfo;
    float x;
    float y;
} CVector2;

extern char CVector2_TypeInfo[];

typedef struct CPlayer {
    char unk_0x0[0x8];
    float posX;              // 0x8
    float posY;              // 0xC
    char unk_0x10[0x1D8];
    int facingDirection;     // 0x1E8 (0 = right, 1 = left)
    char unk_0x1EC[0xC];
    float targetX;           // 0x1F8
    float targetY;           // 0x1FC
    char unk_0x200[0x28];
    int health;              // 0x228
    char unk_0x22C[0x14];
    int state;               // 0x240
} CPlayer;

extern CPlayer** g_ppPlayer;  // 0x801FACE0

void healthSub(void* player, void* damageSource);
void flipCharacter(int param_1);

#endif
