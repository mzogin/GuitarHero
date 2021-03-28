#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <exception>
#include <stdexcept>
#include <vector>

#include "StringSound.h"

BOOST_AUTO_TEST_CASE(SS) {
  std::vector<sf::Int16> v;

  v.push_back(0);
  v.push_back(1000);
  v.push_back(2000);
  v.push_back(-5000);

  BOOST_REQUIRE_NO_THROW(StringSound ss = StringSound(v));

  StringSound ss = StringSound(v);

  // SS is 0 1000 2000 -5000
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == 0);

  ss.tic();
  //  now 1000 2000 -5000 498
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == 1000);

  ss.tic();
  //  now 2000 -5000 498 1494
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == 2000);

  ss.tic();
  //  now -5000 498 1494 -1494
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == -5000);

  ss.tic();
  //  now 498 1494 -1494 -2241
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == 498);

  ss.tic();
  //  now 1494 -1494 -2241 992
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == 1494);

  ss.tic();
  //  now -1494 -2241 992 0
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == -1494);

  ss.tic();
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == -2241);
  ss.tic();
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == 992);
  ss.tic();
  std::cout << "Sample is: " << ss.sample() << "\n";
  BOOST_REQUIRE(ss.sample() == 0);
}
