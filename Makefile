all:
	gcc tora.c -o tora.so -fPIC -ldl -D_GNU_SOURCE
