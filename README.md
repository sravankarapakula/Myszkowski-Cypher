# Myszkowski Cipher (C++ Implementation)

Implementation of the **Myszkowski Transposition Cipher** with a preprocessing step using **DJB2 hashing**.

---

### 1. Source Code
- Implementation of **Myszkowski Transposition Cipher**
  - Encryption
  - Decryption
- Implemented in **C++**
- No external cryptographic libraries used

### 2. Hashing Function
- Implemented **DJB2 Hash Function** from scratch  
- Reason for selection:
  - Simple and efficient (O(n))
  - Deterministic output for consistent encryption input
  - Widely used for string hashing

---

## Theory

### Myszkowski Transposition Cipher
A classical transposition cipher where:
- A keyword determines column ordering
- Duplicate characters in the key share the same rank
- Columns are read based on rank order
- Provides better diffusion than simple columnar transposition

### DJB2 Hash Function
--H = 5381
--For each character c:
    --H = (H * 33) + ASCII(c)

- Converts plaintext into a numeric hash before encryption

---

## Algorithm

### Encryption Flow

1. Input plaintext `P` and key `K`  
2. Compute DJB2 hash `H`  
3. Convert `H` to string  
4. Let:
   - `m = length(K)`
   - `r = ceil(length(H) / m)`
5. Pad `H` with `'X'` until size = `r × m`  
6. Generate Myszkowski order `O`:
   - Extract unique characters from `K`
   - Sort them
   - Assign ranks starting from `0`
   - Map each character in `K` → rank  
7. Fill grid row-wise  
8. For each rank in ascending order:
   - Traverse columns left → right  
   - If column matches rank:
     - Read top → bottom  
     - Append to ciphertext  
9. Output ciphertext `C`  

---

### Decryption Flow

1. Input ciphertext `C` and key `K`  
2. Compute:
   - `m = length(K)`
   - `r = length(C) / m`  
3. Generate Myszkowski order `O`  
4. Create empty grid `r × m`  
5. Fill grid column-wise:
   - For each rank in ascending order:
     - Traverse columns
     - Fill top → bottom using ciphertext  
6. Read grid row-wise:
   - Recover hashed text `H`  
7. Output recovered hash `H`  

---
Provide:
- Plaintext
- Key

Output:
- Ciphertext
- Recovered hash

---

## Worked Examples

### Example 1

- Plaintext: `HELLO`
- Key: `BANANA`

Hash:
`210714636441`

Ciphertext:
`274146110346`

Decryption Output:
`210714636441`

---

### Example 2

- Plaintext: `SECURITY`
- Key: `LEVEL`

Hash:
`7572963598362735`

Ciphertext:
`7935267358726593`

Decryption Output:
`7572963598362735`

---
## Flow:

Plaintext → Hash → Encrypt → Ciphertext  
Ciphertext → Decrypt → Hash

---

## Validation:
- Original hash == Decrypted hash

---

## Constraints Compliance

- Language: **C++**
- No built-in cryptographic libraries
- Custom hashing implemented
- Includes theory, execution, examples, and validation

---
 
## Notes

- Duplicate key characters share the same rank  
- Padding ensures full grid formation  
- Decryption restores only the hash, not the original plaintext  
