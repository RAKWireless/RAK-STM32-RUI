/*
** LinkerScript
** Note: For specific memory allocation, linker and startup files must be customized.
**       Refer to STM32CubeIDE user guide (UM2609), chapter "Modify the linker script".
*/


/* Highest address of the user mode stack */
_estack = ORIGIN(RAM1) + LENGTH(RAM1); /* end of "SRAM1" Ram type memory */

_Min_Heap_Size = 0x1E00;      /* required amount of heap  */
_Min_Stack_Size = 0x2000; /* required amount of stack */
/* Memories definition */
MEMORY
{
  BL     (rx)    : ORIGIN = 0x08000000, LENGTH = 24K    /* Bootloader */
  ROM    (rx)    : ORIGIN = 0x0801F000, LENGTH = 122K   /* Application */

/*Originally RAM1 and RAM2 are the same size: 32K, but it is not enough size for stack*/
  RAM1_DATA   (xrw)   : ORIGIN = 0x20000000, LENGTH = 24K
  RAM1   (xrw)   : ORIGIN = 0x20006000, LENGTH = 39K    /* Non-backup SRAM1 */
  RAM2   (xrw)   : ORIGIN = 0x2000FC00, LENGTH = 1K    /* Backup SRAM2 */
}

/* Sections */
SECTIONS
{
  /* The startup code into "ROM" Rom type memory */
  .isr_vector :
  {
    . = ALIGN(8);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(8);
  } >ROM

  /* The program code and other data into "ROM" Rom type memory */
  .text :
  {
    . = ALIGN(8);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(8);
  } >ROM

  /* Constant data into "ROM" Rom type memory */
  .rodata :
  {
    . = ALIGN(8);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(8);
  } >ROM

  .ARM.extab   : { 
    . = ALIGN(8);
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    . = ALIGN(8);
  } >ROM
  
  .ARM : {
    . = ALIGN(8);
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
    . = ALIGN(8);
  } >ROM

  .preinit_array     :
  {
    . = ALIGN(8);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(8);
  } >ROM
  
  .init_array :
  {
    . = ALIGN(8);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
    . = ALIGN(8);
  } >ROM
  
  .fini_array :
  {
    . = ALIGN(8);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
    . = ALIGN(8);
  } >ROM

  /* Used by the startup to initialize data */
  _sidata_lora = LOADADDR(.data);

  /* Initialized data sections into "SRAM1" Ram type memory */
  .data : 
  {
    . = ALIGN(8);
    _sdata_lora = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(8);
    _edata_lora = .;        /* define a global symbol at data end */
    
  } >RAM1_DATA AT> ROM

  /* Uninitialized data section into "SRAM1" Ram type memory */
  . = ALIGN(8);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss section */
    _sbss_lora = .;         /* define a global symbol at bss start */
    __bss_lora_start__ = _sbss_lora;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(8);
    _ebss_lora = .;         /* define a global symbol at bss end */
    __bss_lora_end__ = _ebss_lora;
  } >RAM1_DATA

  /* Remove information from the compiler libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
