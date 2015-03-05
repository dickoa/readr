// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// empty_cols
std::vector<bool> empty_cols(std::string x);
RcppExport SEXP fastread_empty_cols(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< std::string >::type x(xSEXP);
    __result = Rcpp::wrap(empty_cols(x));
    return __result;
END_RCPP
}
// flip
List flip(ListOf<CharacterVector> x);
RcppExport SEXP fastread_flip(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< ListOf<CharacterVector> >::type x(xSEXP);
    __result = Rcpp::wrap(flip(x));
    return __result;
END_RCPP
}
// read_file_
CharacterVector read_file_(List sourceSpec);
RcppExport SEXP fastread_read_file_(SEXP sourceSpecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< List >::type sourceSpec(sourceSpecSEXP);
    __result = Rcpp::wrap(read_file_(sourceSpec));
    return __result;
END_RCPP
}
// read_lines_
CharacterVector read_lines_(List sourceSpec, int n_max = -1);
RcppExport SEXP fastread_read_lines_(SEXP sourceSpecSEXP, SEXP n_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< List >::type sourceSpec(sourceSpecSEXP);
    Rcpp::traits::input_parameter< int >::type n_max(n_maxSEXP);
    __result = Rcpp::wrap(read_lines_(sourceSpec, n_max));
    return __result;
END_RCPP
}
// dim_tokens_
IntegerVector dim_tokens_(List sourceSpec, List tokenizerSpec);
RcppExport SEXP fastread_dim_tokens_(SEXP sourceSpecSEXP, SEXP tokenizerSpecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< List >::type sourceSpec(sourceSpecSEXP);
    Rcpp::traits::input_parameter< List >::type tokenizerSpec(tokenizerSpecSEXP);
    __result = Rcpp::wrap(dim_tokens_(sourceSpec, tokenizerSpec));
    return __result;
END_RCPP
}
// tokenize_
std::vector<std::vector<std::string> > tokenize_(List sourceSpec, List tokenizerSpec, int n);
RcppExport SEXP fastread_tokenize_(SEXP sourceSpecSEXP, SEXP tokenizerSpecSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< List >::type sourceSpec(sourceSpecSEXP);
    Rcpp::traits::input_parameter< List >::type tokenizerSpec(tokenizerSpecSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    __result = Rcpp::wrap(tokenize_(sourceSpec, tokenizerSpec, n));
    return __result;
END_RCPP
}
// parse_
SEXP parse_(List sourceSpec, List tokenizerSpec, List collectorSpec);
RcppExport SEXP fastread_parse_(SEXP sourceSpecSEXP, SEXP tokenizerSpecSEXP, SEXP collectorSpecSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< List >::type sourceSpec(sourceSpecSEXP);
    Rcpp::traits::input_parameter< List >::type tokenizerSpec(tokenizerSpecSEXP);
    Rcpp::traits::input_parameter< List >::type collectorSpec(collectorSpecSEXP);
    __result = Rcpp::wrap(parse_(sourceSpec, tokenizerSpec, collectorSpec));
    return __result;
END_RCPP
}
// dataframeString
List dataframeString(CharacterVector x, ListOf<List> specs, int n = 100);
RcppExport SEXP fastread_dataframeString(SEXP xSEXP, SEXP specsSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< ListOf<List> >::type specs(specsSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    __result = Rcpp::wrap(dataframeString(x, specs, n));
    return __result;
END_RCPP
}
