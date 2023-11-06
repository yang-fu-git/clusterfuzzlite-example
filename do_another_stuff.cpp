// Copyright 2017 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

// Implementation of "my_api".
#include "my_api.h"
#include <string>
#include <vector>

// Do some computations with 'str', return the result.
// This function contains a bug. Can you spot it?
size_t DoAnotherStuff(const std::string &str) {
  std::string augument_string = str+str;
  return DoStuff(augument_string);
}