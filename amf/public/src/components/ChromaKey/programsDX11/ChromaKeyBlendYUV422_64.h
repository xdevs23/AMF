#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer Params
// {
//
//   uint width;                        // Offset:    0 Size:     4 [unused]
//   uint height;                       // Offset:    4 Size:     4 [unused]
//   uint greenReducing;                // Offset:    8 Size:     4
//   uint threshold;                    // Offset:   12 Size:     4
//   uint threshold2;                   // Offset:   16 Size:     4
//   uint keycolor;                     // Offset:   20 Size:     4 [unused]
//   uint colorTransferSrc;             // Offset:   24 Size:     4
//   uint colorTransferDst;             // Offset:   28 Size:     4
//   uint alphaFromSrc;                 // Offset:   32 Size:     4
//   uint debug;                        // Offset:   36 Size:     4 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// planeIn                           texture  unorm4          2d             t0      1 
// planeMaskSpill                    texture   unorm          2d             t1      1 
// planeMaskBlur                     texture   unorm          2d             t2      1 
// planeOut                              UAV  unorm4          2d             u0      1 
// Params                            cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[3], immediateIndexed
dcl_resource_texture2d (unorm,unorm,unorm,unorm) t0
dcl_resource_texture2d (unorm,unorm,unorm,unorm) t1
dcl_resource_texture2d (unorm,unorm,unorm,unorm) t2
dcl_uav_typed_texture2d (unorm,unorm,unorm,unorm) u0
dcl_input vThreadID.xy
dcl_temps 5
dcl_thread_group 8, 8, 1
resinfo_indexable(texture2d)(unorm,unorm,unorm,unorm) r0.xy, l(0), u0.xyzw
ftoi r0.xy, r0.xyxx
ige r0.xy, vThreadID.xyxx, r0.xyxx
or r0.x, r0.y, r0.x
if_nz r0.x
  ret 
endif 
ushr r0.x, vThreadID.x, l(1)
mov r0.y, vThreadID.y
mov r0.zw, l(0,0,0,0)
ld_indexable(texture2d)(unorm,unorm,unorm,unorm) r0.xyzw, r0.xyzw, t0.xyzw
and r1.x, vThreadID.x, l(1)
movc r1.x, r1.x, r0.w, r0.y
mov r2.xy, vThreadID.xyxx
mov r2.zw, l(0,0,0,0)
ld_indexable(texture2d)(unorm,unorm,unorm,unorm) r0.y, r2.xyww, t1.yxzw
ld_indexable(texture2d)(unorm,unorm,unorm,unorm) r2.x, r2.xyzw, t2.xyzw
movc r2.w, cb0[2].x, r0.w, r2.x
lt r0.y, l(0.023529), r0.y
lt r3.xy, r0.xzxx, l(0.500000, 0.500000, 0.000000, 0.000000)
and r0.w, r3.y, r3.x
add r3.x, -r2.w, l(1.000000)
mul r3.x, r3.x, l(0.500000)
mad r3.x, r1.x, r2.w, r3.x
mov r3.yzw, l(0,0.500000,0.500000,0.500000)
mov r1.yzw, r0.zzxz
movc r3.xyzw, r0.wwww, r3.xyzw, r1.xyzw
movc r0.xyzw, r0.yyyy, r3.xyzw, r1.xyzw
add r0.xyzw, r0.xyzw, l(-0.062745, -0.500000, -0.500000, -0.500000)
mul r1.xyz, r0.xyzx, l(1.164384, 1.792999, -0.212999, 0.000000)
add r3.xw, r1.yyyz, r1.xxxx
mad r3.y, r0.w, l(-0.532998), r3.w
mad r3.z, r0.z, l(2.111999), r1.x
mov_sat r3.xyz, r3.xyzx
ieq r0.x, cb0[0].z, l(1)
utof r0.y, cb0[0].w
utof r0.z, cb0[1].x
add r1.xyzw, -r3.zxzx, r3.yyyy
max r0.w, r1.w, r1.z
mul r0.yzw, r0.yyzw, l(0.000000, 0.003922, 0.003922, 0.500000)
lt r1.xyzw, l(0.000000, 0.000000, 0.003922, 0.003922), r1.xyzw
and r1.x, r1.y, r1.x
min r0.y, r0.y, r0.w
or r1.y, r1.w, r1.z
div r1.z, r0.w, r0.z
mul r1.w, r1.z, r1.z
mul r1.z, r1.z, r1.w
mul r1.z, r0.z, r1.z
lt r0.z, r0.z, r0.w
movc r0.z, r0.z, r0.w, r1.z
add r0.yz, -r0.yyzy, r3.yyyy
movc r0.z, r1.y, r0.z, r3.y
movc r0.y, r1.x, r0.y, r0.z
movc r3.w, r0.x, r0.y, r3.y
ieq r0.x, cb0[1].z, l(1)
if_nz r0.x
  lt r0.xyz, l(0.040450, 0.040450, 0.040450, 0.000000), r3.xwzx
  mad r1.xyz, r3.xwzx, l(0.947867, 0.947867, 0.947867, 0.000000), l(0.052133, 0.052133, 0.052133, 0.000000)
  log r1.xyz, r1.xyzx
  mul r1.xyz, r1.xyzx, l(2.400000, 2.400000, 2.400000, 0.000000)
  exp r1.xyz, r1.xyzx
  mul r4.xyz, r3.xwzx, l(0.077399, 0.077399, 0.077399, 0.000000)
  movc r2.xyz, r0.xyzx, r1.xyzx, r4.xyzx
else 
  ieq r0.x, cb0[1].z, l(2)
  if_nz r0.x
    log r0.xyz, r3.xzwx
    mul r0.xyz, r0.xyzx, l(0.012683, 0.012683, 0.012683, 0.000000)
    exp r0.xyz, r0.xyzx
    add r1.xyz, r0.xyzx, l(-0.835938, -0.835938, -0.835938, 0.000000)
    max r1.xyz, r1.xyzx, l(0.000000, 0.000000, 0.000000, 0.000000)
    mad r0.xyz, -r0.xyzx, l(18.687500, 18.687500, 18.687500, 0.000000), l(18.851563, 18.851563, 18.851563, 0.000000)
    div r0.xyz, r1.xyzx, r0.xyzx
    log r0.xyz, r0.xyzx
    mul r0.xyz, r0.xyzx, l(6.277395, 6.277395, 6.277395, 0.000000)
    exp r0.xyz, r0.xyzx
    mul r2.xyz, r0.xzyx, l(80.000000, 80.000000, 80.000000, 0.000000)
    mov r2.w, l(0)
  else 
    mov r2.xyz, r3.xwzx
  endif 
endif 
lt r0.xyz, l(0.003131, 0.003131, 0.003131, 0.000000), r2.xyzx
log r1.xyz, r2.xyzx
mul r1.xyz, r1.xyzx, l(0.416667, 0.416667, 0.416667, 0.000000)
exp r1.xyz, r1.xyzx
mad r1.xyz, r1.xyzx, l(1.055000, 1.055000, 1.055000, 0.000000), l(-0.055000, -0.055000, -0.055000, 0.000000)
mul r3.xyz, r2.xyzx, l(12.920000, 12.920000, 12.920000, 0.000000)
movc r0.xyz, r0.xyzx, r1.xyzx, r3.xyzx
mov r0.w, r2.w
movc r0.xyzw, cb0[1].wwww, r0.xyzw, r2.xyzw
store_uav_typed u0.xyzw, vThreadID.xyyy, r0.xyzw
ret 
// Approximately 93 instruction slots used
#endif

const BYTE ChromaKeyBlendYUV422_CS[] =
{
     68,  88,  66,  67, 137, 194, 
     19, 159, 113,   2,  30, 254, 
    142, 185, 196, 123, 137, 240, 
    223, 205,   1,   0,   0,   0, 
    140,  15,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    184,   3,   0,   0, 200,   3, 
      0,   0, 216,   3,   0,   0, 
    240,  14,   0,   0,  82,  68, 
     69,  70, 124,   3,   0,   0, 
      1,   0,   0,   0,  20,   1, 
      0,   0,   5,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  67,   0,   1,   0,   0, 
     84,   3,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    220,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 228,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 243,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   1,   0,   0,   4,   0, 
      0,   0,   1,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,  10,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 112, 108, 
     97, 110, 101,  73, 110,   0, 
    112, 108,  97, 110, 101,  77, 
     97, 115, 107,  83, 112, 105, 
    108, 108,   0, 112, 108,  97, 
    110, 101,  77,  97, 115, 107, 
     66, 108, 117, 114,   0, 112, 
    108,  97, 110, 101,  79, 117, 
    116,   0,  80,  97, 114,  97, 
    109, 115,   0, 171, 171, 171, 
     10,   1,   0,   0,  10,   0, 
      0,   0,  44,   1,   0,   0, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    188,   2,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 200,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 236,   2, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 200,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 243,   2,   0,   0, 
      8,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    200,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   3,   0,   0,  12,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0, 200,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  11,   3, 
      0,   0,  16,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0, 200,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  22,   3,   0,   0, 
     20,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
    200,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     31,   3,   0,   0,  24,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0, 200,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  48,   3, 
      0,   0,  28,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0, 200,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  65,   3,   0,   0, 
     32,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    200,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     78,   3,   0,   0,  36,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0, 200,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 119, 105, 
    100, 116, 104,   0, 100, 119, 
    111, 114, 100,   0,   0,   0, 
     19,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    194,   2,   0,   0, 104, 101, 
    105, 103, 104, 116,   0, 103, 
    114, 101, 101, 110,  82, 101, 
    100, 117,  99, 105, 110, 103, 
      0, 116, 104, 114, 101, 115, 
    104, 111, 108, 100,   0, 116, 
    104, 114, 101, 115, 104, 111, 
    108, 100,  50,   0, 107, 101, 
    121,  99, 111, 108, 111, 114, 
      0,  99, 111, 108, 111, 114, 
     84, 114,  97, 110, 115, 102, 
    101, 114,  83, 114,  99,   0, 
     99, 111, 108, 111, 114,  84, 
    114,  97, 110, 115, 102, 101, 
    114,  68, 115, 116,   0,  97, 
    108, 112, 104,  97,  70, 114, 
    111, 109,  83, 114,  99,   0, 
    100, 101,  98, 117, 103,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0,  73,  83, 
     71,  78,   8,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  79,  83,  71,  78, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     83,  72,  69,  88,  16,  11, 
      0,   0,  80,   0,   5,   0, 
    196,   2,   0,   0, 106,   8, 
      0,   1,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     17,  17,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      1,   0,   0,   0,  17,  17, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   2,   0, 
      0,   0,  17,  17,   0,   0, 
    156,  24,   0,   4,   0, 224, 
     17,   0,   0,   0,   0,   0, 
     17,  17,   0,   0,  95,   0, 
      0,   2,  50,   0,   2,   0, 
    104,   0,   0,   2,   5,   0, 
      0,   0, 155,   0,   0,   4, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,   0, 
     61,   0,   0, 137, 194,   0, 
      0, 128,  67,  68,   4,   0, 
     50,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  70, 238, 
     17,   0,   0,   0,   0,   0, 
     27,   0,   0,   5,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,  33,   0,   0,   6, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,   2,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,  60,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  21,   0, 
      0,   1,  85,   0,   0,   6, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,   2,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  54,   0,   0,   4, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,   2,   0, 
     54,   0,   0,   8, 194,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  45,   0,   0, 137, 
    194,   0,   0, 128,  67,  68, 
      4,   0, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   6, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,   2,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   4, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  70,   0,   2,   0, 
     54,   0,   0,   8, 194,   0, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  45,   0,   0, 137, 
    194,   0,   0, 128,  67,  68, 
      4,   0,  34,   0,  16,   0, 
      0,   0,   0,   0,  70,  15, 
     16,   0,   2,   0,   0,   0, 
     22, 126,  16,   0,   1,   0, 
      0,   0,  45,   0,   0, 137, 
    194,   0,   0, 128,  67,  68, 
      4,   0,  18,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 126,  16,   0,   2,   0, 
      0,   0,  55,   0,   0,  10, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     49,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0, 193, 192, 
    192,  60,  26,   0,  16,   0, 
      0,   0,   0,   0,  49,   0, 
      0,  10,  50,   0,  16,   0, 
      3,   0,   0,   0, 134,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,  63,   0,   0,   0,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
      0,   0,   0,   8,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  56,   0,   0,   7, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     54,   0,   0,   8, 226,   0, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  63, 
      0,   0,   0,  63,   0,   0, 
      0,  63,  54,   0,   0,   5, 
    226,   0,  16,   0,   1,   0, 
      0,   0, 166,   8,  16,   0, 
      0,   0,   0,   0,  55,   0, 
      0,   9, 242,   0,  16,   0, 
      3,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9, 242,   0,  16,   0, 
      0,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0, 129, 128, 
    128, 189,   0,   0,   0, 191, 
      0,   0,   0, 191,   0,   0, 
      0, 191,  56,   0,   0,  10, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0, 133,  10, 149,  63, 
      1, 129, 229,  63, 102,  28, 
     90, 190,   0,   0,   0,   0, 
      0,   0,   0,   7, 146,   0, 
     16,   0,   3,   0,   0,   0, 
     86,   9,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9,  34,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0, 150, 114, 
      8, 191,  58,   0,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,   9,  66,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0, 255,  42, 
      7,  64,  10,   0,  16,   0, 
      1,   0,   0,   0,  54,  32, 
      0,   5, 114,   0,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     32,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  86,   0,   0,   6, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  86,   0,   0,   6, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   8, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  38,   2,  16, 128, 
     65,   0,   0,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      3,   0,   0,   0,  52,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,  10, 
    226,   0,  16,   0,   0,   0, 
      0,   0,  86,  14,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
    129, 128, 128,  59, 129, 128, 
    128,  59,   0,   0,   0,  63, 
     49,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    129, 128, 128,  59, 129, 128, 
    128,  59,  70,  14,  16,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  51,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     60,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  14,   0, 
      0,   7,  66,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7,  66,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  49,   0,   0,   7, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     55,   0,   0,   9,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8,  98,   0, 
     16,   0,   0,   0,   0,   0, 
     86,   6,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     86,   5,  16,   0,   3,   0, 
      0,   0,  55,   0,   0,   9, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   3,   0, 
      0,   0,  55,   0,   0,   9, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  55,   0,   0,   9, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   3,   0, 
      0,   0,  32,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  31,   0, 
      4,   3,  10,   0,  16,   0, 
      0,   0,   0,   0,  49,   0, 
      0,  10, 114,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0, 230, 174,  37,  61, 
    230, 174,  37,  61, 230, 174, 
     37,  61,   0,   0,   0,   0, 
    198,   2,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  15, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 198,   2,  16,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0, 111, 167, 114,  63, 
    111, 167, 114,  63, 111, 167, 
    114,  63,   0,   0,   0,   0, 
      2,  64,   0,   0,  25, 137, 
     85,  61,  25, 137,  85,  61, 
     25, 137,  85,  61,   0,   0, 
      0,   0,  47,   0,   0,   5, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,  10, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0, 154, 153, 
     25,  64, 154, 153,  25,  64, 
    154, 153,  25,  64,   0,   0, 
      0,   0,  25,   0,   0,   5, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,  10, 114,   0,  16,   0, 
      4,   0,   0,   0, 198,   2, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0, 145, 131, 
    158,  61, 145, 131, 158,  61, 
    145, 131, 158,  61,   0,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   4,   0, 
      0,   0,  18,   0,   0,   1, 
     32,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,  31,   0,   4,   3, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  47,   0,   0,   5, 
    114,   0,  16,   0,   0,   0, 
      0,   0, 134,   3,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,  10, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0, 172, 205, 
     79,  60, 172, 205,  79,  60, 
    172, 205,  79,  60,   0,   0, 
      0,   0,  25,   0,   0,   5, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  10, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
     86, 191,   0,   0,  86, 191, 
      0,   0,  86, 191,   0,   0, 
      0,   0,  52,   0,   0,  10, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  16, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0, 128, 
    149,  65,   0, 128, 149,  65, 
      0, 128, 149,  65,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0, 208, 150,  65,   0, 208, 
    150,  65,   0, 208, 150,  65, 
      0,   0,   0,   0,  14,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  47,   0,   0,   5, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,  10, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0, 107, 224, 
    200,  64, 107, 224, 200,  64, 
    107, 224, 200,  64,   0,   0, 
      0,   0,  25,   0,   0,   5, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,  10, 114,   0,  16,   0, 
      2,   0,   0,   0, 134,   1, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    160,  66,   0,   0, 160,  66, 
      0,   0, 160,  66,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    130,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   1,  54,   0,   0,   5, 
    114,   0,  16,   0,   2,   0, 
      0,   0, 198,   2,  16,   0, 
      3,   0,   0,   0,  21,   0, 
      0,   1,  21,   0,   0,   1, 
     49,   0,   0,  10, 114,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,  28,  46, 
     77,  59,  28,  46,  77,  59, 
     28,  46,  77,  59,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  47,   0, 
      0,   5, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,  10, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
     85,  85, 213,  62,  85,  85, 
    213,  62,  85,  85, 213,  62, 
      0,   0,   0,   0,  25,   0, 
      0,   5, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  15, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
     61,  10, 135,  63,  61,  10, 
    135,  63,  61,  10, 135,  63, 
      0,   0,   0,   0,   2,  64, 
      0,   0, 174,  71,  97, 189, 
    174,  71,  97, 189, 174,  71, 
     97, 189,   0,   0,   0,   0, 
     56,   0,   0,  10, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
     82, 184,  78,  65,  82, 184, 
     78,  65,  82, 184,  78,  65, 
      0,   0,   0,   0,  55,   0, 
      0,   9, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  54,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     55,   0,   0,  10, 242,   0, 
     16,   0,   0,   0,   0,   0, 
    246, 143,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0, 164,   0, 
      0,   6, 242, 224,  17,   0, 
      0,   0,   0,   0,  70,   5, 
      2,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0,  93,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  44,   0,   0,   0, 
      4,   0,   0,   0,   6,   0, 
      0,   0,   4,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
     11,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0
};