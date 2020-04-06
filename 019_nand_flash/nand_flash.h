#ifndef _NAND_FLASH_H
#define _NAND_FLASH_H

extern void nand_init(void);
extern void nand_read(unsigned int addr, unsigned char *buf, unsigned int len);
extern void nand_flash_test(void);

#endif /* _NAND_FLASH_H */
