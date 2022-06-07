#pragma once
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>

using List = std::vector<int>;

template <class T>

void HoanVi(T& a, T& b);

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(List& a, int n);

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(List& a, int n);

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(List& a, int n);

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(List& a, int n);

void GenerateData(List& a, int n, int dataType);