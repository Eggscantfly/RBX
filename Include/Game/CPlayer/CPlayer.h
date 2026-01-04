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

typedef struct {
    char* typeInfo;
    float x;
    float y;
} CVector2;

extern char CVector2_TypeInfo[];
