#include <iostream>
#include <string>
#include <vector>
namespace kmp {
std::vector<int> prefix(std::string& M) {
  std::vector<int> prefix = std::vector<int>(M.size(), -1);
  int curr_prefix = -1;
  for (unsigned int i = 1; i < M.size(); ++i) {
    while (curr_prefix > -1 && M[curr_prefix + 1] != M[i]) {
      curr_prefix = prefix[curr_prefix];
    }
    if (M[curr_prefix + 1] == M[i]) {
      ++curr_prefix;
    }
    prefix[i] = curr_prefix;
  }
  return prefix;
}

std::vector<int> kmp(const std::string& N, const std::string& M,
                     const std::vector<int> prefix) {
  std::vector<int> match = std::vector<int>(N.size(), -1);
  int curr_match = -1;
  for (unsigned int i = 0; i < N.size(); ++i) {
    while (curr_match + 1 == M.size() ||
           (curr_match > -1 && N[i] != M[curr_match + 1])) {
      curr_match = prefix[curr_match];
    }
    if (M[curr_match + 1] == N[i]) {
      ++curr_match;
    }
    match[i] = curr_match;
  }
  return match;
}
}  // namespace kmp

int main() {
  std::string s = "cocacoco";
  std::string t = "pcococacocokacoco";
  std::vector<int> result = kmp::kmp(t, s, kmp::prefix(s));
  for (int& i : result) {
    std::cout << i << std::endl;
  }
  return 0;
}

