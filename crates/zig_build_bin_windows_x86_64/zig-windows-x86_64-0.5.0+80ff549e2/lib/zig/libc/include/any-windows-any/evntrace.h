/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <winapifamily.h>

#ifndef _EVNTRACE_
#define _EVNTRACE_

#if defined (_WINNT_) || defined (WINNT)

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)

#if !defined (WMIAPI) && !defined (__WIDL__) && !defined (MIDL_PASS)
#ifdef _WMI_SOURCE_
#ifdef _ARM_
#define WMIAPI
#else
#define WMIAPI __stdcall
#endif
#else
#ifdef _ARM_
#define WMIAPI DECLSPEC_IMPORT
#else
#define WMIAPI DECLSPEC_IMPORT __stdcall
#endif
#endif
#endif

#include <guiddef.h>

#if defined (_NTDDK_) || defined (_NTIFS_) || defined (_WMIKM_)
#define _EVNTRACE_KERNEL_MODE
#endif

#ifndef _EVNTRACE_KERNEL_MODE
#include <wmistr.h>
#endif

DEFINE_GUID (EventTraceGuid, 0x68fdd900, 0x4a3e, 0x11d1, 0x84, 0xf4, 0x00, 0x00, 0xf8, 0x04, 0x64, 0xe3);
DEFINE_GUID (SystemTraceControlGuid, 0x9e814aad, 0x3204, 0x11d2, 0x9a, 0x82, 0x00, 0x60, 0x08, 0xa8, 0x69, 0x39);
DEFINE_GUID (EventTraceConfigGuid, 0x01853a65, 0x418f, 0x4f36, 0xae, 0xfc, 0xdc, 0x0f, 0x1d, 0x2f, 0xd2, 0x35);
DEFINE_GUID (DefaultTraceSecurityGuid, 0x0811c1af, 0x7a07, 0x4a06, 0x82, 0xed, 0x86, 0x94, 0x55, 0xcd, 0xf7, 0x13);

#define KERNEL_LOGGER_NAMEW L"NT Kernel Logger"
#define GLOBAL_LOGGER_NAMEW L"GlobalLogger"
#define EVENT_LOGGER_NAMEW L"EventLog"
#define DIAG_LOGGER_NAMEW L"DiagLog"

#define KERNEL_LOGGER_NAMEA "NT Kernel Logger"
#define GLOBAL_LOGGER_NAMEA "GlobalLogger"
#define EVENT_LOGGER_NAMEA "EventLog"
#define DIAG_LOGGER_NAMEA "DiagLog"

#define MAX_MOF_FIELDS 16

#ifndef _TRACEHANDLE_DEFINED
#define _TRACEHANDLE_DEFINED
typedef ULONG64 TRACEHANDLE,*PTRACEHANDLE;
#endif

#define SYSTEM_EVENT_TYPE 1

#define EVENT_TRACE_TYPE_INFO 0x00
#define EVENT_TRACE_TYPE_START 0x01
#define EVENT_TRACE_TYPE_END 0x02
#define EVENT_TRACE_TYPE_STOP 0x02
#define EVENT_TRACE_TYPE_DC_START 0x03
#define EVENT_TRACE_TYPE_DC_END 0x04
#define EVENT_TRACE_TYPE_EXTENSION 0x05
#define EVENT_TRACE_TYPE_REPLY 0x06
#define EVENT_TRACE_TYPE_DEQUEUE 0x07
#define EVENT_TRACE_TYPE_RESUME 0x07
#define EVENT_TRACE_TYPE_CHECKPOINT 0x08
#define EVENT_TRACE_TYPE_SUSPEND 0x08
#define EVENT_TRACE_TYPE_WINEVT_SEND 0x09
#define EVENT_TRACE_TYPE_WINEVT_RECEIVE 0xf0

#define TRACE_LEVEL_NONE 0
#define TRACE_LEVEL_CRITICAL 1
#define TRACE_LEVEL_FATAL 1
#define TRACE_LEVEL_ERROR 2
#define TRACE_LEVEL_WARNING 3
#define TRACE_LEVEL_INFORMATION 4
#define TRACE_LEVEL_VERBOSE 5
#define TRACE_LEVEL_RESERVED6 6
#define TRACE_LEVEL_RESERVED7 7
#define TRACE_LEVEL_RESERVED8 8
#define TRACE_LEVEL_RESERVED9 9

#define EVENT_TRACE_TYPE_LOAD 0x0a
#define EVENT_TRACE_TYPE_TERMINATE 0x0b

#define EVENT_TRACE_TYPE_IO_READ 0x0a
#define EVENT_TRACE_TYPE_IO_WRITE 0x0b
#define EVENT_TRACE_TYPE_IO_READ_INIT 0x0c
#define EVENT_TRACE_TYPE_IO_WRITE_INIT 0x0d
#define EVENT_TRACE_TYPE_IO_FLUSH 0x0e
#define EVENT_TRACE_TYPE_IO_FLUSH_INIT 0x0f

#define EVENT_TRACE_TYPE_MM_TF 0x0a
#define EVENT_TRACE_TYPE_MM_DZF 0x0b
#define EVENT_TRACE_TYPE_MM_COW 0x0c
#define EVENT_TRACE_TYPE_MM_GPF 0x0d
#define EVENT_TRACE_TYPE_MM_HPF 0x0e
#define EVENT_TRACE_TYPE_MM_AV 0x0f

#define EVENT_TRACE_TYPE_SEND 0x0a
#define EVENT_TRACE_TYPE_RECEIVE 0x0b
#define EVENT_TRACE_TYPE_CONNECT 0x0c
#define EVENT_TRACE_TYPE_DISCONNECT 0x0d
#define EVENT_TRACE_TYPE_RETRANSMIT 0x0e
#define EVENT_TRACE_TYPE_ACCEPT 0x0f
#define EVENT_TRACE_TYPE_RECONNECT 0x10
#define EVENT_TRACE_TYPE_CONNFAIL 0x11
#define EVENT_TRACE_TYPE_COPY_TCP 0x12
#define EVENT_TRACE_TYPE_COPY_ARP 0x13
#define EVENT_TRACE_TYPE_ACKFULL 0x14
#define EVENT_TRACE_TYPE_ACKPART 0x15
#define EVENT_TRACE_TYPE_ACKDUP 0x16

#define EVENT_TRACE_TYPE_GUIDMAP 0x0a
#define EVENT_TRACE_TYPE_CONFIG 0x0b
#define EVENT_TRACE_TYPE_SIDINFO 0x0c
#define EVENT_TRACE_TYPE_SECURITY 0x0d
#define EVENT_TRACE_TYPE_DBGID_RSDS 0x40

#define EVENT_TRACE_TYPE_REGCREATE 0x0a
#define EVENT_TRACE_TYPE_REGOPEN 0x0b
#define EVENT_TRACE_TYPE_REGDELETE 0x0c
#define EVENT_TRACE_TYPE_REGQUERY 0x0d
#define EVENT_TRACE_TYPE_REGSETVALUE 0x0e
#define EVENT_TRACE_TYPE_REGDELETEVALUE 0x0f
#define EVENT_TRACE_TYPE_REGQUERYVALUE 0x10
#define EVENT_TRACE_TYPE_REGENUMERATEKEY 0x11
#define EVENT_TRACE_TYPE_REGENUMERATEVALUEKEY 0x12
#define EVENT_TRACE_TYPE_REGQUERYMULTIPLEVALUE 0x13
#define EVENT_TRACE_TYPE_REGSETINFORMATION 0x14
#define EVENT_TRACE_TYPE_REGFLUSH 0x15
#define EVENT_TRACE_TYPE_REGKCBCREATE 0x16
#define EVENT_TRACE_TYPE_REGKCBDELETE 0x17
#define EVENT_TRACE_TYPE_REGKCBRUNDOWNBEGIN 0x18
#define EVENT_TRACE_TYPE_REGKCBRUNDOWNEND 0x19
#define EVENT_TRACE_TYPE_REGVIRTUALIZE 0x1a
#define EVENT_TRACE_TYPE_REGCLOSE 0x1b
#define EVENT_TRACE_TYPE_REGSETSECURITY 0x1c
#define EVENT_TRACE_TYPE_REGQUERYSECURITY 0x1d
#define EVENT_TRACE_TYPE_REGCOMMIT 0x1e
#define EVENT_TRACE_TYPE_REGPREPARE 0x1f
#define EVENT_TRACE_TYPE_REGROLLBACK 0x20
#define EVENT_TRACE_TYPE_REGMOUNTHIVE 0x21

#define EVENT_TRACE_TYPE_CONFIG_CPU 0x0a
#define EVENT_TRACE_TYPE_CONFIG_PHYSICALDISK 0x0b
#define EVENT_TRACE_TYPE_CONFIG_LOGICALDISK 0x0c
#define EVENT_TRACE_TYPE_CONFIG_NIC 0x0d
#define EVENT_TRACE_TYPE_CONFIG_VIDEO 0x0e
#define EVENT_TRACE_TYPE_CONFIG_SERVICES 0x0f
#define EVENT_TRACE_TYPE_CONFIG_POWER 0x10
#define EVENT_TRACE_TYPE_CONFIG_NETINFO 0x11
#define EVENT_TRACE_TYPE_CONFIG_OPTICALMEDIA 0x12

#define EVENT_TRACE_TYPE_CONFIG_IRQ 0x15
#define EVENT_TRACE_TYPE_CONFIG_PNP 0x16
#define EVENT_TRACE_TYPE_CONFIG_IDECHANNEL 0x17
#define EVENT_TRACE_TYPE_CONFIG_NUMANODE 0x18
#define EVENT_TRACE_TYPE_CONFIG_PLATFORM 0x19
#define EVENT_TRACE_TYPE_CONFIG_PROCESSORGROUP 0x1a
#define EVENT_TRACE_TYPE_CONFIG_PROCESSORNUMBER 0x1b
#define EVENT_TRACE_TYPE_CONFIG_DPI 0x1c
#define EVENT_TRACE_TYPE_CONFIG_CI_INFO 0x1d
#define EVENT_TRACE_TYPE_CONFIG_MACHINEID 0x1e
#define EVENT_TRACE_TYPE_CONFIG_DEFRAG 0x1f
#define EVENT_TRACE_TYPE_CONFIG_MOBILEPLATFORM 0x20
#define EVENT_TRACE_TYPE_CONFIG_DEVICEFAMILY 0x21
#define EVENT_TRACE_TYPE_CONFIG_FLIGHTID 0x22
#define EVENT_TRACE_TYPE_CONFIG_PROCESSOR 0x23

#define EVENT_TRACE_TYPE_OPTICAL_IO_READ 0x37
#define EVENT_TRACE_TYPE_OPTICAL_IO_WRITE 0x38
#define EVENT_TRACE_TYPE_OPTICAL_IO_FLUSH 0x39
#define EVENT_TRACE_TYPE_OPTICAL_IO_READ_INIT 0x3a
#define EVENT_TRACE_TYPE_OPTICAL_IO_WRITE_INIT 0x3b
#define EVENT_TRACE_TYPE_OPTICAL_IO_FLUSH_INIT 0x3c

#define EVENT_TRACE_TYPE_FLT_PREOP_INIT 0x60
#define EVENT_TRACE_TYPE_FLT_POSTOP_INIT 0x61
#define EVENT_TRACE_TYPE_FLT_PREOP_COMPLETION 0x62
#define EVENT_TRACE_TYPE_FLT_POSTOP_COMPLETION 0x63
#define EVENT_TRACE_TYPE_FLT_PREOP_FAILURE 0x64
#define EVENT_TRACE_TYPE_FLT_POSTOP_FAILURE 0x65

#define EVENT_TRACE_FLAG_PROCESS 0x00000001
#define EVENT_TRACE_FLAG_THREAD 0x00000002
#define EVENT_TRACE_FLAG_IMAGE_LOAD 0x00000004

#define EVENT_TRACE_FLAG_DISK_IO 0x00000100
#define EVENT_TRACE_FLAG_DISK_FILE_IO 0x00000200

#define EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS 0x00001000
#define EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS 0x00002000

#define EVENT_TRACE_FLAG_NETWORK_TCPIP 0x00010000

#define EVENT_TRACE_FLAG_REGISTRY 0x00020000
#define EVENT_TRACE_FLAG_DBGPRINT 0x00040000

#define EVENT_TRACE_FLAG_PROCESS_COUNTERS 0x00000008
#define EVENT_TRACE_FLAG_CSWITCH 0x00000010
#define EVENT_TRACE_FLAG_DPC 0x00000020
#define EVENT_TRACE_FLAG_INTERRUPT 0x00000040
#define EVENT_TRACE_FLAG_SYSTEMCALL 0x00000080

#define EVENT_TRACE_FLAG_DISK_IO_INIT 0x00000400
#define EVENT_TRACE_FLAG_ALPC 0x00100000
#define EVENT_TRACE_FLAG_SPLIT_IO 0x00200000

#define EVENT_TRACE_FLAG_DRIVER 0x00800000
#define EVENT_TRACE_FLAG_PROFILE 0x01000000
#define EVENT_TRACE_FLAG_FILE_IO 0x02000000
#define EVENT_TRACE_FLAG_FILE_IO_INIT 0x04000000

#define EVENT_TRACE_FLAG_DISPATCHER 0x00000800
#define EVENT_TRACE_FLAG_VIRTUAL_ALLOC 0x00004000

#define EVENT_TRACE_FLAG_VAMAP 0x00008000
#define EVENT_TRACE_FLAG_NO_SYSCONFIG 0x10000000

#define EVENT_TRACE_FLAG_JOB 0x00080000
#define EVENT_TRACE_FLAG_DEBUG_EVENTS 0x00400000

#define EVENT_TRACE_FLAG_EXTENSION 0x80000000
#define EVENT_TRACE_FLAG_FORWARD_WMI 0x40000000
#define EVENT_TRACE_FLAG_ENABLE_RESERVE 0x20000000

#define EVENT_TRACE_FILE_MODE_NONE 0x00000000
#define EVENT_TRACE_FILE_MODE_SEQUENTIAL 0x00000001
#define EVENT_TRACE_FILE_MODE_CIRCULAR 0x00000002
#define EVENT_TRACE_FILE_MODE_APPEND 0x00000004

#define EVENT_TRACE_REAL_TIME_MODE 0x00000100
#define EVENT_TRACE_DELAY_OPEN_FILE_MODE 0x00000200
#define EVENT_TRACE_BUFFERING_MODE 0x00000400
#define EVENT_TRACE_PRIVATE_LOGGER_MODE 0x00000800
#define EVENT_TRACE_ADD_HEADER_MODE 0x00001000

#define EVENT_TRACE_USE_GLOBAL_SEQUENCE 0x00004000
#define EVENT_TRACE_USE_LOCAL_SEQUENCE 0x00008000

#define EVENT_TRACE_RELOG_MODE 0x00010000

#define EVENT_TRACE_USE_PAGED_MEMORY 0x01000000

#define EVENT_TRACE_FILE_MODE_NEWFILE 0x00000008
#define EVENT_TRACE_FILE_MODE_PREALLOCATE 0x00000020

#define EVENT_TRACE_NONSTOPPABLE_MODE 0x00000040
#define EVENT_TRACE_SECURE_MODE 0x00000080
#define EVENT_TRACE_USE_KBYTES_FOR_SIZE 0x00002000
#define EVENT_TRACE_PRIVATE_IN_PROC 0x00020000
#define EVENT_TRACE_MODE_RESERVED 0x00100000

#define EVENT_TRACE_NO_PER_PROCESSOR_BUFFERING 0x10000000

#define EVENT_TRACE_SYSTEM_LOGGER_MODE 0x02000000
#define EVENT_TRACE_ADDTO_TRIAGE_DUMP 0x80000000
#define EVENT_TRACE_STOP_ON_HYBRID_SHUTDOWN 0x00400000
#define EVENT_TRACE_PERSIST_ON_HYBRID_SHUTDOWN 0x00800000

#define EVENT_TRACE_INDEPENDENT_SESSION_MODE 0x08000000
#define EVENT_TRACE_COMPRESSED_MODE 0x04000000

#define EVENT_TRACE_CONTROL_QUERY 0
#define EVENT_TRACE_CONTROL_STOP 1
#define EVENT_TRACE_CONTROL_UPDATE 2
#define EVENT_TRACE_CONTROL_FLUSH 3
#define EVENT_TRACE_CONTROL_INCREMENT_FILE 4

#define TRACE_MESSAGE_SEQUENCE 1
#define TRACE_MESSAGE_GUID 2
#define TRACE_MESSAGE_COMPONENTID 4
#define TRACE_MESSAGE_TIMESTAMP 8
#define TRACE_MESSAGE_PERFORMANCE_TIMESTAMP 16
#define TRACE_MESSAGE_SYSTEMINFO 32

#define TRACE_MESSAGE_POINTER32 0x0040
#define TRACE_MESSAGE_POINTER64 0x0080

#define TRACE_MESSAGE_FLAG_MASK 0xffff

#define TRACE_MESSAGE_MAXIMUM_SIZE (64 * 1024)

#define EVENT_TRACE_USE_PROCTIME 0x0001
#define EVENT_TRACE_USE_NOCPUTIME 0x0002

#define TRACE_HEADER_FLAG_USE_TIMESTAMP 0x00000200
#define TRACE_HEADER_FLAG_TRACED_GUID 0x00020000
#define TRACE_HEADER_FLAG_LOG_WNODE 0x00040000
#define TRACE_HEADER_FLAG_USE_GUID_PTR 0x00080000
#define TRACE_HEADER_FLAG_USE_MOF_PTR 0x00100000

typedef enum {
  EtwCompressionModeRestart = 0,
  EtwCompressionModeNoDisable = 1,
  EtwCompressionModeNoRestart = 2
} ETW_COMPRESSION_RESUMPTION_MODE;

typedef struct _EVENT_TRACE_HEADER {
  USHORT Size;
  __C89_NAMELESS union {
    USHORT FieldTypeFlags;
    __C89_NAMELESS struct {
      UCHAR HeaderType;
      UCHAR MarkerFlags;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  __C89_NAMELESS union {
    ULONG Version;
    struct {
      UCHAR Type;
      UCHAR Level;
      USHORT Version;
    } Class;
  } DUMMYUNIONNAME2;
  ULONG ThreadId;
  ULONG ProcessId;
  LARGE_INTEGER TimeStamp;
  __C89_NAMELESS union {
    GUID Guid;
    ULONGLONG GuidPtr;
  } DUMMYUNIONNAME3;
  __C89_NAMELESS union {
    __C89_NAMELESS struct {
      ULONG KernelTime;
      ULONG UserTime;
    } DUMMYSTRUCTNAME;
    ULONG64 ProcessorTime;
    __C89_NAMELESS struct {
      ULONG ClientContext;
      ULONG Flags;
    } DUMMYSTRUCTNAME2;
  } DUMMYUNIONNAME4;
} EVENT_TRACE_HEADER,*PEVENT_TRACE_HEADER;

typedef struct _EVENT_INSTANCE_HEADER {
  USHORT Size;
  __C89_NAMELESS union {
    USHORT FieldTypeFlags;
    __C89_NAMELESS struct {
      UCHAR HeaderType;
      UCHAR MarkerFlags;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  __C89_NAMELESS union {
    ULONG Version;
    struct {
      UCHAR Type;
      UCHAR Level;
      USHORT Version;
    } Class;
  } DUMMYUNIONNAME2;
  ULONG ThreadId;
  ULONG ProcessId;
  LARGE_INTEGER TimeStamp;
  ULONGLONG RegHandle;
  ULONG InstanceId;
  ULONG ParentInstanceId;
  __C89_NAMELESS union {
    __C89_NAMELESS struct {
      ULONG KernelTime;
      ULONG UserTime;
    } DUMMYSTRUCTNAME;
    ULONG64 ProcessorTime;
    __C89_NAMELESS struct {
      ULONG EventId;
      ULONG Flags;
    } DUMMYSTRUCTNAME2;
  } DUMMYUNIONNAME3;
  ULONGLONG ParentRegHandle;
} EVENT_INSTANCE_HEADER,*PEVENT_INSTANCE_HEADER;

#define ETW_NULL_TYPE_VALUE 0
#define ETW_OBJECT_TYPE_VALUE 1
#define ETW_STRING_TYPE_VALUE 2
#define ETW_SBYTE_TYPE_VALUE 3
#define ETW_BYTE_TYPE_VALUE 4
#define ETW_INT16_TYPE_VALUE 5
#define ETW_UINT16_TYPE_VALUE 6
#define ETW_INT32_TYPE_VALUE 7
#define ETW_UINT32_TYPE_VALUE 8
#define ETW_INT64_TYPE_VALUE 9
#define ETW_UINT64_TYPE_VALUE 10
#define ETW_CHAR_TYPE_VALUE 11
#define ETW_SINGLE_TYPE_VALUE 12
#define ETW_DOUBLE_TYPE_VALUE 13
#define ETW_BOOLEAN_TYPE_VALUE 14
#define ETW_DECIMAL_TYPE_VALUE 15

#define ETW_GUID_TYPE_VALUE 101
#define ETW_ASCIICHAR_TYPE_VALUE 102
#define ETW_ASCIISTRING_TYPE_VALUE 103
#define ETW_COUNTED_STRING_TYPE_VALUE 104
#define ETW_POINTER_TYPE_VALUE 105
#define ETW_SIZET_TYPE_VALUE 106
#define ETW_HIDDEN_TYPE_VALUE 107
#define ETW_BOOL_TYPE_VALUE 108
#define ETW_COUNTED_ANSISTRING_TYPE_VALUE 109
#define ETW_REVERSED_COUNTED_STRING_TYPE_VALUE 110
#define ETW_REVERSED_COUNTED_ANSISTRING_TYPE_VALUE 111
#define ETW_NON_NULL_TERMINATED_STRING_TYPE_VALUE 112
#define ETW_REDUCED_ANSISTRING_TYPE_VALUE 113
#define ETW_REDUCED_STRING_TYPE_VALUE 114
#define ETW_SID_TYPE_VALUE 115
#define ETW_VARIANT_TYPE_VALUE 116
#define ETW_PTVECTOR_TYPE_VALUE 117
#define ETW_WMITIME_TYPE_VALUE 118
#define ETW_DATETIME_TYPE_VALUE 119
#define ETW_REFRENCE_TYPE_VALUE 120

#define DEFINE_TRACE_MOF_FIELD(M, P, LEN, TYP) (M)->DataPtr = (ULONG64) (ULONG_PTR) P; (M)->Length = (ULONG) LEN; (M)->DataType = (ULONG) TYP;

typedef struct _MOF_FIELD {
  ULONG64 DataPtr;
  ULONG Length;
  ULONG DataType;
} MOF_FIELD,*PMOF_FIELD;

#if !defined (_EVNTRACE_KERNEL_MODE) || defined (_WMIKM_)
typedef struct _TRACE_LOGFILE_HEADER {
  ULONG BufferSize;
  __C89_NAMELESS union {
    ULONG Version;
    struct {
      UCHAR MajorVersion;
      UCHAR MinorVersion;
      UCHAR SubVersion;
      UCHAR SubMinorVersion;
    } VersionDetail;
  } DUMMYUNIONNAME;
  ULONG ProviderVersion;
  ULONG NumberOfProcessors;
  LARGE_INTEGER EndTime;
  ULONG TimerResolution;
  ULONG MaximumFileSize;
  ULONG LogFileMode;
  ULONG BuffersWritten;
  __C89_NAMELESS union {
    GUID LogInstanceGuid;
    __C89_NAMELESS struct {
      ULONG StartBuffers;
      ULONG PointerSize;
      ULONG EventsLost;
      ULONG CpuSpeedInMHz;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME2;
#if defined (_WMIKM_)
  PWCHAR LoggerName;
  PWCHAR LogFileName;
  RTL_TIME_ZONE_INFORMATION TimeZone;
#else
  LPWSTR LoggerName;
  LPWSTR LogFileName;
  TIME_ZONE_INFORMATION TimeZone;
#endif
  LARGE_INTEGER BootTime;
  LARGE_INTEGER PerfFreq;
  LARGE_INTEGER StartTime;
  ULONG ReservedFlags;
  ULONG BuffersLost;
} TRACE_LOGFILE_HEADER,*PTRACE_LOGFILE_HEADER;

typedef struct _TRACE_LOGFILE_HEADER32 {
  ULONG BufferSize;
  __C89_NAMELESS union {
    ULONG Version;
    struct {
      UCHAR MajorVersion;
      UCHAR MinorVersion;
      UCHAR SubVersion;
      UCHAR SubMinorVersion;
    } VersionDetail;
  };
  ULONG ProviderVersion;
  ULONG NumberOfProcessors;
  LARGE_INTEGER EndTime;
  ULONG TimerResolution;
  ULONG MaximumFileSize;
  ULONG LogFileMode;
  ULONG BuffersWritten;
  __C89_NAMELESS union {
    GUID LogInstanceGuid;
    __C89_NAMELESS struct {
      ULONG StartBuffers;
      ULONG PointerSize;
      ULONG EventsLost;
      ULONG CpuSpeedInMHz;
    };
  };
  ULONG32 LoggerName;
  ULONG32 LogFileName;
#if defined (_WMIKM_)
  RTL_TIME_ZONE_INFORMATION TimeZone;
#else
  TIME_ZONE_INFORMATION TimeZone;
#endif
  LARGE_INTEGER BootTime;
  LARGE_INTEGER PerfFreq;
  LARGE_INTEGER StartTime;
  ULONG ReservedFlags;
  ULONG BuffersLost;
} TRACE_LOGFILE_HEADER32,*PTRACE_LOGFILE_HEADER32;

typedef struct _TRACE_LOGFILE_HEADER64 {
  ULONG BufferSize;
  __C89_NAMELESS union {
    ULONG Version;
    __C89_NAMELESS struct {
      UCHAR MajorVersion;
      UCHAR MinorVersion;
      UCHAR SubVersion;
      UCHAR SubMinorVersion;
    } VersionDetail;
  };
  ULONG ProviderVersion;
  ULONG NumberOfProcessors;
  LARGE_INTEGER EndTime;
  ULONG TimerResolution;
  ULONG MaximumFileSize;
  ULONG LogFileMode;
  ULONG BuffersWritten;
  __C89_NAMELESS union {
    GUID LogInstanceGuid;
    __C89_NAMELESS struct {
      ULONG StartBuffers;
      ULONG PointerSize;
      ULONG EventsLost;
      ULONG CpuSpeedInMHz;
    };
  };
  ULONG64 LoggerName;
  ULONG64 LogFileName;
#if defined (_WMIKM_)
  RTL_TIME_ZONE_INFORMATION TimeZone;
#else
  TIME_ZONE_INFORMATION TimeZone;
#endif
  LARGE_INTEGER BootTime;
  LARGE_INTEGER PerfFreq;
  LARGE_INTEGER StartTime;
  ULONG ReservedFlags;
  ULONG BuffersLost;
} TRACE_LOGFILE_HEADER64,*PTRACE_LOGFILE_HEADER64;
#endif

typedef struct EVENT_INSTANCE_INFO {
  HANDLE RegHandle;
  ULONG InstanceId;
} EVENT_INSTANCE_INFO,*PEVENT_INSTANCE_INFO;

#ifndef _EVNTRACE_KERNEL_MODE

typedef struct _EVENT_FILTER_DESCRIPTOR EVENT_FILTER_DESCRIPTOR, *PEVENT_FILTER_DESCRIPTOR;

typedef struct _EVENT_TRACE_PROPERTIES {
  WNODE_HEADER Wnode;
  ULONG BufferSize;
  ULONG MinimumBuffers;
  ULONG MaximumBuffers;
  ULONG MaximumFileSize;
  ULONG LogFileMode;
  ULONG FlushTimer;
  ULONG EnableFlags;
  LONG AgeLimit;
  ULONG NumberOfBuffers;
  ULONG FreeBuffers;
  ULONG EventsLost;
  ULONG BuffersWritten;
  ULONG LogBuffersLost;
  ULONG RealTimeBuffersLost;
  HANDLE LoggerThreadId;
  ULONG LogFileNameOffset;
  ULONG LoggerNameOffset;
} EVENT_TRACE_PROPERTIES,*PEVENT_TRACE_PROPERTIES;

typedef struct _EVENT_TRACE_PROPERTIES_V2 {
  WNODE_HEADER Wnode;
  ULONG BufferSize;
  ULONG MinimumBuffers;
  ULONG MaximumBuffers;
  ULONG MaximumFileSize;
  ULONG LogFileMode;
  ULONG FlushTimer;
  ULONG EnableFlags;
  __C89_NAMELESS union {
      LONG  AgeLimit;
      LONG  FlushThreshold;
  };
  ULONG NumberOfBuffers;
  ULONG FreeBuffers;
  ULONG EventsLost;
  ULONG BuffersWritten;
  ULONG LogBuffersLost;
  ULONG RealTimeBuffersLost;
  HANDLE LoggerThreadId;
  ULONG LogFileNameOffset;
  ULONG LoggerNameOffset;
  __C89_NAMELESS union {
      __C89_NAMELESS struct {
          ULONG VersionNumber : 8;
      };
      ULONG V2Control;
  };
  ULONG FilterDescCount;
  PEVENT_FILTER_DESCRIPTOR FilterDesc;
  __C89_NAMELESS union {
      __C89_NAMELESS struct {
          ULONG Wow : 1;
          ULONG QpcDeltaTracking : 1;
      };
      ULONG64 V2Options;
  };
} EVENT_TRACE_PROPERTIES_V2, *PEVENT_TRACE_PROPERTIES_V2;

typedef struct _TRACE_GUID_REGISTRATION {
  LPCGUID Guid;
  HANDLE RegHandle;
} TRACE_GUID_REGISTRATION,*PTRACE_GUID_REGISTRATION;
#endif

typedef struct _TRACE_GUID_PROPERTIES {
  GUID Guid;
  ULONG GuidType;
  ULONG LoggerId;
  ULONG EnableLevel;
  ULONG EnableFlags;
  BOOLEAN IsEnable;
} TRACE_GUID_PROPERTIES,*PTRACE_GUID_PROPERTIES;

#ifndef ETW_BUFFER_CONTEXT_DEF
#define ETW_BUFFER_CONTEXT_DEF

typedef struct _ETW_BUFFER_CONTEXT {
  __C89_NAMELESS union {
    __C89_NAMELESS struct {
      UCHAR ProcessorNumber;
      UCHAR Alignment;
    } DUMMYSTRUCTNAME;
    USHORT ProcessorIndex;
  } DUMMYUNIONNAME;
  USHORT LoggerId;
} ETW_BUFFER_CONTEXT,*PETW_BUFFER_CONTEXT;
#endif

#define TRACE_PROVIDER_FLAG_LEGACY (0x00000001)
#define TRACE_PROVIDER_FLAG_PRE_ENABLE (0x00000002)

typedef struct _TRACE_ENABLE_INFO {
  ULONG IsEnabled;
  UCHAR Level;
  UCHAR Reserved1;
  USHORT LoggerId;
  ULONG EnableProperty;
  ULONG Reserved2;
  ULONGLONG MatchAnyKeyword;
  ULONGLONG MatchAllKeyword;
} TRACE_ENABLE_INFO,*PTRACE_ENABLE_INFO;

typedef struct _TRACE_PROVIDER_INSTANCE_INFO {
  ULONG NextOffset;
  ULONG EnableCount;
  ULONG Pid;
  ULONG Flags;
} TRACE_PROVIDER_INSTANCE_INFO,*PTRACE_PROVIDER_INSTANCE_INFO;

typedef struct _TRACE_GUID_INFO {
  ULONG InstanceCount;
  ULONG Reserved;
} TRACE_GUID_INFO,*PTRACE_GUID_INFO;

typedef struct _PROFILE_SOURCE_INFO {
  ULONG NextEntryOffset;
  ULONG Source;
  ULONG MinInterval;
  ULONG MaxInterval;
  ULONG64 Reserved;
  WCHAR Description[ANYSIZE_ARRAY];
} PROFILE_SOURCE_INFO,*PPROFILE_SOURCE_INFO;

typedef struct _EVENT_TRACE {
  EVENT_TRACE_HEADER Header;
  ULONG InstanceId;
  ULONG ParentInstanceId;
  GUID ParentGuid;
  PVOID MofData;
  ULONG MofLength;
  __C89_NAMELESS union {
    ULONG ClientContext;
    ETW_BUFFER_CONTEXT BufferContext;
  } DUMMYUNIONNAME;
} EVENT_TRACE,*PEVENT_TRACE;

#define EVENT_CONTROL_CODE_DISABLE_PROVIDER 0
#define EVENT_CONTROL_CODE_ENABLE_PROVIDER 1
#define EVENT_CONTROL_CODE_CAPTURE_STATE 2
#endif

#ifndef _EVNTRACE_KERNEL_MODE
#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
typedef struct _EVENT_RECORD EVENT_RECORD,*PEVENT_RECORD;
typedef struct _EVENT_TRACE_LOGFILEW EVENT_TRACE_LOGFILEW,*PEVENT_TRACE_LOGFILEW;
typedef struct _EVENT_TRACE_LOGFILEA EVENT_TRACE_LOGFILEA,*PEVENT_TRACE_LOGFILEA;
typedef ULONG (WINAPI *PEVENT_TRACE_BUFFER_CALLBACKW) (PEVENT_TRACE_LOGFILEW Logfile);
typedef ULONG (WINAPI *PEVENT_TRACE_BUFFER_CALLBACKA) (PEVENT_TRACE_LOGFILEA Logfile);
typedef VOID (WINAPI *PEVENT_CALLBACK) (PEVENT_TRACE pEvent);
typedef VOID (WINAPI *PEVENT_RECORD_CALLBACK) (PEVENT_RECORD EventRecord);
typedef ULONG (WINAPI *WMIDPREQUEST) (WMIDPREQUESTCODE RequestCode, PVOID RequestContext, ULONG *BufferSize, PVOID Buffer);

struct _EVENT_TRACE_LOGFILEW {
  LPWSTR LogFileName;
  LPWSTR LoggerName;
  LONGLONG CurrentTime;
  ULONG BuffersRead;
  __C89_NAMELESS union {
    ULONG LogFileMode;
    ULONG ProcessTraceMode;
  } DUMMYUNIONNAME;
  EVENT_TRACE CurrentEvent;
  TRACE_LOGFILE_HEADER LogfileHeader;
  PEVENT_TRACE_BUFFER_CALLBACKW BufferCallback;
  ULONG BufferSize;
  ULONG Filled;
  ULONG EventsLost;
  __C89_NAMELESS union {
    PEVENT_CALLBACK EventCallback;
    PEVENT_RECORD_CALLBACK EventRecordCallback;
  } DUMMYUNIONNAME2;
  ULONG IsKernelTrace;
  PVOID Context;
};

struct _EVENT_TRACE_LOGFILEA {
  LPSTR LogFileName;
  LPSTR LoggerName;
  LONGLONG CurrentTime;
  ULONG BuffersRead;
  __C89_NAMELESS union {
    ULONG LogFileMode;
    ULONG ProcessTraceMode;
  } DUMMYUNIONNAME;
  EVENT_TRACE CurrentEvent;
  TRACE_LOGFILE_HEADER LogfileHeader;
  PEVENT_TRACE_BUFFER_CALLBACKA BufferCallback;
  ULONG BufferSize;
  ULONG Filled;
  ULONG EventsLost;
  __C89_NAMELESS union {
    PEVENT_CALLBACK EventCallback;
    PEVENT_RECORD_CALLBACK EventRecordCallback;
  } DUMMYUNIONNAME2;
  ULONG IsKernelTrace;
  PVOID Context;
};

#if defined (_UNICODE) || defined (UNICODE)
#define PEVENT_TRACE_BUFFER_CALLBACK PEVENT_TRACE_BUFFER_CALLBACKW
#define EVENT_TRACE_LOGFILE EVENT_TRACE_LOGFILEW
#define PEVENT_TRACE_LOGFILE PEVENT_TRACE_LOGFILEW
#define KERNEL_LOGGER_NAME KERNEL_LOGGER_NAMEW
#define GLOBAL_LOGGER_NAME GLOBAL_LOGGER_NAMEW
#define EVENT_LOGGER_NAME EVENT_LOGGER_NAMEW
#else
#define PEVENT_TRACE_BUFFER_CALLBACK PEVENT_TRACE_BUFFER_CALLBACKA
#define EVENT_TRACE_LOGFILE EVENT_TRACE_LOGFILEA
#define PEVENT_TRACE_LOGFILE PEVENT_TRACE_LOGFILEA
#define KERNEL_LOGGER_NAME KERNEL_LOGGER_NAMEA
#define GLOBAL_LOGGER_NAME GLOBAL_LOGGER_NAMEA
#define EVENT_LOGGER_NAME EVENT_LOGGER_NAMEA
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ENABLE_TRACE_PARAMETERS_VERSION 1
#define ENABLE_TRACE_PARAMETERS_VERSION_2 2

typedef enum _TRACE_QUERY_INFO_CLASS {
    TraceGuidQueryList,
    TraceGuidQueryInfo,
    TraceGuidQueryProcess,
    TraceStackTracingInfo,
    TraceSystemTraceEnableFlagsInfo,
    TraceSampledProfileIntervalInfo,
    TraceProfileSourceConfigInfo,
    TraceProfileSourceListInfo,
    TracePmcEventListInfo,
    TracePmcCounterListInfo,
    TraceSetDisallowList,
    TraceVersionInfo,
    TraceGroupQueryList,
    TraceGroupQueryInfo,
    TraceDisallowListQuery,
    TraceCompressionInfo,
    TracePeriodicCaptureStateListInfo,
    TracePeriodicCaptureStateInfo,
    TraceProviderBinaryTracking,
    TraceMaxLoggersQuery,
    MaxTraceSetInfoClass
} TRACE_QUERY_INFO_CLASS, TRACE_INFO_CLASS;

typedef struct _EVENT_FILTER_DESCRIPTOR EVENT_FILTER_DESCRIPTOR,*PEVENT_FILTER_DESCRIPTOR;

typedef struct _ENABLE_TRACE_PARAMETERS_V1 {
    ULONG                    Version;
    ULONG                    EnableProperty;
    ULONG                    ControlFlags;
    GUID                     SourceId;
    PEVENT_FILTER_DESCRIPTOR EnableFilterDesc;
} ENABLE_TRACE_PARAMETERS_V1, *PENABLE_TRACE_PARAMETERS_V1;

typedef struct _ENABLE_TRACE_PARAMETERS {
    ULONG                    Version;
    ULONG                    EnableProperty;
    ULONG                    ControlFlags;
    GUID                     SourceId;
    PEVENT_FILTER_DESCRIPTOR EnableFilterDesc;
    ULONG                    FilterDescCount;
} ENABLE_TRACE_PARAMETERS, *PENABLE_TRACE_PARAMETERS;

/*To enable the read event type for disk IO events, set GUID to 3d6fa8d4-fe05-11d0-9dda-00c04fd7ba7c and Type to 10.*/
typedef struct _CLASSIC_EVENT_ID {
    GUID  EventGuid;
    UCHAR Type;
    UCHAR Reserved[7];
} CLASSIC_EVENT_ID, *PCLASSIC_EVENT_ID;

typedef struct _TRACE_PROFILE_INTERVAL {
    ULONG Source;
    ULONG Interval;
} TRACE_PROFILE_INTERVAL, *PTRACE_PROFILE_INTERVAL;

typedef struct _TRACE_VERSION_INFO {
    UINT EtwTraceProcessingVersion;
    UINT Reserved;
} TRACE_VERSION_INFO, *PTRACE_VERSION_INFO;

typedef struct _TRACE_PERIODIC_CAPTURE_STATE_INFO {
    ULONG CaptureStateFrequencyInSeconds;
    USHORT ProviderCount;
    USHORT Reserved;
} TRACE_PERIODIC_CAPTURE_STATE_INFO, *PTRACE_PERIODIC_CAPTURE_STATE_INFO;

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
  EXTERN_C ULONG WMIAPI StartTraceA (PTRACEHANDLE TraceHandle, LPCSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI StopTraceA (TRACEHANDLE TraceHandle, LPCSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI QueryTraceA (TRACEHANDLE TraceHandle, LPCSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI UpdateTraceW (TRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI UpdateTraceA (TRACEHANDLE TraceHandle, LPCSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI FlushTraceA (TRACEHANDLE TraceHandle, LPCSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI ControlTraceA (TRACEHANDLE TraceHandle, LPCSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties, ULONG ControlCode);
  EXTERN_C ULONG WMIAPI QueryAllTracesW (PEVENT_TRACE_PROPERTIES *PropertyArray, ULONG PropertyArrayCount, PULONG LoggerCount);
  EXTERN_C ULONG WMIAPI QueryAllTracesA (PEVENT_TRACE_PROPERTIES *PropertyArray, ULONG PropertyArrayCount, PULONG LoggerCount);
  EXTERN_C ULONG WMIAPI CreateTraceInstanceId (HANDLE RegHandle, PEVENT_INSTANCE_INFO InstInfo);
  EXTERN_C ULONG WMIAPI TraceEvent (TRACEHANDLE TraceHandle, PEVENT_TRACE_HEADER EventTrace);
  EXTERN_C ULONG WMIAPI TraceEventInstance (TRACEHANDLE TraceHandle, PEVENT_INSTANCE_HEADER EventTrace, PEVENT_INSTANCE_INFO InstInfo, PEVENT_INSTANCE_INFO ParentInstInfo);
  EXTERN_C ULONG WMIAPI RegisterTraceGuidsA (WMIDPREQUEST RequestAddress, PVOID RequestContext, LPCGUID ControlGuid, ULONG GuidCount, PTRACE_GUID_REGISTRATION TraceGuidReg, LPCSTR MofImagePath, LPCSTR MofResourceName, PTRACEHANDLE RegistrationHandle);
  EXTERN_C ULONG WMIAPI EnumerateTraceGuids (PTRACE_GUID_PROPERTIES *GuidPropertiesArray, ULONG PropertyArrayCount, PULONG GuidCount);
  EXTERN_C TRACEHANDLE WMIAPI OpenTraceA (PEVENT_TRACE_LOGFILEA Logfile);
  EXTERN_C TRACEHANDLE WMIAPI OpenTraceW (PEVENT_TRACE_LOGFILEW Logfile);
  EXTERN_C ULONG WMIAPI ProcessTrace (PTRACEHANDLE HandleArray, ULONG HandleCount, LPFILETIME StartTime, LPFILETIME EndTime);
  EXTERN_C ULONG WMIAPI CloseTrace (TRACEHANDLE TraceHandle);
  EXTERN_C ULONG WMIAPI SetTraceCallback (LPCGUID pGuid, PEVENT_CALLBACK EventCallback);
  EXTERN_C ULONG WMIAPI RemoveTraceCallback (LPCGUID pGuid);
  EXTERN_C ULONG TraceMessageVa (TRACEHANDLE LoggerHandle, ULONG MessageFlags, LPCGUID MessageGuid, USHORT MessageNumber, va_list MessageArgList);
#if WINVER >= 0x0600
  EXTERN_C ULONG WMIAPI EnableTraceEx (LPCGUID ProviderId, LPCGUID SourceId, TRACEHANDLE TraceHandle, ULONG IsEnabled, UCHAR Level, ULONGLONG MatchAnyKeyword, ULONGLONG MatchAllKeyword, ULONG EnableProperty, PEVENT_FILTER_DESCRIPTOR EnableFilterDesc);
  EXTERN_C ULONG WMIAPI EnumerateTraceGuidsEx (TRACE_QUERY_INFO_CLASS TraceQueryInfoClass, PVOID InBuffer, ULONG InBufferSize, PVOID OutBuffer, ULONG OutBufferSize, PULONG ReturnLength);
#endif
#if WINVER >= 0x0601
  EXTERN_C ULONG WMIAPI EnableTraceEx2 (TRACEHANDLE TraceHandle, LPCGUID ProviderId, ULONG ControlCode, UCHAR Level, ULONGLONG MatchAnyKeyword, ULONGLONG MatchAllKeyword, ULONG Timeout, PENABLE_TRACE_PARAMETERS EnableParameters);
  EXTERN_C ULONG WMIAPI TraceSetInformation (TRACEHANDLE SessionHandle, TRACE_INFO_CLASS InformationClass, PVOID TraceInformation, ULONG InformationLength);
#endif
#if WINVER >= 0x0602
  EXTERN_C ULONG WMIAPI TraceQueryInformation (TRACEHANDLE SessionHandle, TRACE_INFO_CLASS InformationClass, PVOID TraceInformation, ULONG InformationLength, PULONG ReturnLength);
#endif
#endif /* WINAPI_PARTITION_DESKTOP */

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)

typedef enum _ETW_PROCESS_HANDLE_INFO_TYPE {
    EtwQueryPartitionInformation = 1,
    EtwQueryProcessHandleInfoMax
} ETW_PROCESS_HANDLE_INFO_TYPE;

typedef struct _ETW_TRACE_PARTITION_INFORMATION {
    GUID PartitionId;
    GUID ParentId;
    LONG64 QpcOffsetFromRoot;
    ULONG PartitionType;
} ETW_TRACE_PARTITION_INFORMATION, *PETW_TRACE_PARTITION_INFORMATION;

  EXTERN_C ULONG WMIAPI StartTraceW (PTRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI StopTraceW (TRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI QueryTraceW (TRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI FlushTraceW (TRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI ControlTraceW (TRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties, ULONG ControlCode);
  EXTERN_C ULONG WMIAPI EnableTrace (ULONG Enable, ULONG EnableFlag, ULONG EnableLevel, LPCGUID ControlGuid, TRACEHANDLE TraceHandle);
  EXTERN_C ULONG WMIAPI RegisterTraceGuidsW (WMIDPREQUEST RequestAddress, PVOID RequestContext, LPCGUID ControlGuid, ULONG GuidCount, PTRACE_GUID_REGISTRATION TraceGuidReg, LPCWSTR MofImagePath, LPCWSTR MofResourceName, PTRACEHANDLE RegistrationHandle);
  EXTERN_C ULONG WMIAPI UnregisterTraceGuids (TRACEHANDLE RegistrationHandle);
  EXTERN_C TRACEHANDLE WMIAPI GetTraceLoggerHandle (PVOID Buffer);
  EXTERN_C UCHAR WMIAPI GetTraceEnableLevel (TRACEHANDLE TraceHandle);
  EXTERN_C ULONG WMIAPI GetTraceEnableFlags (TRACEHANDLE TraceHandle);
  EXTERN_C ULONG __cdecl TraceMessage (TRACEHANDLE LoggerHandle, ULONG MessageFlags, LPCGUID MessageGuid, USHORT MessageNumber,...);
  EXTERN_C ULONG WMIAPI QueryTraceProcessingHandle (TRACEHANDLE ProcessingHandle, ETW_PROCESS_HANDLE_INFO_TYPE InformationClass, PVOID InBuffer, ULONG InBufferSize, PVOID OutBuffer, ULONG OutBufferSize, PULONG ReturnLength);
#endif /* WINAPI_PARTITION_APP */

#ifdef __cplusplus
}
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
#define INVALID_PROCESSTRACE_HANDLE ((TRACEHANDLE)INVALID_HANDLE_VALUE)
#endif

#if defined (UNICODE) || defined (_UNICODE)
#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
#define RegisterTraceGuids RegisterTraceGuidsW
#define StartTrace StartTraceW
#define ControlTrace ControlTraceW

#ifdef __TRACE_W2K_COMPATIBLE
#define StopTrace(a, b, c) ControlTraceW ((a),(b),(c), EVENT_TRACE_CONTROL_STOP)
#define QueryTrace(a, b, c) ControlTraceW ((a),(b),(c), EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a, b, c) ControlTraceW ((a),(b),(c), EVENT_TRACE_CONTROL_UPDATE)
#else
#define StopTrace StopTraceW
#define QueryTrace QueryTraceW
#define UpdateTrace UpdateTraceW
#endif

#define FlushTrace FlushTraceW
#define QueryAllTraces QueryAllTracesW
#define OpenTrace OpenTraceW
#endif
#else

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
#define RegisterTraceGuids RegisterTraceGuidsA
#define StartTrace StartTraceA
#define ControlTrace ControlTraceA

#ifdef __TRACE_W2K_COMPATIBLE
#define StopTrace(a, b, c) ControlTraceA ((a),(b),(c), EVENT_TRACE_CONTROL_STOP)
#define QueryTrace(a, b, c) ControlTraceA ((a),(b),(c), EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a, b, c) ControlTraceA ((a),(b),(c), EVENT_TRACE_CONTROL_UPDATE)
#else
#define StopTrace StopTraceA
#define QueryTrace QueryTraceA
#define UpdateTrace UpdateTraceA
#endif

#define FlushTrace FlushTraceA
#define QueryAllTraces QueryAllTracesA
#define OpenTrace OpenTraceA
#endif
#endif
#endif
#endif
#endif
