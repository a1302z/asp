gcc -g -O5 -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=hard -marm worker.S test.S main.c -o main
