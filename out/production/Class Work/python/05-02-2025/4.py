# Perform every operation of the dictionary.

dict = {
    "name": "John",
    "age": 30,
    "city": "New York"
}
# operations
print(f"Original Dictionary: {dict}")
print(f"Length of Dictionary: {len(dict)}")

# adding a new key-value pair
dict["country"] = "USA"
print(f"Dictionary after adding a new key-value pair: {dict}")

# updating an existing value
dict["age"] = 31
print(f"Dictionary after updating an existing value: {dict}")

# deleting a key-value pair
del dict["city"]
print(f"Dictionary after deleting a key-value pair: {dict}")

# checking if a key exists in the dictionary
if "country" in dict:
    print("Country key exists in the dictionary.")
else:
    print("Country key does not exist in the dictionary.")

# getting all keys in the dictionary
keys = dict.keys()
print(f"Keys in the dictionary: {keys}")

# getting all values in the dictionary
values = dict.values()
print(f"Values in the dictionary: {values}")

# getting all key-value pairs in the dictionary
items = dict.items()
print(f"Key-Value pairs in the dictionary: {items}")

# checking if the dictionary is empty
if not dict:
    print("The dictionary is empty.")
else:
    print("The dictionary is not empty.")

# clearing the dictionary
dict.clear()
print(f"Dictionary after clearing: {dict}")

# converting the dictionary to a list of tuples
list_of_tuples = list(dict.items())
print(f"List of tuples from the dictionary: {list_of_tuples}")

# converting the dictionary to a list of keys
list_of_keys = list(dict.keys())
print(f"List of keys from the dictionary: {list_of_keys}")