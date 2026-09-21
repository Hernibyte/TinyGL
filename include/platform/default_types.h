#pragma once

#include <cstdint>

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using i8f = int_fast8_t;
using i16f = int_fast16_t;
using i32f = int_fast32_t;
using i64f = int_fast64_t;

using i8l = int_least8_t;
using i16l = int_least16_t;
using i32l = int_least32_t;
using i64l = int_least64_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using u8f = uint_fast8_t;
using u16f = uint_fast16_t;
using u32f = uint_fast32_t;
using u64f = uint_fast64_t;

using u8l = uint_least8_t;
using u16l = uint_least16_t;
using u32l = uint_least32_t;
using u64l = uint_least64_t;

using f32 = float;
using f64 = double;

using shader_id = u32;
using buffer_id = u32;

using cstr_ptr = const char*;

#define BIT(x) (1 << x)