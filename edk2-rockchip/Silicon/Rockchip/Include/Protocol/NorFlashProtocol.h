/** @file
*
*  Copyright (c) 2022, Rockchip Limited. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#ifndef _UNI_NOR_FLASH_PROTOCOL_H_
#define _UNI_NOR_FLASH_PROTOCOL_H_

#define UNI_NOR_FLASH_PROTOCOL_GUID   \
    {0x86F305EA, 0xDFAC, 0x4A6B, {0x92, 0x77, 0x47, 0x31, 0x2E, 0xCE, 0x42, 0xA}}

typedef struct _UNI_NOR_FLASH_PROTOCOL UNI_NOR_FLASH_PROTOCOL;

typedef
UINT32
(EFIAPI *UNI_FLASH_GET_SIZE_INTERFACE)(
  IN UNI_NOR_FLASH_PROTOCOL   *This
  );

typedef
EFI_STATUS
(EFIAPI *UNI_FLASH_ERASE_INTERFACE)(
  IN UNI_NOR_FLASH_PROTOCOL   *This,
  IN UINT32                  Offset,
  IN UINT32                  Length
  );

typedef
EFI_STATUS
(EFIAPI *UNI_FLASH_WRITE_INTERFACE)(
  IN UNI_NOR_FLASH_PROTOCOL   *This,
  IN  UINT32                 Offset,
  IN  UINT8                 *Buffer,
  UINT32                   ulLength
  );

typedef
EFI_STATUS
(EFIAPI *UNI_FLASH_READ_INTERFACE)(
  IN UNI_NOR_FLASH_PROTOCOL   *This,
  IN UINT32                  Offset,
  IN OUT UINT8              *Buffer,
  IN UINT32                   ulLen
  );

typedef
EFI_STATUS
(EFIAPI *UNI_FLASH_UPDATE_INTERFACE)(
  IN UNI_NOR_FLASH_PROTOCOL   *This,
  IN  UINT32                 Offset,
  IN  UINT8                 *Buffer,
  UINT32                   ulLength
  );

struct _UNI_NOR_FLASH_PROTOCOL {
  UNI_FLASH_GET_SIZE_INTERFACE    GetSize;
  UNI_FLASH_ERASE_INTERFACE       Erase;
  UNI_FLASH_WRITE_INTERFACE       Write;
  UNI_FLASH_READ_INTERFACE        Read;
  UNI_FLASH_UPDATE_INTERFACE      Update;
};

extern EFI_GUID  gUniNorFlashProtocolGuid;

#endif
