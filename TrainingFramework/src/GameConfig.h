#pragma once

#include "targetver.h"
#include "U_Math.h"

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef ANDROID	
#include <stdio.h>
#include <tchar.h>
#endif

// define game debug  -------------------	1: yes	0: no
#define GAME_DEBUG 1

// define value
#define PI 3.14f
#define MAX_DEGREE 360
#define WAIT_TIME 0.9f	
#define MAX_ROW  12
#define MAX_COL 26

#define PIECE_BLOCKS 5	
#define ZOOM_OBJ 1

#define COLUMN 2*PI/MAX_COL
#define RADIUS 7.0f

// define vetex 
#define VETEX_POSITION			(char*)0
#define VETEX_NORM				(char*)0+(sizeof(Vector3))
#define VETEX_BITTANGEN			(char*)0+2*(sizeof(Vector3))
#define VETEX_TANGEN			(char*)0+3*(sizeof(Vector3))
#define VETEX_UV				(char*)0+4*(sizeof(Vector3))

// define type of Models
#define NONE					111 
#define RAW						222 
#define NFG						333
#define GAME_3D_SPRITE			444
#define GAME_2D_SPRITE			555
#define HEIGHT_MAP_SCALE		10.0f
#define HEIGHT_MAP_SCALE_TEXT	25.0f
#define HEIGHT_MAP_SCALE_SIZE	2.0f

#ifdef WIN32

#define FSCANF fscanf

#elif ANDROID

#define FSCANF fscanf

#endif

// for debug game

#ifdef WIN32 

#define LOGI(...) printf(__VA_ARGS__);
#define LOGE(...) printf(__VA_ARGS__);
#define LOGV(...) printf(__VA_ARGS__);
#define LOGD(...) printf(__VA_ARGS__);
#define LOGW(...) printf(__VA_ARGS__);
#define LOGF(...) printf(__VA_ARGS__);

#elif ANDROID

#include <android/log.h>
#define  LOG_TAG    "CUONG.NV"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL, LOG_TAG, __VA_ARGS__)

#endif

/*
#ifndef GAME_DEBUG
#define LOGI(...) 
#define LOGE(...) 
#define LOGV(...) 
#define LOGD(...) 
#define LOGW(...) 
#define LOGF(...) 
#endif
*/

// KEY define 
#ifdef WIN32

#define KEY_BACK				27	// key Esc
#define KEY_LEFT				37	// key <-
#define KEY_RIGHT				39	// key ->
#define KEY_UP					38	// key |
#define KEY_DOWN				40	// key |
#define KEY_MOVE_LEFT			65	// key a
#define KEY_MOVE_RIGHT			68	// key d
#define KEY_MOVE_FORWORD		87	// key w
#define KEY_MOVE_BACKWORD		83	// key s

#elif ANDROID

#define KEY_BACK				27	// key Esc
#define KEY_LEFT				37	// key <-
#define KEY_RIGHT				39	// key ->
#define KEY_UP					38	// key |
#define KEY_DOWN				40	// key |
#define KEY_MOVE_LEFT			65	// key a
#define KEY_MOVE_RIGHT			68	// key d
#define KEY_MOVE_FORWORD		87	// key w
#define KEY_MOVE_BACKWORD		83	// key s

#endif
