#ifdef X
    #define R
    #ifdef G
        #define L
    #endif
#else
    #define K
#endif

int main() {
    auto const x = 12'000;
    auto const i = 0xAA'FF'EE;
    auto const j = 0b11110000'11110000;
}
