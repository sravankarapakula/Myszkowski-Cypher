# Myszkowski Cipher (C++ Implementation)

Implementation of the **Myszkowski Transposition Cipher** with a preprocessing step using **DJB2 hashing**.

---

## Algorithm

### Encryption Flow

1. Input plaintext `P` and key `K`  

2. Compute DJB2 hash:
   
3. Convert `H` to string  

4. Let:
   
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

## Flow Summary

1. Encryption:
   P → DJB2 → H → Myszkowski → C

2. Decryption:
   C → Reverse Myszkowski → H

---

## Notes

- Duplicate key characters share the same rank  
- Padding ensures full grid formation  
- Decryption restores only the hash, not the original plaintext  
