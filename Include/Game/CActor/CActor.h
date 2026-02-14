#ifndef CACTOR_H
#define CACTOR_H

typedef struct {
    char* typeInfo;
    float x;
    float y;
} CVector2;

extern char CVector2_TypeInfo[];

typedef struct CActor {
    char unk_0x0[0x8];
    float posX;              // 0x8
    float posY;              // 0xC
    char unk_0x10[0x1C8];
    int entityType;          // 0x1D8
    char unk_0x1DC[0xC];
    int facingDirection;     // 0x1E8 (0 = right, 1 = left)
    char unk_0x1EC[0xC];
    float targetX;           // 0x1F8
    float targetY;           // 0x1FC
    char unk_0x200[0x28];
    int health;              // 0x228
    char unk_0x22C[0x14];
    int state;               // 0x240
} CActor;

struct CPlayer;
extern struct CPlayer** g_ppPlayer;  // 0x801FACE0

void healthSub(CActor* player, CActor* damageSource);
void flipCharacter(CActor* actor);

#endif
