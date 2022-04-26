#include <iostream>
#include <cassert>
#include "int24_t.h"

using namespace std;

int main( void )
{
    // Test empty constructor & casting
    int24_t val1;
    assert( (int)val1 == 0 );
    assert( val1 == (int24_t)0 );

    // Test assignment
    int24_t val2 = 69;
    assert( val2 == 69 );

    // Test incrementing
    val1++;
    assert( val1 == 1 );
    val1 = INT24_MAX;
    val1++;
    assert( val1 == INT24_MIN );
    val1++;
    assert( val1 == INT24_MIN + 1 );

    // Test decrementing
    val2--;
    assert( val2 == 68 );
    val2 = INT24_MIN;
    val2--;
    assert( val2 == INT24_MAX );
    val2--;
    assert( val2 == INT24_MAX - 1 );

    // Test addition
    val1 = 22;
    val2 = 1024;
    assert( val1 + 6909 == 6931 );
    assert( val1 + val2 == 1046 );
    int24_t val3 = val1 + val2;
    assert( val3 == 1046 );
    val3 = val2 + INT24_MAX;
    assert( val3 == -8387585 );
    val1 = -7777;
    val2 = -9875;
    assert( val1 + val2 == -17652 );

    // Test subtraction
    val1 = 5000;
    val2 = 1000;
    assert( val1 - val2 == 4000 );
    assert( val2 - val1 == -4000 );
    val3 = val2 - val1 - 1;
    assert( val3 == -4001 );
    val1 = INT24_MIN;
    val2 = 1000;
    val3 = val1 - val2;
    assert( val3 == (int24_t)( INT24_MIN - 1000 ) );

    // Test multiplication
    val1 = INT24_MAX / 2;
    assert( val1 * 2 == ( INT24_MAX - 1 ) );
    val2 = INT24_MIN / 2;
    assert( val2 * 2 == INT24_MIN );
    val1 -= 1000;
    val1 *= 3;
    assert( val1 == -4197307 );
    val2 += 1000;
    val2 *= 3;
    assert( val2 == 4197304 );

    cout << "All tests passed!\n";

    return 0;
}