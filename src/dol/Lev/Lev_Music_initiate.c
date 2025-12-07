// Originally named (FUN_80062bd4)
#include "include/Game/Lev/Lev_Music.h"

void lev_Music_initiate(int Level_id)
{
    extern int Music_id;
    extern char MusicStrings[];
    
    if (Level_id == 0x68) goto shortboss;
    if (Level_id == 0x7b) goto shortboss;
    if ((unsigned int)(Level_id - 0x96) <= 1) goto shortboss;
    
    goto check_6d;

shortboss:
//tension.dum
    if (Music_id == 7) return;
    Music_id = 7;
    FUN_80057c54();
    FUN_80057b48(&MusicStrings[0x700]);
    FUN_80057bf0(1);
    return;

check_6d:
    if (Level_id != 0x6d) goto finalboss;
    if (FUN_800e4154(FUN_800e46dc(), 0xa0, 1) != 0) goto finalboss;
    FUN_80057c54();
    return;

finalboss:
//jefeepic1.zbg
    if (Level_id != 0xa7) goto regular;
    if (Music_id == 6) return;
    Music_id = 6;
    FUN_80057c54();
    FUN_80057b48(&MusicStrings[0x600]);
    FUN_80057bf0(1);
    return;

regular:
//bosque.dan
    if ((unsigned int)(Level_id - 0x64) <= 0x13) {
        if (Music_id != 1) {
            Music_id = 1;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x100]);
            FUN_80057bf0(1);
        }
    }
    //cueva.san
    if ((unsigned int)(Level_id - 0x78) <= 0x13) {
        if (Music_id != 2) {
            Music_id = 2;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x200]);
            FUN_80057bf0(1);
        }
    }
    //gelatina.nac
    if ((unsigned int)(Level_id - 0x8c) <= 0x13) {
        if (Music_id != 3) {
            Music_id = 3;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x300]);
            FUN_80057bf0(1);
        }
    }
    //interiorrobot.ati
    if ((unsigned int)(Level_id - 0xa0) <= 0x13) {
        if (Music_id != 4) {
            Music_id = 4;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x400]);
            FUN_80057bf0(1);
        }
    }
    //interiorrobot.ati twice for some reason...
    if (Level_id >= 0xb4) {
        if (Music_id != 4) {
            Music_id = 4;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x400]);
            FUN_80057bf0(1);
        }
    }
}
