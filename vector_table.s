.section    .vector_table

.word   _msp_init
.word   reset_handler

.weak   nmi_handler
.thumb_set  nmi_handler,default_handler
.word nmi_handler

.weak   hardfault_handler
.thumb_set  hardfault_handler,default_handler
.word   hardfault_handler

.weak   mmfault_handler
.thumb_set  mmfault_handler,default_handler
.word   mmfault_handler

.weak   busfault_handler
.thumb_set  busfault_handler,default_handler
.word   busfault_handler

.weak   usagefault_handler
.thumb_set  usagefault_handler,default_handler
.word   usagefault_handler

// reserved
.word   0
.word   0
.word   0
.word   0

.weak   svc_handler
.thumb_set  svc_handler,default_handler
.word svc_handler

.weak   debugmonitor_handler
.thumb_set  debugmonitor_handler,default_handler
.word   debugmonitor_handler

// reserved
.word   0

.weak   pendsv_handler
.thumb_set  pendsv_handler,default_handler
.word   pendsv_handler

//

.weak	systick_handler
.thumb_set	systick_handler,default_handler
.word systick_handler

/*********************************************************/

.weak	wwdg_handler
.thumb_set	wwdg_handler,default_handler
.word wwdg_handler

/*********************************************************/

.weak	pvd_handler
.thumb_set	pvd_handler,default_handler
.word pvd_handler

/*********************************************************/

.weak	tamp_stamp_handler
.thumb_set	tamp_stamp_handler,default_handler
.word tamp_stamp_handler

/*********************************************************/

.weak	rtc_wkup_handler
.thumb_set	rtc_wkup_handler,default_handler
.word rtc_wkup_handler

/*********************************************************/

.weak	flash_handler
.thumb_set	flash_handler,default_handler
.word flash_handler

/*********************************************************/

.weak	rcc_handler
.thumb_set	rcc_handler,default_handler
.word rcc_handler

/*********************************************************/

.weak	exti0_handler
.thumb_set	exti0_handler,default_handler
.word exti0_handler


.syntax unified

.type   default_handler,%function
default_handler:
    b   .