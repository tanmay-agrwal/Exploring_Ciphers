# **Exploring Cipher Algorithms in C**

This project implements four classical cryptographic ciphers in C: **Caesar Cipher, Playfair Cipher, Vigenere Cipher, and Auto-Key Cipher**. A command-line interface allows users to choose a cipher algorithm, input a message, and either encrypt or decrypt it.


## **Table of Contents**
- [Features](#features)
- [Implemented Cipher Algorithms](#implemented-cipher-algorithms)
- [Compilation and Execution](#compilation-and-execution)
- [How to Use](#how-to-use)

---


## **Features**
✅ Supports encryption and decryption for four different cipher algorithms.  
✅ User-friendly command-line interface for selecting ciphers and modes.  
✅ Accepts user input messages and keys (or keywords).  
✅ Preserves spaces in messages.  
✅ Error handling for invalid input.  

---


## **Implemented Cipher Algorithms**
1. **Caesar Cipher**
   - A simple substitution cipher that shifts letters by a fixed key.
   - **Input:** Plain text (lowercase), key (integer shift value).
   - **Output:** Cipher text (uppercase).

2. **Playfair Cipher**
   - Uses a 5x5 matrix of letters to encrypt digraphs (pairs of letters).
   - **Input:** Plain text (lowercase), keyword (lowercase).
   - **Output:** Cipher text (uppercase).
   - **Note:** This algorithm treats all ***j's*** as ***i's***, and inserts ***x*** for resolving duplicate digrams.

3. **Vigenere Cipher**
   - A polyalphabetic substitution cipher using a repeating keyword.
   - **Input:** Plain text (lowercase), keyword (lowercase).
   - **Output:** Cipher text (uppercase).

4. **Auto-Key Cipher**
   - Similar to Vigenere but extends the keyword with the plaintext itself.
   - **Input:** Plain text (lowercase), keyword (lowercase).
   - **Output:** Cipher text (uppercase).

---


## **Compilation and Execution**
To compile the program, use GCC:

```sh
gcc main.c CaesarCipher.c PlayFairCipher.c VigenereCipher.c AutoKeyCipher.c errormssge.c -o cipher
```

To run the compiled program:

```sh
./cipher
```

---


## **How to Use**
1. **Run the program and select a cipher method:**

    ```csharp
    Which Cipher do you want to work with?

    [1] Caesar Cipher
    [2] Playfair Cipher
    [3] Vigenere Cipher
    [4] Auto-Key Cipher

    Enter the corresponding number here:
    ```

2. **Choose mode (encryption or decryption):**

    ```csharp
    What do you want to do? Cipher[1] or Decipher[2]?
    ```

3. **Input message** (plain text for encryption, cipher text for decryption).

    ```csharp
    Enter the plain/ cipher text:
    ```

4. **Provide a key or keyword** based on the chosen algorithm.

    ```csharp
    Enter the key/ keyword:
    ```

5. **View the result** (output text in uppercase for encryption, lowercase for decryption).
   
    ```csharp
    Corresponding plain/ cipher text:
    ```