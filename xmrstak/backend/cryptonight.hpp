#pragma once
#include <stddef.h>
#include <inttypes.h>
#include <type_traits>

enum xmrstak_algo 
{
	invalid_algo = 0,
	cryptonight = 1,
	cryptonight_lite = 2,
	cryptonight_monero = 3,
	cryptonight_heavy = 4,
	cryptonight_aeon = 5,
	cryptonight_alloy = 6,
	cryptonight_b2n = 7
};

// define aeon settings
constexpr size_t CRYPTONIGHT_LITE_MEMORY = 1 * 1024 * 1024;
constexpr uint32_t CRYPTONIGHT_LITE_MASK = 0xFFFF0;
constexpr uint32_t CRYPTONIGHT_LITE_ITER = 0x40000;

constexpr size_t CRYPTONIGHT_MEMORY = 2 * 1024 * 1024;
constexpr uint32_t CRYPTONIGHT_MASK = 0x1FFFF0;
constexpr uint32_t CRYPTONIGHT_ITER = 0x80000;

constexpr size_t CRYPTONIGHT_HEAVY_MEMORY = 4 * 1024 * 1024;
constexpr uint32_t CRYPTONIGHT_HEAVY_MASK = 0x3FFFF0;
constexpr uint32_t CRYPTONIGHT_HEAVY_ITER = 0x40000;

constexpr size_t CRYPTONIGHT_ALLOY_MEMORY = 2 * 1024 * 1024;
constexpr uint32_t CRYPTONIGHT_ALLOY_MASK = 0x1FFFF0;
constexpr uint32_t CRYPTONIGHT_ALLOY_ITER = 0x100000;

constexpr size_t CRYPTONIGHT_B2N_MEMORY = 2 * 1024 * 1024;
constexpr uint32_t CRYPTONIGHT_B2N_MASK = 0x1FFFF0;
constexpr uint32_t CRYPTONIGHT_B2N_ITER = 0x60000;
                                         

template<xmrstak_algo ALGO>
inline constexpr size_t cn_select_memory() { return 0; }

template<>
inline constexpr size_t cn_select_memory<cryptonight>() { return CRYPTONIGHT_MEMORY; }

template<>
inline constexpr size_t cn_select_memory<cryptonight_lite>() { return CRYPTONIGHT_LITE_MEMORY; }

template<>
inline constexpr size_t cn_select_memory<cryptonight_monero>() { return CRYPTONIGHT_MEMORY; }

template<>
inline constexpr size_t cn_select_memory<cryptonight_heavy>() { return CRYPTONIGHT_HEAVY_MEMORY; }

template<>
inline constexpr size_t cn_select_memory<cryptonight_aeon>() { return CRYPTONIGHT_LITE_MEMORY; }

template<>
inline constexpr size_t cn_select_memory<cryptonight_alloy>() { return CRYPTONIGHT_ALLOY_MEMORY; }

template<>
inline constexpr size_t cn_select_memory<cryptonight_b2n>() { return CRYPTONIGHT_B2N_MEMORY; }


inline size_t cn_select_memory(xmrstak_algo algo)
{
	switch(algo)
	{
	case cryptonight_monero:
	case cryptonight:
		return CRYPTONIGHT_MEMORY;	
	case cryptonight_aeon:
	case cryptonight_lite:
		return CRYPTONIGHT_LITE_MEMORY;
	case cryptonight_heavy:
		return CRYPTONIGHT_HEAVY_MEMORY;
		
	case cryptonight_alloy:
		return CRYPTONIGHT_ALLOY_MEMORY;
		
	case cryptonight_b2n:
		return CRYPTONIGHT_B2N_MEMORY;				
		
	default:
		return 0;
	}
}

template<xmrstak_algo ALGO>
inline constexpr uint32_t cn_select_mask() { return 0; }

template<>
inline constexpr uint32_t cn_select_mask<cryptonight>() { return CRYPTONIGHT_MASK; }

template<>
inline constexpr uint32_t cn_select_mask<cryptonight_lite>() { return CRYPTONIGHT_LITE_MASK; }

template<>
inline constexpr uint32_t cn_select_mask<cryptonight_monero>() { return CRYPTONIGHT_MASK; }

template<>
inline constexpr uint32_t cn_select_mask<cryptonight_heavy>() { return CRYPTONIGHT_HEAVY_MASK; }

template<>
inline constexpr uint32_t cn_select_mask<cryptonight_aeon>() { return CRYPTONIGHT_LITE_MASK; }

template<>
inline constexpr uint32_t cn_select_mask<cryptonight_alloy>() { return CRYPTONIGHT_ALLOY_MASK; }

template<>
inline constexpr uint32_t cn_select_mask<cryptonight_b2n>() { return CRYPTONIGHT_B2N_MASK; }


inline size_t cn_select_mask(xmrstak_algo algo)
{
	switch(algo)
	{
	case cryptonight_monero:
	case cryptonight:
		return CRYPTONIGHT_MASK;
	case cryptonight_aeon:
	case cryptonight_lite:
		return CRYPTONIGHT_LITE_MASK;
	case cryptonight_heavy:
		return CRYPTONIGHT_HEAVY_MASK;

	case cryptonight_alloy:
    	return CRYPTONIGHT_ALLOY_MASK;
		
	case cryptonight_b2n:
    	return CRYPTONIGHT_B2N_MASK;

default:
		return 0;
	}
}

template<xmrstak_algo ALGO>
inline constexpr uint32_t cn_select_iter() { return 0; }

template<>
inline constexpr uint32_t cn_select_iter<cryptonight>() { return CRYPTONIGHT_ITER; }

template<>
inline constexpr uint32_t cn_select_iter<cryptonight_lite>() { return CRYPTONIGHT_LITE_ITER; }

template<>
inline constexpr uint32_t cn_select_iter<cryptonight_monero>() { return CRYPTONIGHT_ITER; }

template<>
inline constexpr uint32_t cn_select_iter<cryptonight_heavy>() { return CRYPTONIGHT_HEAVY_ITER; }

template<>
inline constexpr uint32_t cn_select_iter<cryptonight_aeon>() { return CRYPTONIGHT_LITE_ITER; }

template<>
inline constexpr uint32_t cn_select_iter<cryptonight_alloy>() { return CRYPTONIGHT_ALLOY_ITER; }

template<>
inline constexpr uint32_t cn_select_iter<cryptonight_b2n>() { return CRYPTONIGHT_B2N_ITER; }


inline size_t cn_select_iter(xmrstak_algo algo)
{
	switch(algo)
	{
	case cryptonight_monero:
	case cryptonight:
		return CRYPTONIGHT_ITER;
	case cryptonight_aeon:
	case cryptonight_lite:
		return CRYPTONIGHT_LITE_ITER;
	case cryptonight_heavy:
		return CRYPTONIGHT_HEAVY_ITER;

	case cryptonight_alloy:
		return CRYPTONIGHT_ALLOY_ITER;
		
	case cryptonight_b2n:
		return CRYPTONIGHT_B2N_ITER;

		
				
    default:
		return 0;
	}
}
