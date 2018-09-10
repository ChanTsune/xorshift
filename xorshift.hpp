#pragma once
#ifndef XORSHIFT_HPP
#define XORSHIFT_HPP
#include <cstdint>

namespace xorshift
{
class xorshift32
{
  private:
    uint32_t m_seed;

  public:
    xorshift32(uint32_t _Seed = 1) : m_seed(_Seed) {}
    void seed(uint32_t _Seed) { m_seed = _Seed; }
    void discard(uint64_t z);
    uint32_t operator()(void);
};

void xorshift32::discard(uint64_t z)
{
    while (z--)
        this->operator()();
}

uint32_t xorshift32::operator()(void)
{
    m_seed ^= m_seed << 13;
    m_seed ^= m_seed >> 17;
    m_seed ^= m_seed << 15;
    return m_seed;
}

class xorshift64
{
  private:
    uint64_t m_seed;

  public:
    xorshift64(uint64_t _Seed = 1) : m_seed(_Seed) {}
    void seed(uint64_t seed) { m_seed = seed; }
    void discard(uint64_t z);
    uint64_t operator()(void);
};

void xorshift64::discard(uint64_t z)
{
    while (z--)
        this->operator()();
}

uint64_t xorshift64::operator()(void)
{
    m_seed ^= m_seed << 13;
    m_seed ^= m_seed >> 7;
    m_seed ^= m_seed << 17;
    return m_seed;
}

class xorshift96
{
  private:
    uint32_t m_seed0;
    uint32_t m_seed1;
    uint32_t m_seed2;

  public:
    xorshift96(uint32_t seed1 = 1, uint32_t seed2 = 2, uint32_t seed3 = 3) : m_seed0(seed1), m_seed1(seed2), m_seed2(seed3) {}
    void seed(uint32_t seed1, uint32_t seed2, uint32_t seed3)
    {
        m_seed0 = seed1;
        m_seed1 = seed2;
        m_seed2 = seed3;
    }
    void discard(uint64_t z);
    uint32_t operator()(void);
};

void xorshift96::discard(uint64_t z)
{
    while (z--)
        this->operator()();
}

uint32_t xorshift96::operator()(void)
{
    uint32_t t;
    m_seed0 ^= (m_seed0 << 3);
    t = m_seed0;
    m_seed0 = m_seed1;
    m_seed1 ^= (m_seed1 >> 19);
    t ^= m_seed1;
    m_seed1 = m_seed2;
    m_seed2 ^= (m_seed2 << 6);
    t ^= m_seed2;
    m_seed2 = t;
    return t;
}

class xorshift128
{
  private:
    uint32_t m_seed0;
    uint32_t m_seed1;
    uint32_t m_seed2;
    uint32_t m_seed3;

  public:
    xorshift128(uint32_t seed1 = 1, uint32_t seed2 = 2, uint32_t seed3 = 3, uint64_t seed4 = 4) : m_seed0(seed1), m_seed1(seed2), m_seed2(seed3), m_seed3(seed4) {}
    void seed(uint32_t seed1, uint32_t seed2, uint32_t seed3, uint32_t seed4)
    {
        m_seed0 = seed1;
        m_seed1 = seed2;
        m_seed2 = seed3;
        m_seed3 = seed4;
    }
    void discard(uint64_t z);
    uint32_t operator()(void);
};

void xorshift128::discard(uint64_t z)
{
    while (z--)
        this->operator()();
}

uint32_t xorshift128::operator()(void)
{
    uint32_t t;
    m_seed0 ^= (m_seed0 << 11);
    t = m_seed0;
    m_seed0 = m_seed1;
    m_seed1 = m_seed2;
    m_seed2 = m_seed3;
    t ^= (t >> 8);
    m_seed3 ^= (m_seed3 >> 19);
    m_seed3 ^= t;
    return m_seed3;
}

//xorshift128+ google chrome javascrypt engine V8
class xorshift128Plus
{
  private:
    uint64_t m_seed0;
    uint64_t m_seed1;

  public:
    xorshift128Plus(uint64_t seed1, uint64_t seed2) : m_seed0(seed1), m_seed1(seed2){};
    void seed(uint64_t seed1, uint64_t seed2)
    {
        m_seed0 = seed1;
        m_seed1 = seed2;
    }
    void discard(uint64_t z);
    uint64_t operator()(void);
};

void xorshift128Plus::discard(uint64_t z)
{
    while (z--)
        this->operator()();
}

uint64_t xorshift128Plus::operator()(void)
{
    uint64_t s1 = m_seed0;
    uint64_t s0 = m_seed1;
    m_seed0 = s0;
    s1 ^= s1 << 23;
    s1 ^= s1 >> 17;
    s1 ^= s0;
    s1 ^= s0 >> 26;
    m_seed1 = s1;
    return m_seed0 + m_seed1;
}

} // namespace xorshift

#endif //include gard XORSHIFT_HPP