# libdrv-st-otgfs

libdrv-st-otgfs is a C driver library for the STM32 USB OTG FS peripheral.
It is designed to be used inside the Camelot userspace driver stack, with:

- Merlin for driver framework abstractions
- Kconfig for feature/config selection
- Devicetree for hardware description and pin/peripheral setup

The project builds a static library:

- libdrv-st-otgfs (static archive)

and installs the public API header:

- include/usbotgfs/libusbotgfs.h

## What is in this Repository

- src/: USB OTG FS driver implementation
- include/usbotgfs/: public driver API
- Kconfig: driver feature toggles (device mode by default, host mode is marked WiP)
- dts/sample.dts: sample devicetree description for STM32U5 OTG FS
- configs/sample.config: sample Kconfig configuration used for local builds

## Build system

This project uses Meson and Ninja.

Main Meson options used by this repository:

- config: path to a Kconfig fragment
- dts: path to a devicetree file
- dts-include-dirs: additional include directories for DTS preprocessing

## Prerequisites

Install a Camelot-OS SDK, that you can find here :
https://github.com/camelot-os/camelot-sdk

And configure the PKG_CONFIG_PATH variable so that it targets the lib/pkgconfig subdir of the SDK installation dir.

Project dependency requirements:

- merlin (provided through Meson subproject wrap in this repository)
- kconfig helper subproject (provided through Meson subproject wrap)
- devicetree helper subproject (provided through Meson subproject wrap)
- shield dependency resolvable by your build environment as being a part of the SDK

## Quick Start

From the repository root, run:

```bash
meson setup \
  -Dconfig=configs/sample.config \
  -Ddts-include-dirs=$SDK_ROOT/share/dts \
  -Ddts=dts/sample.dts \
  --cross-file=your-meson-crossfile \
  builddir
```

and then:

```bash
meson compile -C builddir
```

## Typical Integration Notes

- The driver mode is selected in Kconfig through USR_DRV_USBOTGFS_MODE_DEVICE or USR_DRV_USBOTGFS_MODE_HOST.
- Device mode is the default and the currently expected mode for integration.
- Host mode is present but explicitly marked as work in progress in Kconfig help text.
- The sample DTS in this repository defines the OTG FS node and pinctrl for PA11/PA12.
