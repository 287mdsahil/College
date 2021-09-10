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
static const char *ng0 = "/home/sahil/College/Sem_8/vsli/lab/a4/a4_ax2.vhd";
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_16439989833707593767_503743352(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );


static void work_a_3578864400_3212880686_p_0(char *t0)
{
    char t1[16];
    char t7[16];
    char t16[16];
    char t21[16];
    char t26[16];
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    char *t12;
    unsigned char t13;
    char *t14;
    unsigned char t15;
    char *t17;
    char *t18;
    char *t19;
    unsigned char t20;
    char *t22;
    char *t23;
    char *t24;
    unsigned char t25;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned char t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;

LAB0:    xsi_set_current_line(53, ng0);

LAB3:    t2 = (t0 + 1192U);
    t3 = *((char **)t2);
    t4 = (3 - 3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t2 = (t3 + t6);
    t8 = (t7 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 3;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t10 = (0 - 3);
    t11 = (t10 * -1);
    t11 = (t11 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t11;
    t9 = (t0 + 1352U);
    t12 = *((char **)t9);
    t13 = *((unsigned char *)t12);
    t9 = (t0 + 1352U);
    t14 = *((char **)t9);
    t15 = *((unsigned char *)t14);
    t17 = ((IEEE_P_2592010699) + 4000);
    t9 = xsi_base_array_concat(t9, t16, t17, (char)99, t13, (char)99, t15, (char)101);
    t18 = (t0 + 1352U);
    t19 = *((char **)t18);
    t20 = *((unsigned char *)t19);
    t22 = ((IEEE_P_2592010699) + 4000);
    t18 = xsi_base_array_concat(t18, t21, t22, (char)97, t9, t16, (char)99, t20, (char)101);
    t23 = (t0 + 1352U);
    t24 = *((char **)t23);
    t25 = *((unsigned char *)t24);
    t27 = ((IEEE_P_2592010699) + 4000);
    t23 = xsi_base_array_concat(t23, t26, t27, (char)97, t18, t21, (char)99, t25, (char)101);
    t28 = ieee_p_2592010699_sub_16439989833707593767_503743352(IEEE_P_2592010699, t1, t2, t7, t23, t26);
    t29 = (t1 + 12U);
    t11 = *((unsigned int *)t29);
    t30 = (1U * t11);
    t31 = (4U != t30);
    if (t31 == 1)
        goto LAB5;

LAB6:    t32 = (t0 + 3912);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memcpy(t36, t28, 4U);
    xsi_driver_first_trans_delta(t32, 0U, 4U, 0LL);

LAB2:    t37 = (t0 + 3800);
    *((int *)t37) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(4U, t30, 0);
    goto LAB6;

}

static void work_a_3578864400_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    char *t6;
    int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned char t11;
    unsigned char t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    static char *nl0[] = {&&LAB6, &&LAB6, &&LAB6, &&LAB5, &&LAB6, &&LAB6, &&LAB6, &&LAB6, &&LAB6};

LAB0:    t1 = (t0 + 3232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t2 = (char *)((nl0) + t4);
    goto **((char **)t2);

LAB4:    xsi_set_current_line(55, ng0);

LAB9:    t2 = (t0 + 3816);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB10;

LAB1:    return;
LAB5:    xsi_set_current_line(55, ng0);
    t5 = (t0 + 1832U);
    t6 = *((char **)t5);
    t7 = (4 - 4);
    t8 = (t7 * -1);
    t9 = (1U * t8);
    t10 = (0 + t9);
    t5 = (t6 + t10);
    t11 = *((unsigned char *)t5);
    t12 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t11);
    t13 = (t0 + 3976);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = t12;
    xsi_driver_first_trans_delta(t13, 0U, 1, 0LL);
    goto LAB4;

LAB6:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t7 = (4 - 4);
    t8 = (t7 * -1);
    t9 = (1U * t8);
    t10 = (0 + t9);
    t2 = (t3 + t10);
    t4 = *((unsigned char *)t2);
    t5 = (t0 + 3976);
    t6 = (t5 + 56U);
    t13 = *((char **)t6);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t4;
    xsi_driver_first_trans_delta(t5, 0U, 1, 0LL);
    goto LAB4;

LAB7:    t3 = (t0 + 3816);
    *((int *)t3) = 0;
    goto LAB2;

LAB8:    goto LAB7;

LAB10:    goto LAB8;

}

static void work_a_3578864400_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(56, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = (4 - 3);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t6 = (t0 + 4040);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_delta(t6, 1U, 4U, 0LL);

LAB2:    t11 = (t0 + 3832);
    *((int *)t11) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3578864400_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3578864400_3212880686_p_0,(void *)work_a_3578864400_3212880686_p_1,(void *)work_a_3578864400_3212880686_p_2};
	xsi_register_didat("work_a_3578864400_3212880686", "isim/tb_a4_ax2_isim_beh.exe.sim/work/a_3578864400_3212880686.didat");
	xsi_register_executes(pe);
}
