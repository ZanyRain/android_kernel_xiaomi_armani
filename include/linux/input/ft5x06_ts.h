/*
 *
 * FocalTech ft5x06 TouchScreen driver header file.
 *
 * Copyright (c) 2010  Focal tech Ltd.
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 * Copyright (c) 2012, Code Aurora Forum. All rights reserved.
 * Copyright (C) 2015 XiaoMi, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __LINUX_FT5X06_TS_H__
#define __LINUX_FT5X06_TS_H__

#define FT5X06_ID		0x55
#define FT5X16_ID		0x0A
#define FT5X36_ID		0x14
#define FT6X06_ID		0x06

#include <linux/types.h>

#ifndef CONFIG_VENDOR_XIAOMI
struct fw_upgrade_info {
	bool auto_cal;
	u16 delay_aa;
	u16 delay_55;
	u8 upgrade_id_1;
	u8 upgrade_id_2;
	u16 delay_readid;
	u16 delay_erase_flash;
};
#endif /* CONFIG_VENDOR_XIAOMI */

#ifdef CONFIG_VENDOR_XIAOMI
/* platform data for Focaltech touchscreen */
struct ft5x06_firmware_data {
	u8	chip;
	u8	vendor;
	const char	*fwname;
	u8	*data;
	int	size;
};

struct ft5x06_rect { /* rectangle on the touch screen */
	u16 left , top;
	u16 width, height;
};

struct ft5x06_keypad_data {
	/* two cases could happen:
	   1.if length == 0, disable keypad functionality.
	   2.else convert touch in kparea to key event. */
	u8 chip;
	unsigned int              length; /* for keymap and button */
	unsigned int       *keymap; /* scancode==>keycode map */
	struct ft5x06_rect *button; /* define button location */
	int *key_pos;
};

struct ft5x06_test_data {
	int tx_num;
	int rx_num;
};
#endif /* CONFIG_VENDOR_XIAOMI */



struct ft5x06_ts_platform_data {
#ifndef CONFIG_VENDOR_XIAOMI
	struct fw_upgrade_info info;
	const char *name;
	const char *fw_name;
	u32 irqflags;
#endif /* CONFIG_VENDOR_XIAOMI */


#ifdef CONFIG_VENDOR_XIAOMI
	unsigned long irqflags;
	u32 x_max;
	u32 y_max;
	u32 z_max;
	u32 w_max;
#endif /* CONFIG_VENDOR_XIAOMI */


	u32 irq_gpio;

	u32 reset_gpio;
	u32 reset_gpio_flags;
#ifndef CONFIG_VENDOR_XIAOMI
	u32 family_id;
	u32 x_max;
	u32 y_max;
	u32 x_min;
	u32 y_min;
	u32 panel_minx;
	u32 panel_miny;
	u32 panel_maxx;
	u32 panel_maxy;
	u32 group_id;
	u32 hard_rst_dly;
	u32 soft_rst_dly;
	u32 num_max_touches;
	bool fw_vkey_support;
	bool no_force_update;
	bool ignore_id_check;
	int (*power_init) (bool);
#endif /* CONFIG_VENDOR_XIAOMI */

	bool i2c_pull_up;

	int (*power_on) (bool);

#ifdef CONFIG_VENDOR_XIAOMI
	u32 cfg_size;
	struct ft5x06_firmware_data *firmware; /* terminated by 0 size */
	struct ft5x06_keypad_data *keypad;
	struct ft5x06_test_data *testdata;
	unsigned long                landing_jiffies;
	int                          landing_threshold;
	int                          staying_threshold;
	int                          moving_threshold;
	u16                          raw_min;
	u16                          raw_max;
	/* optional callback for platform needs */
	int (*power_init)(bool);
#endif /* CONFIG_VENDOR_XIAOMI */

};

#endif
