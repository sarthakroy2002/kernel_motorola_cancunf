/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2016 MediaTek Inc.
 */

#ifndef _MTK_EEM_
#define _MTK_EEM_

#include <linux/kernel.h>
#include <mt-plat/sync_write.h>
#include "mtk_eem_config.h"

#define EN_EEM (1) /* enable/disable EEM (SW) */

/* have 5 banks */
enum eem_ctrl_id {
//	EEM_CTRL_L,
	EEM_CTRL_2L,
//	EEM_CTRL_GPU,
#if ENABLE_LOO
//	EEM_CTRL_L_HI,
	EEM_CTRL_2L_HI,
#endif

	NR_EEM_CTRL,
};

enum eem_det_id {
//	EEM_DET_L	=	EEM_CTRL_L,
	EEM_DET_2L	=	EEM_CTRL_2L,
//	EEM_DET_GPU	=	EEM_CTRL_GPU,
#if ENABLE_LOO
//	EEM_DET_L_HI	=	EEM_CTRL_L_HI,
	EEM_DET_2L_HI	=	EEM_CTRL_2L_HI,
#endif

	NR_EEM_DET,
};

enum mt_eem_cpu_id {
//	MT_EEM_CPU_L,
	MT_EEM_CPU_LL,
//	MT_EEM_CPU_CCI,

	NR_MT_EEM_CPU,
};

/* internal use */
/* EEM detector is disabled by who */
enum {
	BY_PROCFS	= BIT(0),
	BY_INIT_ERROR	= BIT(1),
	BY_MON_ERROR	= BIT(2),
	BY_PROCFS_INIT2 = BIT(3),
};

enum eem_phase {
	EEM_PHASE_INIT01,
	EEM_PHASE_INIT02,
	EEM_PHASE_MON,

	NR_EEM_PHASE,
};

enum eem_features {
	FEA_INIT01	= BIT(EEM_PHASE_INIT01),
	FEA_INIT02	= BIT(EEM_PHASE_INIT02),
	FEA_MON		= BIT(EEM_PHASE_MON),
};

enum {
	EEM_VOLT_NONE	= 0,
	EEM_VOLT_UPDATE  = BIT(0),
	EEM_VOLT_RESTORE = BIT(1),
};

extern const unsigned int reg_dump_addr_off[105];

#if IS_ENABLED(CONFIG_MTK_AEE_IPANIC)


#define EEM_AEE_RR_REC 1
/* label_comment_undef */
#undef EEM_AEE_RR_REC

#endif

#ifdef EEM_AEE_RR_REC
enum eem_state {
	EEM_CPU_LITTLE_IS_SET_VOLT,		/* L */
	EEM_CPU_2_LITTLE_IS_SET_VOLT,	/* 2L */
	EEM_CPU_GPU_IS_SET_VOLT,		/* CCI */
#if ENABLE_LOO
	EEM_CPU_LITTLE_HI_IS_SET_VOLT,
	EEM_CPU_2_LITTLE_HI_IS_SET_VOLT,
#endif
};

extern void aee_rr_rec_ptp_devinfo_0(u32 val);
extern void aee_rr_rec_ptp_devinfo_1(u32 val);
extern void aee_rr_rec_ptp_devinfo_2(u32 val);
extern void aee_rr_rec_ptp_devinfo_3(u32 val);
extern void aee_rr_rec_ptp_devinfo_4(u32 val);
extern void aee_rr_rec_ptp_devinfo_5(u32 val);
extern void aee_rr_rec_ptp_devinfo_6(u32 val);
extern void aee_rr_rec_ptp_devinfo_7(u32 val);
extern void aee_rr_rec_ptp_e0(u32 val);
extern void aee_rr_rec_ptp_e1(u32 val);
extern void aee_rr_rec_ptp_e2(u32 val);
extern void aee_rr_rec_ptp_e3(u32 val);
extern void aee_rr_rec_ptp_e4(u32 val);
extern void aee_rr_rec_ptp_e5(u32 val);
extern void aee_rr_rec_ptp_e6(u32 val);
extern void aee_rr_rec_ptp_e7(u32 val);
extern void aee_rr_rec_ptp_e8(u32 val);
extern void aee_rr_rec_ptp_e9(u32 val);
extern void aee_rr_rec_ptp_e10(u32 val);
extern void aee_rr_rec_ptp_e11(u32 val);
extern void aee_rr_rec_ptp_vboot(u64 val);
extern void aee_rr_rec_ptp_cpu_big_volt(u64 val);
extern void aee_rr_rec_ptp_cpu_big_volt_1(u64 val);
extern void aee_rr_rec_ptp_cpu_big_volt_2(u64 val);
extern void aee_rr_rec_ptp_cpu_big_volt_3(u64 val);
extern void aee_rr_rec_ptp_gpu_volt(u64 val);
extern void aee_rr_rec_ptp_gpu_volt_1(u64 val);
extern void aee_rr_rec_ptp_gpu_volt_2(u64 val);
extern void aee_rr_rec_ptp_gpu_volt_3(u64 val);
extern void aee_rr_rec_ptp_cpu_little_volt(u64 val);
extern void aee_rr_rec_ptp_cpu_little_volt_1(u64 val);
extern void aee_rr_rec_ptp_cpu_little_volt_2(u64 val);
extern void aee_rr_rec_ptp_cpu_little_volt_3(u64 val);
extern void aee_rr_rec_ptp_cpu_2_little_volt(u64 val);
extern void aee_rr_rec_ptp_cpu_2_little_volt_1(u64 val);
extern void aee_rr_rec_ptp_cpu_2_little_volt_2(u64 val);
extern void aee_rr_rec_ptp_cpu_2_little_volt_3(u64 val);
extern void aee_rr_rec_ptp_cpu_cci_volt(u64 val);
extern void aee_rr_rec_ptp_cpu_cci_volt_1(u64 val);
extern void aee_rr_rec_ptp_cpu_cci_volt_2(u64 val);
extern void aee_rr_rec_ptp_cpu_cci_volt_3(u64 val);
extern void aee_rr_rec_ptp_temp(u64 val);
extern void aee_rr_rec_ptp_status(u8 val);
extern void aee_rr_rec_eem_pi_offset(u8 val);

extern u32 aee_rr_curr_ptp_devinfo_0(void);
extern u32 aee_rr_curr_ptp_devinfo_1(void);
extern u32 aee_rr_curr_ptp_devinfo_2(void);
extern u32 aee_rr_curr_ptp_devinfo_3(void);
extern u32 aee_rr_curr_ptp_devinfo_4(void);
extern u32 aee_rr_curr_ptp_devinfo_5(void);
extern u32 aee_rr_curr_ptp_devinfo_6(void);
extern u32 aee_rr_curr_ptp_devinfo_7(void);
extern u32 aee_rr_curr_ptp_e0(void);
extern u32 aee_rr_curr_ptp_e1(void);
extern u32 aee_rr_curr_ptp_e2(void);
extern u32 aee_rr_curr_ptp_e3(void);
extern u32 aee_rr_curr_ptp_e4(void);
extern u32 aee_rr_curr_ptp_e5(void);
extern u32 aee_rr_curr_ptp_e6(void);
extern u32 aee_rr_curr_ptp_e7(void);
extern u32 aee_rr_curr_ptp_e8(void);
extern u32 aee_rr_curr_ptp_e9(void);
extern u32 aee_rr_curr_ptp_e10(void);
extern u32 aee_rr_curr_ptp_e11(void);
extern u64 aee_rr_curr_ptp_vboot(void);
extern u64 aee_rr_curr_ptp_cpu_big_volt(void);
extern u64 aee_rr_curr_ptp_cpu_big_volt_1(void);
extern u64 aee_rr_curr_ptp_cpu_big_volt_2(void);
extern u64 aee_rr_curr_ptp_cpu_big_volt_3(void);
extern u64 aee_rr_curr_ptp_gpu_volt(void);
extern u64 aee_rr_curr_ptp_gpu_volt_1(void);
extern u64 aee_rr_curr_ptp_gpu_volt_2(void);
extern u64 aee_rr_curr_ptp_gpu_volt_3(void);
extern u64 aee_rr_curr_ptp_cpu_little_volt(void);
extern u64 aee_rr_curr_ptp_cpu_little_volt_1(void);
extern u64 aee_rr_curr_ptp_cpu_little_volt_2(void);
extern u64 aee_rr_curr_ptp_cpu_little_volt_3(void);
extern u64 aee_rr_curr_ptp_cpu_2_little_volt(void);
extern u64 aee_rr_curr_ptp_cpu_2_little_volt_1(void);
extern u64 aee_rr_curr_ptp_cpu_2_little_volt_2(void);
extern u64 aee_rr_curr_ptp_cpu_2_little_volt_3(void);
extern u64 aee_rr_curr_ptp_cpu_cci_volt(void);
extern u64 aee_rr_curr_ptp_cpu_cci_volt_1(void);
extern u64 aee_rr_curr_ptp_cpu_cci_volt_2(void);
extern u64 aee_rr_curr_ptp_cpu_cci_volt_3(void);
extern u64 aee_rr_curr_ptp_temp(void);
extern u8 aee_rr_curr_ptp_status(void);
#endif

/* EEM Extern Function */
extern int mt_eem_status(enum eem_det_id id);
extern unsigned int get_efuse_status(void);
extern unsigned int mt_eem_is_enabled(void);

extern void eem_set_pi_efuse(enum eem_det_id id, unsigned int pi_efuse);

/* DRCC */
extern unsigned int drcc_offset_done;
#endif
