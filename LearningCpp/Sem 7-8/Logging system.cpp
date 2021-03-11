////
////  Logging system.cpp
////  LearningCpp
////
////  Created by Egor Denisov on 09.03.2021.
////
//
//#include <iostream>
//#include <boost/circular_buffer.hpp>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
//
//string numbInDate(int numb) {
//    return ((to_string(numb).length() == 1) ? "0" : "") + to_string(numb);
//}
//
//string getDate() {
//    time_t now = time(0);
//    tm * localTimeNow = localtime(&now);
//    
//    string date = numbInDate(localTimeNow->tm_wday)
//    + ":" + numbInDate(localTimeNow->tm_mon)
//    + ":" + to_string(localTimeNow->tm_year + 1900)
//    + " "
//    + numbInDate(localTimeNow->tm_hour)
//    + ":" + numbInDate(localTimeNow->tm_min)
//    + ":" + numbInDate(localTimeNow->tm_sec);
//    
//    return date;
//}
//
//
//int main() {
//    boost::circular_buffer<string> buf(3);
//    
//    for(int i = 0; i < buf.capacity(); i++) {
//        string email = "";
//        cout << "Email: ";
//        cin >> email;
//        string date = getDate();
//        buf.push_back(email + "-" + date);
//    }
//    for(string it: buf) {
//        cout << it << endl;
//    }
//    return 0;
//}
