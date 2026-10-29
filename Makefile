pong: pong.c libraylib.a 
	gcc pong.c libraylib.a -o pong -lGL -lm -lpthread -ldl -lrt -lX11
test: test.c libraylib.a
	gcc test.c libraylib.a -o test -lGL -lm -lpthread -ldl -lrt -lX11
