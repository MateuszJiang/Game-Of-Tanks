#pragma once

#ifdef STATE_DEBUG
	#define STATE_ENABLE_ASSERTS
#endif

#ifdef STATE_ENABLE_ASSERTS
	#define STATE_ASSERT(x, ...) { if(!(x)) {HZ_ERROR("Assertion Failed{0}", __VA_ARGS__); __debugbreak();} }
	#define STATE_CORE_ASSERT(x, ...) { if(!(x)) {HZ_CORE_ERROR("Assertion Failed{0}", __VA_ARGS__); __debugbreak();} }
#else
	#define STATE_ASSERT(x, ...)
	#define STATE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define STATE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)