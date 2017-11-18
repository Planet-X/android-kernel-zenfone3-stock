/////////////////////////////////////////////////////////////////////////////////////////////
////                  ASUS Debugging mechanism
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __ASUSDEBUG_H__
#define __ASUSDEBUG_H__


extern phys_addr_t PRINTK_BUFFER_PA;
extern void *PRINTK_BUFFER_VA;
extern phys_addr_t RTB_BUFFER_PA;
#define PRINTK_BUFFER_SIZE      (0x00300000)

#define PRINTK_BUFFER_MAGIC     (0xFEEDBEEF)
#define PRINTK_BUFFER_SLOT_SIZE (0x00040000)

#define PRINTK_BUFFER_SLOT1     (PRINTK_BUFFER_VA)
#define PRINTK_BUFFER_SLOT2     ((void *)((ulong)PRINTK_BUFFER_VA + (ulong)PRINTK_BUFFER_SLOT_SIZE))

#define PHONE_HANG_LOG_BUFFER   ((void *)((ulong)PRINTK_BUFFER_VA + (ulong)2*PRINTK_BUFFER_SLOT_SIZE) - (ulong)0x3F000)
#define PHONE_HANG_LOG_SIZE     (0x00080000 + 0x3F000)

/* ASUS_BSP Paul +++ */
#define LOGCAT_BUFFER           ((void *)((ulong)PRINTK_BUFFER_VA + (ulong)SZ_2M))
#define LOGCAT_BUFFER_SIZE      (SZ_16K)
#define LAST_KMSG_SIZE          (SZ_16K)
/* ASUS_BSP Paul --- */

/////////////////////////////////////////////////////////////////////////////////////////////
////                  Eventlog mask mechanism
/////////////////////////////////////////////////////////////////////////////////////////////
#define ASUS_ASDF_BASE_DIR "/asdf/"
#define ASUS_EVTLOG_PATH ASUS_ASDF_BASE_DIR"ASUSEvtlog"
#define ASUS_EVTLOG_STR_MAXLEN (256)
#define ASUS_EVTLOG_MAX_ITEM (20)
/*ASUS-BBSP SubSys Health Record+++*/
#define SUBSYS_HEALTH_MEDICAL_TABLE_PATH "/asdf/SubSysMedicalTable"
#define SUBSYS_NUM 5 /* MODEM, WCNSS, ADSP, VENUS, A506_ZAP */
#define SUBSYS_W_MAXLEN (170) /*%04d-%02d-%02d %02d:%02d:%02d : [SSR]:name reason*/
#define SUBSYS_R_MAXLEN (512)
#define SUBSYS_C_MAXLEN (30)
/*ASUS-BBSP SubSys Health Record---*/

void save_all_thread_info(void);
void delta_all_thread_info(void);
void save_phone_hang_log(int delta);
void save_last_shutdown_log(char *filename);
#if defined(CONFIG_MSM_RTB)
void save_rtb_log(void);
#endif
void get_last_shutdown_log(void);
void printk_lcd(const char *fmt, ...);
void printk_lcd_xy(int xx, int yy, unsigned int color, const char *fmt, ...);
void ASUSEvtlog(const char *fmt, ...);
void SubSysHealthRecord(const char *fmt, ...);/*ASUS-BBSP SubSys Health Record+*/
//20101202_Bruno: added to get debug mask value
bool isASUS_MSK_set(const char *fmt);
#endif
