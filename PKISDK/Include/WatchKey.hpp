#if !defined(_WATCHKEY_HPP_INCLUDED)
#define _WATCHKEY_HPP_INCLUDED

/**
  * @Name: WatchKey.hpp
  * @Copyright: KTXA SoftWare
  * @Author: Hongwei Yu
  * @Date:  2003/04/25 14:03
  * @Description: WatchKey module interface file 
*/

#undef STATIC_LIB

//if this project is a not static lib, comment out the next line.
#define STATIC_LIB
#ifdef KT_WIN32
	#if _MSC_VER >= 1000
	#pragma once
	#endif // _MSC_VER >= 1000

	#if !defined(_MT)
		#error Please use the /MD or /MT switch (multithreaded (DLL) C-runtime)
	#endif
	#if defined (_DEBUG)
		#pragma comment(lib,"WatchKeyd.lib")
		#pragma message("Automatically linking with WatchKeyd.lib")
	#else
		#pragma comment(lib,"WatchKey.lib")
		#pragma message("Automatically linking with WatchKey.lib")	 	
	#endif
#endif

#undef	KT_LIB_MODE
#define KT_LIB_MODE
#ifndef STATIC_LIB //it is a dll project
    #if defined(KT_WIN32)
        //so we must change MFC extension dll definitions to AFX_CLASS_IMPORT to make this
        //dll importable.
        #undef KT_LIB_MODE
        #define KT_LIB_MODE __declspec(dllimport)
    #endif
#endif

	#include "./Interface/ICommonKeyMangr.h"	
	#include "./Interface/ICommonICCHelper.h"
	#include "./Interface/ICommonICCHelperPK.h"
	#include "./Key/WatchKey.h"
	
#undef STATIC_LIB

#undef KT_LIB_MODE

#if defined(KL_LIB_STATIC)
    #define KT_LIB_MODE
#elif defined(KL_LIB_SHARED)
    #ifdef KT_WIN32
        #define KT_LIB_MODE __declspec(dllexport)
	#else
        //i do not know how to make a unix shared lib to export class, is this enough?
        #define KT_LIB_MODE
    #endif
#else
    #define KT_LIB_MODE
#endif

/// Rivison history
/// ----------------------------------------------------------------------------
/// 	Version	       Date        Author      Note
/// ----------------------------------------------------------------------------
///   1.0.0.0  2003/04/25 14:04  Hongwei Yu   created 
///   1.0.0.1  2003/05/12 23:08  Hongwei Yu   remove KT_LOGGER macro
///   1.0.0.2  2003/07/01 14:28  Hongwei Yu   switch /MT and /MD case

#endif // _WATCHKEY_HPP_INCLUDED
