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
extern char *IEEE_P_2592010699;
static const char *ng1 = "/home/sahil/College/Sem_8/vsli/lab/a2/a2_ax2a.vhd";

unsigned char ieee_p_2592010699_sub_3488546069778340532_503743352(char *, unsigned char , unsigned char );


char *work_a_3912455475_3212880686_sub_16921157127339253934_3057020925(char *t1, char *t2, unsigned char t3, char *t4, char *t5)
{
    char t6[128];
    char t7[24];
    char t8[16];
    char t15[8];
    char *t0;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned char t21;
    char *t22;
    unsigned char t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    int t29;
    int t30;
    int t31;

LAB0:    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 1;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t11 = (0 - 1);
    t12 = (t11 * -1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t10 = (t6 + 4U);
    t13 = ((IEEE_P_2592010699) + 4000);
    t14 = (t10 + 88U);
    *((char **)t14) = t13;
    t16 = (t10 + 56U);
    *((char **)t16) = t15;
    xsi_type_set_default_value(t13, t15, t8);
    t17 = (t10 + 64U);
    *((char **)t17) = t8;
    t18 = (t10 + 80U);
    *((unsigned int *)t18) = 2U;
    t19 = (t7 + 4U);
    *((unsigned char *)t19) = t3;
    t20 = (t7 + 5U);
    t21 = (t4 != 0);
    if (t21 == 1)
        goto LAB3;

LAB2:    t22 = (t7 + 13U);
    *((char **)t22) = t5;
    t23 = (t3 == (unsigned char)2);
    if (t23 != 0)
        goto LAB4;

LAB6:    t21 = (t3 == (unsigned char)3);
    if (t21 != 0)
        goto LAB7;

LAB8:
LAB5:    t9 = (t10 + 56U);
    t13 = *((char **)t9);
    t9 = (t8 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t0 = xsi_get_transient_memory(t12);
    memcpy(t0, t13, t12);
    t14 = (t8 + 0U);
    t11 = *((int *)t14);
    t16 = (t8 + 4U);
    t29 = *((int *)t16);
    t17 = (t8 + 8U);
    t30 = *((int *)t17);
    t18 = (t2 + 0U);
    t24 = (t18 + 0U);
    *((int *)t24) = t11;
    t24 = (t18 + 4U);
    *((int *)t24) = t29;
    t24 = (t18 + 8U);
    *((int *)t24) = t30;
    t31 = (t29 - t11);
    t28 = (t31 * t30);
    t28 = (t28 + 1);
    t24 = (t18 + 12U);
    *((unsigned int *)t24) = t28;

LAB1:    return t0;
LAB3:    *((char **)t20) = t4;
    goto LAB2;

LAB4:    t24 = (t1 + 4694);
    t26 = (t10 + 56U);
    t27 = *((char **)t26);
    t26 = (t27 + 0);
    memcpy(t26, t24, 2U);
    goto LAB5;

LAB7:    t9 = (t5 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t13 = (t1 + 4696);
    t23 = 1;
    if (t12 == 4U)
        goto LAB12;

LAB13:    t23 = 0;

LAB14:    if (t23 != 0)
        goto LAB9;

LAB11:    t9 = (t5 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t13 = (t1 + 4702);
    t21 = 1;
    if (t12 == 4U)
        goto LAB20;

LAB21:    t21 = 0;

LAB22:    if (t21 != 0)
        goto LAB18;

LAB19:    t9 = (t5 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t13 = (t1 + 4708);
    t21 = 1;
    if (t12 == 4U)
        goto LAB28;

LAB29:    t21 = 0;

LAB30:    if (t21 != 0)
        goto LAB26;

LAB27:    t9 = (t5 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t13 = (t1 + 4714);
    t21 = 1;
    if (t12 == 4U)
        goto LAB36;

LAB37:    t21 = 0;

LAB38:    if (t21 != 0)
        goto LAB34;

LAB35:    t9 = (t1 + 4720);
    t14 = (t10 + 56U);
    t16 = *((char **)t14);
    t14 = (t16 + 0);
    memcpy(t14, t9, 2U);

LAB10:    goto LAB5;

LAB9:    t18 = (t1 + 4700);
    t25 = (t10 + 56U);
    t26 = *((char **)t25);
    t25 = (t26 + 0);
    memcpy(t25, t18, 2U);
    goto LAB10;

LAB12:    t28 = 0;

LAB15:    if (t28 < t12)
        goto LAB16;
    else
        goto LAB14;

LAB16:    t16 = (t4 + t28);
    t17 = (t13 + t28);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB13;

LAB17:    t28 = (t28 + 1);
    goto LAB15;

LAB18:    t18 = (t1 + 4706);
    t25 = (t10 + 56U);
    t26 = *((char **)t25);
    t25 = (t26 + 0);
    memcpy(t25, t18, 2U);
    goto LAB10;

LAB20:    t28 = 0;

LAB23:    if (t28 < t12)
        goto LAB24;
    else
        goto LAB22;

LAB24:    t16 = (t4 + t28);
    t17 = (t13 + t28);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB21;

LAB25:    t28 = (t28 + 1);
    goto LAB23;

LAB26:    t18 = (t1 + 4712);
    t25 = (t10 + 56U);
    t26 = *((char **)t25);
    t25 = (t26 + 0);
    memcpy(t25, t18, 2U);
    goto LAB10;

LAB28:    t28 = 0;

LAB31:    if (t28 < t12)
        goto LAB32;
    else
        goto LAB30;

LAB32:    t16 = (t4 + t28);
    t17 = (t13 + t28);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB29;

LAB33:    t28 = (t28 + 1);
    goto LAB31;

LAB34:    t18 = (t1 + 4718);
    t25 = (t10 + 56U);
    t26 = *((char **)t25);
    t25 = (t26 + 0);
    memcpy(t25, t18, 2U);
    goto LAB10;

LAB36:    t28 = 0;

LAB39:    if (t28 < t12)
        goto LAB40;
    else
        goto LAB38;

LAB40:    t16 = (t4 + t28);
    t17 = (t13 + t28);
    if (*((unsigned char *)t16) != *((unsigned char *)t17))
        goto LAB37;

LAB41:    t28 = (t28 + 1);
    goto LAB39;

LAB42:;
}

static void work_a_3912455475_3212880686_p_0(char *t0)
{
    char t38[16];
    char t43[16];
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
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    unsigned char t23;
    char *t24;
    char *t25;
    int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned char t30;
    unsigned char t31;
    char *t32;
    char *t33;
    int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    int t39;
    int t40;
    int t41;
    int t42;
    int t44;
    int t45;
    int t46;
    char *t47;
    int t48;
    int t49;
    char *t50;
    char *t51;
    int t52;
    char *t53;
    char *t54;
    char *t55;

LAB0:    xsi_set_current_line(67, ng1);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = (15 - 15);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 1032U);
    t9 = *((char **)t8);
    t10 = (14 - 15);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t8 = (t9 + t13);
    t14 = *((unsigned char *)t8);
    t15 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t7, t14);
    t16 = (t0 + 1032U);
    t17 = *((char **)t16);
    t18 = (13 - 15);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t16 = (t17 + t21);
    t22 = *((unsigned char *)t16);
    t23 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t15, t22);
    t24 = (t0 + 1032U);
    t25 = *((char **)t24);
    t26 = (12 - 15);
    t27 = (t26 * -1);
    t28 = (1U * t27);
    t29 = (0 + t28);
    t24 = (t25 + t29);
    t30 = *((unsigned char *)t24);
    t31 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t23, t30);
    t32 = (t0 + 1488U);
    t33 = *((char **)t32);
    t34 = (3 - 3);
    t35 = (t34 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t32 = (t33 + t37);
    *((unsigned char *)t32) = t31;
    xsi_set_current_line(68, ng1);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = (11 - 15);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 1032U);
    t9 = *((char **)t8);
    t10 = (10 - 15);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t8 = (t9 + t13);
    t14 = *((unsigned char *)t8);
    t15 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t7, t14);
    t16 = (t0 + 1032U);
    t17 = *((char **)t16);
    t18 = (9 - 15);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t16 = (t17 + t21);
    t22 = *((unsigned char *)t16);
    t23 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t15, t22);
    t24 = (t0 + 1032U);
    t25 = *((char **)t24);
    t26 = (8 - 15);
    t27 = (t26 * -1);
    t28 = (1U * t27);
    t29 = (0 + t28);
    t24 = (t25 + t29);
    t30 = *((unsigned char *)t24);
    t31 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t23, t30);
    t32 = (t0 + 1488U);
    t33 = *((char **)t32);
    t34 = (2 - 3);
    t35 = (t34 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t32 = (t33 + t37);
    *((unsigned char *)t32) = t31;
    xsi_set_current_line(69, ng1);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = (7 - 15);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 1032U);
    t9 = *((char **)t8);
    t10 = (6 - 15);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t8 = (t9 + t13);
    t14 = *((unsigned char *)t8);
    t15 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t7, t14);
    t16 = (t0 + 1032U);
    t17 = *((char **)t16);
    t18 = (5 - 15);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t16 = (t17 + t21);
    t22 = *((unsigned char *)t16);
    t23 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t15, t22);
    t24 = (t0 + 1032U);
    t25 = *((char **)t24);
    t26 = (4 - 15);
    t27 = (t26 * -1);
    t28 = (1U * t27);
    t29 = (0 + t28);
    t24 = (t25 + t29);
    t30 = *((unsigned char *)t24);
    t31 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t23, t30);
    t32 = (t0 + 1488U);
    t33 = *((char **)t32);
    t34 = (1 - 3);
    t35 = (t34 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t32 = (t33 + t37);
    *((unsigned char *)t32) = t31;
    xsi_set_current_line(70, ng1);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = (3 - 15);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 1032U);
    t9 = *((char **)t8);
    t10 = (2 - 15);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t8 = (t9 + t13);
    t14 = *((unsigned char *)t8);
    t15 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t7, t14);
    t16 = (t0 + 1032U);
    t17 = *((char **)t16);
    t18 = (1 - 15);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t16 = (t17 + t21);
    t22 = *((unsigned char *)t16);
    t23 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t15, t22);
    t24 = (t0 + 1032U);
    t25 = *((char **)t24);
    t26 = (0 - 15);
    t27 = (t26 * -1);
    t28 = (1U * t27);
    t29 = (0 + t28);
    t24 = (t25 + t29);
    t30 = *((unsigned char *)t24);
    t31 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t23, t30);
    t32 = (t0 + 1488U);
    t33 = *((char **)t32);
    t34 = (0 - 3);
    t35 = (t34 * -1);
    t36 = (1U * t35);
    t37 = (0 + t36);
    t32 = (t33 + t37);
    *((unsigned char *)t32) = t31;
    xsi_set_current_line(72, ng1);
    t1 = (t0 + 1488U);
    t2 = *((char **)t1);
    t1 = (t0 + 4632U);
    t8 = work_a_3912455475_3212880686_sub_16921157127339253934_3057020925(t0, t38, (unsigned char)3, t2, t1);
    t9 = (t38 + 12U);
    t4 = *((unsigned int *)t9);
    t4 = (t4 * 1U);
    t7 = (2U != t4);
    if (t7 == 1)
        goto LAB2;

LAB3:    t16 = (t0 + 2984);
    t17 = (t16 + 56U);
    t24 = *((char **)t17);
    t25 = (t24 + 56U);
    t32 = *((char **)t25);
    memcpy(t32, t8, 2U);
    xsi_driver_first_trans_delta(t16, 0U, 2U, 0LL);
    xsi_set_current_line(73, ng1);
    t1 = (t0 + 4722);
    t7 = (2U != 2U);
    if (t7 == 1)
        goto LAB4;

LAB5:    t8 = (t0 + 2984);
    t9 = (t8 + 56U);
    t16 = *((char **)t9);
    t17 = (t16 + 56U);
    t24 = *((char **)t17);
    memcpy(t24, t1, 2U);
    xsi_driver_first_trans_delta(t8, 2U, 2U, 0LL);
    xsi_set_current_line(76, ng1);
    t1 = (t0 + 4724);
    *((int *)t1) = 0;
    t2 = (t0 + 4728);
    *((int *)t2) = 3;
    t3 = 0;
    t10 = 3;

LAB6:    if (t3 <= t10)
        goto LAB7;

LAB9:    t1 = (t0 + 2904);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_size_not_matching(2U, t4, 0);
    goto LAB3;

LAB4:    xsi_size_not_matching(2U, 2U, 0);
    goto LAB5;

LAB7:    xsi_set_current_line(77, ng1);
    t8 = (t0 + 1488U);
    t9 = *((char **)t8);
    t8 = (t0 + 4724);
    t18 = *((int *)t8);
    t26 = (t18 - 3);
    t4 = (t26 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t8));
    t5 = (1U * t4);
    t6 = (0 + t5);
    t16 = (t9 + t6);
    t7 = *((unsigned char *)t16);
    t17 = (t0 + 1032U);
    t24 = *((char **)t17);
    t17 = (t0 + 4724);
    t34 = *((int *)t17);
    t39 = (4 * t34);
    t40 = (t39 + 3);
    t11 = (15 - t40);
    t25 = (t0 + 4724);
    t41 = *((int *)t25);
    t42 = (4 * t41);
    xsi_vhdl_check_range_of_slice(15, 0, -1, t40, t42, -1);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t32 = (t24 + t13);
    t33 = (t0 + 4724);
    t44 = *((int *)t33);
    t45 = (4 * t44);
    t46 = (t45 + 3);
    t47 = (t0 + 4724);
    t48 = *((int *)t47);
    t49 = (4 * t48);
    t50 = (t43 + 0U);
    t51 = (t50 + 0U);
    *((int *)t51) = t46;
    t51 = (t50 + 4U);
    *((int *)t51) = t49;
    t51 = (t50 + 8U);
    *((int *)t51) = -1;
    t52 = (t49 - t46);
    t19 = (t52 * -1);
    t19 = (t19 + 1);
    t51 = (t50 + 12U);
    *((unsigned int *)t51) = t19;
    t51 = work_a_3912455475_3212880686_sub_16921157127339253934_3057020925(t0, t38, t7, t32, t43);
    t53 = (t0 + 1608U);
    t54 = *((char **)t53);
    t53 = (t54 + 0);
    t55 = (t38 + 12U);
    t19 = *((unsigned int *)t55);
    t19 = (t19 * 1U);
    memcpy(t53, t51, t19);
    xsi_set_current_line(78, ng1);
    t1 = (t0 + 1488U);
    t2 = *((char **)t1);
    t1 = (t0 + 4724);
    t18 = *((int *)t1);
    t26 = (t18 - 3);
    t4 = (t26 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t1));
    t5 = (1U * t4);
    t6 = (0 + t5);
    t8 = (t2 + t6);
    t7 = *((unsigned char *)t8);
    t14 = (t7 == (unsigned char)3);
    if (t14 != 0)
        goto LAB10;

LAB12:
LAB11:
LAB8:    t1 = (t0 + 4724);
    t3 = *((int *)t1);
    t2 = (t0 + 4728);
    t10 = *((int *)t2);
    if (t3 == t10)
        goto LAB9;

LAB13:    t18 = (t3 + 1);
    t3 = t18;
    t8 = (t0 + 4724);
    *((int *)t8) = t3;
    goto LAB6;

LAB10:    xsi_set_current_line(79, ng1);
    t9 = (t0 + 1608U);
    t16 = *((char **)t9);
    t9 = (t0 + 2984);
    t17 = (t9 + 56U);
    t24 = *((char **)t17);
    t25 = (t24 + 56U);
    t32 = *((char **)t25);
    memcpy(t32, t16, 2U);
    xsi_driver_first_trans_delta(t9, 2U, 2U, 0LL);
    goto LAB11;

}


extern void work_a_3912455475_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3912455475_3212880686_p_0};
	static char *se[] = {(void *)work_a_3912455475_3212880686_sub_16921157127339253934_3057020925};
	xsi_register_didat("work_a_3912455475_3212880686", "isim/tb_a2_ax2a_isim_beh.exe.sim/work/a_3912455475_3212880686.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
