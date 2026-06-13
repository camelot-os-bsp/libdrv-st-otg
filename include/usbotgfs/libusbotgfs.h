/*
 * Copyright (c) 2026 H2Lab Development Team
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBDRV_ST_OTGFS_H
#define LIBDRV_ST_OTGFS_H

/**
 * @file libusbotgfs.h
 * @brief STM32 OTG FS driver public API aligned with Merlin unified USB API.
 *
 * This driver exposes the Merlin high-level USB interface so upper layers can
 * use a portable API independently from the underlying USB controller
 * implementation.
 */

#include <stddef.h>
#include <stdint.h>

/*
 * Merlin USB control-plane callback prototypes are provided by this header.
 */
#include <merlin/platform/api/usb.h>

/*
 * USB control-plane hooks are resolved at link time from upper layers.
 */
extern int usbctrl_handle_earlysuspend(uint32_t dev_id);
extern int usbctrl_handle_reset(uint32_t dev_id);
extern int usbctrl_handle_usbsuspend(uint32_t dev_id);
extern int usbctrl_handle_inepevent(uint32_t dev_id, uint32_t size, uint8_t ep);
extern int usbctrl_handle_outepevent(uint32_t dev_id, uint32_t size, uint8_t ep);
extern int usbctrl_handle_wakeup(uint32_t dev_id);

/*
 * Public USB API prototypes are intentionally re-exported from
 * merlin/platform/api/usb.h to avoid duplicated declarations.
 */

#endif /* LIBDRV_ST_OTGFS_H */
