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
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_16439989833707593767_503743352(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_3488546069778340532_503743352(char *, unsigned char , unsigned char );
unsigned char ieee_p_2592010699_sub_3488768496604610246_503743352(char *, unsigned char , unsigned char );
unsigned char ieee_p_2592010699_sub_3488768497506413324_503743352(char *, unsigned char , unsigned char );
unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );


void work_p_2039065742_sub_17772734202513611019_3720953609(char *t0, char *t1, int t2, int t3, char *t4, char *t5)
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

void work_p_2039065742_sub_18409588216962174043_3720953609(char *t0, char *t1, unsigned char t2, unsigned char t3, char *t4, char *t5)
{
    char t7[24];
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned char t12;
    char *t13;

LAB0:    t8 = (t7 + 4U);
    *((unsigned char *)t8) = t2;
    t9 = (t7 + 5U);
    *((unsigned char *)t9) = t3;
    t10 = (t7 + 6U);
    *((char **)t10) = t4;
    t11 = (t7 + 14U);
    *((char **)t11) = t5;
    t12 = ieee_p_2592010699_sub_3488768497506413324_503743352(IEEE_P_2592010699, t2, t3);
    t13 = (t4 + 0);
    *((unsigned char *)t13) = t12;
    t12 = ieee_p_2592010699_sub_3488768496604610246_503743352(IEEE_P_2592010699, t2, t3);
    t13 = (t5 + 0);
    *((unsigned char *)t13) = t12;

LAB1:    return;
}

void work_p_2039065742_sub_913065848825170742_3720953609(char *t0, char *t1, unsigned char t2, unsigned char t3, unsigned char t4, char *t5, char *t6)
{
    char t7[488];
    char t8[24];
    char t12[8];
    char t18[8];
    char t24[8];
    char t30[8];
    char *t9;
    char *t10;
    char *t11;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    unsigned char t42;
    unsigned char t43;

LAB0:    t9 = (t7 + 4U);
    t10 = ((IEEE_P_2592010699) + 3312);
    t11 = (t9 + 88U);
    *((char **)t11) = t10;
    t13 = (t9 + 56U);
    *((char **)t13) = t12;
    xsi_type_set_default_value(t10, t12, 0);
    t14 = (t9 + 80U);
    *((unsigned int *)t14) = 1U;
    t15 = (t7 + 124U);
    t16 = ((IEEE_P_2592010699) + 3312);
    t17 = (t15 + 88U);
    *((char **)t17) = t16;
    t19 = (t15 + 56U);
    *((char **)t19) = t18;
    xsi_type_set_default_value(t16, t18, 0);
    t20 = (t15 + 80U);
    *((unsigned int *)t20) = 1U;
    t21 = (t7 + 244U);
    t22 = ((IEEE_P_2592010699) + 3312);
    t23 = (t21 + 88U);
    *((char **)t23) = t22;
    t25 = (t21 + 56U);
    *((char **)t25) = t24;
    xsi_type_set_default_value(t22, t24, 0);
    t26 = (t21 + 80U);
    *((unsigned int *)t26) = 1U;
    t27 = (t7 + 364U);
    t28 = ((IEEE_P_2592010699) + 3312);
    t29 = (t27 + 88U);
    *((char **)t29) = t28;
    t31 = (t27 + 56U);
    *((char **)t31) = t30;
    xsi_type_set_default_value(t28, t30, 0);
    t32 = (t27 + 80U);
    *((unsigned int *)t32) = 1U;
    t33 = (t8 + 4U);
    *((unsigned char *)t33) = t2;
    t34 = (t8 + 5U);
    *((unsigned char *)t34) = t3;
    t35 = (t8 + 6U);
    *((unsigned char *)t35) = t4;
    t36 = (t8 + 7U);
    *((char **)t36) = t5;
    t37 = (t8 + 15U);
    *((char **)t37) = t6;
    t38 = (t15 + 56U);
    t39 = *((char **)t38);
    t38 = (t39 + 0);
    t40 = (t9 + 56U);
    t41 = *((char **)t40);
    t40 = (t41 + 0);
    work_p_2039065742_sub_18409588216962174043_3720953609(t0, t1, t2, t3, t38, t40);
    t10 = (t15 + 56U);
    t11 = *((char **)t10);
    t42 = *((unsigned char *)t11);
    t10 = (t5 + 0);
    t13 = (t21 + 56U);
    t14 = *((char **)t13);
    t13 = (t14 + 0);
    work_p_2039065742_sub_18409588216962174043_3720953609(t0, t1, t4, t42, t10, t13);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t42 = *((unsigned char *)t11);
    t10 = (t21 + 56U);
    t13 = *((char **)t10);
    t43 = *((unsigned char *)t13);
    t10 = (t6 + 0);
    t14 = (t27 + 56U);
    t16 = *((char **)t14);
    t14 = (t16 + 0);
    work_p_2039065742_sub_18409588216962174043_3720953609(t0, t1, t42, t43, t10, t14);

LAB1:    return;
}

void work_p_2039065742_sub_15890213299389334342_3720953609(char *t0, char *t1, char *t2, char *t3, unsigned char t4, char *t5)
{
    char t6[128];
    char t7[56];
    char t8[16];
    char t13[16];
    char t16[16];
    char t19[16];
    char t24[8];
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t14;
    int t15;
    char *t17;
    int t18;
    char *t20;
    int t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned char t29;
    char *t30;
    char *t31;
    unsigned char t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    int t39;
    char *t40;
    int t41;
    int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    int t46;
    int t47;
    unsigned int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    int t53;
    int t54;
    unsigned int t55;
    int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned char t59;
    char *t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    unsigned int t65;
    char *t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t72;
    int t73;
    int t74;
    char *t75;
    int t76;
    int t77;
    unsigned int t78;
    char *t79;
    int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;

LAB0:    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 3;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t11 = (0 - 3);
    t12 = (t11 * -1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t10 = (t13 + 0U);
    t14 = (t10 + 0U);
    *((int *)t14) = 3;
    t14 = (t10 + 4U);
    *((int *)t14) = 0;
    t14 = (t10 + 8U);
    *((int *)t14) = -1;
    t15 = (0 - 3);
    t12 = (t15 * -1);
    t12 = (t12 + 1);
    t14 = (t10 + 12U);
    *((unsigned int *)t14) = t12;
    t14 = (t16 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 4;
    t17 = (t14 + 4U);
    *((int *)t17) = 0;
    t17 = (t14 + 8U);
    *((int *)t17) = -1;
    t18 = (0 - 4);
    t12 = (t18 * -1);
    t12 = (t12 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t12;
    t17 = (t19 + 0U);
    t20 = (t17 + 0U);
    *((int *)t20) = 4;
    t20 = (t17 + 4U);
    *((int *)t20) = 0;
    t20 = (t17 + 8U);
    *((int *)t20) = -1;
    t21 = (0 - 4);
    t12 = (t21 * -1);
    t12 = (t12 + 1);
    t20 = (t17 + 12U);
    *((unsigned int *)t20) = t12;
    t20 = (t6 + 4U);
    t22 = ((IEEE_P_2592010699) + 4000);
    t23 = (t20 + 88U);
    *((char **)t23) = t22;
    t25 = (t20 + 56U);
    *((char **)t25) = t24;
    xsi_type_set_default_value(t22, t24, t19);
    t26 = (t20 + 64U);
    *((char **)t26) = t19;
    t27 = (t20 + 80U);
    *((unsigned int *)t27) = 5U;
    t28 = (t7 + 4U);
    t29 = (t2 != 0);
    if (t29 == 1)
        goto LAB3;

LAB2:    t30 = (t7 + 12U);
    *((char **)t30) = t8;
    t31 = (t7 + 20U);
    t32 = (t3 != 0);
    if (t32 == 1)
        goto LAB5;

LAB4:    t33 = (t7 + 28U);
    *((char **)t33) = t13;
    t34 = (t7 + 36U);
    *((unsigned char *)t34) = t4;
    t35 = (t7 + 37U);
    *((char **)t35) = t5;
    t36 = (t7 + 45U);
    *((char **)t36) = t16;
    t37 = (t20 + 56U);
    t38 = *((char **)t37);
    t37 = (t19 + 0U);
    t39 = *((int *)t37);
    t40 = (t19 + 8U);
    t41 = *((int *)t40);
    t42 = (0 - t39);
    t12 = (t42 * t41);
    t43 = (1U * t12);
    t44 = (0 + t43);
    t45 = (t38 + t44);
    *((unsigned char *)t45) = t4;
    t11 = 0;
    t15 = 3;

LAB6:    if (t11 <= t15)
        goto LAB7;

LAB9:    t9 = (t20 + 56U);
    t10 = *((char **)t9);
    t9 = (t19 + 0U);
    t11 = *((int *)t9);
    t14 = (t19 + 8U);
    t15 = *((int *)t14);
    t18 = (4 - t11);
    t12 = (t18 * t15);
    t43 = (1U * t12);
    t44 = (0 + t43);
    t17 = (t10 + t44);
    t29 = *((unsigned char *)t17);
    t22 = (t16 + 0U);
    t21 = *((int *)t22);
    t23 = (t16 + 8U);
    t39 = *((int *)t23);
    t41 = (4 - t21);
    t48 = (t41 * t39);
    t50 = (1U * t48);
    t51 = (0 + t50);
    t25 = (t5 + t51);
    *((unsigned char *)t25) = t29;

LAB1:    return;
LAB3:    *((char **)t28) = t2;
    goto LAB2;

LAB5:    *((char **)t31) = t3;
    goto LAB4;

LAB7:    t9 = (t8 + 0U);
    t18 = *((int *)t9);
    t10 = (t8 + 8U);
    t21 = *((int *)t10);
    t39 = (t11 - t18);
    t12 = (t39 * t21);
    t14 = (t8 + 4U);
    t41 = *((int *)t14);
    xsi_vhdl_check_range_of_index(t18, t41, t21, t11);
    t43 = (1U * t12);
    t44 = (0 + t43);
    t17 = (t2 + t44);
    t29 = *((unsigned char *)t17);
    t22 = (t13 + 0U);
    t42 = *((int *)t22);
    t23 = (t13 + 8U);
    t46 = *((int *)t23);
    t47 = (t11 - t42);
    t48 = (t47 * t46);
    t25 = (t13 + 4U);
    t49 = *((int *)t25);
    xsi_vhdl_check_range_of_index(t42, t49, t46, t11);
    t50 = (1U * t48);
    t51 = (0 + t50);
    t26 = (t3 + t51);
    t32 = *((unsigned char *)t26);
    t27 = (t20 + 56U);
    t37 = *((char **)t27);
    t27 = (t19 + 0U);
    t52 = *((int *)t27);
    t38 = (t19 + 8U);
    t53 = *((int *)t38);
    t54 = (t11 - t52);
    t55 = (t54 * t53);
    t40 = (t19 + 4U);
    t56 = *((int *)t40);
    xsi_vhdl_check_range_of_index(t52, t56, t53, t11);
    t57 = (1U * t55);
    t58 = (0 + t57);
    t45 = (t37 + t58);
    t59 = *((unsigned char *)t45);
    t60 = (t16 + 0U);
    t61 = *((int *)t60);
    t62 = (t16 + 8U);
    t63 = *((int *)t62);
    t64 = (t11 - t61);
    t65 = (t64 * t63);
    t66 = (t16 + 4U);
    t67 = *((int *)t66);
    xsi_vhdl_check_range_of_index(t61, t67, t63, t11);
    t68 = (1U * t65);
    t69 = (0 + t68);
    t70 = (t5 + t69);
    t71 = (t20 + 56U);
    t72 = *((char **)t71);
    t73 = (t11 + 1);
    t71 = (t19 + 0U);
    t74 = *((int *)t71);
    t75 = (t19 + 8U);
    t76 = *((int *)t75);
    t77 = (t73 - t74);
    t78 = (t77 * t76);
    t79 = (t19 + 4U);
    t80 = *((int *)t79);
    xsi_vhdl_check_range_of_index(t74, t80, t76, t73);
    t81 = (1U * t78);
    t82 = (0 + t81);
    t83 = (t72 + t82);
    work_p_2039065742_sub_913065848825170742_3720953609(t0, t1, t29, t32, t59, t70, t83);

LAB8:    if (t11 == t15)
        goto LAB9;

LAB10:    t18 = (t11 + 1);
    t11 = t18;
    goto LAB6;

}

void work_p_2039065742_sub_8850450602204196737_3720953609(char *t0, char *t1, char *t2, char *t3, unsigned char t4, char *t5)
{
    char t6[248];
    char t7[56];
    char t8[16];
    char t13[16];
    char t16[16];
    char t19[16];
    char t24[8];
    char t28[16];
    char t34[8];
    char t47[16];
    char t53[16];
    char t58[16];
    char t61[16];
    char t64[16];
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t14;
    int t15;
    char *t17;
    int t18;
    char *t20;
    int t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    int t31;
    char *t32;
    char *t33;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    unsigned char t39;
    char *t40;
    char *t41;
    unsigned char t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t54;
    char *t55;
    int t56;
    unsigned int t57;
    char *t59;
    char *t60;
    char *t62;
    char *t63;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned char t76;

LAB0:    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 3;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t11 = (0 - 3);
    t12 = (t11 * -1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t10 = (t13 + 0U);
    t14 = (t10 + 0U);
    *((int *)t14) = 3;
    t14 = (t10 + 4U);
    *((int *)t14) = 0;
    t14 = (t10 + 8U);
    *((int *)t14) = -1;
    t15 = (0 - 3);
    t12 = (t15 * -1);
    t12 = (t12 + 1);
    t14 = (t10 + 12U);
    *((unsigned int *)t14) = t12;
    t14 = (t16 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 4;
    t17 = (t14 + 4U);
    *((int *)t17) = 0;
    t17 = (t14 + 8U);
    *((int *)t17) = -1;
    t18 = (0 - 4);
    t12 = (t18 * -1);
    t12 = (t12 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t12;
    t17 = (t19 + 0U);
    t20 = (t17 + 0U);
    *((int *)t20) = 3;
    t20 = (t17 + 4U);
    *((int *)t20) = 0;
    t20 = (t17 + 8U);
    *((int *)t20) = -1;
    t21 = (0 - 3);
    t12 = (t21 * -1);
    t12 = (t12 + 1);
    t20 = (t17 + 12U);
    *((unsigned int *)t20) = t12;
    t20 = (t6 + 4U);
    t22 = ((IEEE_P_2592010699) + 4000);
    t23 = (t20 + 88U);
    *((char **)t23) = t22;
    t25 = (t20 + 56U);
    *((char **)t25) = t24;
    xsi_type_set_default_value(t22, t24, t19);
    t26 = (t20 + 64U);
    *((char **)t26) = t19;
    t27 = (t20 + 80U);
    *((unsigned int *)t27) = 4U;
    t29 = (t28 + 0U);
    t30 = (t29 + 0U);
    *((int *)t30) = 4;
    t30 = (t29 + 4U);
    *((int *)t30) = 0;
    t30 = (t29 + 8U);
    *((int *)t30) = -1;
    t31 = (0 - 4);
    t12 = (t31 * -1);
    t12 = (t12 + 1);
    t30 = (t29 + 12U);
    *((unsigned int *)t30) = t12;
    t30 = (t6 + 124U);
    t32 = ((IEEE_P_2592010699) + 4000);
    t33 = (t30 + 88U);
    *((char **)t33) = t32;
    t35 = (t30 + 56U);
    *((char **)t35) = t34;
    xsi_type_set_default_value(t32, t34, t28);
    t36 = (t30 + 64U);
    *((char **)t36) = t28;
    t37 = (t30 + 80U);
    *((unsigned int *)t37) = 5U;
    t38 = (t7 + 4U);
    t39 = (t2 != 0);
    if (t39 == 1)
        goto LAB3;

LAB2:    t40 = (t7 + 12U);
    *((char **)t40) = t8;
    t41 = (t7 + 20U);
    t42 = (t3 != 0);
    if (t42 == 1)
        goto LAB5;

LAB4:    t43 = (t7 + 28U);
    *((char **)t43) = t13;
    t44 = (t7 + 36U);
    *((unsigned char *)t44) = t4;
    t45 = (t7 + 37U);
    *((char **)t45) = t5;
    t46 = (t7 + 45U);
    *((char **)t46) = t16;
    t48 = (t13 + 0U);
    t49 = *((int *)t48);
    t12 = (t49 - 3);
    t50 = (t12 * 1U);
    t51 = (0 + t50);
    t52 = (t3 + t51);
    t54 = (t53 + 0U);
    t55 = (t54 + 0U);
    *((int *)t55) = 3;
    t55 = (t54 + 4U);
    *((int *)t55) = 0;
    t55 = (t54 + 8U);
    *((int *)t55) = -1;
    t56 = (0 - 3);
    t57 = (t56 * -1);
    t57 = (t57 + 1);
    t55 = (t54 + 12U);
    *((unsigned int *)t55) = t57;
    t59 = ((IEEE_P_2592010699) + 4000);
    t55 = xsi_base_array_concat(t55, t58, t59, (char)99, t4, (char)99, t4, (char)101);
    t62 = ((IEEE_P_2592010699) + 4000);
    t60 = xsi_base_array_concat(t60, t61, t62, (char)97, t55, t58, (char)99, t4, (char)101);
    t65 = ((IEEE_P_2592010699) + 4000);
    t63 = xsi_base_array_concat(t63, t64, t65, (char)97, t60, t61, (char)99, t4, (char)101);
    t66 = ieee_p_2592010699_sub_16439989833707593767_503743352(IEEE_P_2592010699, t47, t52, t53, t63, t64);
    t67 = (t20 + 56U);
    t68 = *((char **)t67);
    t67 = (t19 + 0U);
    t69 = *((int *)t67);
    t57 = (t69 - 3);
    t70 = (t57 * 1U);
    t71 = (0 + t70);
    t72 = (t68 + t71);
    t73 = (t47 + 12U);
    t74 = *((unsigned int *)t73);
    t75 = (1U * t74);
    memcpy(t72, t66, t75);
    t9 = (t8 + 12U);
    t12 = *((unsigned int *)t9);
    t12 = (t12 * 1U);
    t10 = (char *)alloca(t12);
    memcpy(t10, t2, t12);
    t14 = (t20 + 56U);
    t17 = *((char **)t14);
    t14 = (t19 + 12U);
    t50 = *((unsigned int *)t14);
    t50 = (t50 * 1U);
    t22 = (char *)alloca(t50);
    memcpy(t22, t17, t50);
    t23 = (t30 + 56U);
    t25 = *((char **)t23);
    work_p_2039065742_sub_15890213299389334342_3720953609(t0, t1, t10, t22, (unsigned char)2, t25);
    t39 = (t4 == (unsigned char)3);
    if (t39 != 0)
        goto LAB6;

LAB8:
LAB7:    t9 = (t30 + 56U);
    t14 = *((char **)t9);
    t9 = (t5 + 0);
    t17 = (t28 + 12U);
    t12 = *((unsigned int *)t17);
    t12 = (t12 * 1U);
    memcpy(t9, t14, t12);

LAB1:    return;
LAB3:    *((char **)t38) = t2;
    goto LAB2;

LAB5:    *((char **)t41) = t3;
    goto LAB4;

LAB6:    t9 = (t30 + 56U);
    t14 = *((char **)t9);
    t9 = (t28 + 0U);
    t11 = *((int *)t9);
    t17 = (t28 + 8U);
    t15 = *((int *)t17);
    t18 = (4 - t11);
    t12 = (t18 * t15);
    t50 = (1U * t12);
    t51 = (0 + t50);
    t23 = (t14 + t51);
    t42 = *((unsigned char *)t23);
    t76 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t42);
    t25 = (t30 + 56U);
    t26 = *((char **)t25);
    t25 = (t28 + 0U);
    t21 = *((int *)t25);
    t27 = (t28 + 8U);
    t31 = *((int *)t27);
    t49 = (4 - t21);
    t57 = (t49 * t31);
    t70 = (1U * t57);
    t71 = (0 + t70);
    t29 = (t26 + t71);
    *((unsigned char *)t29) = t76;
    goto LAB7;

}

void work_p_2039065742_sub_6416716729160755020_3720953609(char *t0, char *t1, char *t2, char *t3, char *t4)
{
    char t5[488];
    char t6[56];
    char t7[16];
    char t12[16];
    char t15[16];
    char t18[16];
    char t23[8];
    char t30[8];
    char t36[8];
    char t39[16];
    char t45[8];
    char t82[16];
    char t83[16];
    char t84[16];
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    char *t13;
    int t14;
    char *t16;
    int t17;
    char *t19;
    int t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    int t42;
    char *t43;
    char *t44;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    unsigned char t50;
    char *t51;
    char *t52;
    unsigned char t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    int t65;
    int t66;
    int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned char t71;
    int t72;
    int t73;
    int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned char t78;
    unsigned char t79;
    unsigned char t80;
    unsigned char t81;

LAB0:    t8 = (t7 + 0U);
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
    t9 = (t12 + 0U);
    t13 = (t9 + 0U);
    *((int *)t13) = 3;
    t13 = (t9 + 4U);
    *((int *)t13) = 0;
    t13 = (t9 + 8U);
    *((int *)t13) = -1;
    t14 = (0 - 3);
    t11 = (t14 * -1);
    t11 = (t11 + 1);
    t13 = (t9 + 12U);
    *((unsigned int *)t13) = t11;
    t13 = (t15 + 0U);
    t16 = (t13 + 0U);
    *((int *)t16) = 4;
    t16 = (t13 + 4U);
    *((int *)t16) = 0;
    t16 = (t13 + 8U);
    *((int *)t16) = -1;
    t17 = (0 - 4);
    t11 = (t17 * -1);
    t11 = (t11 + 1);
    t16 = (t13 + 12U);
    *((unsigned int *)t16) = t11;
    t16 = (t18 + 0U);
    t19 = (t16 + 0U);
    *((int *)t19) = 4;
    t19 = (t16 + 4U);
    *((int *)t19) = 0;
    t19 = (t16 + 8U);
    *((int *)t19) = -1;
    t20 = (0 - 4);
    t11 = (t20 * -1);
    t11 = (t11 + 1);
    t19 = (t16 + 12U);
    *((unsigned int *)t19) = t11;
    t19 = (t5 + 4U);
    t21 = ((IEEE_P_2592010699) + 4000);
    t22 = (t19 + 88U);
    *((char **)t22) = t21;
    t24 = (t19 + 56U);
    *((char **)t24) = t23;
    xsi_type_set_default_value(t21, t23, t18);
    t25 = (t19 + 64U);
    *((char **)t25) = t18;
    t26 = (t19 + 80U);
    *((unsigned int *)t26) = 5U;
    t27 = (t5 + 124U);
    t28 = ((IEEE_P_2592010699) + 3312);
    t29 = (t27 + 88U);
    *((char **)t29) = t28;
    t31 = (t27 + 56U);
    *((char **)t31) = t30;
    xsi_type_set_default_value(t28, t30, 0);
    t32 = (t27 + 80U);
    *((unsigned int *)t32) = 1U;
    t33 = (t5 + 244U);
    t34 = ((IEEE_P_2592010699) + 3312);
    t35 = (t33 + 88U);
    *((char **)t35) = t34;
    t37 = (t33 + 56U);
    *((char **)t37) = t36;
    xsi_type_set_default_value(t34, t36, 0);
    t38 = (t33 + 80U);
    *((unsigned int *)t38) = 1U;
    t40 = (t39 + 0U);
    t41 = (t40 + 0U);
    *((int *)t41) = 3;
    t41 = (t40 + 4U);
    *((int *)t41) = 0;
    t41 = (t40 + 8U);
    *((int *)t41) = -1;
    t42 = (0 - 3);
    t11 = (t42 * -1);
    t11 = (t11 + 1);
    t41 = (t40 + 12U);
    *((unsigned int *)t41) = t11;
    t41 = (t5 + 364U);
    t43 = ((IEEE_P_2592010699) + 4000);
    t44 = (t41 + 88U);
    *((char **)t44) = t43;
    t46 = (t41 + 56U);
    *((char **)t46) = t45;
    xsi_type_set_default_value(t43, t45, t39);
    t47 = (t41 + 64U);
    *((char **)t47) = t39;
    t48 = (t41 + 80U);
    *((unsigned int *)t48) = 4U;
    t49 = (t6 + 4U);
    t50 = (t2 != 0);
    if (t50 == 1)
        goto LAB3;

LAB2:    t51 = (t6 + 12U);
    *((char **)t51) = t7;
    t52 = (t6 + 20U);
    t53 = (t3 != 0);
    if (t53 == 1)
        goto LAB5;

LAB4:    t54 = (t6 + 28U);
    *((char **)t54) = t12;
    t55 = (t6 + 36U);
    *((char **)t55) = t4;
    t56 = (t6 + 44U);
    *((char **)t56) = t15;
    t57 = (t33 + 56U);
    t58 = *((char **)t57);
    t57 = (t58 + 0);
    *((unsigned char *)t57) = (unsigned char)2;
    t8 = (t7 + 12U);
    t11 = *((unsigned int *)t8);
    t11 = (t11 * 1U);
    t9 = (char *)alloca(t11);
    memcpy(t9, t2, t11);
    t13 = (t12 + 12U);
    t59 = *((unsigned int *)t13);
    t59 = (t59 * 1U);
    t16 = (char *)alloca(t59);
    memcpy(t16, t3, t59);
    t21 = (t33 + 56U);
    t22 = *((char **)t21);
    t50 = *((unsigned char *)t22);
    t21 = (t19 + 56U);
    t24 = *((char **)t21);
    work_p_2039065742_sub_15890213299389334342_3720953609(t0, t1, t9, t16, t50, t24);
    t8 = (t19 + 56U);
    t13 = *((char **)t8);
    t8 = (t18 + 0U);
    t10 = *((int *)t8);
    t21 = (t18 + 8U);
    t14 = *((int *)t21);
    t17 = (4 - t10);
    t11 = (t17 * t14);
    t59 = (1U * t11);
    t60 = (0 + t59);
    t22 = (t13 + t60);
    t50 = *((unsigned char *)t22);
    t24 = (t19 + 56U);
    t25 = *((char **)t24);
    t24 = (t18 + 0U);
    t20 = *((int *)t24);
    t26 = (t18 + 8U);
    t42 = *((int *)t26);
    t61 = (3 - t20);
    t62 = (t61 * t42);
    t63 = (1U * t62);
    t64 = (0 + t63);
    t28 = (t25 + t64);
    t53 = *((unsigned char *)t28);
    t29 = (t19 + 56U);
    t31 = *((char **)t29);
    t29 = (t18 + 0U);
    t65 = *((int *)t29);
    t32 = (t18 + 8U);
    t66 = *((int *)t32);
    t67 = (2 - t65);
    t68 = (t67 * t66);
    t69 = (1U * t68);
    t70 = (0 + t69);
    t34 = (t31 + t70);
    t71 = *((unsigned char *)t34);
    t35 = (t19 + 56U);
    t37 = *((char **)t35);
    t35 = (t18 + 0U);
    t72 = *((int *)t35);
    t38 = (t18 + 8U);
    t73 = *((int *)t38);
    t74 = (1 - t72);
    t75 = (t74 * t73);
    t76 = (1U * t75);
    t77 = (0 + t76);
    t40 = (t37 + t77);
    t78 = *((unsigned char *)t40);
    t79 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t71, t78);
    t80 = ieee_p_2592010699_sub_3488768496604610246_503743352(IEEE_P_2592010699, t53, t79);
    t81 = ieee_p_2592010699_sub_3488546069778340532_503743352(IEEE_P_2592010699, t50, t80);
    t43 = (t27 + 56U);
    t44 = *((char **)t43);
    t43 = (t44 + 0);
    *((unsigned char *)t43) = t81;
    t8 = (t33 + 56U);
    t13 = *((char **)t8);
    t50 = *((unsigned char *)t13);
    t8 = (t27 + 56U);
    t21 = *((char **)t8);
    t53 = *((unsigned char *)t21);
    t22 = ((IEEE_P_2592010699) + 4000);
    t8 = xsi_base_array_concat(t8, t82, t22, (char)99, t50, (char)99, t53, (char)101);
    t24 = (t27 + 56U);
    t25 = *((char **)t24);
    t71 = *((unsigned char *)t25);
    t26 = ((IEEE_P_2592010699) + 4000);
    t24 = xsi_base_array_concat(t24, t83, t26, (char)97, t8, t82, (char)99, t71, (char)101);
    t28 = (t33 + 56U);
    t29 = *((char **)t28);
    t78 = *((unsigned char *)t29);
    t31 = ((IEEE_P_2592010699) + 4000);
    t28 = xsi_base_array_concat(t28, t84, t31, (char)97, t24, t83, (char)99, t78, (char)101);
    t32 = (t41 + 56U);
    t34 = *((char **)t32);
    t32 = (t34 + 0);
    t11 = (1U + 1U);
    t59 = (t11 + 1U);
    t60 = (t59 + 1U);
    memcpy(t32, t28, t60);
    t8 = (t19 + 56U);
    t13 = *((char **)t8);
    t8 = (t18 + 0U);
    t10 = *((int *)t8);
    t11 = (t10 - 3);
    t59 = (t11 * 1U);
    t60 = (0 + t59);
    t21 = (t13 + t60);
    t14 = (0 - 3);
    t62 = (t14 * -1);
    t62 = (t62 + 1);
    t63 = (1U * t62);
    t22 = (char *)alloca(t63);
    memcpy(t22, t21, t63);
    t24 = (t41 + 56U);
    t25 = *((char **)t24);
    t24 = (t39 + 12U);
    t64 = *((unsigned int *)t24);
    t64 = (t64 * 1U);
    t26 = (char *)alloca(t64);
    memcpy(t26, t25, t64);
    t28 = (t33 + 56U);
    t29 = *((char **)t28);
    t50 = *((unsigned char *)t29);
    work_p_2039065742_sub_15890213299389334342_3720953609(t0, t1, t22, t26, t50, t4);
    t8 = (t27 + 56U);
    t13 = *((char **)t8);
    t50 = *((unsigned char *)t13);
    t8 = (t15 + 0U);
    t10 = *((int *)t8);
    t21 = (t15 + 8U);
    t14 = *((int *)t21);
    t17 = (4 - t10);
    t11 = (t17 * t14);
    t59 = (1U * t11);
    t60 = (0 + t59);
    t24 = (t4 + t60);
    *((unsigned char *)t24) = t50;

LAB1:    return;
LAB3:    *((char **)t49) = t2;
    goto LAB2;

LAB5:    *((char **)t52) = t3;
    goto LAB4;

}


extern void work_p_2039065742_init()
{
	static char *se[] = {(void *)work_p_2039065742_sub_17772734202513611019_3720953609,(void *)work_p_2039065742_sub_18409588216962174043_3720953609,(void *)work_p_2039065742_sub_913065848825170742_3720953609,(void *)work_p_2039065742_sub_15890213299389334342_3720953609,(void *)work_p_2039065742_sub_8850450602204196737_3720953609,(void *)work_p_2039065742_sub_6416716729160755020_3720953609};
	xsi_register_didat("work_p_2039065742", "isim/tb_a4_ax1_isim_beh.exe.sim/work/p_2039065742.didat");
	xsi_register_subprogram_executes(se);
}
