MDC: main.o main_choice.o compression.o open_file.o create_Master_Array.o unique.o count_length.o decompression.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o find_index.o init.o decompress4.o decompress3.o decompress5.o decompress6.o decompress2.o
	gcc -lm -o MDC main.o main_choice.o compression.o open_file.o create_Master_Array.o unique.o count_length.o decompression.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o find_index.o init.o decompress4.o decompress3.o decompress5.o decompress6.o decompress2.o

decompress2.o: decompress2.c header.h declaration.h
	gcc -c decompress2.c
decompress6.o: decompress6.c header.h declaration.h
	gcc -c decompress6.c
decompress5.o: decompress5.c header.h declaration.h
	gcc -c decompress5.c
decompress3.o: decompress3.c header.h declaration.h
	gcc -c decompress3.c
decompress4.o: decompress4.c header.h declaration.h
	gcc -c decompress4.c
init.o: init.c header.h declaration.h
	gcc -c init.c
find_index.o: find_index.c header.h declaration.h
	gcc -c find_index.c
compress7.o: compress7.c header.h declaration.h
	gcc -c compress7.c 
compress6.o: compress6.c header.h declaration.h
	gcc -c compress6.c 
compress5.o: compress5.c header.h declaration.h
	gcc -c compress5.c 
compress4.o: compress4.c header.h declaration.h
	gcc -c compress4.c 
compress3.o: compress3.c header.h declaration.h
	gcc -c compress3.c 
compress2.o: compress2.c header.h declaration.h
	gcc -c compress2.c 
decompression.o: decompression.c header.h declaration.h
	gcc -c decompression.c 
count_length.o: count_length.c header.h declaration.h
	gcc -c count_length.c 
unique.o: unique.c header.h declaration.h
	gcc -c unique.c 
create_Master_Array.o: create_Master_Array.c header.h declaration.h
	gcc -c create_Master_Array.c 
open_file.o: open_file.c header.h declaration.h
	gcc -c open_file.c 
compression.o: compression.c header.h declaration.h
	gcc -c compression.c 
main_choice.o: main_choice.c header.h declaration.h
	gcc -c main_choice.c
main.o: main.c header.h declaration.h
	gcc -c main.c

clean: 
	rm *.o
	rm ./MDC
