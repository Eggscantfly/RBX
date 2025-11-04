/* Robox (Wii) Memory Layout - Matching Build Linker Script */

ENTRY(0x80004050)

/* BSS starts here */
_bss_start = 0x801FAB80;
_bss_end   = _bss_start + 0x000AEE18;

SECTIONS
{
    /* ========================= */
    /* TEXT (code)               */
    /* ========================= */
    .text 0x80004000 :
    {
        /* Place all function code here */
        build/*.o(.text*)
    }

    /* ========================= */
    /* RODATA (const data)       */
    /* ========================= */
    .rodata ALIGN(32) :
    {
        build/*.o(.rodata*)
    }

    /* ========================= */
    /* DATA (initialized vars)   */
    /* ========================= */
    .data ALIGN(32) :
    {
        build/*.o(.data*)
    }

    /* ========================= */
    /* BSS (zero init memory)    */
    /* ========================= */
    .bss _bss_start (NOLOAD) :
    {
        *(COMMON)
        build/*.o(.bss*)
    } > NONE
}
