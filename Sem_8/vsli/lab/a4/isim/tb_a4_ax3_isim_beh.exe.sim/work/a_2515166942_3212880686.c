/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/sahil/College/Sem_8/vsli/lab/a4/a4_d.vhd";
extern char *WORK_P_2039065742;

void work_p_2039065742_sub_6416716729160755020_3720953609(char *, char *, char *, char *, char *);


static void work_a_2515166942_3212880686_p_0(char *t0)
{
    char t4[8];
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 2432);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    memcpy(t4, t3, 4U);
    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    memcpy(t6, t5, 4U);
    t2 = (t0 + 1648U);
    t7 = *((char **)t2);
    work_p_2039065742_sub_6416716729160755020_3720953609(WORK_P_2039065742, t1, t4, t6, t7);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 1648U);
    t2 = *((char **)t1);
    t1 = (t0 + 3040);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 5U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 2944);
    *((int *)t1) = 1;

LAB1:    return;
}


extern void work_a_2515166942_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2515166942_3212880686_p_0};
	xsi_register_didat("work_a_2515166942_3212880686", "isim/tb_a4_ax3_isim_beh.exe.sim/work/a_2515166942_3212880686.didat");
	xsi_register_executes(pe);
}
