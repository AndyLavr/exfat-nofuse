/*
 *  Copyright (C) 2012-2013 Samsung Electronics Co., Ltd.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _EXFAT_BLKDEV_H
#define _EXFAT_BLKDEV_H

#include "exfat_config.h"
#include "exfat_global.h"

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct __BD_INFO_T {
		s32 sector_size;
		s32 sector_size_bits;
		s32 sector_size_mask;
		s32 num_sectors;
		BOOL  opened;
	} BD_INFO_T;

	s32 bdev_init(void);
	s32 bdev_shutdown(void);
	s32 bdev_open(struct super_block *sb);
	s32 bdev_close(struct super_block *sb);
	s32 bdev_read(struct super_block *sb, sector_t secno, struct buffer_head **bh, u32 num_secs, s32 read);
	s32 bdev_write(struct super_block *sb, sector_t secno, struct buffer_head *bh, u32 num_secs, s32 sync);
	s32 bdev_sync(struct super_block *sb);
	s32 bdev_reada(struct super_block *sb, sector_t secno, u32 num_secs);
#ifdef __cplusplus
}
#endif
#endif
