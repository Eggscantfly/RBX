// Originally named (FUN_80062bd4)
void lev_Music_initiate(int Level_id)
{
    extern int Music_id;
    extern char MusicStrings[];
    
    if (Level_id == 0x68) goto tension;
    if (Level_id == 0x7b) goto tension;
    if ((unsigned int)(Level_id - 0x96) <= 1) goto tension;
    
    goto check_6d;

tension:
    if (Music_id == 7) return;
    Music_id = 7;
    FUN_80057c54();
    FUN_80057b48(&MusicStrings[0x700]);
    FUN_80057bf0(1);
    return;

check_6d:
    if (Level_id != 0x6d) goto check_a7;
    if (FUN_800e4154(FUN_800e46dc(), 0xa0, 1) != 0) goto check_a7;
    FUN_80057c54();
    return;

check_a7:
    if (Level_id != 0xa7) goto check_world1;
    if (Music_id == 6) return;
    Music_id = 6;
    FUN_80057c54();
    FUN_80057b48(&MusicStrings[0x600]);
    FUN_80057bf0(1);
    return;

check_world1:
    if ((unsigned int)(Level_id - 0x64) <= 0x13) {
        if (Music_id != 1) {
            Music_id = 1;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x100]);
            FUN_80057bf0(1);
        }
    }
    if ((unsigned int)(Level_id - 0x78) <= 0x13) {
        if (Music_id != 2) {
            Music_id = 2;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x200]);
            FUN_80057bf0(1);
        }
    }
    if ((unsigned int)(Level_id - 0x8c) <= 0x13) {
        if (Music_id != 3) {
            Music_id = 3;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x300]);
            FUN_80057bf0(1);
        }
    }
    if ((unsigned int)(Level_id - 0xa0) <= 0x13) {
        if (Music_id != 4) {
            Music_id = 4;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x400]);
            FUN_80057bf0(1);
        }
    }
    if (Level_id >= 0xb4) {
        if (Music_id != 4) {
            Music_id = 4;
            FUN_80057c54();
            FUN_80057b48(&MusicStrings[0x400]);
            FUN_80057bf0(1);
        }
    }
}
