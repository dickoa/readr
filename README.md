# readr

[![Build Status](https://travis-ci.org/hadley/readr.png?branch=master)](https://travis-ci.org/hadley/readr)

The goal of readr is to provide a fast and friendly way to read tabular data into R. The most important functions are:

* Read delimited files: `read_delim()`, `read_csv()`, `read_tsv()`, `read_csv2()`.
* Read fixed width files: `read_fwf()`, `read_table()`.
* Read lines: `read_lines()`.
* Read whole file: `read_file()`.

## Installation

Currently, readr is not available from CRAN, but you can try out the dev version with:

```R
# install.packages("devtools")
devtools::install_github("hadley/readr")
```

## Usage

```r
library(readr)
library(dplyr)

mtcars_path <- tempfile(fileext = ".csv")
write_csv(mtcars, mtcars_path)

# Read a csv file into a data frame
read_csv(mtcars_path)
# Read lines into a vector
read_lines(mtcars_path)
# Read whole file into a single string
read_file(mtcars_path)
```

## Column types

Currently, readr automatically recognises the following types of columns:

* `col_logical()` [l], containing only `T`, `F`, `TRUE` or `FALSE`.
* `col_integer()` [i], integers.
* `col_double()` [d], doubles.
* `col_euro_double()` [e], "Euro" doubles that use `,` as decimal separator.
* `col_character()` [c], everything else.

You can also manually specify other column types:

* `col_skip()` [_], don't import this column.
* `col_datetime(format)`, date times with given format
* `col_numeric()` [n], a sloppy numeric parser that ignores everything apart from
   0-9, `-` and `.` (this is useful for parsing data formatted as currencies).
* `col_factor(levels, ordered)`, parse a fixed set of known values into a 
  factor

Use the `col_types` argument to override the default choices. There are two ways to use it:

* With a string: `"dc__d"`: read first column as double, second as character,
  skip the next two and read the last column as a double. (There's no way to
  use this form with types that need parameters like date time and factor.)

* With a (named) list of col objects:

    ```R
    read_csv("iris.csv", col_types = list(
      Sepal.Length = col_double(),
      Sepal.Width = col_double(),
      Petal.Length = col_double(),
      Petal.Width = col_double(),
      Species = col_factor(c("setosa", "versicolor", "virginica"))
    ))
    ```
    
    Any omitted columns will be parsed automatically, so the previous call is 
    equivalent to:
    
    ```R
    read_csv("iris.csv", col_types = list(
      Species = col_factor(c("setosa", "versicolor", "virginica"))
    )
    ```

## Output

`read_csv()` produces a data frame with the following properties:

* Characters are never automatically converted to factors (i.e. no more 
  `stringsAsFactors = FALSE`).

* Column names are left as is, not munged into valid R identifiers
  (i.e. there is no `check.names = TRUE`).

* The data frame is given class `c("tbl_df", "tbl", "data.frame")` so 
  if you also use [dplyr](https://github.com/hadley/dplyr/) you'll get an 
  enhanced display.

* Row names are never set.

## Compared to base functions

Compared to the corresponding base functions, readr functions:

* Use a consistent naming scheme for the parameters (e.g. `col_names` and 
 `col_types` not `header` and `colClasses`).
 
* Are much faster (up to 10x faster).

* Have a helpful progress bar if loading is going to take a while.

## Compared to `fread()`

[data.table](https://github.com/Rdatatable/data.table) has a function similar to `read_csv()` called fread. Compared to fread, readr:

* Is slower (currently ~1.2-2x slower. If you want absolutely the best 
  performance, use `data.table::fread()`.
  
* Readr has a slightly more sophisticated parser, recognising both 
  doubled ("""") and backslash escapes ("\""). Readr allows you to read
  factors and date times directly from disk.
  
* `fread()` saves you work by automatically guessing the delimiter, whether
  or not the file has a header, how many lines to skip by default and 
  more. Readr forces you to supply these parameters.
  
* The underlying designs are quite different. Readr is designed to be
  general, and dealing with new types of rectangular data just requires 
  implementing a new tokenizer. `fread()` is designed to be as fast as 
  possible. `fread()` is pure C, readr is C++ (and Rcpp).

## Acknowledgements

A big set of thanks to:

* [Joe Cheng](https://github.com/jcheng5) for showing me the beauty of
  deterministic finite automata for parsing, and for teaching me why I 
  should write a tokenizer.
  
* [JJ Allaire](https://github.com/jjallaire) for helping me come up with a
  design that makes very few copies, and is easy to extend.
  
* [Dirk Eddelbuettel](http://dirk.eddelbuettel.com) for coming up with the
  name!
