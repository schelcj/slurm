/*****************************************************************************\
 *  attach.c - Definitions needed for parallel debugger
 *  $Id$
 *****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Mark Grondona <grondona1@llnl.gov>, et. al.
 *  UCRL-CODE-226842.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#if HAVE_CONFIG_H
#  include "config.h"
#endif

#include "src/common/log.h"

#include "src/slaunch/attach.h"

/*
 *  Instantiate extern variables from attach.h
 */
MPIR_PROCDESC *MPIR_proctable;
int MPIR_proctable_size;
VOLATILE int MPIR_debug_state;
VOLATILE int MPIR_debug_gate;
int MPIR_being_debugged;
int MPIR_i_am_starter;
int MPIR_acquired_pre_main;
char *totalview_jobid;

void MPIR_Breakpoint(void)
{
	/* 
	 * This just notifies parallel debugger that some event of 
	 *  interest occurred.
	 */ 
	debug("In MPIR_Breakpoint");
}

