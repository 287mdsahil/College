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
static const char *ng0 = "/home/sahil/College/Sem_8/vsli/lab/a2/tb_a2_ax2a.vhd";



static void work_a_3332303039_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    int t10;
    int t11;
    int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    int64 t17;

LAB0:    t1 = (t0 + 2344U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 4420);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 4436);
    *((int *)t2) = 0;
    t3 = (t0 + 4440);
    *((int *)t3) = 15;
    t9 = 0;
    t10 = 15;

LAB4:    if (t9 <= t10)
        goto LAB5;

LAB7:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 4444);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(78, ng0);
    t17 = (1 * 1LL);
    t2 = (t0 + 2152);
    xsi_process_wait(t2, t17);

LAB15:    *((char **)t1) = &&LAB16;

LAB1:    return;
LAB5:    xsi_set_current_line(72, ng0);
    t4 = (t0 + 4436);
    t11 = *((int *)t4);
    t12 = (t11 - 15);
    t13 = (t12 * -1);
    t14 = (1 * t13);
    t15 = (0U + t14);
    t5 = (t0 + 2728);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t16 = *((char **)t8);
    *((unsigned char *)t16) = (unsigned char)3;
    xsi_driver_first_trans_delta(t5, t15, 1, 0LL);
    xsi_set_current_line(73, ng0);
    t17 = (1 * 1LL);
    t2 = (t0 + 2152);
    xsi_process_wait(t2, t17);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB6:    t2 = (t0 + 4436);
    t9 = *((int *)t2);
    t3 = (t0 + 4440);
    t10 = *((int *)t3);
    if (t9 == t10)
        goto LAB7;

LAB12:    t11 = (t9 + 1);
    t9 = t11;
    t4 = (t0 + 4436);
    *((int *)t4) = t9;
    goto LAB4;

LAB8:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 4436);
    t11 = *((int *)t2);
    t12 = (t11 - 15);
    t13 = (t12 * -1);
    t14 = (1 * t13);
    t15 = (0U + t14);
    t3 = (t0 + 2728);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t3, t15, 1, 0LL);
    goto LAB6;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB13:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 4460);
    t4 = (t0 + 2728);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(80, ng0);
    t17 = (1 * 1LL);
    t2 = (t0 + 2152);
    xsi_process_wait(t2, t17);

LAB19:    *((char **)t1) = &&LAB20;
    goto LAB1;

LAB14:    goto LAB13;

LAB16:    goto LAB14;

LAB17:    goto LAB2;

LAB18:    goto LAB17;

LAB20:    goto LAB18;

}


extern void work_a_3332303039_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3332303039_2372691052_p_0};
	xsi_register_didat("work_a_3332303039_2372691052", "isim/tb_a2_ax2a_isim_beh.exe.sim/work/a_3332303039_2372691052.didat");
	xsi_register_executes(pe);
}
