#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

using std::map;
using std::string;
using std::to_string;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::stoi;
using std::atoi;

const char *ERROR = "Wrong arguments!\nThe program takes 1 positive integer.\n";

void process_factor(int n, map<int, int>& primes) {
  auto it = primes.begin();
  while (it != primes.end() && n != 1) {
    if (n % it->first == 0) {
      it->second++;
	    n /= it->first;
	    it = primes.begin();
      continue;
    }
    it++;
  }
  if (n != 1) {
    primes[n] = 1;
  }
}

string to_string(map<int, int>& primes) {
  string result = "";
  string aux = "";
  for (auto it = primes.begin(); it != primes.end(); it++) {
    aux = it->second == 1
          ? to_string(it->first)      
          : to_string(it->first) + "^" + to_string(it->second);
    result += result == "" ? aux : " * " + aux;
  }
  return result;
}

string decompose(int n)
{
  map<int, int> primes;
  for (int i = 2; i <= n; i++) {
    process_factor(i, primes);
  }
  return to_string(primes);
}

int main(int argc, char **argv)
{
  if (argc != 2) {
    cerr << ERROR;
    return 1;
  }
  string input = argv[1];
  int n = atoi(input.c_str());
  if (n == 0 && argv[1][0] != '0') {
    cerr << ERROR;
    return 1;
  }
  cout << decompose(n) << endl;
}
