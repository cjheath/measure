#if !defined(MEASURE_H)
#define MEASURE_H
/*
 * Measurement units system
 *
 * (c) Copyright Clifford Heath 2024
 */
#include        <stdlib.h>
#include        <stdint.h>
#include        <string>

class Unit
{
public:
	struct Coefficient
	{
		double		numerator;
		uint64_t	denominator;
		bool		is_precise;
		double		offset;
	};

	struct Derivation
	{
		const Unit*	unit;		// Array of base Units
		int8_t		exponent;	// Array of exponent applying to respective base Unit
	};

protected:
	// REVISIT: Do we want a single-char name for SI units here?
	std::string	name;			// e.g. "inch"
	std::string	plural_name;		// e.g. "inches"
	short		derivation_count;	// Number of base units. 0 means it's a fundamental unit (Coefficient == 1) or a multiplier
	Derivation*	derivation;		// Array of Derivation
	Coefficient	coefficient;		// The multiplier
	// std::string	ephemera_url;		// A web service that can provide a coefficient relevant to a specific time&date

public:
};

#endif /* MEASURE_H */
