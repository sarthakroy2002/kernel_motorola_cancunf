/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#ifndef __DRV_CLK_MT6768_PG_H
#define __DRV_CLK_MT6768_PG_H

enum subsys_id {
	SYS_MD1 = 0,
	SYS_CONN = 1,
	SYS_DPY = 2,
	SYS_DIS = 3,
	SYS_MFG = 4,
	SYS_ISP = 5,
	SYS_IFR = 6,
	SYS_MFG_CORE0 = 7,
	SYS_MFG_CORE1 = 8,
	SYS_MFG_ASYNC = 9,
	SYS_CAM = 10,
	SYS_VENC = 11,
	SYS_VDEC = 12,
	NR_SYSS = 13,
};

enum mtcmos_op {
	MTCMOS_BUS_PROT = 0,
	MTCMOS_PWR = 1,
};

struct pg_callbacks {
	struct list_head list;
	void (*before_off)(enum subsys_id sys);
	void (*after_on)(enum subsys_id sys);
	void (*debug_dump)(enum subsys_id sys);
};

/* register new pg_callbacks and return previous pg_callbacks. */
extern struct pg_callbacks *register_pg_callback(struct pg_callbacks *pgcb);
extern int spm_topaxi_protect(unsigned int mask_value, int en);

extern void subsys_if_on(void);
extern void mtcmos_force_off(void);

/*new arch*/
extern void check_ven_clk_sts(void);
extern void set_ven_bus_protect(void);
extern void mm_clk_restore(void);
extern void mfg_sts_check(void);
extern void ven_clk_check(void);
extern unsigned int mt_get_ckgen_freq(unsigned int ID);
extern struct provider_clk *get_all_provider_clks(void);
/*extern void aee_sram_printk(const char *fmt, ...);*/
/*ram console api*/
#if IS_ENABLED(CONFIG_MTK_AEE_IPANIC)
extern void aee_rr_rec_clk(int id, u32 val);
#endif

extern int get_sw_req_vcore_opp(void);
extern void print_enabled_clks_once(void);
#endif/* __DRV_CLK_MT6768_PG_H */
