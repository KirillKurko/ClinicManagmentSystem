#ifndef CorrectCin_hpp
#define CorrectCin_hpp

template <class T>
decltype(auto) CorrectCin() {
    T value;
    while (true) {
        std::cin.unsetf(std::ios::skipws);
        std::cin >> value;
        if (std::cin.good() && std::cin.peek() == '\n') {
            std::cin.ignore(10, '\n');
            break;
        }
        std::cin.clear();
        std::cout << "Ошибка, повторите ввод: ";
        std::cin.ignore(10, '\n');
    }
    return value;
}

#endif
