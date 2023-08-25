
# Password Manager XOR Cipher for Encryption

# Program Description:
# This program takes a 20 character password and a 20 character key,
# converts the data into binary, then performs the XOR operation
# on the two bit strings. This is known as an XOR encryption cipher,
# and the original message can be restored by simply doing the XOR
# operation again (i.e. XOR the result with the key to get the password)

# Passwords are defined to have a maximum of 20 ASCII chars and are randomly generated
# With 8 bits per ASCII character and our passwords being 20 characters,
# this means we need to allocate 8 x 20 = 160 bits to represent one password.
# Possible binary values in ASCII range from 0000 0000 to 1111 1111

# TO DO: Implement the reverse decryption function.
# TO DO: Integrate the random password generator with the encryption function

import math
import numpy as np
import secrets
import string

# Step 1: Converting a Password String to Binary

# Take password string and use a for loop to convert each character into bits,
# and append each set of bits to the previous one to make one long string of 120 bits.

password = "sordfishsordfishsord"
print("The password is " + password)

# Calling string.encode() function to turn the specified string into an array of bytes
byte_array = password.encode()

# Converting the byte_array into a binary integer
# 'big' argument means the most significant byte is at the beginning of the byte array
binary_int = int.from_bytes(byte_array, "big")

# Printing the converted binary characters
print("This is pw converted from ascii to binary:")
#print(format(binary_int, '064b'))
binresult1 = bin(binary_int)[2:].zfill(160)
print (binresult1)



# Step 2: Converting the key from ASCII to binary
# Creates a binary string based on a master key (also 20 char limit)


key = "whateverwhateverwhat"
byte_array2 = key.encode()

binary_int2 = int.from_bytes(byte_array2, "big")

print("This is the key converted from ascii to binary:")
#print(format(binary_int2, '064b'))
binresult2 = bin(binary_int2)[2:].zfill(160)
print (binresult2)



# Step 3: Takes a password and encrypts it using the master key and XOR cipher

# Does XOR operation and returns an integer
xorresult = np.bitwise_xor(binary_int2, binary_int)

# Converts binary string to bytes
# First argument is the number of bytes to represent the integer
# In this case, we use 20 because 160/8 = 20.
bytes3 = int(xorresult).to_bytes(20, "big")

# Converts result from int to binary
bxorresult = bin(xorresult)

print("This is the XOR result:")

#print(format(xorresult, '064b'))
binresult3 = bin(xorresult)[2:].zfill(160)
print (binresult3)

# Prints xor result in ascii
print("This is the XOR result in ASCII")
ascii_text2 = bytes3.decode()
print(ascii_text2)



# Reading and Writing Text to a File

from pathlib import Path

# Writes password (in binary) to a text file

print('Writing password to file passwords.txt...')
# Sets a file path to a variable
# We want to use the 'a' (append) argument to add to the file, not replace our first line
p = open('passwords.txt', 'a')
# Writes key to the file specified by the path in variable p
p.write('\n' + binresult1 + '\n')
p.close()

# Writes the key (in binary) to a text file
print('Writing key to file passwords.txt...')
p1 = open('passwords.txt', 'a')
p1.write('\n' + binresult2 + '\n')
p1.close()


# Writes XOR result (in binary) to a text file
print('Writing XOR result to file passwords.txt...')
p2 = open('passwords.txt', 'a')
p2.write('\n' + binresult3 + '\n')
p2.close()



# Generating random n=20 character passwords

# Uses the secret module which generates less predictable random numbers.

n = 20

# using secrets.choice()
# generating random strings
res = ''.join(secrets.choice(string.ascii_uppercase + string.digits)
              for i in range(n))

# print result
print("The generated random key : " + str(res))




