#ifndef CPLAYER_H
#define CPLAYER_H

typedef struct CPlayer {
    char unk_0x0[0x228];
    int health;              // 0x228
    char unk_0x22C[0x14];
    int state;               // 0x240
} CPlayer;

extern CPlayer** g_ppPlayer;  // 0x801FACE0

void healthSub(void* player, void* damageSource);

#endif
