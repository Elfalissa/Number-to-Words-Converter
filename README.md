# Number-to-Words Converter  

This project is written in **C** and follows the **Norminette** coding standard.  
It provides a program that converts a positive integer (up to 37 digits) into its **word representation**, using a dictionary file (`numbers.dict`).  

## Features
- Written in **pure C**, Norminette-compliant.
- Input validation to reject invalid or unsupported inputs.
- Handles **numbers up to 10^37 - 1**.
- Uses a **dictionary file** (`numbers.dict`) for word lookups.
- Includes a **Makefile** for easy compilation and execution.

## Compilation

To build the project, simply run:
```
make
```
This will generate the executable rush02

## Usage
```
./rush02 <number>
```
Example
```
./rush02 123
```
### ✅ Valid inputs and their outputs

```
./rush02 0
Output: zero

./rush02 7
Output: seven

./rush02 42
Output: forty two

./rush02 105
Output: one hundred five

./rush02 123456
Output: one hundred twenty three thousand four hundred fifty six
```

### ❌ Invalid inputs and their error message

No argument/more than one argument/empty argument
```
./rush02
Output: Error
```
Leading zeros
```
./rush02 0123
Output: Error
```
Not a number
```
./rush02 abc
Output: Error
```
Too many digits (> 37)
```
./rush02 999999999999999999999999999999999999999
Output: Error
```

## Author
This project is part of a 42 School Rush project — written in C with ❤️ and fully compliant with the Norminette standard.
