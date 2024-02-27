/**
 * Overview:
 *      std::unordered_map is an associative container that stores key-value pairs with unique keys.
 *      It provides efficient search, insertion, and removal operations with an average constant-time complexity.
 *      Unlike std::map, the elements in an unordered_map are not sorted in any particular order.
 * 
 * Hash Table Implementation:
 *      Internally, std::unordered_map uses a hash table to organize its elements.
 * 
 * Here’s how it works:
 *      Hashing: The keys are hashed into the hash table using a hashing function.
 *      Buckets: The hash table is divided into buckets based on the hash values of keys.
 *      Mapping: Each key-value pair is mapped to a specific bucket.
 *      Fast Access: This organization allows for fast access to individual elements directly by their key values.
 * 
 * Ordering:
 *      The elements within each bucket are not sorted with respect to either their key or mapped values.
 *      Keys with the same hash code appear in the same bucket, but their order is unordered.
 * 
 * Performance:
 *      std::unordered_map containers are generally faster than std::map containers for accessing individual elements by their key.
 * However, they may be less efficient for range iteration through a subset of elements.
 * In summary, std::unordered_map provides a powerful and efficient way to manage key-value associations, leveraging the underlying hash table structure. Remember that the keys are unordered, making it suitable for scenarios where sorting is not a requirement.
*/
#include <iostream>
#include <unordered_map>
