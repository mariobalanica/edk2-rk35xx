# EDK2 UEFI firmware for Rockchip RK35xx platforms

**WARNING: This repo is highly experimental**

## Description

This repository is based on the official open-source UEFI implementation from Rockchip, which is under active development.

Therefore, to keep up with the work from Rockchip, we should avoid modifying code from Rockchip in most cases.

Discussion thread: [Windows / UEFI on Rock 5 (Mega thread)](https://forum.radxa.com/t/windows-uefi-on-rock-5-mega-thread/12924)

## Building

Using Arch Linux as example

Install required packages:
```bash
sudo pacman -Syu
sudo pacman -S git base-devel gcc dtc aarch64-linux-gnu-binutils aarch64-linux-gnu-gcc aarch64-linux-gnu-glibc python python-pyelftools iasl --needed
```

Required packages for Ubuntu/Debian:
```bash
sudo apt install git gcc g++ build-essential gcc-aarch64-linux-gnu iasl python3-pyelftools
```

Clone the repository:
```bash
git clone https://github.com/edk2-porting/edk2-rk35xx.git
cd edk2-rk35xx
```

Build UEFI (ROCK 5B for example):
```bash
./build.sh -d rock-5b
```

## TODO
 - Create gpt image in build process instead of using the prebuilt one
 - Fix resetting to maskrom
