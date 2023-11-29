#include <concepts>

#ifdef X
    #define R
    #ifdef G
        #define L
    #endif
#else
    #define K
#endif

namespace MyNamespace {
class Base {};

class Derived: public Base {
public:
    struct Args {
        float f;
        int x;
    };

    explicit Derived(Args args)
        : m_f{args.f}
        , m_x{args.x} {}

protected:
    float m_f{};

private:
    int m_x{};
};
}  // namespace MyNamespace

template <typename T>
requires std::integral<T>
[[nodiscard]] constexpr auto identity(T t) noexcept {
    return [t] { return t; };
}

template <typename T>
concept C = requires(T t) {
    { t.push() } -> std::same_as<void>;
    { t.pop() } -> std::same_as<void>;
};

int main() {
    auto const x = 12'000;               // A comment
    auto const i = 0xAA'FF'EE;           // Another comment
    auto const j = 0b11110000'11110000;  // third comment
    auto const k = 100 + 300 + 100'000 + 45'543'232 + 12'345 + 543 + 678 + 6 - 4 - 3 - 4 - 5
                   - 5'556'766 - 3'245;
    MyNamespace::Derived const d{
        {.f = 10.F, .x = 11}
    };

    MyNamespace::Derived::Args const args{.f = 10.F, .x = 11};
    MyNamespace::Derived const d1{args};
}
