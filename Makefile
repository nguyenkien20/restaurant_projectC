CFLAGS = -Wall -Wextra -g -Werror

all: final_project

final_project: main.o app_state.o admin.o customer.o inventory.o discount.o
	@echo "Compile final_project file to .exe file"
	gcc $(CFLAGS) main.o app_state.o admin.o customer.o inventory.o discount.o -o final_project

main.o : main.c discount.h app_state.h inventory.h customer.h admin.h common.h config.h
	@echo "Compile file main.c to object file"
	gcc $(CFLAGS) -c main.c

app_state.o : app_state.c app_state.h config.h
	@echo "Compile file app_state.c to object file"
	gcc $(CFLAGS) -c app_state.c

admin.o : admin.c admin.h
	@echo "Compile file admin.c to object file"
	gcc $(CFLAGS) -c admin.c

customer.o : customer.c customer.h
	@echo "Compile file customer.c to object file"
	gcc $(CFLAGS) -c customer.c

inventory.o : inventory.c inventory.h
	@echo "Compile file inventory.c to object file"
	gcc $(CFLAGS) -c inventory.c

discount.o : discount.c discount.h
	@echo "Compile file discount.c to object file"
	gcc $(CFLAGS) -c discount.c
	
clean: 
	rm -f *.o final_project 

.PHONY: all clean