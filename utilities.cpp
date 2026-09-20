/**
 * @brief Revisting C++ coding standards and practices. 
 *
 * Starting off with Utilities. Utilities are valuable tools that can be 
 * used in many different contexts. They are not bound to a typical domain.
 */

 #include <iostream>
 #include <algorithm>
 #include <ranges>
 #include <iomanip>
 #include <chrono>
 #include <thread>
 #include <cmath>
 #include <numeric>

 void updateStatusBar(int percentage) {
    if(percentage < 0 || percentage > 100) {
        throw std::invalid_argument("Numeric value is invalid.");
    }
    
    constexpr int bar_width = 50;

    int bar_counter = percentage / 2;
    int space_counter = bar_width - bar_counter;

    std::cout << '\r'
              << std::string(bar_counter, '|')
              << std::string(space_counter, ' ')
              << std::flush;
 }


 // Main Function
 int main() {
    /**
     * The functions std::min¹, std::max² and std::minmax³, defined in the 
     * header <algorithm>, act on values and initialiser lists and give you the 
     * requested value back as result. In the case of std::minmax, you get a 
     * std::pair. The first element of the pair is the minimum, the second the 
     * maximum of the values. By default, the less operator (<) is used, but 
     * you can specify your comparison operator. This function needs two 
     * arguments and returns a boolean. Functions either return true or false 
     * are called predicates.
     */

    std::cout << "The functions std::min and std::minmax." \
              << std::endl;
    std::cout << "---------------------------------------\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Example output of the function 'std::min' :" << std::endl;
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "Minimum of (2011, 2014): " << std::min(2011, 2014) \
              << std::endl;
    std::cout << "Minimum of {4, 1, 2011, 2014, -5}: "
              << std::min({4, 1, 2011, 2014, -5}) << std::endl;
    std::cout << "Minimum of (-10, -5) with custom comparator: "
              << std::min(-10, -5, [](int a, int b){ return std::abs(a) \
                          < std::abs(b); }) << std::endl;
    
    std::cout << "\n....\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    std::cout << "Example output of the function 'std::minmax' " << std::endl;
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto pairInt = std::minmax({2011, 2014});
    auto pairSeq = std::minmax({3, 1, 2011, 2014, -5});
    auto pairAbs = std::minmax({3, 1, 2011, 2014, -5}, 
        [](int a, int b){ return std::abs(a) < std::abs(b); });

    std::cout << "pairInt: (2011, 2014) \n" ;
    std::cout << "pairSeq: (3, 1, 2011, 2014, -5) \n" ;
    std::cout << "pairAbs: (3, 1, 2011, 2014, -5) with custom comparator \n\n" ;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "Min/Max for pairInt, Minimum: " << pairInt.first \
              << ", Maximum: " << pairInt.second << std::endl;
    std::cout << "Min/Max for pairSeq, Minimum: " << pairSeq.first \
              << ", Maximum: " << pairSeq.second << std::endl;
    std::cout << "Min/Max for pairAbs, Minimum: " << pairAbs.first \
              << ", Maximum: " << pairAbs.second << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";

    std::cout << "\n----------- Pausing for a short moment -----------" \
              << std::endl;
    for (int i : std::views::iota(1, 101)) {
        updateStatusBar(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }
    std::cout << "\n\n" << std::endl;

    /**
     * @brief The function std::midpoint(a, b) calculates the midpoint between 
     * a and b. a and b can be integers, floating-point numbers, or pointers. 
     * If a and b are pointers, they have to point to the same array object. 
     * The function std::midpoint requires the header <numeric>. The function 
     * std::lerp(a, b, t) calculates the linear arithmetic of two numbers. 
     * It requires the header <cmath>. The return value is a + t(b- a).
     */

    std::cout << "The functions std::midpoint and std::lerp" << std::endl;
    std::cout << "-----------------------------------------\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    std::cout << "Example output of the function 'std::midpoint'" << std::endl;
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";

    std::cout << "std::midpoint(10, 20): " << std::midpoint(10, 20) \
              << std::endl;

    std::cout << "\n....\n" << std::endl;

    std::cout << "Example output of the function 'std::lerp'" << std::endl;
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << " Vector: {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, " \
                 "0.9, 1.0}" << std::endl;
    for (auto v: {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}) {
        std::cout << "std::lerp(10, 20, " << v << "): " << std::lerp(10,20, v) \
                  << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    
    std::cout << "\n----------- Pausing for a short moment -----------" \
              << std::endl;
    for (int i : std::views::iota(1, 101)) {
        updateStatusBar(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }
    std::cout << "\n\n" << std::endl;

    return 0;
}