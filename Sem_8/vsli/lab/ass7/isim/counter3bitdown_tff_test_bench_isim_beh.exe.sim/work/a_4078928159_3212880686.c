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
static const char *ng0 = "/home/lp2917/14.7/ISE_DS/ass7/counter3bitdown_tff.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_3488768496604610246_503743352(char *, unsigned char , unsigned char );
unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );


static void work_a_4078928159_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    xsi_set_current_line(16, ng0);

LAB3:    t1 = (t0 + 5920);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_4078928159_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(17, ng0);

LAB3:    t1 = (t0 + 2304U);
    t2 = *((char **)t1);
    t3 = (0 - 2);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 5984);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_delta(t8, 1U, 1, 0LL);

LAB2:    t13 = (t0 + 5776);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_4078928159_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(18, ng0);

LAB3:    t1 = (t0 + 2304U);
    t2 = *((char **)t1);
    t3 = (0 - 2);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 2304U);
    t9 = *((char **)t8);
    t10 = (1 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t8 = (t9 + t13);
    t14 = *((unsigned char *)t8);
    t15 = ieee_p_2592010699_sub_3488768496604610246_503743352(IEEE_P_2592010699, t7, t14);
    t16 = (t0 + 6048);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = t15;
    xsi_driver_first_trans_delta(t16, 0U, 1, 0LL);

LAB2:    t21 = (t0 + 5792);
    *((int *)t21) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_4078928159_3212880686_p_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;
    unsigned char t15;
    unsigned char t16;
    unsigned char t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    xsi_set_current_line(23, ng0);
    t1 = (t0 + 1824U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1944U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 5808);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(24, ng0);
    t1 = (t0 + 6112);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);
    xsi_set_current_line(25, ng0);
    t1 = (t0 + 6176);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 2U, 1, 0LL);
    xsi_set_current_line(26, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3000U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    *((unsigned char *)t1) = (unsigned char)3;
    t6 = (t0 + 2704U);
    xsi_variable_act(t6);
    xsi_set_current_line(27, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3000U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    *((unsigned char *)t1) = (unsigned char)2;
    t6 = (t0 + 2824U);
    xsi_variable_act(t6);
    goto LAB3;

LAB5:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 2464U);
    t6 = *((char **)t2);
    t2 = (t0 + 3000U);
    t7 = *((char **)t2);
    t9 = *((int *)t7);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t6 + t13);
    t16 = *((unsigned char *)t2);
    t17 = (t16 == (unsigned char)2);
    if (t17 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3000U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6112);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 2U, 1, 0LL);
    xsi_set_current_line(34, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3000U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6176);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 2U, 1, 0LL);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3000U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 2760U);
    t7 = *((char **)t6);
    t6 = (t0 + 3000U);
    t8 = *((char **)t6);
    t20 = *((int *)t8);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t6 = (t7 + t24);
    *((unsigned char *)t6) = t3;
    t18 = (t0 + 2704U);
    xsi_variable_act(t18);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3000U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t4 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t3);
    t6 = (t0 + 2880U);
    t7 = *((char **)t6);
    t6 = (t0 + 3000U);
    t8 = *((char **)t6);
    t20 = *((int *)t8);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t6 = (t7 + t24);
    *((unsigned char *)t6) = t4;
    t18 = (t0 + 2824U);
    xsi_variable_act(t18);

LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 1984U);
    t5 = *((char **)t2);
    t14 = *((unsigned char *)t5);
    t15 = (t14 == (unsigned char)3);
    t3 = t15;
    goto LAB9;

LAB10:    xsi_set_current_line(30, ng0);
    t8 = (t0 + 2760U);
    t18 = *((char **)t8);
    t8 = (t0 + 3000U);
    t19 = *((char **)t8);
    t20 = *((int *)t19);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t8 = (t18 + t24);
    t25 = *((unsigned char *)t8);
    t26 = (t0 + 6112);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = t25;
    xsi_driver_first_trans_delta(t26, 2U, 1, 0LL);
    xsi_set_current_line(31, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3000U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6176);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 2U, 1, 0LL);
    goto LAB11;

}

static void work_a_4078928159_3212880686_p_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;
    unsigned char t15;
    unsigned char t16;
    unsigned char t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    xsi_set_current_line(23, ng0);
    t1 = (t0 + 1824U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1944U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 5824);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(24, ng0);
    t1 = (t0 + 6240);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);
    xsi_set_current_line(25, ng0);
    t1 = (t0 + 6304);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);
    xsi_set_current_line(26, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3120U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    *((unsigned char *)t1) = (unsigned char)3;
    t6 = (t0 + 2704U);
    xsi_variable_act(t6);
    xsi_set_current_line(27, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3120U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    *((unsigned char *)t1) = (unsigned char)2;
    t6 = (t0 + 2824U);
    xsi_variable_act(t6);
    goto LAB3;

LAB5:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 2464U);
    t6 = *((char **)t2);
    t2 = (t0 + 3120U);
    t7 = *((char **)t2);
    t9 = *((int *)t7);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t6 + t13);
    t16 = *((unsigned char *)t2);
    t17 = (t16 == (unsigned char)2);
    if (t17 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3120U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6240);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 1U, 1, 0LL);
    xsi_set_current_line(34, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3120U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6304);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 1U, 1, 0LL);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3120U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 2760U);
    t7 = *((char **)t6);
    t6 = (t0 + 3120U);
    t8 = *((char **)t6);
    t20 = *((int *)t8);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t6 = (t7 + t24);
    *((unsigned char *)t6) = t3;
    t18 = (t0 + 2704U);
    xsi_variable_act(t18);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3120U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t4 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t3);
    t6 = (t0 + 2880U);
    t7 = *((char **)t6);
    t6 = (t0 + 3120U);
    t8 = *((char **)t6);
    t20 = *((int *)t8);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t6 = (t7 + t24);
    *((unsigned char *)t6) = t4;
    t18 = (t0 + 2824U);
    xsi_variable_act(t18);

LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 1984U);
    t5 = *((char **)t2);
    t14 = *((unsigned char *)t5);
    t15 = (t14 == (unsigned char)3);
    t3 = t15;
    goto LAB9;

LAB10:    xsi_set_current_line(30, ng0);
    t8 = (t0 + 2760U);
    t18 = *((char **)t8);
    t8 = (t0 + 3120U);
    t19 = *((char **)t8);
    t20 = *((int *)t19);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t8 = (t18 + t24);
    t25 = *((unsigned char *)t8);
    t26 = (t0 + 6240);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = t25;
    xsi_driver_first_trans_delta(t26, 1U, 1, 0LL);
    xsi_set_current_line(31, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3120U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6304);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 1U, 1, 0LL);
    goto LAB11;

}

static void work_a_4078928159_3212880686_p_5(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;
    unsigned char t15;
    unsigned char t16;
    unsigned char t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    xsi_set_current_line(23, ng0);
    t1 = (t0 + 1824U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1944U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 5840);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(24, ng0);
    t1 = (t0 + 6368);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 0U, 1, 0LL);
    xsi_set_current_line(25, ng0);
    t1 = (t0 + 6432);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 0U, 1, 0LL);
    xsi_set_current_line(26, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3240U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    *((unsigned char *)t1) = (unsigned char)3;
    t6 = (t0 + 2704U);
    xsi_variable_act(t6);
    xsi_set_current_line(27, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3240U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    *((unsigned char *)t1) = (unsigned char)2;
    t6 = (t0 + 2824U);
    xsi_variable_act(t6);
    goto LAB3;

LAB5:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 2464U);
    t6 = *((char **)t2);
    t2 = (t0 + 3240U);
    t7 = *((char **)t2);
    t9 = *((int *)t7);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t6 + t13);
    t16 = *((unsigned char *)t2);
    t17 = (t16 == (unsigned char)2);
    if (t17 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3240U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6368);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 0U, 1, 0LL);
    xsi_set_current_line(34, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3240U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6432);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 0U, 1, 0LL);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3240U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 2760U);
    t7 = *((char **)t6);
    t6 = (t0 + 3240U);
    t8 = *((char **)t6);
    t20 = *((int *)t8);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t6 = (t7 + t24);
    *((unsigned char *)t6) = t3;
    t18 = (t0 + 2704U);
    xsi_variable_act(t18);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 2760U);
    t2 = *((char **)t1);
    t1 = (t0 + 3240U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t4 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t3);
    t6 = (t0 + 2880U);
    t7 = *((char **)t6);
    t6 = (t0 + 3240U);
    t8 = *((char **)t6);
    t20 = *((int *)t8);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t6 = (t7 + t24);
    *((unsigned char *)t6) = t4;
    t18 = (t0 + 2824U);
    xsi_variable_act(t18);

LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 1984U);
    t5 = *((char **)t2);
    t14 = *((unsigned char *)t5);
    t15 = (t14 == (unsigned char)3);
    t3 = t15;
    goto LAB9;

LAB10:    xsi_set_current_line(30, ng0);
    t8 = (t0 + 2760U);
    t18 = *((char **)t8);
    t8 = (t0 + 3240U);
    t19 = *((char **)t8);
    t20 = *((int *)t19);
    t21 = (t20 - 2);
    t22 = (t21 * -1);
    t23 = (1U * t22);
    t24 = (0 + t23);
    t8 = (t18 + t24);
    t25 = *((unsigned char *)t8);
    t26 = (t0 + 6368);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    *((unsigned char *)t30) = t25;
    xsi_driver_first_trans_delta(t26, 0U, 1, 0LL);
    xsi_set_current_line(31, ng0);
    t1 = (t0 + 2880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3240U);
    t5 = *((char **)t1);
    t9 = *((int *)t5);
    t10 = (t9 - 2);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t2 + t13);
    t3 = *((unsigned char *)t1);
    t6 = (t0 + 6432);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t18 = (t8 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t3;
    xsi_driver_first_trans_delta(t6, 0U, 1, 0LL);
    goto LAB11;

}


extern void work_a_4078928159_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4078928159_3212880686_p_0,(void *)work_a_4078928159_3212880686_p_1,(void *)work_a_4078928159_3212880686_p_2,(void *)work_a_4078928159_3212880686_p_3,(void *)work_a_4078928159_3212880686_p_4,(void *)work_a_4078928159_3212880686_p_5};
	xsi_register_didat("work_a_4078928159_3212880686", "isim/counter3bitdown_tff_test_bench_isim_beh.exe.sim/work/a_4078928159_3212880686.didat");
	xsi_register_executes(pe);
}
