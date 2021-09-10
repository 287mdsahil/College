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
static const char *ng0 = "/home/sahil/College/Sem_8/vsli/lab/a4/tb_a4_ax2.vhd";
extern char *WORK_P_2039065742;

void work_p_2039065742_sub_17772734202513611019_3720953609(char *, char *, int , int , char *, char *);


static void work_a_0620545086_2372691052_p_0(char *t0)
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

LAB0:    t1 = (t0 + 2904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 5398);
    *((int *)t2) = 0;
    t3 = (t0 + 5402);
    *((int *)t3) = 15;
    t4 = 0;
    t5 = 15;

LAB4:    if (t4 <= t5)
        goto LAB5;

LAB7:    goto LAB2;

LAB5:    xsi_set_current_line(80, ng0);
    t6 = (t0 + 5406);
    *((int *)t6) = 0;
    t7 = (t0 + 5410);
    *((int *)t7) = 15;
    t8 = 0;
    t9 = 15;

LAB8:    if (t8 <= t9)
        goto LAB9;

LAB11:
LAB6:    t2 = (t0 + 5398);
    t4 = *((int *)t2);
    t3 = (t0 + 5402);
    t5 = *((int *)t3);
    if (t4 == t5)
        goto LAB7;

LAB21:    t8 = (t4 + 1);
    t4 = t8;
    t6 = (t0 + 5398);
    *((int *)t6) = t4;
    goto LAB4;

LAB9:    xsi_set_current_line(81, ng0);
    t10 = (t0 + 2712);
    t11 = (t0 + 5398);
    t12 = (t0 + 1808U);
    t13 = *((char **)t12);
    t12 = (t0 + 5352U);
    work_p_2039065742_sub_17772734202513611019_3720953609(WORK_P_2039065742, t10, *((int *)t11), 4, t13, t12);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 1808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3288);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2712);
    t3 = (t0 + 5406);
    t6 = (t0 + 1928U);
    t7 = *((char **)t6);
    t6 = (t0 + 5352U);
    work_p_2039065742_sub_17772734202513611019_3720953609(WORK_P_2039065742, t2, *((int *)t3), 4, t7, t6);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 1928U);
    t3 = *((char **)t2);
    t2 = (t0 + 3352);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 3416);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(86, ng0);
    t14 = (1 * 1LL);
    t2 = (t0 + 2712);
    xsi_process_wait(t2, t14);

LAB14:    *((char **)t1) = &&LAB15;

LAB1:    return;
LAB10:    t2 = (t0 + 5406);
    t8 = *((int *)t2);
    t3 = (t0 + 5410);
    t9 = *((int *)t3);
    if (t8 == t9)
        goto LAB11;

LAB20:    t15 = (t8 + 1);
    t8 = t15;
    t6 = (t0 + 5406);
    *((int *)t6) = t8;
    goto LAB8;

LAB12:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2712);
    t3 = (t0 + 5398);
    t6 = (t0 + 1808U);
    t7 = *((char **)t6);
    t6 = (t0 + 5352U);
    work_p_2039065742_sub_17772734202513611019_3720953609(WORK_P_2039065742, t2, *((int *)t3), 4, t7, t6);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 1808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3288);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2712);
    t3 = (t0 + 5406);
    t6 = (t0 + 1928U);
    t7 = *((char **)t6);
    t6 = (t0 + 5352U);
    work_p_2039065742_sub_17772734202513611019_3720953609(WORK_P_2039065742, t2, *((int *)t3), 4, t7, t6);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 1928U);
    t3 = *((char **)t2);
    t2 = (t0 + 3352);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 4U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 3416);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(92, ng0);
    t14 = (1 * 1LL);
    t2 = (t0 + 2712);
    xsi_process_wait(t2, t14);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    goto LAB10;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

}


extern void work_a_0620545086_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0620545086_2372691052_p_0};
	xsi_register_didat("work_a_0620545086_2372691052", "isim/tb_a4_ax2_isim_beh.exe.sim/work/a_0620545086_2372691052.didat");
	xsi_register_executes(pe);
}
