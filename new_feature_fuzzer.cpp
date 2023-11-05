#include "my_api.h"

#include <fuzzer/FuzzedDataProvider.h>
#include <string>
#include <stdlib.h>



extern "C" void LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

  FuzzedDataProvider fuzzed_data(data, size);
  int a = fuzzed_data.ConsumeIntegral<int>();
  int b = fuzzed_data.ConsumeIntegral<int>();
  std::string c = fuzzed_data.ConsumeRandomLengthString();

  exploreMe(a, b, c);
}

// extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
//   if(size < 3) {
//     return 0;
//   }
//   int a = *reinterpret_cast<int*>(data[0]);
//   int b = *reinterpret_cast<int*>(data[1]);
  
//   std::string c(reinterpret_cast<const char *>(data+2), size-2);
//   exploreMe(a, b, c);
//   return 0;
// }