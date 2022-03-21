# cpp-enum-proposal

This proposal, as described in the attached .pdf-file, presents a series of additions to the scoped enum type.
All these additions are meant as strictly **compile-time** additions, with zero runtime overhead.
That is, the compiler should be able to detect and work out all usages, so that runtime deduction or
runtime substitution will never take place. A brief overview:

* concept `std::scoped_enum<T>`
* iterating through all named identifiers through an `std::enum_iterator<T>`
* 

## TODO ##

A requested feature is bitwise operators, which will be added to this proposal at a later date.


## Remarks ##

An earliest possible shipping date for this proposal would likely be C++-26, as it seems that the intended
feature-scope for C++-23 is more or less well-defined ([here](https://en.cppreference.com/w/cpp/compiler_support)).
