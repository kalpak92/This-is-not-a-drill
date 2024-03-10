#ifndef _COMPARE_H_
#define _COMPARE_H_

template <typename T>
int compare(const T &value1, const T &value2) {
    if (value1 < value2) return -1;
    if (value2 < value1) return 1;
    return 0;
}

#endif  // _COMPARE_H_