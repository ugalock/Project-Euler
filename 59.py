"""
Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.
"""
from functools import reduce
from collections import Counter
strings = [line.split(',') for line in open('59_cipher.txt')]

cipher = [int(char) for s in strings for char in s]

def isEng(a, b):
    ab = ord(a)^b
    if ab in range(97,123) or ab in range(65,91) or ab == 32:
        return True
    return False

def decrypt(s, t):
    return ''.join(chr(a ^ ord(b)) for a, b in zip(s, t))

letters = 'abcdefghijklmnopqrstuvwxyz'

keys = Counter()

for a in letters:
    for b in letters:
        for c in letters:
            for i in range(0, 1198, 3):
                if isEng(a,cipher[i]) and isEng(b,cipher[i+1]) and isEng(c,cipher[i+2]):
                    keys[a+b+c] += 1
print(reduce(lambda x,y: x+y, [ord(c) for c in decrypt(cipher, keys.most_common(1)[0][0]*401)]))
