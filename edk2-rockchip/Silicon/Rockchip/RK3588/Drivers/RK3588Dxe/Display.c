/** @file
 *
 *  Copyright (c) 2025, Mario Bălănică <mariobalanica02@gmail.com>
 *
 *  SPDX-License-Identifier: BSD-2-Clause-Patent
 *
 **/

#include <Library/DebugLib.h>
#include <Library/PcdLib.h>

#include "Display.h"

STATIC
EFI_STATUS
InitializeDisplayVariables (
  VOID
  )
{
  EFI_STATUS  Status;
  UINTN       Index;
  UINT32      *Connectors;
  UINTN       ConnectorsSize;
  UINT32      ConnectorsMask;

  Connectors     = PcdGetPtr (PcdDisplayConnectors);
  ConnectorsSize = PcdGetSize (PcdDisplayConnectors);
  ASSERT ((ConnectorsSize / sizeof (*Connectors)) <= VOP_OUTPUT_IF_NUMS);

  ConnectorsMask = 0;
  for (Index = 0; Index < (ConnectorsSize / sizeof (*Connectors)); Index++ ) {
    ConnectorsMask |= Connectors[Index];
  }

  if ((ConnectorsMask & (VOP_OUTPUT_IF_HDMI0 | VOP_OUTPUT_IF_EDP0)) ==
      (VOP_OUTPUT_IF_HDMI0 | VOP_OUTPUT_IF_EDP0))
  {
    DEBUG ((DEBUG_ERROR, "%a: Cannot support both HDMI0 and EDP0 simultaneously!\n", __func__));
    ASSERT (FALSE);
    ConnectorsMask &= ~(VOP_OUTPUT_IF_HDMI0 | VOP_OUTPUT_IF_EDP0);
  }

  if ((ConnectorsMask & (VOP_OUTPUT_IF_HDMI1 | VOP_OUTPUT_IF_EDP1)) ==
      (VOP_OUTPUT_IF_HDMI1 | VOP_OUTPUT_IF_EDP1))
  {
    DEBUG ((DEBUG_ERROR, "%a: Cannot support both HDMI1 and EDP1 simultaneously!\n", __func__));
    ASSERT (FALSE);
    ConnectorsMask &= ~(VOP_OUTPUT_IF_HDMI1 | VOP_OUTPUT_IF_EDP1);
  }

  Status = PcdSet32S (PcdDisplayConnectorsMask, ConnectorsMask);
  ASSERT_EFI_ERROR (Status);

  if (ConnectorsMask == 0) {
    return EFI_UNSUPPORTED;
  }

  return EFI_SUCCESS;
}

VOID
EFIAPI
ApplyDisplayVariables (
  VOID
  )
{
}

VOID
EFIAPI
SetupDisplayVariables (
  VOID
  )
{
  EFI_STATUS  Status;

  Status = InitializeDisplayVariables ();
  if (EFI_ERROR (Status)) {
    return;
  }
}
