/* This file generated by errnos.awk from
     errno.texi
     mach/message.h
     mach/kern_return.h
     mach/mig_errors.h
     device/device_types.h
   Do not edit this file; edit errnos.awk and regenerate it.  */

#ifndef _BITS_ERRNO_H
#define _BITS_ERRNO_H 1

#if !defined _ERRNO_H
# error "Never include <bits/errno.h> directly; use <errno.h> instead."
#endif

#ifndef __ASSEMBLER__

enum __error_t_codes
{
  /* The value zero always means success and it is perfectly fine
     for code to use 0 explicitly (or implicitly, e.g. via Boolean
     coercion.)  Having an enum entry for zero both makes the
     debugger print the name for error_t-typed zero values, and
     prevents the compiler from issuing warnings about 'case 0:'
     in a switch on an error_t-typed value.  */
  ESUCCESS                       = 0,

  /* The Hurd uses Mach error system 0x10, subsystem 0. */
  EPERM                          = 0x40000001,	/* Operation not permitted */
  ENOENT                         = 0x40000002,	/* No such file or directory */
  ESRCH                          = 0x40000003,	/* No such process */
  EINTR                          = 0x40000004,	/* Interrupted system call */
  EIO                            = 0x40000005,	/* Input/output error */
  ENXIO                          = 0x40000006,	/* No such device or address */
  E2BIG                          = 0x40000007,	/* Argument list too long */
  ENOEXEC                        = 0x40000008,	/* Exec format error */
  EBADF                          = 0x40000009,	/* Bad file descriptor */
  ECHILD                         = 0x4000000a,	/* No child processes */
  EDEADLK                        = 0x4000000b,	/* Resource deadlock avoided */
  ENOMEM                         = 0x4000000c,	/* Cannot allocate memory */
  EACCES                         = 0x4000000d,	/* Permission denied */
  EFAULT                         = 0x4000000e,	/* Bad address */
  ENOTBLK                        = 0x4000000f,	/* Block device required */
  EBUSY                          = 0x40000010,	/* Device or resource busy */
  EEXIST                         = 0x40000011,	/* File exists */
  EXDEV                          = 0x40000012,	/* Invalid cross-device link */
  ENODEV                         = 0x40000013,	/* No such device */
  ENOTDIR                        = 0x40000014,	/* Not a directory */
  EISDIR                         = 0x40000015,	/* Is a directory */
  EINVAL                         = 0x40000016,	/* Invalid argument */
  EMFILE                         = 0x40000018,	/* Too many open files */
  ENFILE                         = 0x40000017,	/* Too many open files in system */
  ENOTTY                         = 0x40000019,	/* Inappropriate ioctl for device */
  ETXTBSY                        = 0x4000001a,	/* Text file busy */
  EFBIG                          = 0x4000001b,	/* File too large */
  ENOSPC                         = 0x4000001c,	/* No space left on device */
  ESPIPE                         = 0x4000001d,	/* Illegal seek */
  EROFS                          = 0x4000001e,	/* Read-only file system */
  EMLINK                         = 0x4000001f,	/* Too many links */
  EPIPE                          = 0x40000020,	/* Broken pipe */
  EDOM                           = 0x40000021,	/* Numerical argument out of domain */
  ERANGE                         = 0x40000022,	/* Numerical result out of range */
  EAGAIN                         = 0x40000023,	/* Resource temporarily unavailable */
  EINPROGRESS                    = 0x40000024,	/* Operation now in progress */
  EALREADY                       = 0x40000025,	/* Operation already in progress */
  ENOTSOCK                       = 0x40000026,	/* Socket operation on non-socket */
  EMSGSIZE                       = 0x40000028,	/* Message too long */
  EPROTOTYPE                     = 0x40000029,	/* Protocol wrong type for socket */
  ENOPROTOOPT                    = 0x4000002a,	/* Protocol not available */
  EPROTONOSUPPORT                = 0x4000002b,	/* Protocol not supported */
  ESOCKTNOSUPPORT                = 0x4000002c,	/* Socket type not supported */
  EOPNOTSUPP                     = 0x4000002d,	/* Operation not supported */
  EPFNOSUPPORT                   = 0x4000002e,	/* Protocol family not supported */
  EAFNOSUPPORT                   = 0x4000002f,	/* Address family not supported by protocol */
  EADDRINUSE                     = 0x40000030,	/* Address already in use */
  EADDRNOTAVAIL                  = 0x40000031,	/* Cannot assign requested address */
  ENETDOWN                       = 0x40000032,	/* Network is down */
  ENETUNREACH                    = 0x40000033,	/* Network is unreachable */
  ENETRESET                      = 0x40000034,	/* Network dropped connection on reset */
  ECONNABORTED                   = 0x40000035,	/* Software caused connection abort */
  ECONNRESET                     = 0x40000036,	/* Connection reset by peer */
  ENOBUFS                        = 0x40000037,	/* No buffer space available */
  EISCONN                        = 0x40000038,	/* Transport endpoint is already connected */
  ENOTCONN                       = 0x40000039,	/* Transport endpoint is not connected */
  EDESTADDRREQ                   = 0x40000027,	/* Destination address required */
  ESHUTDOWN                      = 0x4000003a,	/* Cannot send after transport endpoint shutdown */
  ETOOMANYREFS                   = 0x4000003b,	/* Too many references: cannot splice */
  ETIMEDOUT                      = 0x4000003c,	/* Connection timed out */
  ECONNREFUSED                   = 0x4000003d,	/* Connection refused */
  ELOOP                          = 0x4000003e,	/* Too many levels of symbolic links */
  ENAMETOOLONG                   = 0x4000003f,	/* File name too long */
  EHOSTDOWN                      = 0x40000040,	/* Host is down */
  EHOSTUNREACH                   = 0x40000041,	/* No route to host */
  ENOTEMPTY                      = 0x40000042,	/* Directory not empty */
  EPROCLIM                       = 0x40000043,	/* Too many processes */
  EUSERS                         = 0x40000044,	/* Too many users */
  EDQUOT                         = 0x40000045,	/* Disk quota exceeded */
  ESTALE                         = 0x40000046,	/* Stale file handle */
  EREMOTE                        = 0x40000047,	/* Object is remote */
  EBADRPC                        = 0x40000048,	/* RPC struct is bad */
  ERPCMISMATCH                   = 0x40000049,	/* RPC version wrong */
  EPROGUNAVAIL                   = 0x4000004a,	/* RPC program not available */
  EPROGMISMATCH                  = 0x4000004b,	/* RPC program version wrong */
  EPROCUNAVAIL                   = 0x4000004c,	/* RPC bad procedure for program */
  ENOLCK                         = 0x4000004d,	/* No locks available */
  EFTYPE                         = 0x4000004f,	/* Inappropriate file type or format */
  EAUTH                          = 0x40000050,	/* Authentication error */
  ENEEDAUTH                      = 0x40000051,	/* Need authenticator */
  ENOSYS                         = 0x4000004e,	/* Function not implemented */
  ELIBEXEC                       = 0x40000053,	/* Cannot exec a shared library directly */
  ENOTSUP                        = 0x40000076,	/* Not supported */
  EILSEQ                         = 0x4000006a,	/* Invalid or incomplete multibyte or wide character */
  EBACKGROUND                    = 0x40000064,	/* Inappropriate operation for background process */
  EDIED                          = 0x40000065,	/* Translator died */
#if 0
  ED                             = 0x40000066,	/* ? */
#endif
  EGREGIOUS                      = 0x40000067,	/* You really blew it this time */
  EIEIO                          = 0x40000068,	/* Computer bought the farm */
  EGRATUITOUS                    = 0x40000069,	/* Gratuitous error */
  EBADMSG                        = 0x4000006b,	/* Bad message */
  EIDRM                          = 0x4000006c,	/* Identifier removed */
  EMULTIHOP                      = 0x4000006d,	/* Multihop attempted */
  ENODATA                        = 0x4000006e,	/* No data available */
  ENOLINK                        = 0x4000006f,	/* Link has been severed */
  ENOMSG                         = 0x40000070,	/* No message of desired type */
  ENOSR                          = 0x40000071,	/* Out of streams resources */
  ENOSTR                         = 0x40000072,	/* Device not a stream */
  EOVERFLOW                      = 0x40000073,	/* Value too large for defined data type */
  EPROTO                         = 0x40000074,	/* Protocol error */
  ETIME                          = 0x40000075,	/* Timer expired */
  ECANCELED                      = 0x40000077,	/* Operation canceled */
  EOWNERDEAD                     = 0x40000078,	/* Owner died */
  ENOTRECOVERABLE                = 0x40000079,	/* State not recoverable */

/* Errors from <mach/message.h>.  */
  EMACH_SEND_IN_PROGRESS         = 0x10000001,
  EMACH_SEND_INVALID_DATA        = 0x10000002,
  EMACH_SEND_INVALID_DEST        = 0x10000003,
  EMACH_SEND_TIMED_OUT           = 0x10000004,
  EMACH_SEND_WILL_NOTIFY         = 0x10000005,
  EMACH_SEND_NOTIFY_IN_PROGRESS  = 0x10000006,
  EMACH_SEND_INTERRUPTED         = 0x10000007,
  EMACH_SEND_MSG_TOO_SMALL       = 0x10000008,
  EMACH_SEND_INVALID_REPLY       = 0x10000009,
  EMACH_SEND_INVALID_RIGHT       = 0x1000000a,
  EMACH_SEND_INVALID_NOTIFY      = 0x1000000b,
  EMACH_SEND_INVALID_MEMORY      = 0x1000000c,
  EMACH_SEND_NO_BUFFER           = 0x1000000d,
  EMACH_SEND_NO_NOTIFY           = 0x1000000e,
  EMACH_SEND_INVALID_TYPE        = 0x1000000f,
  EMACH_SEND_INVALID_HEADER      = 0x10000010,
  EMACH_RCV_IN_PROGRESS          = 0x10004001,
  EMACH_RCV_INVALID_NAME         = 0x10004002,
  EMACH_RCV_TIMED_OUT            = 0x10004003,
  EMACH_RCV_TOO_LARGE            = 0x10004004,
  EMACH_RCV_INTERRUPTED          = 0x10004005,
  EMACH_RCV_PORT_CHANGED         = 0x10004006,
  EMACH_RCV_INVALID_NOTIFY       = 0x10004007,
  EMACH_RCV_INVALID_DATA         = 0x10004008,
  EMACH_RCV_PORT_DIED            = 0x10004009,
  EMACH_RCV_IN_SET               = 0x1000400a,
  EMACH_RCV_HEADER_ERROR         = 0x1000400b,
  EMACH_RCV_BODY_ERROR           = 0x1000400c,

/* Errors from <mach/kern_return.h>.  */
  EKERN_INVALID_ADDRESS          = 1,
  EKERN_PROTECTION_FAILURE       = 2,
  EKERN_NO_SPACE                 = 3,
  EKERN_INVALID_ARGUMENT         = 4,
  EKERN_FAILURE                  = 5,
  EKERN_RESOURCE_SHORTAGE        = 6,
  EKERN_NOT_RECEIVER             = 7,
  EKERN_NO_ACCESS                = 8,
  EKERN_MEMORY_FAILURE           = 9,
  EKERN_MEMORY_ERROR             = 10,
  EKERN_NOT_IN_SET               = 12,
  EKERN_NAME_EXISTS              = 13,
  EKERN_ABORTED                  = 14,
  EKERN_INVALID_NAME             = 15,
  EKERN_INVALID_TASK             = 16,
  EKERN_INVALID_RIGHT            = 17,
  EKERN_INVALID_VALUE            = 18,
  EKERN_UREFS_OVERFLOW           = 19,
  EKERN_INVALID_CAPABILITY       = 20,
  EKERN_RIGHT_EXISTS             = 21,
  EKERN_INVALID_HOST             = 22,
  EKERN_MEMORY_PRESENT           = 23,
  EKERN_WRITE_PROTECTION_FAILURE = 24,
  EKERN_TERMINATED               = 26,
  EKERN_TIMEDOUT                 = 27,
  EKERN_INTERRUPTED              = 28,

/* Errors from <mach/mig_errors.h>.  */
  EMIG_TYPE_ERROR                = -300,	/* client type check failure */
  EMIG_REPLY_MISMATCH            = -301,	/* wrong reply message ID */
  EMIG_REMOTE_ERROR              = -302,	/* server detected error */
  EMIG_BAD_ID                    = -303,	/* bad request message ID */
  EMIG_BAD_ARGUMENTS             = -304,	/* server type check failure */
  EMIG_NO_REPLY                  = -305,	/* no reply should be sent */
  EMIG_EXCEPTION                 = -306,	/* server raised exception */
  EMIG_ARRAY_TOO_LARGE           = -307,	/* array not large enough */
  EMIG_SERVER_DIED               = -308,	/* server died */
  EMIG_DESTROY_REQUEST           = -309,	/* destroy request with no reply */

/* Errors from <device/device_types.h>.  */
  ED_IO_ERROR                    = 2500,	/* hardware IO error */
  ED_WOULD_BLOCK                 = 2501,	/* would block, but D_NOWAIT set */
  ED_NO_SUCH_DEVICE              = 2502,	/* no such device */
  ED_ALREADY_OPEN                = 2503,	/* exclusive-use device already open */
  ED_DEVICE_DOWN                 = 2504,	/* device has been shut down */
  ED_INVALID_OPERATION           = 2505,	/* bad operation for device */
  ED_INVALID_RECNUM              = 2506,	/* invalid record (block) number */
  ED_INVALID_SIZE                = 2507,	/* invalid IO size */
  ED_NO_MEMORY                   = 2508,	/* memory allocation failure */
  ED_READ_ONLY                   = 2509,	/* device cannot be written to */

  /* Because the C standard requires that errno have type 'int',
     this enumeration must be a signed type.  */
  __FORCE_ERROR_T_CODES_SIGNED = -1
};

#endif /* not __ASSEMBLER__ */

/* The C standard requires that all of the E-constants be
   defined as macros.  */

#define EPERM                          0x40000001
#define ENOENT                         0x40000002
#define ESRCH                          0x40000003
#define EINTR                          0x40000004
#define EIO                            0x40000005
#define ENXIO                          0x40000006
#define E2BIG                          0x40000007
#define ENOEXEC                        0x40000008
#define EBADF                          0x40000009
#define ECHILD                         0x4000000a
#define EDEADLK                        0x4000000b
#define ENOMEM                         0x4000000c
#define EACCES                         0x4000000d
#define EFAULT                         0x4000000e
#define ENOTBLK                        0x4000000f
#define EBUSY                          0x40000010
#define EEXIST                         0x40000011
#define EXDEV                          0x40000012
#define ENODEV                         0x40000013
#define ENOTDIR                        0x40000014
#define EISDIR                         0x40000015
#define EINVAL                         0x40000016
#define EMFILE                         0x40000018
#define ENFILE                         0x40000017
#define ENOTTY                         0x40000019
#define ETXTBSY                        0x4000001a
#define EFBIG                          0x4000001b
#define ENOSPC                         0x4000001c
#define ESPIPE                         0x4000001d
#define EROFS                          0x4000001e
#define EMLINK                         0x4000001f
#define EPIPE                          0x40000020
#define EDOM                           0x40000021
#define ERANGE                         0x40000022
#define EAGAIN                         0x40000023
#define EWOULDBLOCK                    EAGAIN
#define EINPROGRESS                    0x40000024
#define EALREADY                       0x40000025
#define ENOTSOCK                       0x40000026
#define EMSGSIZE                       0x40000028
#define EPROTOTYPE                     0x40000029
#define ENOPROTOOPT                    0x4000002a
#define EPROTONOSUPPORT                0x4000002b
#define ESOCKTNOSUPPORT                0x4000002c
#define EOPNOTSUPP                     0x4000002d
#define EPFNOSUPPORT                   0x4000002e
#define EAFNOSUPPORT                   0x4000002f
#define EADDRINUSE                     0x40000030
#define EADDRNOTAVAIL                  0x40000031
#define ENETDOWN                       0x40000032
#define ENETUNREACH                    0x40000033
#define ENETRESET                      0x40000034
#define ECONNABORTED                   0x40000035
#define ECONNRESET                     0x40000036
#define ENOBUFS                        0x40000037
#define EISCONN                        0x40000038
#define ENOTCONN                       0x40000039
#define EDESTADDRREQ                   0x40000027
#define ESHUTDOWN                      0x4000003a
#define ETOOMANYREFS                   0x4000003b
#define ETIMEDOUT                      0x4000003c
#define ECONNREFUSED                   0x4000003d
#define ELOOP                          0x4000003e
#define ENAMETOOLONG                   0x4000003f
#define EHOSTDOWN                      0x40000040
#define EHOSTUNREACH                   0x40000041
#define ENOTEMPTY                      0x40000042
#define EPROCLIM                       0x40000043
#define EUSERS                         0x40000044
#define EDQUOT                         0x40000045
#define ESTALE                         0x40000046
#define EREMOTE                        0x40000047
#define EBADRPC                        0x40000048
#define ERPCMISMATCH                   0x40000049
#define EPROGUNAVAIL                   0x4000004a
#define EPROGMISMATCH                  0x4000004b
#define EPROCUNAVAIL                   0x4000004c
#define ENOLCK                         0x4000004d
#define EFTYPE                         0x4000004f
#define EAUTH                          0x40000050
#define ENEEDAUTH                      0x40000051
#define ENOSYS                         0x4000004e
#define ELIBEXEC                       0x40000053
#define ENOTSUP                        0x40000076
#define EILSEQ                         0x4000006a
#define EBACKGROUND                    0x40000064
#define EDIED                          0x40000065
#if 0
#define ED                             0x40000066
#endif
#define EGREGIOUS                      0x40000067
#define EIEIO                          0x40000068
#define EGRATUITOUS                    0x40000069
#define EBADMSG                        0x4000006b
#define EIDRM                          0x4000006c
#define EMULTIHOP                      0x4000006d
#define ENODATA                        0x4000006e
#define ENOLINK                        0x4000006f
#define ENOMSG                         0x40000070
#define ENOSR                          0x40000071
#define ENOSTR                         0x40000072
#define EOVERFLOW                      0x40000073
#define EPROTO                         0x40000074
#define ETIME                          0x40000075
#define ECANCELED                      0x40000077
#define EOWNERDEAD                     0x40000078
#define ENOTRECOVERABLE                0x40000079

/* Errors from <mach/message.h>.  */
#define EMACH_SEND_IN_PROGRESS         0x10000001
#define EMACH_SEND_INVALID_DATA        0x10000002
#define EMACH_SEND_INVALID_DEST        0x10000003
#define EMACH_SEND_TIMED_OUT           0x10000004
#define EMACH_SEND_WILL_NOTIFY         0x10000005
#define EMACH_SEND_NOTIFY_IN_PROGRESS  0x10000006
#define EMACH_SEND_INTERRUPTED         0x10000007
#define EMACH_SEND_MSG_TOO_SMALL       0x10000008
#define EMACH_SEND_INVALID_REPLY       0x10000009
#define EMACH_SEND_INVALID_RIGHT       0x1000000a
#define EMACH_SEND_INVALID_NOTIFY      0x1000000b
#define EMACH_SEND_INVALID_MEMORY      0x1000000c
#define EMACH_SEND_NO_BUFFER           0x1000000d
#define EMACH_SEND_NO_NOTIFY           0x1000000e
#define EMACH_SEND_INVALID_TYPE        0x1000000f
#define EMACH_SEND_INVALID_HEADER      0x10000010
#define EMACH_RCV_IN_PROGRESS          0x10004001
#define EMACH_RCV_INVALID_NAME         0x10004002
#define EMACH_RCV_TIMED_OUT            0x10004003
#define EMACH_RCV_TOO_LARGE            0x10004004
#define EMACH_RCV_INTERRUPTED          0x10004005
#define EMACH_RCV_PORT_CHANGED         0x10004006
#define EMACH_RCV_INVALID_NOTIFY       0x10004007
#define EMACH_RCV_INVALID_DATA         0x10004008
#define EMACH_RCV_PORT_DIED            0x10004009
#define EMACH_RCV_IN_SET               0x1000400a
#define EMACH_RCV_HEADER_ERROR         0x1000400b
#define EMACH_RCV_BODY_ERROR           0x1000400c

/* Errors from <mach/kern_return.h>.  */
#define EKERN_INVALID_ADDRESS          1
#define EKERN_PROTECTION_FAILURE       2
#define EKERN_NO_SPACE                 3
#define EKERN_INVALID_ARGUMENT         4
#define EKERN_FAILURE                  5
#define EKERN_RESOURCE_SHORTAGE        6
#define EKERN_NOT_RECEIVER             7
#define EKERN_NO_ACCESS                8
#define EKERN_MEMORY_FAILURE           9
#define EKERN_MEMORY_ERROR             10
#define EKERN_NOT_IN_SET               12
#define EKERN_NAME_EXISTS              13
#define EKERN_ABORTED                  14
#define EKERN_INVALID_NAME             15
#define EKERN_INVALID_TASK             16
#define EKERN_INVALID_RIGHT            17
#define EKERN_INVALID_VALUE            18
#define EKERN_UREFS_OVERFLOW           19
#define EKERN_INVALID_CAPABILITY       20
#define EKERN_RIGHT_EXISTS             21
#define EKERN_INVALID_HOST             22
#define EKERN_MEMORY_PRESENT           23
#define EKERN_WRITE_PROTECTION_FAILURE 24
#define EKERN_TERMINATED               26
#define EKERN_TIMEDOUT                 27
#define EKERN_INTERRUPTED              28

/* Errors from <mach/mig_errors.h>.  */
#define EMIG_TYPE_ERROR                -300
#define EMIG_REPLY_MISMATCH            -301
#define EMIG_REMOTE_ERROR              -302
#define EMIG_BAD_ID                    -303
#define EMIG_BAD_ARGUMENTS             -304
#define EMIG_NO_REPLY                  -305
#define EMIG_EXCEPTION                 -306
#define EMIG_ARRAY_TOO_LARGE           -307
#define EMIG_SERVER_DIED               -308
#define EMIG_DESTROY_REQUEST           -309

/* Errors from <device/device_types.h>.  */
#define ED_IO_ERROR                    2500
#define ED_WOULD_BLOCK                 2501
#define ED_NO_SUCH_DEVICE              2502
#define ED_ALREADY_OPEN                2503
#define ED_DEVICE_DOWN                 2504
#define ED_INVALID_OPERATION           2505
#define ED_INVALID_RECNUM              2506
#define ED_INVALID_SIZE                2507
#define ED_NO_MEMORY                   2508
#define ED_READ_ONLY                   2509

#define _HURD_ERRNOS 122

#endif /* bits/errno.h.  */
