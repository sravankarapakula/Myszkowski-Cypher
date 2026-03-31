# Myszkowski-Cypher
Myszkowski cipher implementation in cpp

# Algorithm:
Encryption Flow:
Input plaintext P and key K
Compute DJB2 hash:
  H ← 5381
  For each character c in P:
    H ← H * 33 + ASCII(c)
Convert H to string
Let m ← length(K)
Compute rows r ← ceil(length(H)/m)
Pad H with 'X' to fill grid
Generate Myszkowski order O
Fill grid row-wise
For each rank in ascending order:
  Read columns top → bottom
Output ciphertext C

Decryption Flow:
Input ciphertext C and key K
Compute m ← length(K)
Compute rows r ← length(C)/m
Generate Myszkowski order O
Fill grid column-wise based on rank order
Read grid row-wise
Output recovered hash H

style the data to present it in readme file in hte git repo
