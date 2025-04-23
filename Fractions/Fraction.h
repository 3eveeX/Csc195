#pragma once
#include <iostream>

namespace mathlib {
	template<typename T>
	class Fraction {
	public:
		Fraction() = default;
		Fraction(T numerator, T denominator) {
			if (denominator != 0) {
				m_numerator = numerator;
				m_denominator = denominator;
			}
			else {
				std::cout << "Invalid inputs. Denominator must not be 0." << std::endl;
				exit(0);
			}
		}
		Fraction<T> operator +(Fraction<T>& other)  {
			if (m_denominator != other.m_denominator) {
				m_numerator *= other.m_denominator;
				other.m_numerator *= m_denominator;
				m_denominator *= other.m_denominator;
				other.m_denominator *= m_denominator;
			}

			return Simplify(m_numerator + other.m_numerator, m_denominator);			
		}
		
		Fraction<T> operator -(Fraction<T>& other)  {
			
			if (m_denominator != other.m_denominator) {
				m_numerator *= other.m_denominator;
				other.m_numerator *= m_denominator;
				m_denominator *= other.m_denominator;
				other.m_denominator *= m_denominator;
			}
			return Simplify(m_numerator - other.m_numerator, m_denominator);
			
		}

		Fraction<T> operator /(const Fraction<T>& other)  {
			return Simplify(m_numerator * other.m_denominator, m_denominator * other.m_numerator);
		}
		
		Fraction<T> operator *(const Fraction<T>& other) {
			return Simplify(m_numerator * other.m_numerator, m_denominator * other.m_denominator);	
		}

		bool operator ==(Fraction<T> other) {
			Simplify(m_numerator, m_denominator);
			Simplify(other.m_numerator, other.m_denominator);
			return ( m_numerator == other.m_numerator && m_denominator == other.m_denominator);
		}
		bool operator >(Fraction<T> other) {
			if (m_denominator != other.m_denominator) {
				m_numerator *= other.m_denominator;
				other.m_numerator *= m_denominator;
				m_denominator *= other.m_denominator;
				other.m_denominator *= m_denominator;
			}
			return(m_numerator > other.m_numerator);
		}

		friend std::ostream& operator << (std::ostream& ostream, const Fraction<T>& f) {
			ostream << f.m_numerator << "/" << f.m_denominator;
			return ostream;
		}

		friend std::istream& operator >> (std::istream& istream, Fraction<T>& f) {
			istream >> f.m_numerator;
			istream >> f.m_denominator;
			return istream;
		}

		T getNumerator() {  return m_numerator; }
		T getDenominator() { return m_denominator; }

		float toFloat() {
			return (float)m_numerator / (float)m_denominator;
		}

		int findGCD(int a, int b) {
			while (b != 0) {
				int temp = b;
				b = a % b;
				a = temp;
			}
			return a;
		}

		Fraction Simplify(T numerator, T denominator) {
			int gcd = findGCD(abs((int)numerator), abs((int)denominator));

			T simplifiedNumerator = numerator / gcd;
			T simplifiedDenominator = denominator / gcd;

			if (denominator < 0) {
				simplifiedDenominator *= -1;
				simplifiedNumerator *= -1;
			}
			return Fraction<T>(simplifiedNumerator, simplifiedDenominator);
		}
	private:
		T m_numerator;
		T m_denominator;
	};
}
