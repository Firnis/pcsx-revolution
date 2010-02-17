/***************************************************************************
 *   Copyright (C) 2007 Ryan Schultz, PCSX-df Team, PCSX team              *
 *   schultz.ryan@gmail.com, http://rschultz.ath.cx/code.php               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Steet, Fifth Floor, Boston, MA 02111-1307 USA.            *
 ***************************************************************************/

#ifndef __PSXCOUNTERS_H__
#define __PSXCOUNTERS_H__

#include "psxcommon.h"
#include "r3000a.h"
#include "psxmem.h"
#include "plugins.h"

typedef struct {
	u32 count, mode, target;
	u32 sCycle, Cycle, rate, interrupt;
	u32 IsCounting:1;
	u32 FutureTarget:1;
} psxCounter;

extern psxCounter psxCounters[5];

u32 psxNextCounter, psxNextsCounter;

#ifdef NEW_EVENTS
// We can separate them only with new interrupt system.
#	define SEPARATE_CNTS
#endif

#ifdef SEPARATE_CNTS
void psxRcntUpdate0();
void psxRcntUpdate1();
void psxRcntUpdate2();
void psxRcntUpdate3();
void psxRcntUpdate4();
#endif

void psxRcntInit();
void psxRcntUpdate();
void psxRcntWcount(u32 index, u32 value);
void psxRcntWmode(u32 index, u32 value);
void psxRcntWtarget(u32 index, u32 value);
u32 psxRcntRcount(u32 index);
u32 psxRcntRmode(u32 index);
int psxRcntFreeze(gzFile f, int Mode);

void psxUpdateVSyncRate();

#endif /* __PSXCOUNTERS_H__ */