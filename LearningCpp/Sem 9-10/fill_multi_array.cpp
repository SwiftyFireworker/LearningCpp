//
//  fill_multi_array.cpp
//  LearningCpp
//
//  Created by Egor Denisov on 11.03.2021.
//

#include <iostream>
#include <vector>
#include <boost/multi_array.hpp>


//template<typename T, typename U, std::size_t Dim, std::size_t Dim2>
//void fill_multi_array(typename SubArray<T, Dim, Dim2>::type multiArray, const std::vector<U> & vec) {
//    if (Dim == 1) {
//        for(size_t i = 0; i < vec.size(); i++) {
//            multiArray[i] = vec[i];
//        }
//    } else {
//        for(size_t i = 0; i < vec.size(); i++) {
//            fill_multi_array(multiArray[i], vec[i]);
//        }
//    }
//}

//template<typename T>
//struct is_vector: std::false_type
//{  };
//
//template<typename T>
//struct is_vector<std::vector<T>>: std::true_type
//{  };

template<typename T, typename U, std::size_t Dim>
void fill_multi_array(boost::detail::multi_array::sub_array<T, Dim> & multiArray, const std::vector<U> & vec) {
    if (Dim > 1) {
        for(size_t i = 0; i < vec.size(); i++) {
            fill_multi_array(multiArray[i], vec[i]);
        }
//        return;
    } else {
        for(size_t i = 0; i < vec.size(); i++) {
            multiArray[i] = vec[i];
        }
    }
}

//template<typename T, typename U, std::size_t Dim=1>
//void fill_multi_array(boost::detail::multi_array::sub_array<T, Dim> & multiArray, const std::vector<U> & vec) {
//    for(size_t i = 0; i < vec.size(); i++) {
//        multiArray[i] = vec[i];
//    }
//}

template<typename T, typename U, std::size_t Dim>
void fill_multi_array(boost::multi_array<T, Dim> & multiArray, const std::vector<U> & vec) {
    if (Dim > 1) {
        for(size_t i = 0; i < vec.size(); i++) {
            fill_multi_array(multiArray[i], vec[i]);
        }
        return;
    } else {
        for(size_t i = 0; i < vec.size(); i++) {
            multiArray[i] = vec[i];
        }
    }
}


//template<typename T, typename U>
//void fill_multi_array(T & multiArray, const U & vec) {
//    if (is_vector<U>::value) {
//        for(size_t i = 0; i < vec.size(); i++) {
//            multiArray[i] = vec[i];
//        }
//    } else {
//        for(size_t i = 0; i < vec.size(); i++) {
//            fill_multi_array(multiArray[i], vec[i]);
//        }
//    }
//}

//template<typename T, typename U, std::size_t Dim>
//void fill_multi_array(boost::multi_array<T, Dim> & multiArray, const std::vector<U> & vec) {
//    if (Dim == 1) {
//        for(size_t i = 0; i < vec.size(); i++) {
//            multiArray[i] = vec[i];
//        }
//    } else {
//        for(size_t i = 0; i < vec.size(); i++) {
//            fill_multi_array(static_cast<boost::multi_array<T, Dim-1>>(multiArray[i]), vec[i]);
//        }
//    }
//}

int main() {
    {
        std::vector<double> vec {1, 2, 3};
        boost::multi_array<double, 1> arr { boost::extents[3] };
        fill_multi_array(arr, vec);
        for (int i = 0; i < 3; i++) {
            if (arr[i] != vec[i]) {
                std::cout << "Not ok: " << arr[i] << " " << vec[i] << std::endl;
            }
        }
    }
    {
        std::vector<std::vector<double>> vec { {1, 2, 3}, {4, 5, 6} };
        boost::multi_array<double, 2> arr { boost::extents[3][3] };
        fill_multi_array(arr, vec);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] != vec[i][j]) {
                    std::cout << "Not ok: " << arr[i][j] << " " << vec[i][j] << std::endl;
                }
            }
        }
    }
//    {
//        std::vector<std::vector<std::vector<double>>> vec { { {1, 2, 3}, {4, 5, 6} } };
//        boost::multi_array<double, 3> arr { boost::extents[3][3] };
//        fill_multi_array(arr, vec);
//        for (int k = 0; k < 1; k++) {
//            for (int i = 0; i < 2; i++) {
//                for (int j = 0; j < 3; j++) {
//                    if (arr[k][i][j] != vec[k][i][j]) {
//                        std::cout << "Not ok: " << arr[k][i][j] << " " << vec[k][i][j] << std::endl;
//                    }
//                }
//            }
//        }
//    }
}
