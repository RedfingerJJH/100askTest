
.text 
.global _start
 
_start:
 
	/* 设置内存：sp栈 */
	ldr sp,=4096 /* nand启动 */
//	ldr sp,=0x40000000+4096 /* nor启动 */
	
	/* 通过r0传递参数 */
	mov r0,#4
	bl led_on
	
	ldr r0,=100000
	bl delay
	
	mov r0,#5
	bl led_on
	
	/* 死循环 */
halt:
	b halt