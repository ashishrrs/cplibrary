/*



#define int long long
should be below it

*/

template<int M>
struct static_mint {
    static_assert(0 < M, "Module must be positive");

    using mint = static_mint;
    inline constexpr static int get_mod() { return M; }

    int val;
    static_mint(): val() {}
    static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
    inline mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
    inline mint inv() const { return pow(M - 2); }

    inline friend mint pow(const mint &m, long long n) { return m.pow(n); }
    inline friend mint inv(const mint &m) { return m.inv(); }

    inline mint operator+() const { mint m; m.val = val; return m; }
    inline mint operator-() const { mint m; m.val = M - val; return m; }
    inline mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
    inline mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
    inline mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
    inline mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

    inline friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    inline friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    inline friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    inline friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
    inline friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
    inline friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

    inline mint &operator++() { return *this += 1; }
    inline mint &operator--() { return *this -= 1; }
    inline mint operator++(int) { mint result(*this); *this += 1; return result; }
    inline mint operator--(int) { mint result(*this); *this -= 1; return result; }

    template <typename T> inline explicit operator T() const { return T(val); }

    friend std::ostream &operator<<(std::ostream &os, const mint &m) {
        return os << m.val;
    }

    friend std::istream &operator>>(std::istream &is, mint &m) {
        long long x; is >> x; m = x;
        return is;
    }
};

using mint = static_mint<mod>;
