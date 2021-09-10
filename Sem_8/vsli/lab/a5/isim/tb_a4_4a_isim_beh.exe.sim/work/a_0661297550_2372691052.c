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
static const char *ng0 = "/home/sahil/College/Sem_8/vsli/lab/a5/tb_a4_4a.vhd";
extern char *WORK_P_2730956969;

void work_p_2730956969_sub_17772734202513611019_3550175573(char *, char *, int , int , char *, char *);


static void work_a_0661297550_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    char *t6;
    char *t7;
    int t8;
    int t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    int64 t14;
    int t15;

LAB0:    t1 = (t0 + 2744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 5091);
    *((int *)t2) = 0;
    t3 = (t0 + 5095);
    *((int *)t3) = 255;
    t4 = 0;
    t5 = 255;

LAB4:    if (t4 <= t5)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(78, ng0);
    t6 = (t0 + 5099);
    *((int *)t6) = 0;
    t7 = (t0 + 5103);
    *((int *)t7) = 255;
    t8 = 0;
    t9 = 255;

LAB8:    if (t8 <= t9)
        goto LAB9;

LAB11:
LAB6:    t2 = (t0 + 5091);
    t4 = *((int *)t2);
    t3 = (t0 + 5095);
    t5 = *((int *)t3);
    if (t4 == t5)
        goto LAB7;

LAB17:    t8 = (t4 + 1);
    t4 = t8;
    t6 = (t0 + 5091);
    *((int *)t6) = t4;
    goto LAB4;

LAB9:    xsi_set_current_line(79, ng0);
    t10 = (t0 + 2552);
    t11 = (t0 + 5091);
    t12 = (t0 + 1648U);
    t13 = *((char **)t12);
    t12 = (t0 + 5032U);
    work_p_2730956969_sub_17772734202513611019_3550175573(WORK_P_2730956969, t10, *((int *)t11), 8, t13, t12);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 1648U);
    t3 = *((char **)t2);
    t2 = (t0 + 3128);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 8U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 2552);
    t3 = (t0 + 5099);
    t6 = (t0 + 1768U);
    t7 = *((char **)t6);
    t6 = (t0 + 5032U);
    work_p_2730956969_sub_17772734202513611019_3550175573(WORK_P_2730956969, t2, *((int *)t3), 8, t7, t6);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 1768U);
    t3 = *((char **)t2);
    t2 = (t0 + 3192);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 8U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(83, ng0);
    t14 = (1 * 1LL);
    t2 = (t0 + 2552);
    xsi_process_wait(t2, t14);

LAB14:    *((char **)t1) = &&LAB15;

LAB1:    return;
LAB10:    t2 = (t0 + 5099);
    t8 = *((int *)t2);
    t3 = (t0 + 5103);
    t9 = *((int *)t3);
    if (t8 == t9)
        goto LAB11;

LAB16:    t15 = (t8 + 1);
    t8 = t15;
    t6 = (t0 + 5099);
    *((int *)t6) = t8;
    goto LAB8;

LAB12:    goto LAB10;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}


extern void work_a_0661297550_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0661297550_2372691052_p_0};
	xsi_register_didat("work_a_0661297550_2372691052", "isim/tb_a4_4a_isim_beh.exe.sim/work/a_0661297550_2372691052.didat");
	xsi_register_executes(pe);
}
