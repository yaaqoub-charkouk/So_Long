all: 
	cc main.c libmlx.a -framework OpenGL -framework AppKit
run: all
	./a.out
clean :
	rm -rf a.out