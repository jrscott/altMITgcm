C $Header: /u/gcmpack/MITgcm/pkg/bling/bling_ad_check_lev1_dir.h,v 1.2 2016/09/12 20:00:27 mmazloff Exp $
C $Name:  $

#ifdef ALLOW_BLING

C common CARBON_NEEDS
CADJ STORE pH                = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE fice              = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE silica            = comlev1, key = ikey_dynamics, kind=isbyte

C common BLING_LOAD
CADJ STORE ice0,ice1         = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE atmosp0,atmosp1   = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE silica0,silica1   = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE feinput0,feinput1 = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE dicwind0,dicwind1 = comlev1, key = ikey_dynamics, kind=isbyte

CADJ STORE irr_mem           = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE phyto_sm          = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE phyto_lg          = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE phyto_diaz        = comlev1, key = ikey_dynamics, kind=isbyte
CADJ STORE chl               = comlev1, key = ikey_dynamics, kind=isbyte

#ifdef ALLOW_BLING_COST
CADJ STORE totcost           = comlev1, key = ikey_dynamics, kind=isbyte
#endif

#endif /* ALLOW_BLING */

