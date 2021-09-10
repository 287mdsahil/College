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
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ass6/mux8x1_test_bench.vhd";
extern char *WORK_P_2199507181;

void work_p_2199507181_sub_17772734202513611019_24204227(char *, char *, int , int , char *, char *);


static void work_a_0259544508_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    int t11;
    int64 t12;
    int t13;

LAB0:    t1 = (t0 + 2744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 5103);
    *((int *)t2) = 0;
    t3 = (t0 + 5107);
    *((int *)t3) = 7;
    t4 = 0;
    t5 = 7;

LAB4:    if (t4 <= t5)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(46, ng0);
    t6 = (t0 + 2552);
    t7 = (t0 + 5103);
    t8 = (t0 + 1648U);
    t9 = *((char **)t8);
    t8 = (t0 + 5040U);
    work_p_2199507181_sub_17772734202513611019_24204227(WORK_P_2199507181, t6, *((int *)t7), 3, t9, t8);
    xsi_set_current_line(47, ng0);
    t2 = (t0 + 1648U);
    t3 = *((char **)t2);
    t2 = (t0 + 3128);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 3U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 5111);
    *((int *)t2) = 0;
    t3 = (t0 + 5115);
    *((int *)t3) = 127;
    t10 = 0;
    t11 = 127;

LAB8:    if (t10 <= t11)
        goto LAB9;

LAB11:
LAB6:    t2 = (t0 + 5103);
    t4 = *((int *)t2);
    t3 = (t0 + 5107);
    t5 = *((int *)t3);
    if (t4 == t5)
        goto LAB7;

LAB17:    t10 = (t4 + 1);
    t4 = t10;
    t6 = (t0 + 5103);
    *((int *)t6) = t4;
    goto LAB4;

LAB9:    xsi_set_current_line(49, ng0);
    t6 = (t0 + 2552);
    t7 = (t0 + 5111);
    t8 = (t0 + 1768U);
    t9 = *((char **)t8);
    t8 = (t0 + 5056U);
    work_p_2199507181_sub_17772734202513611019_24204227(WORK_P_2199507181, t6, *((int *)t7), 8, t9, t8);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1768U);
    t3 = *((char **)t2);
    t2 = (t0 + 3192);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 8U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(51, ng0);
    t12 = (1 * 1LL);
    t2 = (t0 + 2552);
    xsi_process_wait(t2, t12);

LAB14:    *((char **)t1) = &&LAB15;

LAB1:    return;
LAB10:    t2 = (t0 + 5111);
    t10 = *((int *)t2);
    t3 = (t0 + 5115);
    t11 = *((int *)t3);
    if (t10 == t11)
        goto LAB11;

LAB16:    t13 = (t10 + 1);
    t10 = t13;
    t6 = (t0 + 5111);
    *((int *)t6) = t10;
    goto LAB8;

LAB12:    goto LAB10;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}


extern void work_a_0259544508_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0259544508_2372691052_p_0};
	xsi_register_didat("work_a_0259544508_2372691052", "isim/mux8x1_test_bench_isim_beh.exe.sim/work/a_0259544508_2372691052.didat");
	xsi_register_executes(pe);
}
