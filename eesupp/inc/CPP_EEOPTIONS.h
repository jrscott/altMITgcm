C $Header: /u/gcmpack/MITgcm/eesupp/inc/CPP_EEOPTIONS.h,v 1.30 2009/04/26 00:32:23 jmc Exp $
C $Name:  $

CBOP
C     !ROUTINE: CPP_EEOPTIONS.h
C     !INTERFACE:
C     include "CPP_EEOPTIONS.h"
C
C     !DESCRIPTION:
C     *==========================================================*
C     | CPP\_EEOPTIONS.h                                         |
C     *==========================================================*
C     | C preprocessor "execution environment" supporting        |
C     | flags. Use this file to set flags controlling the        |
C     | execution environment in which a model runs - as opposed |
C     | to the dynamical problem the model solves.               |
C     | Note: Many options are implemented with both compile time|
C     |       and run-time switches. This allows options to be   |
C     |       removed altogether, made optional at run-time or   |
C     |       to be permanently enabled. This convention helps   |
C     |       with the data-dependence analysis performed by the |
C     |       adjoint model compiler. This data dependency       |
C     |       analysis can be upset by runtime switches that it  |
C     |       is unable to recoginise as being fixed for the     |
C     |       duration of an integration.                        |
C     |       A reasonable way to use these flags is to          |
C     |       set all options as selectable at runtime but then  |
C     |       once an experimental configuration has been        |
C     |       identified, rebuild the code with the appropriate  |
C     |       options set at compile time.                       |
C     *==========================================================*
CEOP

#ifndef _CPP_EEOPTIONS_H_
#define _CPP_EEOPTIONS_H_

C     In general the following convention applies:
C     ALLOW  - indicates an feature will be included but it may
C     CAN      have a run-time flag to allow it to be switched
C              on and off.
C              If ALLOW or CAN directives are "undef'd" this generally
C              means that the feature will not be available i.e. it
C              will not be included in the compiled code and so no
C              run-time option to use the feature will be available.
C
C     ALWAYS - indicates the choice will be fixed at compile time
C              so no run-time option will be present

C--   Flag used to indicate whether Fortran formatted write
C     and read are threadsafe. On SGI the routines can be thread
C     safe, on Sun it is not possible - if you are unsure then
C     undef this option.
#undef FMTFTN_IO_THREAD_SAFE

C--   Flag used to indicate whether Binary write to Local file (i.e.,
C     a different file for each tile) and read are thread-safe.
#undef LOCBIN_IO_THREAD_SAFE

C--   Flag to turn off the writing of error message to ioUnit zero
#undef DISABLE_WRITE_TO_UNIT_ZERO

C--   Flag to turn on checking for errors from all threads and procs
C     (calling S/R IF_ERROR_STOP) before stopping.
#define USE_CHECK_FOR_ERROR

C--   Flag turns off MPI_SEND ready_to_receive polling in the
C     gather_* subroutines to speed up integrations.
#undef DISABLE_MPI_READY_TO_RECEIVE

C--   Control MPI based parallel processing
CXXX We no longer select the use of MPI via this file (CPP_EEOPTIONS.h)
CXXX To use MPI, use an appropriate genmake2 options file or use
CXXX genmake2 -mpi .
CXXX #undef  ALLOW_USE_MPI
CXXX #undef  ALWAYS_USE_MPI

C--   Control use of communication that might overlap computation.
C     Under MPI selects/deselects "non-blocking" sends and receives.
#define ALLOW_ASYNC_COMMUNICATION
#undef  ALLOW_ASYNC_COMMUNICATION
#undef  ALWAYS_USE_ASYNC_COMMUNICATION
C--   Control use of communication that is atomic to computation.
C     Under MPI selects/deselects "blocking" sends and receives.
#define ALLOW_SYNC_COMMUNICATION
#undef  ALWAYS_USE_SYNC_COMMUNICATION

C--   Control use of JAM routines for Artic network
C     These invoke optimized versions of "exchange" and "sum" that
C     utilize the programmable aspect of Artic cards.
#undef  LETS_MAKE_JAM
#undef  JAM_WITH_TWO_PROCS_PER_NODE

C--   Control storage of floating point operands
C     On many systems it improves performance only to use
C     8-byte precision for time stepped variables.
C     Constant in time terms ( geometric factors etc.. )
C     can use 4-byte precision, reducing memory utilisation and
C     boosting performance because of a smaller working
C     set size. However, on vector CRAY systems this degrades
C     performance.
#define REAL4_IS_SLOW

C--   Control use of "double" precision constants.
C     Use D0 where it means REAL*8 but not where it means REAL*16
#define D0 d0

C--   Control XY periodicity in processor to grid mappings
C     Note: Model code does not need to know whether a domain is
C           periodic because it has overlap regions for every box.
C           Model assume that these values have been
C           filled in some way.
#undef  ALWAYS_PREVENT_X_PERIODICITY
#undef  ALWAYS_PREVENT_Y_PERIODICITY
#define CAN_PREVENT_X_PERIODICITY
#define CAN_PREVENT_Y_PERIODICITY

C--   Alternative formulation of BYTESWAP, faster than
C     compiler flag -byteswapio on the Altix.
#undef FAST_BYTESWAP

C--   Alternative way of doing global sum without MPI allreduce call
C     but instead, explicit MPI send & recv calls.
#undef GLOBAL_SUM_SEND_RECV

C--   Alternative way of doing global sum on a single CPU
C     to eliminate tiling-dependent roundoff errors.
C     Note: This is slow.
#undef  CG2D_SINGLECPU_SUM

#endif /* _CPP_EEOPTIONS_H_ */

#include "CPP_EEMACROS.h"

