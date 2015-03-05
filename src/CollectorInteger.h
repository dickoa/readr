#ifndef FASTREAD_COLLECTORINTEGER_H_
#define FASTREAD_COLLECTORINTEGER_H_

#include <Rcpp.h>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
namespace qi = boost::spirit::qi;

#include "Collector.h"

class CollectorInteger : public Collector {
public:

  CollectorInteger(): Collector(IntegerVector()) {
  }

  void setValue(int i, const Token& t) {
    INTEGER(column_)[i] = parse(t);
  }

  int parse(const Token& t) {
    int res = 0;

    switch(t.type()) {
    case TOKEN_STRING: {
      boost::container::string buffer;
      SourceIterators string = t.getString(&buffer);

      bool ok = qi::parse(string.first, string.second, qi::int_, res);
      if (!ok || string.first != string.second) {
        Collector::warn(t);
        res = NA_INTEGER;
      }

      break;
    };
    case TOKEN_MISSING:
    case TOKEN_EMPTY:
      res = NA_INTEGER;
      break;
    case TOKEN_EOF:
      Rcpp::stop("Invalid token");
    }

    return res;
  }

  static bool canParse(std::string x) {
    const char* start = x.c_str();
    char* end;

    errno = 0;
    strtol(start, &end, 10);
    // parsed to end of string and no errors
    return (end == start + x.size()) && (errno == 0);
  }

};

#endif
