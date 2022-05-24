# cpp-enum-proposal #

How many times have you not created an enum class in C++ together with a function to print out its value:

```cpp
enum class WeekdayType { monday, tuesday, wednesday, thursday, friday, saturday, sunday  };

const char* GetWeekdayTypeString(WeekdayType wt){
    switch (wt) {
    case WeekdayType::monday: return "monday";
    [...]
    }
}
```

This is annoying and difficult to maintain, because if we remove/add/change enum values, we must also
remember to change the function. No more! This proposal adds the following syntax to the C++ language:

```cpp
const char* wdstr = std::enum_string<WeekdayType::monday>;
```

We can also perform checks, such as checking how many weekdays we have, this particular case slightly
contrived but shows the intent:

```cpp
static_assert(std::enum_cardinality<WeekdayType> == 7);
```

## Formalities ##

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

The precise syntax and namings are not set in stone, e.g. it is undetermined whether the naming would best be
`enum_string` or `enum_string_v`. I personally don't have too strong feelings about this. An implementation of
this proposal needs to be designed to fit with the naming- and calling conventions of the rest of the language,
and to support the freedom and strict compile-time requirements appreciated by C++-programmers.

## Suggestions ##

Suggestions and feedback is welcome! Feel free to post an issue. :)
