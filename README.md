# Cybercube BloomFilter task

Bloom filter has two parameters: _m_, the maximum size (usually a large enough multiple of the cardinality to be represented) and _k_, the number of hashing functions for the elements of the set. (The actual hashing functions are important too, but this is not a parameter for this implementation.) Bloom filter is maintained by the key is represented in the filter by setting bits for each hash value. Membership in a set is done by _testing_ whether the bits are set for each hash value. If yes, then the item is in the set. If the item is indeed in the set, the Bloom filter will never fail (true positive value is 1.0); but it is prone to false positives. The art of choosing the right _k_ and _m_.
In this implementation, the hashing functions used is simple hash, a non-cryptographic hashing function.

This implementation accepts keys for setting and testing as `String`.

```cpp
    BloomFilter filter = BloomFilter();
    filter.loadFromFile("../../data/wordlist.txt");

    REQUIRE(filter.isContain("molecule's") == true);
    REQUIRE(filter.isContain("oh-no-i-know") == false);
 ```
 
