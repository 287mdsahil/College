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
static const char *ng0 = "/home/sahil/College/Sem_8/vsli/lab/a4/a4_b.vhd";
extern char *WORK_P_2039065742;

void work_p_2039065742_sub_913065848825170742_3720953609(char *, char *, unsigned char , unsigned char , unsigned char , char *, char *);


static void work_a_3874496340_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 2872);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    t6 = *((unsigned char *)t5);
    t2 = (t0 + 1352U);
    t7 = *((char **)t2);
    t8 = *((unsigned char *)t7);
    t2 = (t0 + 1968U);
    t9 = *((char **)t2);
    t2 = (t9 + 0);
    t10 = (t0 + 2088U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    work_p_2039065742_sub_913065848825170742_3720953609(WORK_P_2039065742, t1, t4, t6, t8, t2, t10);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 1968U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t1 = (t0 + 3480);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t7 = (t5 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = t4;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(49, ng0);
    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t1 = (t0 + 3544);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t7 = (t5 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = t4;
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3384);
    *((int *)t1) = 1;

LAB1:    return;
}


extern void work_a_3874496340_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3874496340_3212880686_p_0};
	xsi_register_didat("work_a_3874496340_3212880686", "isim/tb_a4_ax1_isim_beh.exe.sim/work/a_3874496340_3212880686.didat");
	xsi_register_executes(pe);
}
