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
 #include <map>
 #include <functional>
 #include <tuple>

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


    std::cout << "\033[?25l";   // Hide cursor

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
    std::cout << '\n' << "--------------------------------------------------"
              << '\n'
              << "\033[2A";   // Move cursor up two lines
    std::cout << "\033[?25l";   // Hide cursor
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
    std::cout << " --- Vector: {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, " \
                 "0.9, 1.0} ---" << std::endl;
    for (auto v: {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}) {
        std::cout << "std::lerp(10, 20, " << v << "): " << std::lerp(10,20, v) \
                  << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(350));
    }
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    
    std::cout << "\n----------- Pausing for a short moment -----------" \
              << std::endl;
    std::cout << '\n' << "--------------------------------------------------"
              << '\n'
              << "\033[2A";   // Move cursor up two lines
    for (int i : std::views::iota(1, 101)) {
        updateStatusBar(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }
    std::cout << "\n\n" << std::endl;

    /**
     * @brief std::function¹¹ can store arbitrary callables in variables. It’s 
     * a kind of polymorphic function wrapper. A callable may be a lambda 
     * function, a function object, or a function. std::function is always 
     * necessary and can’t be replaced by auto, if you have to specify the type 
     * of the callable explicitly.
     */

    std::cout << "The function std::function" << std::endl;
    std::cout << "--------------------------\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    std::cout << "Creating a table of arithmetic operations using std::function"
              << std::endl;
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    std::map<const char, std::function<double(double, double)>> tab;
    tab.insert(std::make_pair('+', [](double a, double b) { return a + b; }));
    tab.insert(std::make_pair('-', [](double a, double b) { return a - b; }));
    tab.insert(std::make_pair('*', [](double a, double b) { return a * b; }));
    tab.insert(std::make_pair('/', [](double a, double b) { return a / b; }));

    std::cout << "tab.insert(std::make_pair('+', [](double a, double b) { " \
              << "return a + b; }))" << std::endl;
    std::cout << "tab.insert(std::make_pair('-', [](double a, double b) { " \
                 "return a - b; }))" << std::endl;
    std::cout << "tab.insert(std::make_pair('*', [](double a, double b) { " \
              << "return a * b; }))" << std::endl;
    std::cout << "tab.insert(std::make_pair('/', [](double a, double b) { " \
              << "return a / b; }))" << std::endl;
     
    std::cout << "\n....\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Output: 8
    std::cout << "tab['+'](3.5, 4.5) = " << tab['+'](3.5, 4.5) << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Output: -1
    std::cout << "tab['-'](3.5, 4.5) = " << tab['-'](3.5, 4.5) << std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Output: 15.75
    std::cout << "tab['*'](3.5, 4.5) = " << tab['*'](3.5, 4.5) << std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Output: 0.777778
    std::cout << "tab['/'](3.5, 4.5) = " << tab['/'](3.5, 4.5) << std::endl; 

    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    
    std::cout << "\n----------- Pausing for a short moment -----------" \
              << std::endl;
    std::cout << '\n' << "--------------------------------------------------"
              << '\n'
              << "\033[2A";   // Move cursor up two lines
    for (int i : std::views::iota(1, 101)) {
        updateStatusBar(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }
    std::cout << "\n\n" << std::endl;

    /**
     * @brief Tuples
     * 
     * You can create tuples of arbitrary length and types with std::tuple¹⁴. 
     * The class template needs the header <tuple>. std::tuple is a 
     * generalization of std::pair. You can convert between tuples with two 
     * elements and pairs. Like his small brother std::pair, the tuple has a 
     * default, a copy, and a move constructor. You can swap tuples with the 
     * function std::swap.
     * 
     * The i-th element of a tuple t can be referenced by the function template
     * std::get: std::get<i-1>(t). By std::get<type>(t) you can directly refer 
     * to the element of the type type.
     * 
     * Tuples support the comparison operators ==, !=, <, >, <= and >=. If you 
     * compare two tuples, the elements of the tuples are compared 
     * lexicographically. The comparison starts at the index 0.
     */


    std::cout << "The functions std::tuple and std::make_tuple" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    std::tuple<std::string, int, float> tup1("first", 3, 4.17f);

    // The helper function std::make_tuple¹⁵ is quite convenient for the 
    // creation of tuples.
    auto tup2 = std::make_tuple("second", 4, 1.1f);

    // first, 3, 4.17
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "Creating a tuple: std::tuple<std::string, int, float> " \
                 "tup1(\"first\", 3, 4.17f): ";
    std::cout << "\t" <<get<0>(tup1) << ", " << get<1>(tup1) << ", " 
              << get<2>(tup1) << std::endl;
    
    // second, 4, 1.1
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "Creating a tuple: auto tup2 = " \
                 "std::make_tuple(\"second\", 4, 1.1): ";
    std::cout << "\t" << get<0>(tup2) << ", " << get<1>(tup2) << ", " << get<2>(tup2)
              << std::endl;
    
    // true
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "tup1 < tup2: ";
    std::cout << "\t" << (tup1 < tup2) << std::endl;              

    auto pair = std::make_pair(1, true);
    std::tuple<int, bool> tup = pair; // conversion from pair to tuple
    
    std::cout << "\n....\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    std::cout << "Setting tup2 for second to Second 'get<0>(tup2) = Second";
    get<0>(tup2)= "Second";
    std::this_thread::sleep_for(std::chrono::milliseconds(750));

    std::cout << "\nTuple tup2: ";
    std::cout << get<0>(tup2) << "," << get<1>(tup2) << ","
              << get<2>(tup2) << std::endl; // Second, 4, 1.1
    std::this_thread::sleep_for(std::chrono::milliseconds(750));

    std::cout << "tup1 < tup2: ";
    std::cout << (tup1 < tup2) << std::endl; // false
    std::this_thread::sleep_for(std::chrono::milliseconds(750));

    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";

    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;
    std::cout << first << " " << second << " "
              << third << " " << fourth << std::endl; // 1 2 3 4

    std::cout << "Binding a tuple to the variables first, second, third and " \
              << "fourth" << std::endl;
    auto tup0 = std::tie(first, second, third, fourth) // bind the tuple
                    = std::make_tuple(101, 102, 103, 104); // create the tuple

    // and assign it
    std::cout << get<0>(tup0) << " " << get<1>(tup0) << " " << get<2>(tup0)
              << " " << get<3>(tup) << std::endl; // 101 102 103 104
    std::cout << first << " " << second << " " << third << " "
              << fourth << std::endl; // 101 102 103 104
    
    first = 201;
    get<1>(tup0) = 202;
    std::cout << get<0>(tup0) << " " << get<1>(tup) << " " << get<2>(tup)
              << " " << get<3>(tup0) << std::endl; // 201 202 103 104
    std::cout << first << " " << second << " " << third << " "
              << fourth << std::endl; // 201 202 103 104
    int a, b;
    std::tie(std::ignore, a, std::ignore, b) = tup0;
    std::cout << a << " " << b << std::endl; // 202 104            
    

    std::cout << "-----------------------------------------------------------" \
                 "--------------------\n";
    
    std::cout << "\n----------- Pausing for a short moment -----------" \
              << std::endl;
    std::cout << '\n' << "--------------------------------------------------"
              << '\n'
              << "\033[2A";   // Move cursor up two lines
    for (int i : std::views::iota(1, 101)) {
        updateStatusBar(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }
    std::cout << "\n\n" << std::endl;


















    std::cout << "\n\n" << std::endl;
    std::cout << "\033[?25h";   // Show cursor
    std::cout << "[Exiting Application]" << std::endl;

    return 0;
}