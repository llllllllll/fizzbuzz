#include <iostream>
#include <tuple>
#include <utility>

constexpr std::size_t max_fizzbuzz = 100;

template<char... cs>
using char_sequence = std::integer_sequence<char, cs...>;

template<char... cs, char... ds>
constexpr auto _cat(char_sequence<cs...>,
                    char_sequence<ds...>) {
    return char_sequence<cs..., ds...>{};
};

template<char... cs, char... ds, char... es>
constexpr auto _cat(char_sequence<cs...>,
                    char_sequence<ds...>,
                    char_sequence<es...>) {
    return char_sequence<cs..., ds..., es...>{};
}

template<typename... Ts>
constexpr auto cat(Ts... es) {
    return _cat(es...);
}

template<bool p, typename T, typename F>
struct if_ {
    typedef T type;
};

template<typename T, typename F>
struct if_<false, T, F> {
    typedef F type;
};

template<bool p, typename T, typename F>
using if_t = typename if_<p, T, F>::type;

struct nil {
    constexpr static auto value = char_sequence<>{};
};

template<std::size_t n>
struct itoa {
    constexpr static auto value = cat(
        if_t<n >= 10, itoa<n / 10>, nil>::value,
        char_sequence<((char) ('0' + (n % 10)))>{});
};

template<int m3, int m5, std::size_t n>
struct _fizzbuzz {
    constexpr static auto value = itoa<n>::value;
};

template<std::size_t n>
struct _fizzbuzz<0, 0, n> {
    constexpr static auto value = char_sequence<'f', 'i', 'z', 'z',
                                                'b', 'u', 'z', 'z'>{};
};

template<int m5, std::size_t n>
struct _fizzbuzz<0, m5, n> {
    constexpr static auto value = char_sequence<'f', 'i', 'z', 'z'>{};
};

template<int m3, std::size_t n>
struct _fizzbuzz<m3, 0, n> {
    constexpr static auto value = char_sequence<'b', 'u', 'z', 'z'>{};
};

template<std::size_t n>
struct fizzbuzz {
    constexpr static auto value = _fizzbuzz<n % 3, n % 5, n>::value;
};

template<std::size_t n>
struct fizzbuzzer {
    constexpr static auto value = cat(fizzbuzz<n>::value,
                                      char_sequence<'\n'>{},
                                      fizzbuzzer<n + 1>::value);
};

template<>
struct fizzbuzzer<max_fizzbuzz> {
    constexpr static auto value = cat(fizzbuzz<max_fizzbuzz>::value,
                                      char_sequence<'\n'>{});
};

template<char... cs>
constexpr auto to_array(char_sequence<cs...>) {
    return std::array<char, sizeof...(cs) + 1> {cs..., '\0'};
}

int main() {
    std::cout << to_array(fizzbuzzer<1>::value).data();
    return 0;
}
