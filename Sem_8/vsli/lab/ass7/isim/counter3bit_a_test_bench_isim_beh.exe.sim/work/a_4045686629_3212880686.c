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
static const char *ng0 = "/home/sahil/College/Sem_8/vsli/lab/ass7/srff.vhd";



static void work_a_4045686629_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    unsigned char t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    xsi_set_current_line(19, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1312U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 3544);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(20, ng0);
    t1 = (t0 + 3624);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(21, ng0);
    t1 = (t0 + 3688);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(22, ng0);
    t1 = (t0 + 2128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    t5 = (t0 + 2072U);
    xsi_variable_act(t5);
    xsi_set_current_line(23, ng0);
    t1 = (t0 + 2248U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)3;
    t5 = (t0 + 2192U);
    xsi_variable_act(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 1032U);
    t6 = *((char **)t2);
    t12 = *((unsigned char *)t6);
    t13 = (t12 == (unsigned char)2);
    if (t13 == 1)
        goto LAB13;

LAB14:    t11 = (unsigned char)0;

LAB15:    if (t11 != 0)
        goto LAB10;

LAB12:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)2);
    if (t9 == 1)
        goto LAB18;

LAB19:    t3 = (unsigned char)0;

LAB20:    if (t3 != 0)
        goto LAB16;

LAB17:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB23;

LAB24:    t3 = (unsigned char)0;

LAB25:    if (t3 != 0)
        goto LAB21;

LAB22:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 3624);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(40, ng0);
    t1 = (t0 + 3688);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(41, ng0);
    t1 = (t0 + 2128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)4;
    t5 = (t0 + 2072U);
    xsi_variable_act(t5);
    xsi_set_current_line(42, ng0);
    t1 = (t0 + 2248U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)4;
    t5 = (t0 + 2192U);
    xsi_variable_act(t5);

LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 1352U);
    t5 = *((char **)t2);
    t9 = *((unsigned char *)t5);
    t10 = (t9 == (unsigned char)3);
    t3 = t10;
    goto LAB9;

LAB10:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 2128U);
    t8 = *((char **)t2);
    t16 = *((unsigned char *)t8);
    t2 = (t0 + 3624);
    t17 = (t2 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = t16;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(27, ng0);
    t1 = (t0 + 2248U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3688);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB11;

LAB13:    t2 = (t0 + 1192U);
    t7 = *((char **)t2);
    t14 = *((unsigned char *)t7);
    t15 = (t14 == (unsigned char)2);
    t11 = t15;
    goto LAB15;

LAB16:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 3624);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t17 = *((char **)t8);
    *((unsigned char *)t17) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(30, ng0);
    t1 = (t0 + 3688);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(31, ng0);
    t1 = (t0 + 2128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    t5 = (t0 + 2072U);
    xsi_variable_act(t5);
    xsi_set_current_line(32, ng0);
    t1 = (t0 + 2248U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)3;
    t5 = (t0 + 2192U);
    xsi_variable_act(t5);
    goto LAB11;

LAB18:    t1 = (t0 + 1192U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t11 = (t10 == (unsigned char)3);
    t3 = t11;
    goto LAB20;

LAB21:    xsi_set_current_line(34, ng0);
    t1 = (t0 + 3624);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t17 = *((char **)t8);
    *((unsigned char *)t17) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 3688);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)3;
    t5 = (t0 + 2072U);
    xsi_variable_act(t5);
    xsi_set_current_line(37, ng0);
    t1 = (t0 + 2248U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    t5 = (t0 + 2192U);
    xsi_variable_act(t5);
    goto LAB11;

LAB23:    t1 = (t0 + 1192U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t11 = (t10 == (unsigned char)2);
    t3 = t11;
    goto LAB25;

}


extern void work_a_4045686629_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4045686629_3212880686_p_0};
	xsi_register_didat("work_a_4045686629_3212880686", "isim/counter3bit_a_test_bench_isim_beh.exe.sim/work/a_4045686629_3212880686.didat");
	xsi_register_executes(pe);
}
