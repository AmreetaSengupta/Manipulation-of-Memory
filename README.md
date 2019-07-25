# Manipulation-of-Memory
Code contains design of an interactive command-line utility to perform memory manipulation functions on Linux platform as well as MCUXpresso IDE.

The following functions have been implemented:

## **Help:**

The help function displays a brief description of what each function in the utilty does. This function is
invoked when the string ‘help’ is entered by the user. The string is not case sensitive. This input is
compared with the predefine string in the lookup table and if it matches then the help function is
executed.

**--> Allocate:**

The Allocate function allocates 32 bit blocks of memory. The number of blocks to be allocated is
specified by the user. This function is invoked when the string ‘allocate’ is entered by the user. The
string is not case sensitive. This input is compared with the predefined string in the lookup table and if it
matches then the allocate function is executed. In case allocation fails the user is asked to allocate again
using the same commands.

**--> Write:**

• The Write function write hexadecimal value of the data entered by the user to a specified
address. This function is invoked when the string ‘write’ is entered by the user. The string is not case
sensitive. This input is compared with the predefined string in the lookup table and if it matches then the
write function is executed.

• The user is asked to specify the address where the data is to be written . The user can either type
the entire address or give the offset from the starting address. The user must enter ‘a’ if he wants
to enter address and ‘o’ if he wants to enter offset. If the user enters anything other than a and o
then an error message is displayed and the user is asked to input again.

• If the user enters ‘a’, he is asked to enter the address next. The user is expected to enter the hex
value of the address.

• If the user enters ‘o’ he is asked to enter the address between 0 to the number of words that he
has allocated.

• In both the case if the address is incorrect or if it is out of range an error message is displayed
and user is asked to enter again.

**--> Display:**

• The Display function display hexadecimal data written by the user from a specified address.
This function is invoked when the string ‘display’ is entered by the user. The string is not case sensitive.
This input is compared with the predefined string in the lookup table and if it matches then the write
function is executed.

• The user is asked to specify the address from where the data is to be read . The user can either
type the entire address or give the offset from the starting address. The user must enter ‘a’ if he
wants to enter address and ‘o’ if he wants to enter offset. If the user enters anything other than a
and o then an error message is displayed and the user is asked to input again.

• If the user enters ‘a’, he is asked to enter the address next. The user is expected to enter the hex
value of the address.

• If the user enters ‘o’ he is asked to enter the address between 0 to the number of words that he
has allocated.

• In both the case if the address is incorrect or if it is out of range an error message is displayed
and user is asked to enter again.

• The data is the displayed on the screen.

**--> Invert:**

• The Invert function inverts the hexadecimal data present at the address by the user.the time taken to
execute this function is also printed This function is invoked when the string ‘invert’ is entered by the
user. The string is not case sensitive. This input is compared with the predefined string in the lookup
table and if it matches then the write function is executed.

• The user is asked to specify the address where the data is to be inverted . the user can either type
the entire address or give the offset from the starting address. The user must enter ‘a’ if he wants
to enter address and ‘o’ if he wants to enter offset. If the user enters anything other than a and o
then an error message is displayed and the user is asked to input again.

• If the user enters ‘a’, he is asked to enter the address next. The user is expected to enter the hex
value of the address.

• If the user enters ‘o’ he is asked to enter the address between 0 to the number of words that he
has allocated.

• In both the case if the address is incorrect or if it is out of range an error message is displayed
and user is asked to enter again.

• The inverted data is then displayed on the screen along with the original data. The time taken to
execute this function is also printed.

**--> Write Pattern:**

• The write pattern function is used to write pseudo random numbers to the number of blocks of
addresses specified by the user. the time taken to execute this function is also printed This function is
invoked when the string ‘write_pattern’ is entered by the user. The string is not case sensitive. This input 
is compared with the predefined string in the lookup table and if it matches then the write function is
executed.

• The user is asked to specify the address where the data is to be written. the user can either type
the entire address or give the offset from the starting address. The user must enter ‘a’ if he wants
to enter address and ‘o’ if he wants to enter offset. If the user enters anything other than a and o
then an error message is displayed and the user is asked to input again.

• If the user enters ‘a’, he is asked to enter the address next. The user is expected to enter the hex
value of the address.

• If the user enters ‘o’ he is asked to enter the address between 0 to the number of words that he
has allocated.

• In both the case if the address is incorrect or if it is out of range an error message is displayed
and user is asked to enter again.

• After the address or offset is specified the user is asked to enter the number of block to which he
wants to write the random numbers. The user is expected to enter the number of blocks that start
from the address that he specified and is within the range of the allocated range.

• A seed value is then take from the user which is used to generate the random number.

**--> Verify Pattern:**

• The verify pattern function is used to verify the pseudo random numbers written by the user. the time
taken to execute this function is also printed This function is invoked when the string ‘verify_pattern’ is
entered by the user. The string is not case sensitive. This input is compared with the predefined string in
the lookup table and if it matches then the write function is executed.

• The user is asked to specify the address where the data is to be written. the user can either type
the entire address or give the offset from the starting address. The user must enter ‘a’ if he wants
to enter address and ‘o’ if he wants to enter offset. If the user enters anything other than a and o
then an error message is displayed and the user is asked to input again.

• If the user enters ‘a’, he is asked to enter the address next. The user is expected to enter the hex
value of the address.

• If the user enters ‘o’ he is asked to enter the address between 0 to the number of words that he
has allocated.

• In both the case if the address is incorrect or if it is out of range an error message is displayed
and user is asked to enter again.

• After the address or offset is specified the user is asked to enter the number of block to which he
wants to verify. The user is expected to enter the number of blocks that start from the address
that he specified and is within the range of the allocated range.

• A seed value is then taken from the user which is used to generate the random number

• It is then compared and printed if it is successfully matching or if it has descripencies.

**--> Free:**

This function releases the allocated memory. This function is invoked when the string ‘free’ is
entered by the user. The string is not case sensitive.

**--> Exit:**

This function is used from exiting the utility. This function is invoked when the string ‘exit’ is
entered by the user. The string is not case sensitive.
