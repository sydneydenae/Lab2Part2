signals: signal.c
	gcc signal.c -o signalab 

timerlab: timer.c
	gcc timer.c -o timerlab 

all: signals timerlab