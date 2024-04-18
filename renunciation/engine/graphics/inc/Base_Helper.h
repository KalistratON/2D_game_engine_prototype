#pragma once

#ifndef _GRAPHICS_EXPORT
#ifdef _WIN32
#define _GRAPHICS_EXPORT __declspec(dllexport)
#else 
#define _GRAPHICS_EXPORT 
#endif
#endif

