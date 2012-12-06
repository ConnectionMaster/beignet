#include "string"
namespace gbe {
std::string ocl_stdlib_str = 
"/* \n"
"uint* Copyright © 2012 Intel Corporation\n"
" *\n"
" * This library is free software; you can redistribute it and/or\n"
" * modify it under the terms of the GNU Lesser General Public\n"
" * License as published by the Free Software Foundation; either\n"
" * version 2 of the License, or (at your option) any later version.\n"
" *\n"
" * This library is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n"
" * Lesser General Public License for more details.\n"
" *\n"
" * You should have received a copy of the GNU Lesser General Public\n"
" * License along with this library. If not, see <http://www.gnu.org/licenses/>.\n"
" *\n"
" * Author: Benjamin Segovia <benjamin.segovia@intel.com>\n"
" */\n"
"\n"
"#ifndef __GEN_OCL_STDLIB_H__\n"
"#define __GEN_OCL_STDLIB_H__\n"
"\n"
"#define INLINE __attribute__((always_inline)) inline\n"
"#define OVERLOADABLE __attribute__((overloadable))\n"
"#define PURE __attribute__((pure))\n"
"#define CONST __attribute__((const))\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// OpenCL built-in scalar data types\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"typedef unsigned char uchar;\n"
"typedef unsigned short ushort;\n"
"typedef unsigned int uint;\n"
"typedef unsigned long ulong;\n"
"typedef unsigned int size_t;\n"
"typedef signed int ptrdiff_t;\n"
"typedef signed int intptr_t;\n"
"typedef unsigned int uintptr_t;\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// OpenCL built-in vector data types\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"#define DEF(type) typedef type type##2 __attribute__((ext_vector_type(2)));\\\n"
"                  typedef type type##3 __attribute__((ext_vector_type(3)));\\\n"
"                  typedef type type##4 __attribute__((ext_vector_type(4)));\\\n"
"                  typedef type type##8 __attribute__((ext_vector_type(8)));\\\n"
"                  typedef type type##16 __attribute__((ext_vector_type(16)));\n"
"DEF(char);\n"
"DEF(uchar);\n"
"DEF(short);\n"
"DEF(ushort);\n"
"DEF(int);\n"
"DEF(uint);\n"
"DEF(long);\n"
"DEF(ulong);\n"
"DEF(float);\n"
"#undef DEF\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// OpenCL preprocessor directives & macros\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"#define __OPENCL_VERSION__ 110\n"
"#define __CL_VERSION_1_0__ 100\n"
"#define __CL_VERSION_1_1__ 110\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// OpenCL floating-point macros and pragmas\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"#define FLT_DIG 6\n"
"#define FLT_MANT_DIG 24\n"
"#define FLT_MAX_10_EXP +38\n"
"#define FLT_MAX_EXP +128\n"
"#define FLT_MIN_10_EXP -37\n"
"#define FLT_MIN_EXP -125\n"
"#define FLT_RADIX 2\n"
"#define FLT_MAX 0x1.fffffep127f\n"
"#define FLT_MIN 0x1.0p-126f\n"
"#define FLT_EPSILON 0x1.0p-23f\n"
"\n"
"#define MAXFLOAT     3.40282347e38F\n"
"#define HUGE_VALF    (__builtin_huge_valf())\n"
"#define INFINITY     (__builtin_inff())\n"
"#define NAN          (__builtin_nanf(\"\"))\n"
"#define M_E_F        2.718281828459045F\n"
"#define M_LOG2E_F    1.4426950408889634F\n"
"#define M_LOG10E_F   0.43429448190325176F\n"
"#define M_LN2_F      0.6931471805599453F\n"
"#define M_LN10_F     2.302585092994046F\n"
"#define M_PI_F       3.141592653589793F\n"
"#define M_PI_2_F     1.5707963267948966F\n"
"#define M_PI_4_F     0.7853981633974483F\n"
"#define M_1_PI_F     0.3183098861837907F\n"
"#define M_2_PI_F     0.6366197723675814F\n"
"#define M_2_SQRTPI_F 1.1283791670955126F\n"
"#define M_SQRT2_F    1.4142135623730951F\n"
"#define M_SQRT1_2_F  0.7071067811865476F\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// OpenCL address space\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"#define __private __attribute__((address_space(0)))\n"
"#define __global __attribute__((address_space(1)))\n"
"#define __constant __attribute__((address_space(2)))\n"
"#define __local __attribute__((address_space(4)))\n"
"#define global __global\n"
"//#define local __local\n"
"#define constant __constant\n"
"#define private __private\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Work Items functions (see 6.11.1 of OCL 1.1 spec)\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// TODO get_global_offset\n"
"// TODO get_work_dim\n"
"\n"
"#define DECL_INTERNAL_WORK_ITEM_FN(NAME) \\\n"
"PURE CONST unsigned int __gen_ocl_##NAME##0(void); \\\n"
"PURE CONST unsigned int __gen_ocl_##NAME##1(void); \\\n"
"PURE CONST unsigned int __gen_ocl_##NAME##2(void);\n"
"DECL_INTERNAL_WORK_ITEM_FN(get_group_id)\n"
"DECL_INTERNAL_WORK_ITEM_FN(get_local_id)\n"
"DECL_INTERNAL_WORK_ITEM_FN(get_local_size)\n"
"DECL_INTERNAL_WORK_ITEM_FN(get_global_size)\n"
"DECL_INTERNAL_WORK_ITEM_FN(get_num_groups)\n"
"#undef DECL_INTERNAL_WORK_ITEM_FN\n"
"\n"
"#define DECL_PUBLIC_WORK_ITEM_FN(NAME) \\\n"
"inline unsigned NAME(unsigned int dim) { \\\n"
"  if (dim == 0) return __gen_ocl_##NAME##0(); \\\n"
"  else if (dim == 1) return __gen_ocl_##NAME##1(); \\\n"
"  else if (dim == 2) return __gen_ocl_##NAME##2(); \\\n"
"  else return 0; \\\n"
"}\n"
"DECL_PUBLIC_WORK_ITEM_FN(get_group_id)\n"
"DECL_PUBLIC_WORK_ITEM_FN(get_local_id)\n"
"DECL_PUBLIC_WORK_ITEM_FN(get_local_size)\n"
"DECL_PUBLIC_WORK_ITEM_FN(get_global_size)\n"
"DECL_PUBLIC_WORK_ITEM_FN(get_num_groups)\n"
"#undef DECL_PUBLIC_WORK_ITEM_FN\n"
"\n"
"INLINE uint get_global_id(uint dim) {\n"
"  return get_local_id(dim) + get_local_size(dim) * get_group_id(dim);\n"
"}\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Math Functions (see 6.11.2 of OCL 1.1 spec)\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"PURE CONST float __gen_ocl_fabs(float x);\n"
"PURE CONST float __gen_ocl_sin(float x);\n"
"PURE CONST float __gen_ocl_cos(float x);\n"
"PURE CONST float __gen_ocl_sqrt(float x);\n"
"PURE CONST float __gen_ocl_rsqrt(float x);\n"
"PURE CONST float __gen_ocl_log(float x);\n"
"PURE CONST float __gen_ocl_pow(float x, float y);\n"
"PURE CONST float __gen_ocl_rcp(float x);\n"
"PURE CONST float __gen_ocl_rndz(float x);\n"
"PURE CONST float __gen_ocl_rnde(float x);\n"
"PURE CONST float __gen_ocl_rndu(float x);\n"
"PURE CONST float __gen_ocl_rndd(float x);\n"
"INLINE OVERLOADABLE float native_cos(float x) { return __gen_ocl_cos(x); }\n"
"INLINE OVERLOADABLE float native_sin(float x) { return __gen_ocl_sin(x); }\n"
"INLINE OVERLOADABLE float native_sqrt(float x) { return __gen_ocl_sqrt(x); }\n"
"INLINE OVERLOADABLE float native_rsqrt(float x) { return __gen_ocl_rsqrt(x); }\n"
"INLINE OVERLOADABLE float native_log2(float x) { return __gen_ocl_log(x); }\n"
"INLINE OVERLOADABLE float native_log(float x) {\n"
"  return native_log2(x) * 0.6931472002f;\n"
"}\n"
"INLINE OVERLOADABLE float native_log10(float x) {\n"
"  return native_log2(x) * 0.3010299956f;\n"
"}\n"
"INLINE OVERLOADABLE float native_powr(float x, float y) { return __gen_ocl_pow(x,y); }\n"
"INLINE OVERLOADABLE float native_recip(float x) { return __gen_ocl_rcp(x); }\n"
"INLINE OVERLOADABLE float native_tan(float x) {\n"
"  return native_sin(x) / native_cos(x);\n"
"}\n"
"#define E 2.71828182845904523536f\n"
"INLINE OVERLOADABLE float native_exp(float x) { return native_powr(E, x); }\n"
"#undef E\n"
"\n"
"// XXX work-around PTX profile\n"
"#define sqrt native_sqrt\n"
"INLINE OVERLOADABLE float rsqrt(float x) { return native_rsqrt(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_fabs(float x)  { return __gen_ocl_fabs(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_trunc(float x) { return __gen_ocl_rndz(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_round(float x) { return __gen_ocl_rnde(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_floor(float x) { return __gen_ocl_rndd(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_ceil(float x)  { return __gen_ocl_rndu(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_log(float x)   { return native_log(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_log2(float x)  { return native_log2(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_log10(float x) { return native_log10(x); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_exp(float x)   { return native_exp(x); }\n"
"INLINE OVERLOADABLE float powr(float x, float y) { return __gen_ocl_pow(x,y); }\n"
"INLINE OVERLOADABLE float fmod(float x, float y) { return x-y*__gen_ocl_rndz(x/y); }\n"
"\n"
"// TODO use llvm intrinsics definitions\n"
"#define cos native_cos\n"
"#define sin native_sin\n"
"#define pow powr\n"
"\n"
"INLINE OVERLOADABLE float mad(float a, float b, float c) {\n"
"  return a*b+c;\n"
"}\n"
"\n"
"INLINE OVERLOADABLE uint select(uint src0, uint src1, uint cond) {\n"
"  return cond ? src1 : src0;\n"
"}\n"
"INLINE OVERLOADABLE int select(int src0, int src1, int cond) {\n"
"  return cond ? src1 : src0;\n"
"}\n"
"INLINE OVERLOADABLE float select(float src0, float src1, int cond) {\n"
"  return cond ? src1 : src0;\n"
"}\n"
"\n"
"// This will be optimized out by LLVM and will output LLVM select instructions\n"
"#define DECL_SELECT4(TYPE4, TYPE, COND_TYPE4, MASK) \\\n"
"INLINE OVERLOADABLE TYPE4 select(TYPE4 src0, TYPE4 src1, COND_TYPE4 cond) { \\\n"
"  TYPE4 dst; \\\n"
"  const TYPE x0 = src0.x; /* Fix performance issue with CLANG */ \\\n"
"  const TYPE x1 = src1.x; \\\n"
"  const TYPE y0 = src0.y; \\\n"
"  const TYPE y1 = src1.y; \\\n"
"  const TYPE z0 = src0.z; \\\n"
"  const TYPE z1 = src1.z; \\\n"
"  const TYPE w0 = src0.w; \\\n"
"  const TYPE w1 = src1.w; \\\n"
"  dst.x = (cond.x & MASK) ? x1 : x0; \\\n"
"  dst.y = (cond.y & MASK) ? y1 : y0; \\\n"
"  dst.z = (cond.z & MASK) ? z1 : z0; \\\n"
"  dst.w = (cond.w & MASK) ? w1 : w0; \\\n"
"  return dst; \\\n"
"}\n"
"DECL_SELECT4(int4, int, int4, 0x80000000)\n"
"DECL_SELECT4(float4, float, int4, 0x80000000)\n"
"#undef DECL_SELECT4\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Common Functions (see 6.11.4 of OCL 1.1 spec)\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"#define DECL_MIN_MAX(TYPE) \\\n"
"INLINE OVERLOADABLE TYPE max(TYPE a, TYPE b) { \\\n"
"  return a > b ? a : b; \\\n"
"} \\\n"
"INLINE OVERLOADABLE TYPE min(TYPE a, TYPE b) { \\\n"
"  return a < b ? a : b; \\\n"
"}\n"
"DECL_MIN_MAX(float)\n"
"DECL_MIN_MAX(int)\n"
"DECL_MIN_MAX(short)\n"
"DECL_MIN_MAX(char)\n"
"DECL_MIN_MAX(uint)\n"
"DECL_MIN_MAX(unsigned short)\n"
"DECL_MIN_MAX(unsigned char)\n"
"#undef DECL_MIN_MAX\n"
"\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_fmax(float a, float b) { return max(a,b); }\n"
"INLINE OVERLOADABLE float __gen_ocl_internal_fmin(float a, float b) { return min(a,b); }\n"
"INLINE OVERLOADABLE float mix(float x, float y, float a) { return x + (y-x)*a;}\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Geometric functions (see 6.11.5 of OCL 1.1 spec)\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"INLINE OVERLOADABLE float dot(float2 p0, float2 p1) {\n"
"  return mad(p0.x,p1.x,p0.y*p1.y);\n"
"}\n"
"INLINE OVERLOADABLE float dot(float3 p0, float3 p1) {\n"
"  return mad(p0.x,p1.x,mad(p0.z,p1.z,p0.y*p1.y));\n"
"}\n"
"INLINE OVERLOADABLE float dot(float4 p0, float4 p1) {\n"
"  return mad(p0.x,p1.x,mad(p0.w,p1.w,mad(p0.z,p1.z,p0.y*p1.y)));\n"
"}\n"
"\n"
"INLINE OVERLOADABLE float dot(float8 p0, float8 p1) {\n"
"  return mad(p0.x,p1.x,mad(p0.s7,p1.s7, mad(p0.s6,p1.s6,mad(p0.s5,p1.s5,\n"
"         mad(p0.s4,p1.s4,mad(p0.w,p1.w, mad(p0.z,p1.z,p0.y*p1.y)))))));\n"
"}\n"
"INLINE OVERLOADABLE float dot(float16 p0, float16 p1) {\n"
"  return mad(p0.sc,p1.sc,mad(p0.sd,p1.sd,mad(p0.se,p1.se,mad(p0.sf,p1.sf,\n"
"         mad(p0.s8,p1.s8,mad(p0.s9,p1.s9,mad(p0.sa,p1.sa,mad(p0.sb,p1.sb,\n"
"         mad(p0.x,p1.x,mad(p0.s7,p1.s7, mad(p0.s6,p1.s6,mad(p0.s5,p1.s5,\n"
"         mad(p0.s4,p1.s4,mad(p0.w,p1.w, mad(p0.z,p1.z,p0.y*p1.y)))))))))))))));\n"
"}\n"
"\n"
"INLINE OVERLOADABLE float length(float x) { return __gen_ocl_fabs(x); }\n"
"INLINE OVERLOADABLE float length(float2 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float length(float3 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float length(float4 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float length(float8 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float length(float16 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float distance(float x, float y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float distance(float2 x, float2 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float distance(float3 x, float3 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float distance(float4 x, float4 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float distance(float8 x, float8 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float distance(float16 x, float16 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float normalize(float x) { return 1.f; }\n"
"INLINE OVERLOADABLE float2 normalize(float2 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float3 normalize(float3 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float4 normalize(float4 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float8 normalize(float8 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float16 normalize(float16 x) { return x * rsqrt(dot(x, x)); }\n"
"\n"
"INLINE OVERLOADABLE float fast_length(float x) { return __gen_ocl_fabs(x); }\n"
"INLINE OVERLOADABLE float fast_length(float2 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float fast_length(float3 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float fast_length(float4 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float fast_length(float8 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float fast_length(float16 x) { return sqrt(dot(x,x)); }\n"
"INLINE OVERLOADABLE float fast_distance(float x, float y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float fast_distance(float2 x, float2 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float fast_distance(float3 x, float3 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float fast_distance(float4 x, float4 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float fast_distance(float8 x, float8 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float fast_distance(float16 x, float16 y) { return length(x-y); }\n"
"INLINE OVERLOADABLE float fast_normalize(float x) { return 1.f; }\n"
"INLINE OVERLOADABLE float2 fast_normalize(float2 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float3 fast_normalize(float3 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float4 fast_normalize(float4 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float8 fast_normalize(float8 x) { return x * rsqrt(dot(x, x)); }\n"
"INLINE OVERLOADABLE float16 fast_normalize(float16 x) { return x * rsqrt(dot(x, x)); }\n"
"\n"
"INLINE OVERLOADABLE float3 cross(float3 v0, float3 v1) {\n"
"   return v0.yzx*v1.zxy-v0.zxy*v1.yzx;\n"
"}\n"
"INLINE OVERLOADABLE float4 cross(float4 v0, float4 v1) {\n"
"   return (float4)(v0.yzx*v1.zxy-v0.zxy*v1.yzx, 0.f);\n"
"}\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Vector loads and stores\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"\n"
"// These loads and stores will use untyped reads and writes, so we can just\n"
"// cast to vector loads / stores. Not C99 compliant BTW due to aliasing issue.\n"
"// Well we do not care, we do not activate TBAA in the compiler\n"
"#define DECL_UNTYPED_RW_SPACE_N(TYPE, DIM, SPACE) \\\n"
"INLINE OVERLOADABLE TYPE##DIM vload##DIM(size_t offset, const SPACE TYPE *p) { \\\n"
"  return *(SPACE TYPE##DIM *) (p + DIM * offset); \\\n"
"} \\\n"
"INLINE OVERLOADABLE void vstore##DIM(TYPE##DIM v, size_t offset, SPACE TYPE *p) { \\\n"
"  *(SPACE TYPE##DIM *) (p + DIM * offset) = v; \\\n"
"}\n"
"\n"
"#define DECL_UNTYPED_RW_ALL_SPACE(TYPE, SPACE) \\\n"
"  DECL_UNTYPED_RW_SPACE_N(TYPE, 2, SPACE) \\\n"
"  DECL_UNTYPED_RW_SPACE_N(TYPE, 3, SPACE) \\\n"
"  DECL_UNTYPED_RW_SPACE_N(TYPE, 4, SPACE) \\\n"
"  DECL_UNTYPED_RW_SPACE_N(TYPE, 8, SPACE) \\\n"
"  DECL_UNTYPED_RW_SPACE_N(TYPE, 16, SPACE)\n"
"\n"
"#define DECL_UNTYPED_RW_ALL(TYPE) \\\n"
"  DECL_UNTYPED_RW_ALL_SPACE(TYPE, __global) \\\n"
"  DECL_UNTYPED_RW_ALL_SPACE(TYPE, __local) \\\n"
"  DECL_UNTYPED_RW_ALL_SPACE(TYPE, __constant) \\\n"
"  DECL_UNTYPED_RW_ALL_SPACE(TYPE, __private)\n"
"\n"
"DECL_UNTYPED_RW_ALL(float)\n"
"DECL_UNTYPED_RW_ALL(uint)\n"
"DECL_UNTYPED_RW_ALL(int)\n"
"\n"
"#undef DECL_UNTYPED_RW_ALL\n"
"#undef DECL_UNTYPED_RW_ALL_SPACE\n"
"#undef DECL_UNTYPED_RW_SPACE_N\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Declare functions for vector types which are derived from scalar ones\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"#define DECL_VECTOR_1OP(NAME, TYPE) \\\n"
"  INLINE OVERLOADABLE TYPE##2 NAME(TYPE##2 v) { \\\n"
"    return (TYPE##2)(NAME(v.x), NAME(v.y)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##3 NAME(TYPE##3 v) { \\\n"
"    return (TYPE##3)(NAME(v.x), NAME(v.y), NAME(v.z)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##4 NAME(TYPE##4 v) { \\\n"
"    return (TYPE##4)(NAME(v.x), NAME(v.y), NAME(v.z), NAME(v.w)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##8 NAME(TYPE##8 v) { \\\n"
"    TYPE##8 dst;\\\n"
"    dst.s0123 = NAME(v.s0123);\\\n"
"    dst.s4567 = NAME(v.s4567);\\\n"
"    return dst;\\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##16 NAME(TYPE##16 v) { \\\n"
"    TYPE##16 dst;\\\n"
"    dst.s01234567 = NAME(v.s01234567);\\\n"
"    dst.s89abcdef = NAME(v.s89abcdef);\\\n"
"    return dst;\\\n"
"  }\n"
"DECL_VECTOR_1OP(native_cos, float);\n"
"DECL_VECTOR_1OP(native_sin, float);\n"
"DECL_VECTOR_1OP(native_tan, float);\n"
"DECL_VECTOR_1OP(native_sqrt, float);\n"
"DECL_VECTOR_1OP(native_rsqrt, float);\n"
"DECL_VECTOR_1OP(native_log2, float);\n"
"DECL_VECTOR_1OP(native_recip, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_fabs, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_trunc, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_round, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_floor, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_ceil, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_log, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_log2, float);\n"
"DECL_VECTOR_1OP(__gen_ocl_internal_log10, float);\n"
"#undef DECL_VECTOR_1OP\n"
"\n"
"#define DECL_VECTOR_2OP(NAME, TYPE) \\\n"
"  INLINE OVERLOADABLE TYPE##2 NAME(TYPE##2 v0, TYPE##2 v1) { \\\n"
"    return (TYPE##2)(NAME(v0.x, v1.x), NAME(v1.y, v1.y)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##3 NAME(TYPE##3 v0, TYPE##3 v1) { \\\n"
"    return (TYPE##3)(NAME(v0.x, v1.x), NAME(v0.y, v1.y), NAME(v0.z, v1.z)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##4 NAME(TYPE##4 v0, TYPE##4 v1) { \\\n"
"    return (TYPE##4)(NAME(v0.x, v1.x), NAME(v0.y, v1.y), NAME(v0.z, v1.z), NAME(v0.w, v1.w)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##8 NAME(TYPE##8 v0, TYPE##8 v1) { \\\n"
"    TYPE##8 dst;\\\n"
"    dst.s0123 = NAME(v0.s0123, v1.s0123);\\\n"
"    dst.s4567 = NAME(v0.s4567, v1.s4567);\\\n"
"    return dst;\\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##16 NAME(TYPE##16 v0, TYPE##16 v1) { \\\n"
"    TYPE##16 dst;\\\n"
"    dst.s01234567 = NAME(v0.s01234567, v1.s01234567);\\\n"
"    dst.s89abcdef = NAME(v0.s89abcdef, v1.s89abcdef);\\\n"
"    return dst;\\\n"
"  }\n"
"DECL_VECTOR_2OP(min, float);\n"
"DECL_VECTOR_2OP(max, float);\n"
"DECL_VECTOR_2OP(fmod, float);\n"
"DECL_VECTOR_2OP(powr, float);\n"
"#undef DECL_VECTOR_2OP\n"
"\n"
"#define DECL_VECTOR_3OP(NAME, TYPE) \\\n"
"  INLINE OVERLOADABLE TYPE##2 NAME(TYPE##2 v0, TYPE##2 v1, TYPE##2 v2) { \\\n"
"    return (TYPE##2)(NAME(v0.x, v1.x, v2.x), NAME(v1.y, v1.y, v2.y)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##3 NAME(TYPE##3 v0, TYPE##3 v1, TYPE##3 v2) { \\\n"
"    return (TYPE##3)(NAME(v0.x, v1.x, v2.x), NAME(v0.y, v1.y, v2.y), NAME(v0.z, v1.z, v2.z)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##4 NAME(TYPE##4 v0, TYPE##4 v1, TYPE##4 v2) { \\\n"
"    return (TYPE##4)(NAME(v0.x, v1.x, v2.x), NAME(v0.y, v1.y, v2.y), NAME(v0.z, v1.z, v2.z), NAME(v0.w, v1.w, v2.w)); \\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##8 NAME(TYPE##8 v0, TYPE##8 v1, TYPE##8 v2) { \\\n"
"    TYPE##8 dst;\\\n"
"    dst.s0123 = NAME(v0.s0123, v1.s0123, v2.s0123);\\\n"
"    dst.s4567 = NAME(v0.s4567, v1.s4567, v2.s4567);\\\n"
"    return dst;\\\n"
"  }\\\n"
"  INLINE OVERLOADABLE TYPE##16 NAME(TYPE##16 v0, TYPE##16 v1, TYPE##16 v2) { \\\n"
"    TYPE##16 dst;\\\n"
"    dst.s01234567 = NAME(v0.s01234567, v1.s01234567, v2.s01234567);\\\n"
"    dst.s89abcdef = NAME(v0.s89abcdef, v1.s89abcdef, v2.s89abcdef);\\\n"
"    return dst;\\\n"
"  }\n"
"DECL_VECTOR_3OP(mad, float);\n"
"DECL_VECTOR_3OP(mix, float);\n"
"#undef DECL_VECTOR_3OP\n"
"\n"
"// mix requires more variants\n"
"INLINE OVERLOADABLE float2 mix(float2 x, float2 y, float a) { return mix(x,y,(float2)(a));}\n"
"INLINE OVERLOADABLE float3 mix(float3 x, float3 y, float a) { return mix(x,y,(float3)(a));}\n"
"INLINE OVERLOADABLE float4 mix(float4 x, float4 y, float a) { return mix(x,y,(float4)(a));}\n"
"INLINE OVERLOADABLE float8 mix(float8 x, float8 y, float a) { return mix(x,y,(float8)(a));}\n"
"INLINE OVERLOADABLE float16 mix(float16 x, float16 y, float a) { return mix(x,y,(float16)(a));}\n"
"\n"
"// XXX workaround ptx profile\n"
"#define fabs __gen_ocl_internal_fabs\n"
"#define trunc __gen_ocl_internal_trunc\n"
"#define round __gen_ocl_internal_round\n"
"#define floor __gen_ocl_internal_floor\n"
"#define ceil __gen_ocl_internal_ceil,\n"
"#define log __gen_ocl_internal_log\n"
"#define log2 __gen_ocl_internal_log2\n"
"#define log10 __gen_ocl_internal_log10\n"
"#define exp __gen_ocl_internal_exp\n"
"#define fmin __gen_ocl_internal_fmin\n"
"#define fmax __gen_ocl_internal_fmax\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Synchronization functions\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"#define CLK_LOCAL_MEM_FENCE  (1 << 0)\n"
"#define CLK_GLOBAL_MEM_FENCE (1 << 1)\n"
"\n"
"void __gen_ocl_barrier_local(void);\n"
"void __gen_ocl_barrier_global(void);\n"
"void __gen_ocl_barrier_local_and_global(void);\n"
"\n"
"typedef uint cl_mem_fence_flags;\n"
"INLINE void barrier(cl_mem_fence_flags flags) {\n"
"  if (flags == (CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE))\n"
"    __gen_ocl_barrier_local_and_global();\n"
"  else if (flags == CLK_LOCAL_MEM_FENCE)\n"
"    __gen_ocl_barrier_local();\n"
"  else if (flags == CLK_GLOBAL_MEM_FENCE)\n"
"    __gen_ocl_barrier_global();\n"
"}\n"
"\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"// Force the compilation to SIMD8 or SIMD16\n"
"/////////////////////////////////////////////////////////////////////////////\n"
"\n"
"int __gen_ocl_force_simd8(void);\n"
"int __gen_ocl_force_simd16(void);\n"
"\n"
"#define NULL ((void*)0)\n"
"#undef PURE\n"
"#undef CONST\n"
"#undef OVERLOADABLE\n"
"#undef INLINE\n"
"#endif /* __GEN_OCL_STDLIB_H__ */\n"
"\n"
;
}

