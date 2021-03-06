/*++

Copyright (c) 2019 changeofpace. All rights reserved.

Use of this source code is governed by the MIT license. See the 'LICENSE' file
for more information.

--*/

#pragma once

#include <Windows.h>

#include "..\common\arch_x64.h"
#include "..\common\driver_io_types.h"

//=============================================================================
// Meta Interface
//=============================================================================
_Check_return_
BOOL
VivienneIoInitialization();

VOID
VivienneIoTermination();

//=============================================================================
// Public Interface
//=============================================================================
_Check_return_
BOOL
VivienneIoQuerySystemDebugState(
    _Out_writes_bytes_(cbSystemDebugState) PSYSTEM_DEBUG_STATE pSystemDebugState,
    _In_ ULONG cbSystemDebugState
);

_Check_return_
BOOL
VivienneIoSetHardwareBreakpoint(
    _In_ ULONG_PTR ProcessId,
    _In_ ULONG DebugRegisterIndex,
    _In_ ULONG_PTR Address,
    _In_ HWBP_TYPE Type,
    _In_ HWBP_SIZE Size
);

_Check_return_
BOOL
VivienneIoClearHardwareBreakpoint(
    _In_ ULONG DebugRegisterIndex
);

_Check_return_
BOOL
VivienneIoCaptureRegisterValues(
    _In_ ULONG_PTR ProcessId,
    _In_ ULONG DebugRegisterIndex,
    _In_ ULONG_PTR Address,
    _In_ HWBP_TYPE Type,
    _In_ HWBP_SIZE Size,
    _In_ X64_REGISTER Register,
    _In_ ULONG DurationInMilliseconds,
    _Out_writes_bytes_(cbValuesCtx) PCEC_REGISTER_VALUES pValuesCtx,
    _In_ ULONG cbValuesCtx
);

_Check_return_
BOOL
VivienneIoCaptureMemoryValues(
    _In_ ULONG_PTR ProcessId,
    _In_ ULONG DebugRegisterIndex,
    _In_ ULONG_PTR Address,
    _In_ HWBP_TYPE Type,
    _In_ HWBP_SIZE Size,
    _In_ PCEC_MEMORY_DESCRIPTION pMemoryDescription,
    _In_ ULONG DurationInMilliseconds,
    _Out_writes_bytes_(cbValuesCtx) PCEC_MEMORY_VALUES pValuesCtx,
    _In_ ULONG cbValuesCtx
);
