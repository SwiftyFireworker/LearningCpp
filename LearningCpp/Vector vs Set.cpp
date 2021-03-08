//
//  main.cpp
//  LearningCpp
//
//  Created by Egor Denisov on 10.02.2021.
//

#include <iostream>
#include <vector>
#include <set>
#include <ctime>

using namespace std;


int main() {
    const int n = 100000;
    int numbers[n];
    for(int i = 0; i < n; i++) {
        numbers[i] = rand() % 100;
    }
    
    set<int> s;
    clock_t time = clock();
    for(int i = 0; i < n; i++) {
        s.insert(numbers[i]);
    }
    cout << "Set: " << clock() - time << endl;
    
    vector<int> v;
    for(int i = 0; i < n; i++) {
        v.push_back(numbers[i]);
    }
    time = clock();
    sort(v.begin(), v.end());
    cout << "Vector: " << clock() - time << endl;
    
    //LEADER: VECTOR
    return 0;
}
