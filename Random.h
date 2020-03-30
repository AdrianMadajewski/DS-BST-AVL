#ifndef RANDOM_H
#define RANDOM_H

inline constexpr auto DATA_MIN{ 1 };
inline constexpr auto DATA_MAX{ 15 };

namespace random
{
	int generateNumber(const int min, const int max);
}

#endif // !RANDOM_H
