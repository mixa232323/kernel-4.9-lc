/*
 * Copyright (C) 2011-2014 MediaTek Inc.
 *
 * This program is free software: you can
 * redistribute it and/or modify it under
 * the terms of the GNU General Public License
 * version 2 as published by the Free Software
 * Foundation.
 *
 * This program is distributed in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU
 * General Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CAMERA_SYSRAM_H
#define CAMERA_SYSRAM_H
/* ---------------------------------------------- */
#define SYSRAM_DEV_NAME     "camera-sysram"
#define SYSRAM_MAGIC_NO     'p'
/* ---------------------------------------------- */

#ifdef CONFIG_COMPAT
/* 64 bit */
#include <linux/fs.h>
#include <linux/compat.h>
#endif


enum SYSRAM_USER_ENUM {
	SYSRAM_USER_VIDO,
	SYSRAM_USER_GDMA,
	SYSRAM_USER_SW_FD,
	SYSRAM_USER_AMOUNT,
	SYSRAM_USER_NONE
};
/*  */
struct SYSRAM_ALLOC_STRUCT {
	unsigned int Alignment;
	unsigned int Size;
	enum SYSRAM_USER_ENUM User;
	unsigned int Addr;	/* In/Out : address */
	unsigned int TimeoutMS;	/* In : millisecond */
};
/*  */
enum SYSRAM_CMD_ENUM {
	SYSRAM_CMD_ALLOC,
	SYSRAM_CMD_FREE,
	SYSRAM_CMD_DUMP
};


#ifdef CONFIG_COMPAT
enum compat_SYSRAM_USER_ENUM {
	compat_SYSRAM_USER_VIDO,
	compat_SYSRAM_USER_GDMA,
	compat_SYSRAM_USER_SW_FD,
	compat_SYSRAM_USER_AMOUNT,
	compat_SYSRAM_USER_NONE
};
/*  */
struct compat_SYSRAM_ALLOC_STRUCT {
	unsigned int Alignment;
	unsigned int Size;
	enum compat_SYSRAM_USER_ENUM User;
	unsigned int Addr;	/* In/Out : address */
	unsigned int TimeoutMS;	/* In : millisecond */
};
#endif


/* ---------------------------------------------- */
#define SYSRAM_ALLOC    _IOWR(SYSRAM_MAGIC_NO, \
SYSRAM_CMD_ALLOC,   struct SYSRAM_ALLOC_STRUCT)
#define SYSRAM_FREE     _IOWR(SYSRAM_MAGIC_NO, \
SYSRAM_CMD_FREE,    enum SYSRAM_USER_ENUM)
#define SYSRAM_DUMP     _IO(SYSRAM_MAGIC_NO, \
SYSRAM_CMD_DUMP)

#ifdef CONFIG_COMPAT
#define COMPAT_SYSRAM_ALLOC    _IOWR(SYSRAM_MAGIC_NO, \
SYSRAM_CMD_ALLOC,   struct compat_SYSRAM_ALLOC_STRUCT)
#define COMPAT_SYSRAM_FREE     _IOWR(SYSRAM_MAGIC_NO, \
SYSRAM_CMD_FREE,    enum compat_SYSRAM_USER_ENUM)
#endif
/* ---------------------------------------------- */
#endif
