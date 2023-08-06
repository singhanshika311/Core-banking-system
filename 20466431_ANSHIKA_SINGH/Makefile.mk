CC = gcc

CFLAGS = -Wall -Wextra




# Define the target executable

TARGET = a.out




# Define the source files

SRCS = main.c admin/admin.c customer/customer.c



# Build rule for the target executable

$(TARGET): $(SRCS)

	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)



# Clean rule to remove generated files

clean:

	rm -f $(TARGET)