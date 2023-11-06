// Copyright 2017 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

// Implementation of "my_api".
#include "my_api.h"

#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

// just a function with multiple paths that can be discoverd by a fuzzer
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