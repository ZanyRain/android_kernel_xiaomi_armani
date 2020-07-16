/*
 * Atmel maXTouch Touchscreen driver
 *
 * Copyright (C) 2010 Samsung Electronics Co.Ltd
 * Author: Joonyoung Shim <jy0922.shim@samsung.com>
 * Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 * Copyright (C) 2015 XiaoMi, Inc.
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */
#ifdef CONFIG_VENDOR_XIAOMI
#ifndef __LINUX_ATMEL_MXT_TS
#define __LINUX_ATMEL_MXT_TS
#else
#ifndef __LINUX_ATMEL_MXT_TS_H
#define __LINUX_ATMEL_MXT_TS_H
#endif

#include <linux/types.h>

#ifdef CONFIG_VENDOR_XIAOMI
#define MXT224_I2C_ADDR1        0x4A
#define MXT224_I2C_ADDR2        0x4B
#define MXT1386_I2C_ADDR1       0x4C
#define MXT1386_I2C_ADDR2       0x4D
#define MXT1386_I2C_ADDR3       0x5A
#define MXT1386_I2C_ADDR4       0x5B
#endif /* CONFIG_VENDOR_XIAOMI */

/* Orient */
#define MXT_NORMAL		0x0
#define MXT_DIAGONAL		0x1
#define MXT_HORIZONTAL_FLIP	0x2
#define MXT_ROTATED_90_COUNTER	0x3
#define MXT_VERTICAL_FLIP	0x4
#define MXT_ROTATED_90		0x5
#define MXT_ROTATED_180		0x6
#define MXT_DIAGONAL_COUNTER	0x7

/* MXT_TOUCH_KEYARRAY_T15 */
#define MXT_KEYARRAY_MAX_KEYS	32

#ifdef CONFIG_VENDOR_XIAOMI
#define CFG_NAME_SIZE			64
#endif /* CONFIG_VENDOR_XIAOMI */


/* Bootoader IDs */
#ifndef CONFIG_VENDOR_XIAOMI
#define MXT_BOOTLOADER_ID_224		0x0A
#define MXT_BOOTLOADER_ID_224E		0x06
#define MXT_BOOTLOADER_ID_336S		0x1A
#define MXT_BOOTLOADER_ID_1386		0x01
#define MXT_BOOTLOADER_ID_1386E		0x10
#define MXT_BOOTLOADER_ID_1664S		0x14
#endif /* CONFIG_VENDOR_XIAOMI */

#ifdef CONFIG_VENDOR_XIAOMI
#define CONFIG_MXT_IRQ_WORKQUEUE
#define CONFIG_MXT_PLUGIN_SUPPORT
#endif /* CONFIG_VENDOR_XIAOMI */

/* Config data for a given maXTouch controller with a specific firmware */
struct mxt_config_info {
#ifndef CONFIG_VENDOR_XIAOMI
	const u8 *config;
	size_t config_length;
	/* Points to the firmware name to be upgraded to */
	const char *fw_name;
#endif /* CONFIG_VENDOR_XIAOMI */

	u8 family_id;
	u8 variant_id;
	u8 version;
	u8 build;
	u8 bootldr_id;
	const char* mxt_cfg_name;
	int *key_codes;
	int key_num;
#ifdef CONFIG_VENDOR_XIAOMI
	u8 vendor_id;
	u16 mult_no_touch_threshold;
#endif /* CONFIG_VENDOR_XIAOMI */


};

/* The platform data for the Atmel maXTouch touchscreen driver */
struct mxt_platform_data {
#ifndef CONFIG_VENDOR_XIAOMI
	const struct mxt_config_info *config_array;

	/* touch panel's minimum and maximum coordinates */
	u32 panel_minx;
	u32 panel_maxx;
	u32 panel_miny;
	u32 panel_maxy;

	/* display's minimum and maximum coordinates */
	u32 disp_minx;
	u32 disp_maxx;
	u32 disp_miny;
	u32 disp_maxy;

	bool	i2c_pull_up;
	bool	digital_pwr_regulator;
	u32 reset_gpio_flags;

	u32 irq_gpio_flags;
	int *key_codes;
	bool need_calibration;
	bool no_force_update;
	bool no_lpm_support;
	u8 bl_addr;
	int (*init_hw) (bool);
	int (*power_on) (bool);
#endif /* CONFIG_VENDOR_XIAOMI */

	size_t config_array_size;
	unsigned long irqflags;
	int reset_gpio;
	int irq_gpio;
	u8(*read_chg) (void);

#ifdef CONFIG_VENDOR_XIAOMI
	struct mxt_config_info *config_array;
	const char* mxt_fw_name;
	int power_gpio;
	const char *input_name;
	u32 reset_gpio_flags;
	u32 irq_gpio_flags;
	u32 power_gpio_flags;
	u8 gpio_mask;
	bool i2c_pull_up;
	u8 rx_num;
	u8 tx_num;
#endif /* CONFIG_VENDOR_XIAOMI */
};

#ifdef CONFIG_VENDOR_XIAOMI
#endif /* __LINUX_ATMEL_MXT_TS_640T_H */
#else
#endif /* __LINUX_ATMEL_MXT_TS_H */
#endif /* CONFIG_VENDOR_XIAOMI */

