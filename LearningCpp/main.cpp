////
////  main.cpp
////  LearningCpp
////
////  Created by Egor Denisov on 11.03.2021.
////
//
//#include <iostream>
//#include <random>
//#include <vector>
//#include <cmath>
//
//double getRandomFloatingPointBetween_progressive(int min, int max) {
//    std::random_device rd; // uniformly-distributed integer random number generator
//    std::mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
//    std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
//    return dis(gen);
//}
//
//class Descend {
//public:
//    bool operator() (const double left, const double right) {
//        return abs(left) < abs(right);
//    }
//};
//
//void sortVector(std::vector<double> & v) {
//    Descend d;
//    std::sort(v.begin(), v.end(), d);
//}
//
//
//int main() {
//    std::vector<double> v;
//    for (int i = 0; i < 10; i++) {
//        v.push_back(getRandomFloatingPointBetween_progressive(-2, 2));
//    }
//    for (auto i : v) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//    
//    sortVector(v);
//    
//    for (auto i : v) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//}
