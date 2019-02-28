#include <iostream>
#include "../singleheader/simdjson.h"

int main() {
  const char * filename = JSON_TEST_PATH; 
  std::string_view p = get_corpus(filename);
  ParsedJson pj = build_parsed_json(p); // do the parsing
  if( ! pj.isValid() ) {
    return EXIT_FAILURE;
  }
  pj.allocateCapacity(p.size());
  const int res = json_parse(p, pj);
  if (res) {
    std::cerr << simdjerr::errorMsg(res) << std::endl;
    return EXIT_FAILURE;
  }
  free((void*)p.data());
  return EXIT_SUCCESS;
}