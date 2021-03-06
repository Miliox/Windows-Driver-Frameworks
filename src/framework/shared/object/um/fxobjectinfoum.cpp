//
//    Copyright (C) Microsoft.  All rights reserved.
//
#include "FxMin.hpp"
#include "fxobjectpch.hpp"

#include "FxUserObject.hpp"
#include "pnppriv.hpp"

//
// More object types should be added to this table as more objects
// are merged and incorporated in UMDF
//

extern "C" {

//
// Assumes sorted (by type) order!
//
FX_OBJECT_INFO FxObjectsInfo[] = {
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxObject, FX_TYPE_OBJECT),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxDriver, FX_TYPE_DRIVER, WDFDRIVER),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxDevice, FX_TYPE_DEVICE, WDFDEVICE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxIoQueue, FX_TYPE_QUEUE, WDFQUEUE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxWmiProvider, FX_TYPE_WMI_PROVIDER, WDFWMIPROVIDER),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxRegKey, FX_TYPE_REG_KEY, WDFKEY),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxString, FX_TYPE_STRING, WDFSTRING),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxRequest, FX_TYPE_REQUEST, WDFREQUEST),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxLookasideList, FX_TYPE_LOOKASIDE, WDFLOOKASIDE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxMemoryObject, IFX_TYPE_MEMORY, WDFMEMORY),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxIrpQueue, FX_TYPE_IRPQUEUE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxUserObject, FX_TYPE_USEROBJECT, WDFOBJECT),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxCollection, FX_TYPE_COLLECTION, WDFCOLLECTION),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxVerifierLock, FX_TYPE_VERIFIERLOCK),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxSystemThread, FX_TYPE_SYSTEMTHREAD),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxMpDevice, FX_TYPE_MP_DEVICE, WDFDEVICE),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxResourceIo, FX_TYPE_RESOURCE_IO),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxResourceCm, FX_TYPE_RESOURCE_CM),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxFileObject, FX_TYPE_FILEOBJECT, WDFFILEOBJECT),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxRelatedDevice, FX_TYPE_RELATED_DEVICE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxMemoryBufferPreallocated, FX_TYPE_MEMORY_PREALLOCATED, WDFMEMORY),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxWaitLock, FX_TYPE_WAIT_LOCK, WDFWAITLOCK),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxSpinLock, FX_TYPE_SPIN_LOCK, WDFSPINLOCK),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxWorkItem, FX_TYPE_WORKITEM, WDFWORKITEM),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxInterrupt, FX_TYPE_INTERRUPT, WDFINTERRUPT),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxTimer, FX_TYPE_TIMER, WDFTIMER),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxChildList, FX_TYPE_CHILD_LIST, WDFCHILDLIST),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxSystemWorkItem, FX_TYPE_SYSTEMWORKITEM),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxRequestMemory, FX_TYPE_REQUEST_MEMORY, WDFMEMORY),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxDisposeList, FX_TYPE_DISPOSELIST),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxIoResList, FX_TYPE_IO_RES_LIST, WDFIORESLIST),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxCmResList, FX_TYPE_CM_RES_LIST, WDFCMRESLIST),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxIoResReqList, FX_TYPE_IO_RES_REQ_LIST, WDFIORESREQLIST),

    FX_INTERNAL_OBJECT_INFO_ENTRY(FxPkgIo, FX_TYPE_PACKAGE_IO),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxPkgFdo, FX_TYPE_PACKAGE_FDO),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxPkgPdo, FX_TYPE_PACKAGE_PDO),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxPkgGeneral, FX_TYPE_PACKAGE_GENERAL),
    FX_INTERNAL_OBJECT_INFO_ENTRY(FxDefaultIrpHandler, FX_TYPE_DEFAULT_IRP_HANDLER),

    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxIoTarget, FX_TYPE_IO_TARGET, WDFIOTARGET),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxUsbDevice, FX_TYPE_IO_TARGET_USB_DEVICE, WDFUSBDEVICE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxUsbPipe, FX_TYPE_IO_TARGET_USB_PIPE, WDFUSBPIPE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxUsbInterface, FX_TYPE_USB_INTERFACE, WDFUSBINTERFACE),
    FX_EXTERNAL_OBJECT_INFO_ENTRY(FxIoTargetSelf, FX_TYPE_IO_TARGET_SELF, WDFIOTARGET),
};

ULONG FxObjectsInfoCount = sizeof(FxObjectsInfo)/sizeof(FX_OBJECT_INFO);

} //extern "C"
