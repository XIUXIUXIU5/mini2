#include "schedos-app.h"
#include "x86sync.h"

/*****************************************************************************
 * schedos-1
 *
 *   This tiny application prints red "1"s to the console.
 *   It yields the CPU to the kernel after each "1" using the sys_yield()
 *   system call.  This lets the kernel (schedos-kern.c) pick another
 *   application to run, if it wants.
 *
 *   The other schedos-* processes simply #include this file after defining
 *   PRINTCHAR appropriately.
 *
 *****************************************************************************/

#ifndef PRINTCHAR
#define PRINTCHAR	('1' | 0x0C00)
#define MYPRIORITY	1
#endif

void
start(void)
{
	int i;

	for (i = 0; i < RUNCOUNT; i++) {
		// Write characters to the console, yielding after each one.
		
	#define EX6

	#if defined(EX6)
		sys_printc(PRINTCHAR);
	#elif
		*cursorpos++ = PRINTCHAR;
	#endif
	}

	// Yield forever.
	sys_exit(0);
}
