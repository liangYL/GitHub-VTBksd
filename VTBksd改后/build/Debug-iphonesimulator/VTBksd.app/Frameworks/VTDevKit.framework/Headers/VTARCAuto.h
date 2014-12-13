//
//  PXISARC.h
//  paixiu
//
//  Created by Static Ga on 12-10-15.
//  Copyright (c) 2012年 PaiXiu. All rights reserved.
//

#ifndef VT_PXISARC_h
    #define VT_PXISARC_h

#ifndef VT_STRONG
    #if __has_feature(objc_arc)
        #define VT_STRONG strong
    #else
        #define VT_STRONG retain
    #endif
#endif

#ifndef VT_WEAK
    #if __has_feature(objc_arc_weak)
        #define VT_WEAK weak
    #elif __has_feature(objc_arc)
        #define VT_WEAK unsafe_unretained
    #else
        #define VT_WEAK assign
    #endif
#endif

#if __has_feature(objc_arc)
    #define VT_AUTORELEASE(exp) exp
    #define VT_RELEASE(exp) exp
    #define VT_RETAIN(exp) exp
#else
    #define VT_AUTORELEASE(exp) [exp autorelease]
    #define VT_RELEASE(exp) [exp release]
    #define VT_RETAIN(exp) [exp retain]
#endif

#endif
