# MDCAEUIT
# Project : Multiple Data Compression and Encryption Using Iterative Technique

#Author : Sajan Kumar Jha

Description : This project is about compressing size of file using Iterative technique. In this project, unique character are picked up from the target file(the file to be compressed) stored in an array,which is also called the master array. After the preperation of master array , the target file is read character by character and according to the length of master array the compression technique is performed. 

for eg: if the length of master array is 12 then it mean that 4 bit compression will be done on the file
            as (2^4) = (16)-1 > master array length(which is 12)
            
Now, the target file is read character by character as then that picked character is searched in the master array and the index/position no is fetched and stored in the first four bit of a character(eg: char c) then 2nd character is picked from the target file and searched in the master array and index is fetched and that index is again stored in the last four bit of the same character.Now when all the 8-bit of the character is filled then its written down in file which is also called the compressed file. Likewise all the character are read and a complete compressed file is created.

After the completion of compressed file , one should also store the master array into some file which is also called the Key file as it will be needed to decompress the file.

Decompression is a reverse of compression as in this , compressed file is read character by character then by using bit shifting technique index is retrived and that index is matched into the master array which eventually gives the character corresponding to that index and finally the compressed file gets decompressed.

Here we can also see that the compressed file is not only compressed but also encrypted as the two character gets compressed into a single character and that character get transformed into a new character which is not the actual data.
