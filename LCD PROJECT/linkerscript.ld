ENTRY(Reset_Handler)
MEMORY
{
	FLASH(xr): ORIGIN = 0x08000000, LENGTH = 128k
	SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 20k
}
SECTIONS
{
	.isr_vector :
	{
		. = ALIGN(4);
		*(.isr_vector)
		. = ALIGN(4);
	}>FLASH
	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text*)
		. = ALIGN(4);
	}>FLASH
	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
	}>FLASH
	_sidata = LOADADDR(.data);
	.data :
	{
		_sdata = .;
		. = ALIGN(4);
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	}>SRAM AT>FLASH
	.bss :
	{
		_sbss = .;
		. = ALIGN(4);
		*(.bss)
		*(.bss*)
		. = ALIGN(4);
		_ebss = .;
	}>SRAM

}