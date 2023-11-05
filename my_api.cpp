// Copyright 2017 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

// Implementation of "my_api".
#include "my_api.h"

#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

// Do some computations with 'str', return the result.
// This function contains a bug. Can you spot it?
size_t DoStuff(const std::string &str) {
  std::vector<int> Vec({0, 1, 2, 3, 4});
  size_t Idx = 0;
  if (str.size() > 5)
    Idx++;
  if (str.find("foo") != std::string::npos)
    Idx++;
  if (str.find("bar") != std::string::npos)
    Idx++;
  if (str.find("ouch") != std::string::npos)
    Idx++;
  if (str.find("omg") != std::string::npos)
    Idx++;
  if (str.find("on") != std::string::npos)
    Idx++;
  // This is the bug fix: the index can be out of bounds.
  if (Idx >= 5)
    {
      printf("Idx too large\n");
      return 0;
    }
  return Vec[Idx];
}

using namespace std;

void exploreMe(int a, int b, string c) {
  if (a >= 20000) {
    if (b >= 2000000) {
      if (b - a < 100000) {
        if (c == "FUZZING") {
          // Trigger a heap buffer overflow
          char *s = (char *)malloc(8);
          strcpy(s, "too long");
          printf("%s\n", s);
          // free(s);
        }
      }
    }
  }
}