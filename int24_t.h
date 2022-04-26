const int INT24_MAX = 8388607;
const int INT24_MIN = -8388608;

class int24_t
{
  protected:
    unsigned char value[3];

  public:
    int24_t()
    {
        value[0] = value[1] = value[2] = 0;
    }

    int24_t( const int24_t &val )
    {
        *this = val;
    }

    int24_t( const int &val )
    {
        *this = (int)val;
    }

    int24_t( const unsigned char val[3] )
    {
        value[0] = val[0];
        value[1] = val[1];
        value[2] = val[2];
    }

    operator int() const
    {
        // Ensure signed values are handled properly
        if( value[2] & 0x80 ) {
            return ( 0xff << 24 ) | ( value[2] << 16 ) | ( value[1] << 8 ) | value[0];
        }
        else {
            return ( value[2] << 16 ) | ( value[1] << 8 ) | value[0];
        }
    }

    int24_t &operator=( const int24_t &input )
    {
        value[0] = input.value[0];
        value[1] = input.value[1];
        value[2] = input.value[2];

        return *this;
    }

    int24_t &operator=( const int input )
    {
        value[0] = ( (unsigned char *)&input )[0];
        value[1] = ( (unsigned char *)&input )[1];
        value[2] = ( (unsigned char *)&input )[2];

        return *this;
    }

    int24_t operator+( const int24_t &val ) const
    {
        return int24_t( (int)*this + (int)val );
    }

    int24_t operator-( const int24_t &val ) const
    {
        return int24_t( (int)*this - (int)val );
    }

    int24_t operator*( const int24_t &val ) const
    {
        return int24_t( (int)*this * (int)val );
    }

    int24_t operator/( const int24_t &val ) const
    {
        return int24_t( (int)*this / (int)val );
    }

    int24_t operator%( const int24_t &val ) const
    {
        return int24_t( (int)*this % (int)val );
    }

    int24_t &operator+=( const int24_t &val )
    {
        *this = *this + val;
        return *this;
    }

    int24_t &operator-=( const int24_t &val )
    {
        *this = *this - val;
        return *this;
    }

    int24_t &operator*=( const int24_t &val )
    {
        *this = *this * val;
        return *this;
    }

    int24_t &operator/=( const int24_t &val )
    {
        *this = *this / val;
        return *this;
    }

    int24_t &operator%=( const int24_t &val )
    {
        *this = *this % val;
        return *this;
    }

    int24_t operator+( const int &val ) const
    {
        return int24_t( (int)*this + val );
    }

    int24_t operator-( const int &val ) const
    {
        return int24_t( (int)*this - val );
    }

    int24_t operator*( const int &val ) const
    {
        return int24_t( (int)*this * val );
    }

    int24_t operator/( const int &val ) const
    {
        return int24_t( (int)*this / val );
    }

    int24_t operator%( const int &val ) const
    {
        return int24_t( (int)*this % val );
    }

    int24_t &operator+=( const int &val )
    {
        *this = *this + val;
        return *this;
    }

    int24_t &operator-=( const int &val )
    {
        *this = *this - val;
        return *this;
    }

    int24_t &operator*=( const int &val )
    {
        *this = *this * val;
        return *this;
    }

    int24_t &operator/=( const int &val )
    {
        *this = *this / val;
        return *this;
    }

    int24_t &operator%=( const int &val )
    {
        *this = *this % val;
        return *this;
    }

    int24_t operator>>( const int val ) const
    {
        return int24_t( (int)*this >> val );
    }

    int24_t operator<<( const int val ) const
    {
        return int24_t( (int)*this << val );
    }

    int24_t &operator<<=( const int &val )
    {
        *this = int24_t( (int)*this << val );
        return *this;
    }

    int24_t &operator>>=( const int &val )
    {
        *this = int24_t( (int)*this >> val );
        return *this;
    }

    operator bool() const
    {
        return (int)*this != 0;
    }

    bool operator!() const
    {
        return !( (int)*this );
    }

    int24_t operator-()
    {
        return int24_t( -(int)*this );
    }

    bool operator==( const int24_t &val ) const
    {
        return (int)*this == (int)val;
    }

    bool operator!=( const int24_t &val ) const
    {
        return (int)*this != (int)val;
    }

    bool operator>=( const int24_t &val ) const
    {
        return (int)*this >= (int)val;
    }

    bool operator<=( const int24_t &val ) const
    {
        return (int)*this <= (int)val;
    }

    bool operator==( const int &val ) const
    {
        return (int)*this == val;
    }

    bool operator!=( const int &val ) const
    {
        return (int)*this != val;
    }

    bool operator>=( const int &val ) const
    {
        return (int)*this >= val;
    }

    bool operator<=( const int &val ) const
    {
        return (int)*this <= val;
    }

    int24_t operator++( int )
    {
        *this = (int)*this + 1;
        return *this;
    }

    int24_t operator--( int )
    {
        *this = (int)*this - 1;
        return *this;
    }

    // Make anymore operators that you want to!
};