#ifndef HELPER_H_
#define HELPER_H_

#include <utility>
#include <map>
#include <algorithm>
#include <iostream>
#include <mutex>
#include <string>
#include <cstdlib>

std::mutex cout_lock;

void safe_cout(const std::string& s) {
  std::lock_guard<std::mutex> lock(cout_lock);
  std::cout << s;
}

template<class T> inline
bool contains(const std::map<T,T>& container, const T& value) {
  return container.find(value) != container.end();
};

template<class C_itr, class T> inline
bool contains(const C_itr& first, const C_itr& last, const T& value) {
  return std::find(first, last, value) != last;
};

template<class C, class T> inline
bool contains(const C& container, const T& value) {
  return contains(std::begin(container), std::end(container), value);
};



#endif
