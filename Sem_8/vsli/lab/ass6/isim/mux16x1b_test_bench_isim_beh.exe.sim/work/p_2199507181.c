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
extern char *STD_STANDARD;
static const char *ng1 = "rem 0 asked for.  Divide by zero error.";



void work_p_2199507181_sub_17772734202513611019_24204227(char *t0, char *t1, int t2, int t3, char *t4, char *t5)
{
    char t6[248];
    char t7[32];
    char t11[8];
    char t17[8];
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    int t26;
    unsigned char t27;
    int t28;
    int t29;
    int t30;
    int t31;
    unsigned char t32;
    int t33;
    int t34;
    int t35;
    int t36;
    unsigned int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;

LAB0:    t8 = (t6 + 4U);
    t9 = ((STD_STANDARD) + 384);
    t10 = (t8 + 88U);
    *((char **)t10) = t9;
    t12 = (t8 + 56U);
    *((char **)t12) = t11;
    xsi_type_set_default_value(t9, t11, 0);
    t13 = (t8 + 80U);
    *((unsigned int *)t13) = 4U;
    t14 = (t6 + 124U);
    t15 = ((STD_STANDARD) + 384);
    t16 = (t14 + 88U);
    *((char **)t16) = t15;
    t18 = (t14 + 56U);
    *((char **)t18) = t17;
    xsi_type_set_default_value(t15, t17, 0);
    t19 = (t14 + 80U);
    *((unsigned int *)t19) = 4U;
    t20 = (t7 + 4U);
    *((int *)t20) = t2;
    t21 = (t7 + 8U);
    *((int *)t21) = t3;
    t22 = (t7 + 12U);
    *((char **)t22) = t4;
    t23 = (t7 + 20U);
    *((char **)t23) = t5;
    t24 = (t8 + 56U);
    t25 = *((char **)t24);
    t24 = (t25 + 0);
    *((int *)t24) = t2;
    t9 = (t14 + 56U);
    t10 = *((char **)t9);
    t9 = (t10 + 0);
    *((int *)t9) = 0;

LAB2:    t9 = (t14 + 56U);
    t10 = *((char **)t9);
    t26 = *((int *)t10);
    t27 = (t26 < t3);
    if (t27 != 0)
        goto LAB3;

LAB5:
LAB1:    return;
LAB3:    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t28 = *((int *)t12);
    if (2 == 0)
        goto LAB9;

LAB10:    t29 = abs(t28);
    t30 = (t29 % 2);
    if (t28 < 0)
        goto LAB11;

LAB12:    t32 = (t30 == 0);
    if (t32 != 0)
        goto LAB6;

LAB8:    t9 = (t14 + 56U);
    t10 = *((char **)t9);
    t26 = *((int *)t10);
    t9 = (t5 + 0U);
    t28 = *((int *)t9);
    t12 = (t5 + 8U);
    t29 = *((int *)t12);
    t30 = (t26 - t28);
    t37 = (t30 * t29);
    t13 = (t5 + 4U);
    t31 = *((int *)t13);
    xsi_vhdl_check_range_of_index(t28, t31, t29, t26);
    t39 = (1U * t37);
    t40 = (0 + t39);
    t15 = (t4 + t40);
    *((unsigned char *)t15) = (unsigned char)3;

LAB7:    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t26 = *((int *)t10);
    t28 = (t26 / 2);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t9 = (t12 + 0);
    *((int *)t9) = t28;
    t9 = (t14 + 56U);
    t10 = *((char **)t9);
    t26 = *((int *)t10);
    t28 = (t26 + 1);
    t9 = (t14 + 56U);
    t12 = *((char **)t9);
    t9 = (t12 + 0);
    *((int *)t9) = t28;
    goto LAB2;

LAB4:;
LAB6:    t9 = (t14 + 56U);
    t13 = *((char **)t9);
    t33 = *((int *)t13);
    t9 = (t5 + 0U);
    t34 = *((int *)t9);
    t15 = (t5 + 8U);
    t35 = *((int *)t15);
    t36 = (t33 - t34);
    t37 = (t36 * t35);
    t16 = (t5 + 4U);
    t38 = *((int *)t16);
    xsi_vhdl_check_range_of_index(t34, t38, t35, t33);
    t39 = (1U * t37);
    t40 = (0 + t39);
    t18 = (t4 + t40);
    *((unsigned char *)t18) = (unsigned char)2;
    goto LAB7;

LAB9:    xsi_error(ng1);
    goto LAB10;

LAB11:    t31 = (-(t30));
    t30 = t31;
    goto LAB12;

}


extern void work_p_2199507181_init()
{
	static char *se[] = {(void *)work_p_2199507181_sub_17772734202513611019_24204227};
	xsi_register_didat("work_p_2199507181", "isim/mux16x1b_test_bench_isim_beh.exe.sim/work/p_2199507181.didat");
	xsi_register_subprogram_executes(se);
}
