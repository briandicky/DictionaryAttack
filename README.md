# DictionaryAttack
It is a tool to break a /etc/shadow line using dictionary attack.
This tool will load the dictionary into memory, and tries to concatenate three words into the plaintext password candidate.
It use the crypt library to find the actually password of a person.
Besides, it is implemented a brute force solution with the crypt_r version which is a mutil-thread safe crypt.

##How to compile & run this program
This program is written in Linux environment, GUN make, and GCC(Gnu compiler collection.)
Just type the commands (in BASH shell),
```
make help
```

or

```
make clean dep all
```
It will automatically compile all the necessary files/codes, then generate the execution file.
Then type this,
```
./EXENAME sample_testcase.txt
```

In the end, it will work successfully.

###2016 Advance UNIX Programming HW4
