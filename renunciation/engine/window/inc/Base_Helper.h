#pragma once

#ifndef _WINDOW_EXPORT
#ifdef _WIN32
#define _WINDOW_EXPORT __declspec(dllexport)
#else 
#define _WINDOW_EXPORT 
#endif
#endif

